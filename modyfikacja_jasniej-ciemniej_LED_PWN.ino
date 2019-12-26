 #include <avr/io.h>

 int przeslanyBajt =254;
 int val = 254; // 0-255
 
 void setup(){
 
   Serial.begin(9600);
   
    TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
    DDRB|=(1<<PB3);
    OCR0=val;    
 }
 
 
 void loop(){
 
 
   if(Serial.available()>0){
   
       przeslanyBajt = Serial.parseInt();
       int kopiaBajta = przeslanyBajt;
       while(kopiaBajta){
       OCR0++;
       kopiaBajta--;
        }
       
       Serial.print("Otrzymano: ");
       
       Serial.println(przeslanyBajt,DEC);
       OCR0=przeslanyBajt;
       
       while(przeslanyBajt){
       OCR0--;
       przeslanyBajt--;
       }
       
       //delay(200);
     }
 
 }
