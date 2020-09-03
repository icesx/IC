/*
 ============================================================================
 Name        : point.c
 Author      : icesx
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int * temp;
int * temp2;
int * chars() {
	int x = 100;
	temp = &x;
	return temp;
}
int * chars_malloc() {
	int*p = (int*) malloc(sizeof(int) * 100);
	*p = 1000;
	temp2 = p;
	return p;
}
int main(void) {
	int * p = chars();
	printf("the point value is%d\n", *p);
	*temp = 101;
	printf("the point value is%d\n", *p);
	int * p2 = chars_malloc();
	printf("the point mallco is%d\n", *p2);
	*temp2=1001;
	printf("the point mallco is%d\n", *p2);
	return EXIT_SUCCESS;
}
