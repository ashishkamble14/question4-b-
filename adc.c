/*
  Author     : Ashish Kamble
  File name  : adc
  Type       : Source file 
  
*/

//----------------------------------------------adc.c----------------------------------------------//

//Header files
#include<avr/io.h>
#include<stdlib.h>
#include<compat/deprecated.h>
#include<util/delay.h>
#include<avr/eeprom.h>
#include<adc.h>


//Function Definitions


//Initialises ADC
void adc_init(void)
{
  ADC_DIR=0X00;              //Initialised PORTA as an input PORT
  ADCSRA=0X00; 
  ADMUX = (1<<REFS0);        //Disables internal Vref and we can set Refrence voltage across AREF and GND pin.
  ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);  //Enabled the ADC feature by setting ADEN and set prescalar of 128.
  ACSR=0X80;                       //ACD bit is set high which disables the analog comparator mode by switching off the power 
}                                   //to ACD hence saves power



//Conversion of analog value to digital value takes here
unsigned char adc_start(unsigned char channel)
{
  unsigned char i;

  ADCH=0x00;

  i=channel&0x07;              // ANDing with ’7' will always keep the value of channel between 0 and 7
  ADMUX=i|0x40;               
  ADCSRA|=1<<ADSC;            //set ADSC to start Conversion

  while(ADCSRA & (1<<ADSC));       // wait for conv. to complete
  unsigned int temp=ADC;  
  return temp;                    //return the int conversion of analog value
}
