/*
 * main.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: i
 */
#include <errno.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>
#include "notify.h"
/* Read all available inotify events from the file descriptor 'fd'.
 wd is the table of watch descriptors for the directories in argv.
 argc is the length of wd and argv.
 argv is the list of watched directories.
 Entry 0 of wd and argv is unused. */

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

