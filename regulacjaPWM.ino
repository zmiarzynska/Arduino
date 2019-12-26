// w programie za pomoca sterowania wartoscia val, reguluje jasnosc diody led. 254 - prawie nie swieci


#include <avr/io.h>

//#define PWM_A (1<<PB1)

int przeslanyBajt =0;
int val = 254; // 0-255

void setup(){

    Serial.begin(9600);


    TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
    DDRB|=(1<<PB3);
    OCR0=val;    
}

void loop(){


    OCR0=val;

}
