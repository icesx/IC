/*
 * inotify.cpp
 *
 *  Created on: Nov 3, 2019
 *      Author: i
 */

//
// File:   inotify-example.cpp
// Date:   July 16, 2013
// Author: Peter Krnjevic <pkrnjevic@gmail.com>, on the shoulders of many others
//
// This is a simple inotify sample program monitoring changes to "./tmp" directory (create ./tmp beforehand)
// Recursive monitoring of file and directory create and delete events is implemented, but
// monitoring pre-existing "./tmp" subfolders is not.
// A C++ class containing a couple of maps is used to simplify monitoring.
// The Watch class is minimally integrated, so as to leave the main inotify code
// easily recognizeable.
//
// *N.B.*
// 1. This code is meant to illustrate inotify usage, and not intended to be
//    production ready. Exception and error handling is largely incomplete or missing.
// 2. inotify has a fundamental flaw for which there is no real solution: if subdirectories are
//    created too quickly, create events will be lost, resulting in those subdirectories (as well
//    as their children) going unwatched.
// 3. fanotify, available in newer kernels, can monitor entire volumes, and is often a better solution.
//
//
// This code sample is released into the Public Domain.
//
//
// To compile:
//    $ g++ inotify-example.cpp -o inotify-example
//
// To run:
//    $ ./inotify-example
//
// To exit:
//    control-C
//
//
#include "inotify.h"

// Watch class keeps track of watch descriptors (wd), parent watch descriptors (pd), and names (from event->name).
// The class provides some helpers for inotify, primarily to enable recursive monitoring:
// 1. To add a watch (inotify_add_watch), a complete path is needed, but events only provide file/dir name with no path.
// 2. Delete events provide parent watch descriptor and file/dir name, but removing the watch (infotify_rm_watch) needs a wd.
//
// Insert event information, used to create new watch, into Watch object.
void Watch::insert(int pd, const string &name, int wd) {
	wd_elem elem = { pd, name };
	watch[wd] = elem;
	rwatch[elem] = wd;
	printf("start insert on %s\n",name.c_str());
}
// Erase watch specified by pd (parent watch descriptor) and name from watch list.
// Returns full name (for display etc), and wd, which is required for inotify_rm_watch.
string Watch::erase(int pd, const string &name, int *wd) {
	wd_elem pelem = { pd, name };
	*wd = rwatch[pelem];
	rwatch.erase(pelem);
	const wd_elem &elem = watch[*wd];
	string dir = elem.name;
	watch.erase(*wd);
	return dir;
}
// Given a watch descriptor, return the full directory name as string. Recurses up parent WDs to assemble name,
// an idea borrowed from Windows change journals.
string Watch::get(int wd) {
	const wd_elem &elem = watch[wd];
	return elem.pd == -1 ? elem.name : this->get(elem.pd) + "/" + elem.name;
}
// Given a parent wd and name (provided in IN_DELETE events), return the watch descriptor.
// Main purpose is to help remove directories from watch list.
int Watch::get(int pd, string name) {
	wd_elem elem = { pd, name };
	return rwatch[elem];
}
void Watch::cleanup(int fd) {
	for (map<int, wd_elem>::iterator wi = watch.begin(); wi != watch.end();
			wi++) {
		inotify_rm_watch(fd, wi->first);
		watch.erase(wi);
	}
	rwatch.clear();
}
void Watch::stats() {
	cout << "number of watches=" << watch.size() << " & reverse watches="
			<< rwatch.size() << endl;
}

