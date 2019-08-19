/*
 ============================================================================
 Name        : strcmp.c
 Author      : icesx
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	const char *output_type;
	output_type = argv[1];
	if (!strcmp(output_type, "h264")) {
		printf("%s is h264", output_type);
	} else {
		printf("%s is not h264", output_type);
	}
	return EXIT_SUCCESS;
}
