/*
 * string.c
 *
 *  Created on: Feb 10, 2018
 *      Author: i
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
void print(char* b) {
	int i = 0;
	for (i = 0;; i++) {
		if (b[i] == '\0') {
			printf("%d", i);
			break;
		}
		printf("%c", b[i]);
	}
}
char* append(char* first, char*second) {
	int len = strlen(second) + strlen(first);
	char* command = (char*) malloc(len + 1);
	memcpy(command, first, strlen(first));
	memcpy(command + strlen(first), second, strlen(second));
	return command;
}
void string_test() {
	char *c = append("AT+CIPSTART=\"TCP\"", "www.baidu.com");
	printf("%s", "xxx\n" + 23);
	printf("%s\n", c);
}

