/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
	DDRA = 0x00;
	DDRB = 0xFF;
	PORTA = 0xFF;
	PORTB = 0x00;
	ADC_init();
	
    while (1) {
		unsigned short X = ADC; // value of ADC register now stored in X
		unsigned short MAX = 0x00;
		unsigned char light = 0x00;
		
		if (X >= MAX) {
			MAX = X;
		}
		
		if (X >= (MAX / 2)) {
			light = 0x01;
		}
		else { 
			light = 0x00;
		}
		
		PORTB = light;
			
    }
    return 1;
}
