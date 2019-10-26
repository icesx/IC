/*
 * notify.c
 *
 *  Created on: Oct 26, 2019
 *      Author: i
 */
#include <errno.h>
#include <unistd.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>

void handle_events(int fd, int wd, char *watched_dir) {
	/* Some systems cannot read integer variables if they are not
	 properly aligned. On other systems, incorrect alignment may
	 decrease performance. Hence, the buffer used for reading from
	 the inotify file descriptor should have the same alignment as
	 struct inotify_event. */
	printf("handle_events....\n");
	char buf[4096] __attribute__ ((aligned(__alignof__(struct inotify_event))));
	const struct inotify_event *event;
	ssize_t len;
	char *ptr;
	/* Loop while events can be read from inotify file descriptor. */
	for (;;) {
		/* Read some events. */
		len = read(fd, buf, sizeof buf);
		if (len == -1 && errno != EAGAIN) {
			perror("read");
			exit(EXIT_FAILURE);
		}
		/* If the nonblocking read() found no events to read, then
		 it returns -1 with errno set to EAGAIN. In that case,
		 we exit the loop. */

		if (len <= 0)
			break;
		/* Loop over all events in the buffer */

		for (ptr = buf; ptr < buf + len;
				ptr += sizeof(struct inotify_event) + event->len) {
			event = (const struct inotify_event*) ptr;
			/* Print event type */
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
			if (wd == event->wd) {
				printf("watched_dir:%s \n", watched_dir);
				break;
			}
			/* Print the name of the file */
			if (event->len)
				printf(" name:%s", event->name);
			/* Print type of filesystem object */
			if (event->mask & IN_ISDIR)
				printf(" [directory]\n");
			else
				printf(" [file]\n");
		}
	}
}
void notify_dir(char *dir) {
	/* Create the file descriptor for accessing the inotify API */
	printf("notify on %s.\n", dir);
	int fd = inotify_init1(IN_NONBLOCK);
	if (fd == -1) {
		perror("inotify_init1");
		exit(EXIT_FAILURE);
	}
	/* Allocate memory for watch descriptors */
	/* Mark directories for events
	 - file was opened
	 - file was closed */
	int wd = inotify_add_watch(fd, dir, IN_OPEN | IN_CLOSE | IN_CREATE);
	/* Prepare for polling */
	nfds_t nfds = 1;
	/* Inotify input */
	struct pollfd fds[1];
	fds[0].fd = fd;
	fds[0].events = POLLIN;
	/* Wait for events and/or terminal input */
	printf("Listening for events.\n");
	while (1) {
		int poll_num = poll(fds, nfds, -1);
		printf("poll_num is %d.\n", poll_num);
		if (poll_num == -1) {
			if (errno == EINTR)
				continue;
			perror("poll");
			exit(EXIT_FAILURE);
		}
		printf("fds[0].revents is %d \n", fds[0].revents);
		printf("fds[0].revents & POLLIN %d\n", (fds[0].revents & POLLIN));
		if (fds[0].revents & POLLIN) {
			/* Inotify events are available */
			handle_events(fd, wd, dir);
		}
	}

	printf("Listening for events stopped.\n");
	/* Close inotify file descriptor */
	close(fd);
}
