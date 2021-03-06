#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
char* defaultOk = "OK";
//\x1A=ctrl+z
char ip_data[40] = "GET / \r\n \x1A";
char response[100];
long previous;
uint8_t onModulePin = 4;
void setup()
{
  pownon();
  Serial.begin(115200);
  Serial.println("Calling through GSM Modem");
  mySerial.begin(9600);
  delay(2000);
  prepare();
}
void pownon() {
  pinMode(onModulePin, OUTPUT);
  digitalWrite(onModulePin, LOW);
  delay(1000);
  digitalWrite(onModulePin, HIGH);
  delay(2000);
  digitalWrite(onModulePin, LOW);
  delay(3000);
}
void prepare() {
  Serial.println("init sim900a...");
  sendATcommandTimeout("AT", defaultOk, 5000, true);
  delay(2000);
  sendATcommandTimeout("AT+CIPSHUT", defaultOk, 15000, true);
  delay(2000);
  sendATcommandTimeout("AT+CIPMUX=0", defaultOk, 15000, true);
  delay(2000);
  sendATcommandTimeout("AT+CGATT=1", defaultOk, 15000, true);
  delay(3000);
  sendATcommandTimeout("AT+CSTT=\"www.scp\",\"\",\"\"", defaultOk, 15000, true);
  delay(2000);
  sendATcommandTimeout("AT+CIPSPRT=1", defaultOk, 15000, true);
  delay(2000);
  sendATcommandTimeout("AT+CIICR", defaultOk, 15000, true);
  delay(2000);
  sendATcommandTimeout("AT+CIFSR", ".", 15000, true);
  Serial.println("network inited!");
}
char* readFromMySerial() {
  memset(response, 0, 100);
  uint8_t x = 0;
  while (mySerial.available() != 0) {
    response[x] = mySerial.read();
    delay(2);
    x++;
  } ;
  return response;
}
void runCommand(char* ATcommand) {
  mySerial.println(ATcommand);
  Serial.print("try:");
  Serial.print(ATcommand);
  Serial.print("\r\n");
}
void sendATcommandTimeout(char* ATcommand, char* okFlag, unsigned int timeout, boolean retry) {
  runCommand(ATcommand);
  boolean isOk = readFromSerial(timeout, okFlag);
  Serial.print("\r\n");
  if (isOk)
  {
    return;
  } else {
    if (retry == true) {
      delay(2000); 
      Serial.print("retrytimeout:");
      Serial.println(ATcommand);
      sendATcommandTimeout(ATcommand, okFlag, timeout, retry);
    }
  }
  Serial.print("\r\n");
}
void reconnect() {
  sendATcommandTimeout("AT+CIPSTART=\"TCP\",\"42.96.142.145\",\"80\"",
                       "CONNECT OK", 15000, true);
}
void close_connect() {
  sendATcommandTimeout("AT+CIPCLOSE", "CLOSE OK", 15000, false);
}
void transform() {
  reconnect();
  sendATcommandTimeout("AT+CIPSEND", ">", 15000, false);
  sendATcommandTimeout(ip_data, "SEND OK", 15000, false);
  readFromSerial(15000, "scp");
  Serial.print("\r\n");
  close_connect();
}
boolean readFromSerial(int timeout, char* okFlag) {
  memset(response, 0, 100);
  uint8_t x = 0;
  boolean isOk = false;
  previous = millis();
  do {
    if (mySerial.available() != 0) {
      response[x] = mySerial.read();
      Serial.print(response[x]);
      delay(2);
      x++;
    }
    if (strstr(response, okFlag) != NULL)
    {
      isOk = true;
      break;
    }
  } while ((millis() - previous) < timeout);
  return isOk;
}
void loop()
{
  delay(10000);
  transform();
}
