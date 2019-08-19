/*
 * file_util.c
 *
 *  Created on: 2012-4-28
 *      Author: icesx
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_util.h"

static const char* W = "at";

void readFilePrint(char *file) {
	char ch;
	FILE *fp;
	if ((fp = fopen(file, "r")) == NULL ) /* 打开一个由argv[1]所指的文件*/
	{
		printf("file %s is not exits \r\n", file);
		exit(0);
	}
	while ((ch = fgetc(fp)) != EOF) /* 从文件读一字符，显示到屏幕*/
		putchar(ch);
	fclose(fp);
}

#define MAXLINE 100000
#define BUFLEN 1024
char * readFile(char * file) {
	FILE *_file;
	char buf[BUFLEN];
	int len = 0, i = 0;
	static char *array[MAXLINE];

	_file = fopen(file, "r");
	if (!file) {
		printf("file %s is not exits \r\n", file);
		exit(0);
	}
	while (fgets(buf, BUFLEN, _file)) {
		len = strlen(buf);
		array[i] = (char*) malloc(len + 1);
		if (!array[i])
			break;
		strcpy(array[i++], buf);
	}

	fclose(_file);
	return *array;
}
void readFile4Array(char *file, char *array[]) {
	FILE *_file;
	char buf[BUFLEN];
	int len = 0, i = 0;
	_file = fopen(file, "r");
	if (!file) {
		printf("file %s is not exits \r\n", file);
		exit(0);
	}
	while (fgets(buf, BUFLEN, _file)) {
		len = strlen(buf);
		array[i] = (char*) malloc(len + 1);
		if (!array[i])
			break;
		strcpy(array[i++], buf);
	}

	fclose(_file);
}

char* readFileBytes(char * name) {
	FILE *fl = fopen(name, "r");
	fseek(fl, 0, SEEK_END);
	long len = ftell(fl);
	char *ret = malloc(len);
	fseek(fl, 0, SEEK_SET);
	fread(ret, 1, len, fl);
	fclose(fl);
	return ret;
}
void wrieteFile(char *file, char *fileCode) {
	FILE *fp;
	fp = fopen(file, W);
	if (fp == NULL ) {
		printf("file %s is not exits \r\n", file);
		exit(0);
	}
	fprintf(fp, "%s", fileCode);
	fclose(fp);
}
