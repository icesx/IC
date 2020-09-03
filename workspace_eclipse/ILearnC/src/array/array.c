/*
 * array.c
 *
 *  Created on: Feb 10, 2018
 *      Author: i
 */
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
int a[5] = { 3, 4, 5, 6, 7 };
int b[4] = { 11, 22, 33, 44 };
#define LENGTH(s) (sizeof(s) / sizeof(int))
void array_cp() {
	int c[9] = { 0 };
	int i = 0, j;
	for (; i < 5; i++)
		c[i] = a[i];
	j = i;
	for (j = 0; j < 4; j++, i++)
		c[i] = b[j];
	for (i = 0; i < LENGTH(c); i++) {
		printf("%i\n", c[i]);
	}
}

void array_cp_system() {
	int c[9] = { 0 };
	memcpy(c, a, LENGTH(a));
	int i = 0;
	for (i = 0; i < LENGTH(c); i++) {
		printf("%i\n", c[i]);
	}
}

