/*
 * main.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: i
 */
#include <stdio.h>
#include <stdlib.h>
#include "notify.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s PATH [PATH ...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++) {
		notify_dir(argv[i]);
	}
	exit(EXIT_SUCCESS);
}

