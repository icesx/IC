/*
 * main.c
 *
 *  Created on: Oct 29, 2019
 *      Author: i
 */
#include <stdio.h>
#include <stdlib.h>
int param_stack() {
	int x = 1000;
	return x;
}
int* param_stack2() {
	int i[] = { 1, 2, 3, 4, 5 };
	return i;
}
int main() {
	printf("hello world!\n");
	printf("param on stack %d\n", param_stack());
	int *p = param_stack2();
	for (int i = 0; i < 5; i++) {
		printf("param on stack point %d\n",*p++ );
	}
}

