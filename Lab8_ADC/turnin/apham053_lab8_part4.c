/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
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
		unsigned short threshold = 0x00;
		
		if (X >= MAX) {
			MAX = X;
		}
		
		threshold = MAX / 8;
		
		if (X == 0) {
			light = 0x00;
		}
		else if (X <= (threshold)) {
			light = 0x01;
		} 
		else if (X <= (threshold * 2)) {
			light = 0x03;
		} 
		else if (X <= (threshold * 3)) {
			light = 0x07;
		} 
		else if (X <= (threshold * 4)) {
			light = 0x0F;
		} 
		else if (X <= (threshold * 5)) {
			light = 0x1F;
		} 
		else if (X <= (threshold * 6)) {
			light = 0x3F;
		} 
		else if (X <= (threshold * 7)) {
			light = 0x7F;
		} 
		else if (X <= (threshold * 8)) {
			light = 0xFF;
		} 
		
		PORTB = light;
			
    }
    return 1;
}
