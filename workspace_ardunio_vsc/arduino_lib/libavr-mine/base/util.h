/*
 * util.h
 *
 *  Created on: 2015年9月2日
 *      Author: i
 */

#ifndef UTIL_H_
#define UTIL_H_
#include<Arduino.h>

char* charAppendChar(char*first, char*sencond);
String strAppendChar(String f, char*s);
String strAppendStr(String f, String s);
String strAppendInt(String f, int s);
void convertStrToHex(char* buf, byte* src, int len);
void intToString(int n, char*buf);
void strToChar(String s, char*buf);
#endif /* UTIL_H_ */
