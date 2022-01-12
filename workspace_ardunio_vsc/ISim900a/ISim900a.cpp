#include <Arduino.h>
#include <gprs/Sim900a.h>
int8_t answer;
int onModulePin = 2;
char aux_str[50];
char ip_data[40] = "GET \\ \r\n";
void setup() {
  pinMode(onModulePin, OUTPUT);
  Serial.begin(115200);
  delay(5000);
  Serial.println("Starting...");
  power_on();
  prepare();
}
void prepare() {
  Serial.println("init sim900a...");
  sendATcommand("AT");
  Serial.println("init network...");
  sendATcommand("AT+CIPSHUT");
  delay(500);
  sendATcommand("AT+CIPMUX=0");
  delay(500);
  sendATcommand("AT+CGATT=1");
  delay(1000);
  sendATcommand("AT+CIFSR");
  delay(500);
  sendATcommand("AT+CSTT=\"www\",\"\",\"\"");
  delay(500);
  sendATcommand("AT+CIICR");
  Serial.println("network inited!");
}
void sendATcommand(char* ATcommand) {
  Serial.println(ATcommand);
  uint8_t x = 0, answer = 0;
  char response[100];
  memset(response, 0, 100);
  do {
    // if there are data in the UART input buffer, reads it and checks for the asnwer
    if (Serial.available() != 0) {
      response[x] = Serial.read();
      delay(2);
      x++;
      // check if the desired answer 1  is in the response of the module
      if (strstr(response, "OK") != NULL)
      {
        answer = 1;
      }
      delay(10);
    }
  } while (answer == 0);
}
void reconnect() {
  Serial.println("Openning TCP");
  while (sendATcommandTimeout("AT+CIPSTART=\"TCP\",\"42.96.142.145\",\"80\"",
                              "CONNECT OK", "CONNECT FAIL", 300) != 1);
}
void close_connect() {
  while (sendATcommandTimeout("AT+CIPCLOSE", "CLOSE OK", "ERROR", 1000) != 1);
}
void transform() {
  reconnect();
  sprintf(aux_str, "AT+CIPSEND=%d", strlen(ip_data));
  Serial.println(aux_str);
  if (sendATcommandTimeout(aux_str, ">", "ERROR", 100) != 1)
  {
    sendATcommandTimeout(ip_data, "SEND OK", "ERROR", 100);
  }
  close_connect();
}
void loop() {
  delay(1000);
  //transform();
  delay(10000);
}

void power_on() {
  delay(1000);
  Serial.println("power_on...");
  digitalWrite(onModulePin, HIGH);
  delay(1000);
  digitalWrite(onModulePin, LOW);
}

int8_t sendATcommandTimeout(char* ATcommand, char* expected_answer1,
                            char* expected_answer2, unsigned int timeout) {
  uint8_t x = 0,  answer = 0;
  char response[100];
  unsigned long previous;
  memset(response, 0, 100);    // Initialize the string
  delay(100);
  Serial.println(ATcommand);    // Send the AT command
  x = 0;
  previous = millis();
  // this loop waits for the answer
  do {
    // if there are data in the UART input buffer, reads it and checks for the asnwer
    if (Serial.available() != 0) {
      response[x] = Serial.read();
      delay(2);
      x++;
      // check if the desired answer 1  is in the response of the module
      if (strstr(response, expected_answer1) != NULL)
      {
        answer = 1;
      }
      // check if the desired answer 2 is in the response of the module
      else if (strstr(response, expected_answer2) != NULL)
      {
        answer = 2;
      }
    }
    delay(10);
  }
  // Waits for the asnwer with time out
  while ((answer == 0) && ((millis() - previous) < timeout));
  return answer;
}
