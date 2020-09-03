/*
 * main.c
 *
 *  Created on: Nov 4, 2019
 *      Author: i
 */

#include <poll.h>
#include "inotify.h"
#include <unistd.h>
// Keep going  while run == true, or, in other words, until user hits ctrl-c
static bool run = true;

void sig_exit(int sig) {
	run = false;
}
void is_exits(const char *root) {
	if (access(root, F_OK)) {
		printf("%s is not exist!", root);
		exit(0);
	}
}
void watch(const char *root) {
	is_exits(root);
	// std::map used to keep track of wd (watch descriptors) and directory names
	// As directory creation events arrive, they are added to the Watch map.
	// Directory delete events should be (but currently aren't in this sample) handled the same way.
	Watch watch;

	// watch_set is used by select to wait until inotify returns some data to
	// be read using non-blocking read.

	char buffer[EVENT_BUF_LEN];
	string current_dir, new_dir;
	int total_file_events = 0;
	int total_dir_events = 0;

	// Call sig_callback if user hits ctrl-c
	signal(SIGINT, sig_exit);

	// creating the INOTIFY instance
	// inotify_init1 not available with older kernels, consequently inotify reads block.
	// inotify_init1 allows directory events to complete immediately, avoiding buffering delays. In practice,
	// this significantly improves monotiring of newly created subdirectories.

#ifdef IN_NONBLOCK
	int fd = inotify_init1( IN_NONBLOCK);
#else
    int fd = inotify_init();
#endif

	// checking for error
	if (fd < 0) {
		perror("inotify_init");
	}

	// use select watch list for non-blocking inotify read

	// add “./tmp” to watch list. Normally, should check directory exists first
	int wd = inotify_add_watch(fd, root, WATCH_FLAGS);

	// add wd and directory name to Watch map
	watch.insert(-1, root, wd);

	// Continue until run == false. See signal and sig_callback above.
	struct pollfd pfd;
	pfd.fd = fd;
	pfd.events = POLLIN;
	nfds_t nfds = 1;
	while (run) {
		int poll_num = poll(&pfd, nfds, -1);
		// Read event(s) from non-blocking inotify fd (non-blocking specified in inotify_init1 above).
		if (poll_num < 0) {
			perror("poll error");
		}
		int length = read(fd, buffer, EVENT_BUF_LEN);

		// Loop through event buffer
		for (int i = 0; i < length;) {
			struct inotify_event *event = (struct inotify_event*) &buffer[i];
			// Never actually seen this
			if (event->wd == -1) {
				printf("Overflow\n");
			}
			// Never seen this either
			if (event->mask & IN_Q_OVERFLOW) {
				printf("Overflow\n");
			}
			if (event->len) {
				if (event->mask & IN_IGNORED) {
					printf("IN_IGNORED\n");
				}
				if (event->mask & IN_CREATE) {
					current_dir = watch.get(event->wd);
					if (event->mask & IN_ISDIR) {
						new_dir = current_dir + "/" + event->name;
						wd = inotify_add_watch(fd, new_dir.c_str(),
						WATCH_FLAGS);
						watch.insert(event->wd, event->name, wd);
						total_dir_events++;
						printf("New directory %s created.\n", new_dir.c_str());
					} else {
						total_file_events++;
						printf("New file %s/%s created.\n", current_dir.c_str(),
								event->name);
					}
				} else if (event->mask & IN_DELETE) {
					if (event->mask & IN_ISDIR) {
						new_dir = watch.erase(event->wd, event->name, &wd);
						inotify_rm_watch(fd, wd);
						total_dir_events--;
						printf("Directory %s deleted.\n", new_dir.c_str());
					} else {
						current_dir = watch.get(event->wd);
						total_file_events--;
						printf("File %s/%s deleted.\n", current_dir.c_str(),
								event->name);
					}
				}
			}
			i += EVENT_SIZE + event->len;
		}
	}

	// Cleanup
	printf("cleaning up\n");
	cout << "total dir events = " << total_dir_events
			<< ", total file events = " << total_file_events << endl;
	watch.stats();
	watch.cleanup(fd);
	watch.stats();
	close(fd);
	fflush(stdout);
}
