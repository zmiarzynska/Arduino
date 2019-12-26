
int i=0;
int licznik=1;


void setup() {
  pinMode(40, OUTPUT); 
  
  Serial.begin(9600);
}


void loop() {

 
  
  int odczytanaWartosc = analogRead(0);//Odczytujemy wartość napięcia
  float napiecie=odczytanaWartosc*(5.0/1024.0);
  Serial.println(napiecie);//Wysyłamy ją do terminala
  delay(200);
  
 
  
  
   
   


}

