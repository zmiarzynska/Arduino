//counter to 9999 (by clicking button, you add 1)

#define SEG_A 0
#define SEG_B 1
#define SEG_C 2
#define SEG_D 3
#define SEG_E 4
#define SEG_F 5
#define SEG_G 6
#define SEG_dp 7

#define dodaj 20
#define cyf1 19
#define cyf2 18
#define cyf3 17
#define cyf4 16


int i = 0;
int tab[10];
int jednosci;
int dziesiatki;
int setki;
int tysiace;

void setup(){
 Serial.begin(9600);
 pinMode(SEG_A, OUTPUT);
 pinMode(SEG_B, OUTPUT);
 pinMode(SEG_C, OUTPUT);
 pinMode(SEG_D, OUTPUT);
 pinMode(SEG_E, OUTPUT);
 pinMode(SEG_F, OUTPUT);
 pinMode(SEG_G, OUTPUT);
 pinMode(SEG_dp, OUTPUT);
 
 pinMode(dodaj, INPUT_PULLUP);
 pinMode(cyf1, OUTPUT);
 pinMode(cyf2, OUTPUT);
 pinMode(cyf3, OUTPUT);
 pinMode(cyf4, OUTPUT);
 
 digitalWrite(cyf1,LOW);
 tab[0]=255-(1<<SEG_A)-(1<<SEG_B)-(1<<SEG_C)-(1<<SEG_D)-(1<<SEG_E)- (1<<SEG_F);
 tab[1]=255-(1<<SEG_B)-(1<<SEG_C);
 tab[2]=255-(1<<SEG_A)-(1<<SEG_B)-(1<<SEG_G)-(1<<SEG_E)-(1<<SEG_D);
 tab[3]=255-(1<<SEG_A)-(1<<SEG_B)-(1<<SEG_C)-(1<<SEG_D)-(1<<SEG_G);
 tab[4]=255-(1<<SEG_B)-(1<<SEG_C)-(1<<SEG_F)-(1<<SEG_G);
 tab[5]=255-(1<<SEG_A)-(1<<SEG_F)-(1<<SEG_C)-(1<<SEG_D)-(1<<SEG_G);
 tab[6]=255-(1<<SEG_A)-(1<<SEG_F)-(1<<SEG_C)-(1<<SEG_D)-(1<<SEG_E)-(1<<SEG_G);
 tab[7]=255-(1<<SEG_B)-(1<<SEG_C)-(1<<SEG_A);
 tab[8]=255-(1<<SEG_A)-(1<<SEG_B)-(1<<SEG_C)-(1<<SEG_D)-(1<<SEG_E)- (1<<SEG_F)-(1<<SEG_G);
 tab[9]=255-(1<<SEG_A)-(1<<SEG_B)-(1<<SEG_C)-(1<<SEG_D)- (1<<SEG_F)-(1<<SEG_G);
   
    digitalWrite(cyf1,HIGH);
    digitalWrite(cyf2,HIGH);
    digitalWrite(cyf3,HIGH);
    digitalWrite(cyf4,HIGH);
}
void loop(){
 
 
  if(digitalRead(dodaj)==LOW){
    i++;
   Serial.println(i);
  delay(200);
  jednosci = i%10;
//  i=i/10;
  dziesiatki = (i/10)%10;
//  i=i/10;
  setki = (i/100)%10;
//  i=i/10;
  tysiace = (i/1000)%10;
  }
 digitalWrite(cyf1,LOW);
 PORTB=tab[jednosci];
 delay(2);
 digitalWrite(cyf1,HIGH);
 
 digitalWrite(cyf2,LOW);
 PORTB=tab[dziesiatki];
 delay(2);
 digitalWrite(cyf2,HIGH);
 
  digitalWrite(cyf3,LOW);
 PORTB=tab[setki];
 delay(2);
 digitalWrite(cyf3,HIGH);
 
  digitalWrite(cyf4,LOW);
 PORTB=tab[tysiace];
 delay(2);
 digitalWrite(cyf4,HIGH);
 

 }
