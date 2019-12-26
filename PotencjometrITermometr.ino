#include <LiquidCrystal.h>
#include <OneWire.h>

const int rs=12,enable=11,dc4=5,dc5=4,dc6=3,dc7=2;
const int width = 16, height = 2;
//const int ds = 10;

LiquidCrystal lcd(rs,enable,dc4,dc5,dc6,dc7);
OneWire ds(10);

int givenValueV = 0;
int16_t givenValueT = 0;
float voltage = 0;
float temp = 0;
int index = 0;

void setup(){
    lcd.begin(width,height);
    Serial.begin(9600);
}

void show(int i){
    lcd.clear();
    lcd.print("Voltage: ");
    lcd.print(voltage);
    lcd.print("V");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" Cdeg");
    Serial.print(i);
    Serial.print(",");
    Serial.print(voltage);
    Serial.print(",");
    //Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(";\n"); 
}

void getVoltage(){
   givenValueV = analogRead(PA0);
   voltage = givenValueV*(5.0/1023.0);
}

void getTemperature(){
  byte i;
  byte type_s;
  byte data[12];
  byte addr[8];
  
  if ( !ds.search(addr)) {
    ds.reset_search();
    delay(250);
    return;
  }
  

  if (OneWire::crc8(addr, 7) != addr[7]) {
      //Serial.println("CRC is not valid!");
      return;
  }
  //Serial.println();
 
  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
      //Serial.println("  Chip = DS18S20");  // or old DS1820
      type_s = 1;
      break;
    case 0x28:
      //Serial.println("  Chip = DS18B20");
      type_s = 0;
      break;
    case 0x22:
      //Serial.println("  Chip = DS1822");
      type_s = 0;
      break;
    default:
      //Serial.println("Device is not a DS18x20 family device.");
      return;
  } 

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
  }

  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  temp = (float)raw / 16.0;
}

void loop(){
    getVoltage();
    getTemperature();
    show(++index);
    delay(1000);
}
