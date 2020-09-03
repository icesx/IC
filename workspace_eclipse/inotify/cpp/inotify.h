/*
 * inotify.h
 *
 *  Created on: Nov 4, 2019
 *      Author: i
 */

#ifndef INOTIFY_H_
#define INOTIFY_H_
#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include <sys/inotify.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <map>
#include <unistd.h>

using std::map;
using std::string;
using std::cout;
using std::endl;

#define EVENT_SIZE          ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN       ( 1024 * ( EVENT_SIZE + NAME_MAX + 1) )
#define WATCH_FLAGS         ( IN_CREATE | IN_DELETE )

class Watch {
	struct wd_elem {
		int pd;
		string name;
		bool operator()(const wd_elem &l, const wd_elem &r) const {
			return l.pd < r.pd ? true :
					l.pd == r.pd && l.name < r.name ? true : false;
		}
	};
	map<int, wd_elem> watch;
	map<wd_elem, int, wd_elem> rwatch;
public:
	// Insert event information, used to create new watch, into Watch object.
	void insert(int pd, const string &name, int wd);
	// Returns full name (for display etc), and wd, which is required for inotify_rm_watch.
	string erase(int pd, const string &name, int *wd);
	// Given a watch descriptor, return the full directory name as string. Recurses up parent WDs to assemble name,
	// an idea borrowed from Windows change journals.
	string get(int wd);
	// Given a parent wd and name (provided in IN_DELETE events), return the watch descriptor.
	// Main purpose is to help remove directories from watch list.
	int get(int pd, string name);
	void cleanup(int fd);
	void stats();
};
void watch(const char *root);
#endif /* INOTIFY_H_ */
