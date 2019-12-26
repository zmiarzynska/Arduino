/*
   zczytuje z pinu A0 napiecie (kabelek z a0 do potencjometru )
   The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  Serial.begin(9600); // do menedzera
  // Print a message to the LCD.
    lcd.print("Liczba voltow to: " );
}

void loop() {

  lcd.setCursor(0, 1);
   int odczytanaWartosc = analogRead(0);//Odczytujemy wartość napięcia
  float napiecie=odczytanaWartosc*(5.0/1024.0);
  Serial.println(napiecie);//Wysyłamy ją do terminala

  lcd.print(napiecie);
  delay(200);
}

