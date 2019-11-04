/*
 * notify.h
 *
 *  Created on: Oct 26, 2019
 *      Author: i
 */
#include <sys/inotify.h>
typedef void (*handler)(int fd,const struct inotify_event*,char *watched_dir);
void handle_events(int fd, char *watched_dir, handler);
void notify_dir(char *argv, handler);
