 #define RELAY1 7 //Defining the pin 7 of the Arduino for the 4 relay module
 #define RELAY2 6 //Defining the pin 6 of the Arduino for the 4 relay module

int fsrReading, fsrReading1;
int ref_value = 300;
void setup()
 {
 Serial.begin (9600);
 pinMode(RELAY1, OUTPUT); //Defining the pin 7 of the Arduino as output
 pinMode(RELAY2, OUTPUT); //Defining the pin 6 of the Arduino as output
 digitalWrite(RELAY1, HIGH);
 digitalWrite(RELAY2, HIGH);
 }

void loop()
 {
 fsrReading = analogRead(A0);
 fsrReading1 = analogRead(A1);
 Serial.print(" ");
 Serial.print(fsrReading);
 Serial.print("        ");
 Serial.print(fsrReading1);
 Serial.println();

 if (fsrReading > ref_value) {
 digitalWrite(RELAY1,HIGH); // This will Turn ON the relay 1
 digitalWrite(RELAY2,LOW); // This will Turn OFF the relay 2
 }
 if (fsrReading1 > ref_value) {
 digitalWrite(RELAY2, HIGH); // This will Turn ON the relay 2
 digitalWrite(RELAY1, LOW); // This will Turn OFF the relay 1
 }
 delay (500);
 }