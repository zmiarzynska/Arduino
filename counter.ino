// licznik do 9999
// counter to 9999, click button to add 1, hold to add more

#define segA 0
#define segB 1 
#define segC 2
#define segD 3
#define segE 4
#define segF 5
#define segG 6
#define segdp 7


#define cyfra1 3
#define cyfra2 2
#define cyfra3 1
#define cyfra4 0
#define button 8
int i=0;
int licznik=1;
int tab[10];
  int jednosci,setek,dzies,tys;
void setup() {

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); 
  DDRC=255;

  // odpowiedzialne za przycisk
  pinMode(8, INPUT_PULLUP);
  tab[0]=255-(1<<segA)-(1<<segB)-(1<<segC)-(1<<segD)-(1<<segE)-(1<<segF);
  tab[1]=255-(1<<segC)-(1<<segB);
  tab[2]=255-(1<<segA)-(1<<segB)-(1<<segD)-(1<<segG)-(1<<segE);
  tab[3]=255-(1<<segA)-(1<<segB)-(1<<segC)-(1<<segD)-(1<<segG);
  tab[4]=255-(1<<segF)-(1<<segB)-(1<<segC)-(1<<segG);
  tab[5]=255-(1<<segA)-(1<<segC)-(1<<segD)-(1<<segG)-(1<<segF);
  tab[6]=255-(1<<segA)-(1<<segC)-(1<<segD)-(1<<segG)-(1<<segF)-(1<<segE);
  tab[7]=255-(1<<segC)-(1<<segB)-(1<<segA);
  tab[8]=255-(1<<segA)-(1<<segB)-(1<<segC)-(1<<segD)-(1<<segE)-(1<<segF)-(1<<segG);
  tab[9]=255-(1<<segA)-(1<<segC)-(1<<segD)-(1<<segG)-(1<<segF)-(1<<segB);

  digitalWrite(cyfra1,HIGH);
  digitalWrite(cyfra2,HIGH);
  digitalWrite(cyfra3,HIGH);
  digitalWrite(cyfra4,HIGH);
  Serial.begin(9600);
}


void loop() {

  
  if(digitalRead(button)==LOW){
    i++;
    delay(200);  
    jednosci=i%10;
    dzies=(i/10)%10;
    setek=(i/100)%10;
    tys=(i/1000)%10;
      Serial.println(i);

  }
  
  digitalWrite(cyfra1,LOW);   
  PORTC = tab[jednosci];
  delay(2);  
  digitalWrite(cyfra1,HIGH); 
  
 if(i>9){
  digitalWrite(cyfra2,LOW);   
  PORTC = tab[dzies];
  delay(2);  
  digitalWrite(cyfra2,HIGH); 
}
 else{
 digitalWrite(cyfra2,HIGH); }
 
  
   
  if(i>99){
  digitalWrite(cyfra3,LOW);   
  PORTC = tab[setek];
  delay(2);  
  digitalWrite(cyfra3,HIGH);   
  }
  else   digitalWrite(cyfra3,HIGH); 
    if(i>999){  
  digitalWrite(cyfra4,LOW);   
  PORTC = tab[tys];
  delay(2);  
  digitalWrite(cyfra4,HIGH);   
    }
    else digitalWrite(cyfra4,HIGH); 


}

