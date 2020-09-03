/*
 ============================================================================
 Name        : HelloWorld.c
 Author      : icesx
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include  "I/file_util.h"

static char* HOME_I_TMP_TEST_TXT = "/home/i/tmp/test.txt";
static char* HOME_I_TMP_TEST_TXT_2 = "/home/i/tmp/test2.txt";
int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	readFilePrint(HOME_I_TMP_TEST_TXT);
	char *array;
	array = readFile(HOME_I_TMP_TEST_TXT);
	printf("readFile by point:%s", array);
	free(array);
	char *fileCode2[10000];
	readFile4Array(HOME_I_TMP_TEST_TXT, fileCode2);
	printf("readFile for Array:%s", *fileCode2);
	free(*fileCode2);
	char *array2;
	array2 = readFileBytes(HOME_I_TMP_TEST_TXT);
	printf("readFile by readFileBytes:%s", array2);
	free(array2);
	wrieteFile(HOME_I_TMP_TEST_TXT_2, "wrieteFile");
	return 1;
}
