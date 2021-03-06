/*
 * IdCardTransformer.cpp
 *
 *  Created on: 2015年8月12日
 *      Author: i
 */

#include <Arduino.h>

struct Commands {
  byte heartbit[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x11, 0xFF,
                        0xED
                      };
  byte heartbit2[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x20, 0x01,
                         0x22
                       };
  byte readCard[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x20, 0x02,
                        0x21
                      };
  byte readCard2[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x30, 0x01,
                         0x32
                       };
};
struct Result {
  int carTouchLength = 15;
  int carReadyLength = 19;
};
Commands commands;
Result result;
byte readed[64];
byte carInfo[1024];
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("serial begin at 115200");
  delay(1000);
  Serial1.begin(115200);
  Serial.println("softwareSerial begin at 115200");
  Serial.println("setup ok!");
}
void runCommand(byte* command, int len) {
  Serial1.write(command, len);
  Serial.print("run command:");
  for (int i = 0; i < len; i++) {
    Serial.print(" 0x");
    Serial.print(command[i], HEX);
  }
  Serial.println('\0');
}
byte* carRead() {
  Serial.println("carRead");
  runCommand(commands.readCard2, sizeof(commands.readCard2));
  memset(carInfo, 0, sizeof(carInfo));
  int i = 0;
  long curren = millis();
  do {
    byte b = Serial1.read();
    carInfo[i] = b;
    i++;
  } while ( 5000 > (millis() - curren));
  return carInfo;
}
int readSerial() {
  while (Serial1.available() == 0) {
    Serial.print('w');
    delay(5);
  }
  Serial.println('\0');
  memset(readed, 0, sizeof(readed));
  int size = Serial1.available();
  Serial.print("to read avaliable is ");
  Serial.println(size);
  int i = 0;
  while (Serial1.available()) {
    byte b = Serial1.read();
    readed[i] = b;
    Serial.print(" 0x");
    Serial.print(b, HEX);
  }
  Serial.println('\0');
  return size;
}
void readPrepary() {
  Serial.println("readPrepary");
  runCommand(commands.readCard, sizeof(commands.readCard));
  delay(10);
  int length = readSerial();
  if (length == result.carReadyLength) {
    Serial.println("car is ready to read");
    carRead();
  }
  Serial.println('\0');
  for (int i = 0; i < sizeof(carInfo); i++) {
    Serial.print(' ');
    Serial.print(carInfo[i], HEX);
  }
  Serial.println('\0');
}

void readHeartbit() {
  Serial.println("readHeartbit2");
  int length = readSerial();
  Serial.println();
  if (length == result.carTouchLength) {
    Serial.println("car touched so try to readCard");
    readPrepary();
  }
}
void heartbit() {
  Serial.println("heartbit");
  runCommand(commands.heartbit, sizeof(commands.heartbit));
  Serial.println("read hearbit");
  readSerial();
  delay(10);
  Serial.println("heartbit2");
  runCommand(commands.heartbit2, sizeof(commands.heartbit2));
  readHeartbit();
}
void loop() {
  Serial.println("loop start!");
  heartbit();
  delay(500);
}


