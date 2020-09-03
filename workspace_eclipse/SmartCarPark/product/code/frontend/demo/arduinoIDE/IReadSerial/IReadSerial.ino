/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
 int val = Serial.read();
  if (-1 != val) {
    Serial.println(val);
    if('H'==val){
       digitalWrite(13, HIGH);
       delay(1000);
       digitalWrite(13,LOW);
    }
  }
}



