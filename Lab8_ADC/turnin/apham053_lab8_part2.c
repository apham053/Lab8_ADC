/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #2
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
	DDRD = 0xFF;
	PORTA = 0xFF;
	PORTB = 0x00;
	PORTD = 0x00;
	ADC_init();
	
    while (1) {
		unsigned short X = ADC; // value of ADC register now stored in X
		unsigned char B = (char)X; // sets B to the rightmost 8 bits of ADC
		unsigned char D = (char)(X >> 8); //sets D to leftmost 2 bits of ADC (after bitshifting right 8)
		PORTB = B;
		PORTD = D;
    }
    return 1;
}
