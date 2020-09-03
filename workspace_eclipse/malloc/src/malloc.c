/*
 ============================================================================
 Name        : malloc.c
 Author      : icesx
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int*p = (int*) malloc(sizeof(int) * 100);
	int i=0;
	for (; i<=100;i++) {
		printf("index=%d,%d\n",i, p[i]);
	}
	free(p);
	return EXIT_SUCCESS;
}
