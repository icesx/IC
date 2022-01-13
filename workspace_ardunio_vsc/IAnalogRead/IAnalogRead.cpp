#include <Arduino.h>
void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  Serial.println(analogRead(5), DEC);
  delay(500);
}
