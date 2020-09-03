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
void strcmp_test() {
	const char *output_type = "h264";
	if (!strcmp(output_type, "h264")) {
		printf("%s is h264", output_type);
	} else {
		printf("%s is not h264", output_type);
	}
}

int str_equlse(const char *one, const char *two) {
	if (!strcmp(one, two)) {
		return 1;
	} else {
		return 0;
	}
}
char* str_append(const char *first, const char *second) {
	int len = strlen(second) + strlen(first);
	char *command = (char*) malloc(len + 1);
	memcpy(command, first, strlen(first));
	memcpy(command + strlen(first), second, strlen(second));
	return command;
}


