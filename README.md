# Line-Rollower-Robot

----

##### The main purpose was to develop and implement a line follower robot that would have to follow the line as fast as possible. For that we projected a microcontroller based system with a user friendly mobile application. With this project all the topics that were given during the lecturers were covered since the interruptions on ATMEGA to the Analog/Digital converter. More specifically, we used the timer in PWM mode to control the motors and the USART protocol for the Bluetooth communication. The A/D converter was used to get the battery level and the EEPROM to record the track.

----

Este projeto vai ser implementando dando uso ao microcontrolador ATMEGA-328P, que é o microcontrolador do arduino, irá ser desenvolvido atraves do [eclipse](https://www.eclipse.org/), com o plugin AVR.
Tem como principal objetivo seguir uma linha preta, com diversos extras.
Vai ser usado o conversor A/D, EEPROM, modo PWM, timers e comunicação USART.

<p align="center">
  <img src="https://user-images.githubusercontent.com/35969631/51709991-cd2f1280-201f-11e9-9b0c-49ccb89862b0.jpg" width="400" height="300">
</p>



### Materiais utilizados
* Arduino Uno
* LCD Module Display 20x4
* Modulo Bluetooth HC-06
* Array de 5 sensores infrared
* Motor DC 3V-6V c/Roda
* Dual channel DC motor driver
* Placa acrílico
* Suporte 3x pilhas AA
* Power Bank 4000mah
* Interruptor ON/OFF
* LED azul e vermelho

<p align="center">
  
   <img src="https://user-images.githubusercontent.com/35969631/51689680-0bf8a480-1fef-11e9-9f20-35d9b9e2bc54.png">
</p>

---

## Funcionalidades APP
* **Modo Manual**
  * Controlar robô, muda direção e sentido
  * ALtera velocidade
  * Grava trajeto
  * Reproduz trajeto
  * Ver estado da bateria
  * Caso a bateria esteja a menos de 20%, então é sinalizado essa informação ao começar a piscar a barra da bateria

<p align="center">
  <img src="https://user-images.githubusercontent.com/35969631/51706773-59890780-2017-11e9-8f1a-d1c2298796c1.jpg" width="500" height="270">
</p>




* **Modo Automático**
  * Ver estado dos sensores
  * Ver estado de bateria
  * Dar Start ou Stop
  * Alterar velocidade
  * Conta o numero de voltas
  * Conta o tempo que efectuou na volta
  * Apresenta o melhor tempo
  * Permite dar reset às estatisticas
  * Caso o robô esteja perdido é avisado na APP com a indicação de que está perdido e o dispositivo treme
  * Permite gravar trajeto 
  * Permite reproduzir trajeto
  * Permite ativar modo de competição, em que aumenta mais a velocidade e desliga todas as conexões existentes
  * Caso a bateria esteja a menos de 20%, então é sinalizado essa informação ao começar a piscar a barra da bateria
  
<p align="center">
  <img src="https://user-images.githubusercontent.com/35969631/51708005-9f939a80-201a-11e9-8993-3f61d725abfa.jpg" width="500" height="270">
</p>
<p align="center">
  <img src="https://user-images.githubusercontent.com/35969631/51708004-9f939a80-201a-11e9-8567-8a2dcd8948bc.jpg" width="500" height="270">
</p>


----

## Funcionalidades robô
* **Modo Manual**
  * Permite ser controlado via bluetooth
  * Caso esteja conectado via bluetooth então é imprimido a mensagem "conectado", caso por algum motivo perca a comunicaçao, então é imprimido "desconectado", parando todos os motores e pisca o led azul a cada 0,5s
  * Grava o trajeto, piscando a cada 1s o led vermelho
  * Reproduz o trajeto efetuado, quando acaba a reprodução os motores são parados e imprime a mensagem no lcd "Reprodução acabada"
  <img align="left" width="350" height="180" src="https://user-images.githubusercontent.com/35969631/51706769-5726ad80-2017-11e9-83e0-387e94e55455.jpg">
  
  <img align="left" width="350" height="180" src="https://user-images.githubusercontent.com/35969631/51706770-57bf4400-2017-11e9-9ed0-d4f0ba023969.jpg">

<br/>
<br/>
<br/>
<br/>
<br/>
<br/>

<br/>
<br/>
<br/>




* **Modo Automático**

 


