#include <DueTimer.h>
int t=0;
int d =0;
int s=0;
bool f =0;

#define RELAY1 5 //Defining the pin 5 of the Arduino for the 8 relay module
#define RELAY2 6 //Defining the pin 6 of the Arduino for the 8 relay module
#define RELAY3 7 //Defining the pin 7 of the Arduino for the 8 relay module
#define RELAY4 8 //Defining the pin 8 of the Arduino for the 8 relay module
#define RELAY5 9 //Defining the pin 9 of the Arduino for the 8 relay module
#define RELAY6 10 //Defining the pin 10 of the Arduino for the 8 relay module
#define RELAY7 11 //Defining the pin 11 of the Arduino for the 8 relay module
#define RELAY8 12 //Defining the pin 12 of the Arduino for the 8 relay module

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT_PULLUP);

  pinMode(RELAY1, OUTPUT); 
  pinMode(RELAY2, OUTPUT); 
  pinMode(RELAY3, OUTPUT); 
  pinMode(RELAY4, OUTPUT); 
  pinMode(RELAY5, OUTPUT); 
  pinMode(RELAY6, OUTPUT); 
  pinMode(RELAY7, OUTPUT); 
  pinMode(RELAY8, OUTPUT); 

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  digitalWrite(RELAY5, HIGH);
  digitalWrite(RELAY6, HIGH);
  digitalWrite(RELAY7, HIGH);
  digitalWrite(RELAY8, HIGH);

  attachInterrupt(3,counting,FALLING);
  Timer3.attachInterrupt(Speed);
  Timer3.start(1000);
  Serial.flush();
}

void counting(){
  if ((t<2000)&&(t>300)){
    d=t;
  }
  else if (t<200){
  }
    t=0;
}
void Speed() {
  if (t<2010){
    t=t+1;
  }
  else{
    d=0;
  }
}
void loop() {

  s=(2*7500)/d; //1.95/time
  Serial.println(s);
  delay(100);

 if (s >= 30) {
 digitalWrite(RELAY1, LOW); // 50 watts Object
 }
 if (s >= 35) {
 digitalWrite(RELAY2, LOW); // 100 watts object
 }
 if (s >= 38) {
 digitalWrite(RELAY3, LOW); // 150 watts object
 }
 if (s >= 40) {
 digitalWrite(RELAY4, LOW); // 200 watts object
 }
 if (s >= 42) {
 digitalWrite(RELAY5, LOW); // 250 watts object
 }
 if (s >= 44) {
 digitalWrite(RELAY6, LOW); // 300 watts object
 }
 if (s >= 46) {
 digitalWrite(RELAY7, LOW); // 350 watts object
 }
 if (s >= 47) {
 digitalWrite(RELAY8, LOW); // 400 watts object
 }

 if (s <= 10) {
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  digitalWrite(RELAY5, HIGH);
  digitalWrite(RELAY6, HIGH);
  digitalWrite(RELAY7, HIGH);
  digitalWrite(RELAY8, HIGH);
 }
 delay(100);
}

