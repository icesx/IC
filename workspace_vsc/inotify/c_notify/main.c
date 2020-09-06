/*
 * main.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: i
 */
#include <stdio.h>
#include <stdlib.h>

#include "notify.h"
void callback(int fd, const struct inotify_event *event, char *watched_dir) {
	if (event->mask & IN_ISDIR) {
		printf("[directory]\t");
	} else {
		printf("[file]\t");
	}
	if (event->mask & IN_OPEN)
		printf("IN_OPEN: ");
	if (event->mask & IN_CLOSE_NOWRITE)
		printf("IN_CLOSE_NOWRITE: ");
	if (event->mask & IN_CLOSE_WRITE)
		printf("IN_CLOSE_WRITE: ");
	if (event->mask & IN_CREATE)
		printf("IN_CREATE: ");
	if (event->mask & IN_DELETE)
		printf("IN_DELETE: ");
	/* Print the name of the watched directory */
	printf("watched_dir:%s ,wd is %d ", watched_dir, event->wd);
	/* Print the name of the file */
	if (event->len)
		printf(" name:%s", event->name);
	/* Print type of filesystem object */
	printf("\n");
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s PATH [PATH ...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++) {
		notify_dir(argv[i], callback);
	}
	exit(EXIT_SUCCESS);
}

