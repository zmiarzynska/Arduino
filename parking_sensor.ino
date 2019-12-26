#define trigPin 15  // podlaczony echo do d3 i trid do d4
#define echoPin 14
#define ledpin0 4
#define ledpin1 5
#define ledpin2 6
#define ledpin3 7
#define ledpin4 10
#define ledpin5 11
#define ledpin6 12
#define ledpin7 13
#define trigPin2 16 // podlaczony echo do
#define echoPin2 17

  const int p1 = 0;
  const int p2 = 1;     // the number of the pushbutton pin
  const int p3 = 2;
  const int p4 = 3;
 double pamietanaWartosc=9999;
  double pamietanaWartosc2=9999;
 boolean pomiar=true;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);
  pinMode(p3, INPUT_PULLUP);
  pinMode(p4, INPUT_PULLUP);
  pinMode(ledpin0, OUTPUT);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
  pinMode(ledpin5, OUTPUT);
  pinMode(ledpin6, OUTPUT);
  pinMode(ledpin7, OUTPUT);
  digitalWrite(ledpin0, HIGH);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, HIGH);
  digitalWrite(ledpin6, HIGH);
  digitalWrite(ledpin7, HIGH);
    pinMode(trigPin2, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin2, INPUT);
 
}
 
void loop() {  

   if (digitalRead(p1) == LOW) {     
     pamietanaWartosc=9999;
     pamietanaWartosc2=9999;
      Serial.print("Pamietana wartosc 1 i 2: ");
     Serial.print(pamietanaWartosc);
     delay(2000);
  }
  if (digitalRead(p2) == LOW) {     
     pomiar=false;
  }
  if (digitalRead(p3) == LOW) {     
     pomiar=true;
  }
  if(pomiar){
   // pomiar
  Serial.print("D1= ");
 Serial.print(zmierzOdleglosc());
  Serial.print(" m");
 //2 pomiar 
 Serial.print("D2= ");
  Serial.print(zmierzOdleglosc2());
   Serial.println(" m");
  delay(500);
  //koniecpomiaru
  }
  if (digitalRead(p4) == LOW) {     
      Serial.print("Zapamietane wartosci: D1-MIN=");
     Serial.println(pamietanaWartosc);
     
     delay(2000);
  }
 
  
}

double zapamietajWartoscMin(double nowaWartosc){
  
  if(nowaWartosc<pamietanaWartosc) pamietanaWartosc=nowaWartosc;
   Serial.print("Zapamietalem: ");  // jaka jest minimalna wartosc
   Serial.println(pamietanaWartosc);

}
 
 double zapamietajWartoscMin2(double nowaWartosc){
  
  if(nowaWartosc<pamietanaWartosc2) pamietanaWartosc2=nowaWartosc;
   Serial.print("Zapamietalem: ");  // jaka jest minimalna wartosc
   Serial.println(pamietanaWartosc2);

}
 
double zmierzOdleglosc() {
   double czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
  dystans/=100;
  if(dystans<1)  digitalWrite(ledpin7, LOW);
  else digitalWrite(ledpin7, HIGH);
  if(dystans<0.7)  digitalWrite(ledpin6, LOW);
  else digitalWrite(ledpin6, HIGH);
   if(dystans<0.5)  digitalWrite(ledpin5, LOW);
  else digitalWrite(ledpin5, HIGH);
   if(dystans<0.3)  digitalWrite(ledpin4, LOW);
  else digitalWrite(ledpin4, HIGH);
  zapamietajWartoscMin(dystans);
  return dystans;
}

double zmierzOdleglosc2() {
double czas, dystans;
digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 
  czas = pulseIn(echoPin2, HIGH);
  dystans = czas / 58;
  dystans/=100;
  if(dystans<1)  digitalWrite(ledpin0, LOW);
  else digitalWrite(ledpin0, HIGH);
  if(dystans<0.7)  digitalWrite(ledpin1, LOW);
  else digitalWrite(ledpin1, HIGH);
   if(dystans<0.5)  digitalWrite(ledpin2, LOW);
  else digitalWrite(ledpin2, HIGH);
   if(dystans<0.3)  digitalWrite(ledpin3, LOW);
  else digitalWrite(ledpin3, HIGH);
  zapamietajWartoscMin2(dystans);
  return dystans;
}
