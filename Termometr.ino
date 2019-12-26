#include <OneWire.h>
#include <LiquidCrystal.h>

const int rs=12,enable=11,dc4=5,dc5=4,dc6=3,dc7=2;
const int width = 16, height = 2;
const int oneWirePin = 10;
LiquidCrystal lcd(rs,enable,dc4,dc5,dc6,dc7);
OneWire tempWire(oneWirePin);

int givenValue = 0;
float tempe = 0;

void setup(){
    lcd.begin(width,height);
    Serial.begin(9600);
}

void loop(){
    givenValue = analogRead(PA0);
    voltage = givenValue*(5.0/1023.0);
    lcd.clear();
    lcd.print("Temperature: ");
    lcd.print(temp);
    lcd.print(" C deg.");
    delay(1000);
}
