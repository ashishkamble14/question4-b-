/*
Author    : Ashish Kamble
File name : adc
Type      : Header file
*/

//-----------------------------------------------------adc.h---------------------------------------------------//

//Header Files
#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>


#ifndef ADC_H
#define ADC_H

//ADC 	DIRECTIONS

#define ADC			PORTA                       //Declared ADC macro for PORTA
#define ADC_DIR 	DDRA                        //Declared ADC_DIR macro for DDRA register 

//Functions prototypes
void adc_init(void);
unsigned char adc_start(unsigned char channel);

#endif //ADC_H
