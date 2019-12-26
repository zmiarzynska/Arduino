/*int pwmPin = 2;      //digital pin 2
 int pwmVal   = 10;
 
 void setup()
 {
 pinMode(pwmPin, OUTPUT);   // sets the pin as output
 Serial.begin(9600);
 }
 
 void loop()
 {
 if (pwmVal != 255) {
 analogWrite(pwmPin, pwmVal);
 //pwmVal += 10;
 Serial.print(pwmVal);  // Print red value
 Serial.print("\n");    // Print a tab
 } else {
 Serial.print('at max high');  // Print red value
 Serial.print("\n");    // Print a tab
 }
 delay(1000);
 }*/



// 1 kabelek, przy termometrze DG (srodkowy), do pid nr 1 (lewo gora)
//2 kabelek od 8-wejsciowego segmentu nad po skosie nad termometrem - nr 7 do pin nr 2.
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 1
#define pinAnalog 3
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
boolean czyWieksza=false;
double temperatura =35.0;
double czytanaTemperatura=0.0; 
void setup()
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(pinAnalog, OUTPUT);
}
void loop()
{ 
  //pobranie wartosci z portu szerogowego
  if(Serial.available()>0){
    temperatura = Serial.parseInt();
    Serial.print("Temperatura = ");
    Serial.println(temperatura);
  }
  //
  sensors.requestTemperatures();
  czytanaTemperatura=sensors.getTempCByIndex(0);
  Serial.print(czytanaTemperatura); 
  Serial.println("C"); 

  if(czytanaTemperatura<=temperatura) czyWieksza = false;
  else czyWieksza = true;

  if(czyWieksza) analogWrite(pinAnalog,64);
  else analogWrite(pinAnalog,0);
  delay(200);
}

