/*	Author: kgarc044
 *  Partner(s) Name: kyle
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


void ADC_init(){

    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);

}


unsigned short ReadADC(unsigned char ch){

    ch = ch & 0x07;

    ADMUX = (ADMUX & 0xF8) | ch;

    

    ADCSRA |= (1<<ADSC);


    while(!(ADCSRA & (1<<ADIF)));

    

    //        ADCSRA |= (1<<ADIF);

    

    return(ADC);

}



unsigned char _left = 0;

unsigned char _right = 0;

unsigned char _up = 0;

unsigned char _down = 0;

unsigned char led = 0x00;


//#define x ReadADC(0)

//#define y ReadADC(1)

unsigned short x;

unsigned short y;


void js(){

    x = ReadADC(0);

    y = ReadADC(1);

    if(x > 900){

        led = 0x08;

        _left = 1; //left

    }

    else if(x < 300){

        led = 0x04; //right

        _right = 1;

    }

    else if(y < 300){

        led = 0x02; //up

        _up = 1;

    }

    else if(y > 900 ){

        led = 0x01; //down

        _down = 1;

    }

    else{

        led = 0x00;

        _left = 0;

        _right = 0;

        _down = 0;

        _up = 0;

    }

}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    ADC_init();
    while (1) {
        js();
	PORTB = led;
    }
}
