/*
 * method_point.c
 *
 *  Created on: Oct 14, 2019
 *      Author: i
 */
#include <stdio.h>
#include "method_point.h"
int inc(int a) {
	return (++a);
}

int multi(int*a, int*b, int*c) {
	return (*c = *a * *b);
}

typedef int (FUNC1)(int);
typedef int (FUNC2)(int*, int*, int*);

void show(FUNC2 fun, int arg1, int*arg2) {
	FUNC1 *p = &inc;
	int temp = p(arg1);
	fun(&temp, &arg1, arg2);
	printf("%d\n ", *arg2);
}

