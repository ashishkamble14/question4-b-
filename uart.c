/*
  Author     : Ashish Kamble
  File name  : uart
  Type       : Source File
  
*/

//-------------------------------------------uart.c----------------------------------------------//

//Header files
#include<avr/io.h>
#include<stdlib.h>
#include<compat/deprecated.h>
#include<util/delay.h>
#include<avr/eeprom.h>
#include<uart.h>


//Function Definitions
#define BAUD 9600                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate value for UBRR

//Initialisation function
void uart_init(void)
{
 UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
 UBRRL = BAUDRATE;                           // set baud rate
 UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter 
 UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);   // UCSZ0/1 dceides the data format,here both are set so that we get 8 bit data format.
}

 
//Function to send 8 bit data in char data type 
void uart_transmit_char( unsigned char data )
{
  while ( !( UCSRA & (1<<UDRE)) )                    // Wait for empty transmit buffer //
    ;
  UDR = data;                                        // Put data into buffer, sends the data //
}


//Function to send data as a string
void uart_transmit_string(char *msg )
{
  while(*msg!='\0')
  {
    uart_transmit_char(*msg);
    msg++;
  }
}

//Function to receive 8 bit data
unsigned char uart_receive_char(void)
{
   while ( !(UCSRA & (1<<RXC)) )                       // Wait for data to be received //       
    ;
  return UDR;                                           // Get and return received data from buffer //
}

//Function to transmit data on new line
void uart_transmit_newline(void)
{
  uart_transmit_char(10);
  uart_transmit_char(13);
}


