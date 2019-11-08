/*
 * string.c
 *
 *  Created on: Feb 10, 2018
 *      Author: i
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "istring.h"
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

