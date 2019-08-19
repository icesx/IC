/*
 * main.c
 *
 *  Created on: Oct 26, 2018
 *      Author: i
 */

#include <jni.h>
JNIEXPORT jstring JNICALL Java_com_example_i_gpiotb_jni_JniUtil_getJniString(
		JNIEnv * env, jclass jclass) {
	return (*env)->NewStringUTF(env, "i am compiled by aarch64-linux-gnu-gcc-8");
}
JNIEXPORT void JNICALL Java_com_example_i_gpiotb_jni_JniUtil_writeStderr(
		JNIEnv * env, jclass jclass) {
}

