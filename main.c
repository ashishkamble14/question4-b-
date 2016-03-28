/*
  Author     : Ashish Kamble
  File name  : main
  Created on :
  Programmer : Usbasp
  This program is designed so that ATmega16 can communicate with the computer via UART and
  transmit the adc value of voltage obtained across potentiometer.
  The sliding pin of potentiometer is connected to PIN A0 of ATmega16.
  The ADC PIN A0 converts the analog voltage into 10bit adc value.
  10 bits because ATmega16 have maximum adc resolution of 10 bits.
  After getting the value,it is transmitted using UART communication protocol using CP2102
  hardware and is displayed on Serial monitor.
*/


#include<avr/io.h>
#include<util/delay.h>
#include "adc.c"
#include "uart.c"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

//BASIC I/O FILE SETTINGS

#define INPUT 0
#define OUTPUT 1


void main()
{
  //Initialisations
  char message [5];
  adc_init();                   //ADC feature has been initiliased
  uart_init();                  //initialises the uart feature
  uint16_t potentiometer_value = 0;       //defined an 16 bit i.e 2 byte integer to store adc result

  while (1)
  {
    //Read the analog value of potentiometer from PIN A0 and store the converted adc value in integer variable potentiometer_value
    potentiometer_value = adc_start(0);
    //the adc result is an 10 bit value which cannot be directly transmitted via uart because uart can transmit
    //maximum 9 bits at a time
    //so here the integer value has been converted into string
    itoa(potentiometer_value, message, 10);     //Function defined in stdlib.h which converts the integer value to string.
	                                             //Arguments are int value,string variable, base......here int to be displayed is of base 10
    uart_transmit_string(message);              //function transmits the string to computer using uart
	uart_transmit_newline();                    //Function adds new line on the serial monitor where the data is printed     
    _delay_ms(500);                             //Adds delay os 0.5 second so that the dipaly could be easily readable

  }

}

