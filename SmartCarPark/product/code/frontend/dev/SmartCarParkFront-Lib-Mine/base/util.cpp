/*
 * util.c
 *
 *  Created on: 2015年9月2日
 *      Author: i
 */

#include "util.h"
#include <Arduino.h>
// BASE C
char* charAppendChar(char* first, char*second) {
	int len = strlen(second) + strlen(first);
	char* command = new char[len + 1];
	memset(command, 0, len + 1);
	memcpy(command, first, strlen(first));
	memcpy(command + strlen(first), second, strlen(second));
	return command;
}
String strAppendChar(String f, char*s) {
	return f + s;
}
String strAppendStr(String f, String s) {
	return f + s;
}
String strAppendInt(String f, int s) {
	return f + s;
}
void convertStrToHex(char * buf, byte* str, int len) {
	int i;
	for (i = 0; i < len; i++) {
		sprintf(buf, "%02X", str[i]);
		buf += 2;
	};
}
void intToString(int n, char* buf) {
	sprintf(buf, "%d", n);
}
void strToChar(String s, char* buf) {
	s.toCharArray(buf, s.length() + 1);
}
