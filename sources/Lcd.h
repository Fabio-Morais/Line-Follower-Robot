#ifndef LED
#define LED
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define ctrl PORTD
#define en PB5
#define rs PB4


void lcd_command(char cmd);
void lcd_init(void);
void lcd_data(unsigned char data);
void lcdCommand(unsigned char);
void lcdData(unsigned char);
void lcd_print(char *str);
void lcd_gotoxy(unsigned char x, unsigned char y);
void Reset_Lcd();

static FILE mystdout = FDEV_SETUP_STREAM(lcdData, NULL, _FDEV_SETUP_WRITE);

/*Separa 4 em 4 bits para enviar no modo 4bits*/
void lcdCommand(unsigned char cmd_value) {
	char cmd_value1;
	cmd_value1 = cmd_value & 0xF0;          // Mask lower nibble
	lcd_command(cmd_value1);                // Send to LCD
	_delay_us(10);

	cmd_value1 = ((cmd_value << 4) & 0xF0); // Shift 4-bit and mask
	lcd_command(cmd_value1);                // Send to LCD
	_delay_us(10);

}

void lcd_init(void) {

	DDRB |= (1 << rs) | (1 << en);
	lcdCommand(0x02); // To initialize LCD in 4-bit mode.

	lcdCommand(0x01); // Clear LCD

	lcdCommand(0x28); // To initialize LCD in 2 lines, 5X7 dots and 4bit mode.

	lcdCommand(0x0F); // Turn on cursor ON

	lcdCommand(0x80); // —8 go to first line and –0 is for 0th position


	_delay_ms(200);//Espera um pouco antes de começar

	return;
}

void lcd_print(char *str) { // store address value of the string in pointer *str

	while (*str > 0) {  // loop will go on till the NULL character in the string
		lcdData(*str++); // sending data on LCD byte by byte

	}
	return;
}

void lcdData(unsigned char data_value) {
	char data_value1;
	data_value1 = data_value & 0xF0;          // Mask lower nibble
	lcd_data(data_value1);
	_delay_us(10);
	data_value1 = ((data_value << 4) & 0xF0); // Shift 4-bit and mask
	lcd_data(data_value1);                    // Send to LCD	_delay_us(10);
	_delay_us(10);
}

void lcd_data(unsigned char data) {

	PORTB |= (1 << rs);  // RS = 1 for data
	PORTB |= (1 << en);  // EN = 1 for High to Low pulse
	_delay_us(100);
	ctrl |= data;
	_delay_us(10);
	PORTB &= ~(1 << en); // EN = 0 for High to Low Pulse
	_delay_ms(2);
	ctrl &= ~data;

	return;
}
void lcd_command(char cmd) {

	PORTB &= ~(1 << rs); // RS = 0 for command
	PORTB |= (1 << en);  // EN = 1 for High to Low pulse
	_delay_us(100);
	ctrl |= cmd;
	_delay_us(10);
	PORTB &= ~(1 << en); // EN = 0 for High to Low pulse
	_delay_ms(2);
	ctrl &= ~cmd;

	return;
}
void lcd_gotoxy(unsigned char x, unsigned char y) {
	unsigned char firstCharAdr[4] = { 0x80, 0xC0, 0x94, 0xD4 };
	lcdCommand(firstCharAdr[y - 1] + x - 1);
	_delay_us(500);
}

void Reset_Lcd(){
	lcdCommand(0x01); // Clear LCD

}

#endif

