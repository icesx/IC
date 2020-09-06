/*
 * parent.h
 *
 *  Created on: Oct 14, 2019
 *      Author: i
 */
#include <stdio.h>
class Parent {
public:
	virtual ~Parent(){
	}
	virtual void todo(){
	}
};
class Driver {
public:
	void doSome(Parent& doing);
};

