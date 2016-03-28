/*
 Author  : Ashish Kamble
 File name : uart
 Type :header file
 */
 
//-----------------------------------------uart.h--------------------------------------------//



//Header Files
#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>




#ifndef UART_H
#define UART_H

//Functions prototype
void usart_init(void);
void usart_transmit_char( unsigned char data );
void usart_transmit_string(char *msg );
unsigned char usart_receive_char(void);
void uart_transmit_newline(void);
#endif //UART_H
