/*
 * sample.c
 *
 *  Created on: Oct 29, 2019
 *      Author: i
 */

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
static pthread_mutex_t worker_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t worker_wait = PTHREAD_COND_INITIALIZER;
void* doSomeThing(void *arg) {
	pthread_t id = pthread_self();
	if (pthread_equal(id, tid[0])) {
		printf("\n First thread processing id is %ld \n", id);
	} else {
		printf("\n Second thread processing id is %ld \n", id);
	}
	sleep(3);
	printf("broadcast...");
	pthread_cond_broadcast(&worker_wait);
	return NULL;
}

int sample_pthread(void) {
	int i = 0;
	int err;
	while (i < 2) {
		err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
		if (err != 0)
			printf("\ncan't create thread :[%s]", strerror(err));
		else
			printf("\n Thread created successfully\n");
		i++;
	}
	pthread_cond_wait(&worker_wait, &worker_lock);
	printf("%ld,exit", pthread_self());
	return 0;
}
