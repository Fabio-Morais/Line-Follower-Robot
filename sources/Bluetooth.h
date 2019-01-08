#ifndef Blue
#define Blue
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/interrupt.h>

/*Baud rate do hc-06*/
#define BAUD 9600
#define UBBR_VAL (F_CPU/8/BAUD-1)



void init_usart(void){

	// Definir baudrate
	 UBRR0H = (unsigned char)(UBBR_VAL>>8);
	 UBRR0L = (unsigned char) UBBR_VAL;

	 // Definir formato da trama
	 UCSR0C = (1 << UCSZ01) | (1 << UCSZ00) // 8 data bits
	 | (0<<USBS0); // 1 stop bit

	 /*Velocidade dupla*/
	 UCSR0A= (1<<U2X0);
	 /* Ativar Rx, Tx e interrupção no Rx*/
	 UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);


}

/*Envia Codigo ascii para o bluetooth*/
void Send_Data(unsigned char str){

		while (!( UCSR0A & (1<<UDRE0)) );
			UDR0 = str;

}



/*Recebe codigo ascii do bluetooth*/
unsigned char Receive_Data(){

	while(!(UCSR0A & (1<<RXC0)));

	return UDR0;

}




#endif
