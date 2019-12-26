// 1 kabelek, przy termometrze DG (srodkowy), do pid nr 1 (lewo gora)
//2 kabelek od 8-wejsciowego segmentu nad po skosie nad termometrem - nr 7 do pin nr 2.
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 1
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
boolean czyWieksza=false;
double temperatura =28.0;
double czytanaTemperatura=0.0; 
void setup()
  {
    Serial.begin(9600);
    sensors.begin();
    pinMode(2, OUTPUT);
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
    
    if(czyWieksza) digitalWrite(2,LOW);
    else digitalWrite(2,HIGH);
    delay(200);
  }
