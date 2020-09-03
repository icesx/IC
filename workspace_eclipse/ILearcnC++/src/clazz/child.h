/*
 * child.h
 *
 *  Created on: Oct 14, 2019
 *      Author: i
 */

#ifndef CLAZZ_CHILD_H_
#define CLAZZ_CHILD_H_

#include "driver.h"
class Child: public Parent {
public:
	~Child(){

	}
	void todo();
	void doChild();
};

#endif /* CLAZZ_CHILD_H_ */
