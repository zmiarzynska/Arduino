 
 int przeslanyBajt=0;
 
 
 void setup(){
 
   Serial.begin(9600);
 }
 
 
 void loop(){
 
 
   if(Serial.available()>0){
   
       przeslanyBajt = Serial.parseInt();
       
       
       Serial.print("Otrzymano: ");
       
       Serial.println(przeslanyBajt,DEC);
   
   }
 
 }
