/*
 * test_vector.c
 *
 *  Created on: Nov 9, 2019
 *      Author: i
 */
#include "test_vector.h"
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int id;
} person;
void foreach(vector<person> v) {
	for (vector<person>::iterator it = v.begin(); it < v.end(); it++) {
		printf("person.id=%d\n", it->id);
	}
}
void test_free() {
	vector<person*> *v = new vector<person*>;
	person *p = new person;
	p->id=100;
	v->push_back(p);
	free(v);
	printf("is free person %d\n", p->id);
	free(p);
	printf("is free person %d\n", p->id);
}
void test_vector() {
	vector<person> v;
	for (int i = 0; i < 10; i++) {
		person p;
		p.id = i;
		v.push_back(p);
	}
	foreach(v);
	printf("pop_back\n");
	v.pop_back();
	foreach(v);
	printf("delete position 4\n");
	v.erase(v.begin() + 3);
	foreach(v);
	struct each {
		void operator()(person p1) {
			printf("person %d\n", p1.id);
		}
	};
	for_each(v.begin(), v.end(), each());
	test_free();
}

