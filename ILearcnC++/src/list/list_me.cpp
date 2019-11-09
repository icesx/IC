/*
 * list_me.cpp
 *
 *  Created on: Nov 8, 2019
 *      Author: i
 */

#include <list>
#include "list_me.h"
#include <iostream>
#include <stdlib.h>
void test_list() {
	std::list<Student> data;
	Student st;
	st.name = "zhangsan";
	data.push_back(st);
	// do whatever you wish but don't modify the list elements
	for (std::list<Student>::iterator it = data.begin(); it != data.end();
			++it) {
		printf("list:name %s\n", it->name);
	}
}
void test_list2() {
	std::list<Student*> *data = new std::list<Student*>();
	Student st;
	st.name = "zhangsan2";
	data->push_back(&st);
	// do whatever you wish but don't modify the list elements
	for (std::list<Student*>::iterator it = data->begin(); it != data->end();
			it++) {
		printf("list:name %s\n", (**it).name);
	}
}

