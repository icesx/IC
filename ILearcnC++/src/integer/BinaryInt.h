/*
 * BinaryInt.h
 *
 *  Created on: Nov 2, 2018
 *      Author: i
 */

#ifndef INTEGER_BINARYINT_H_
#define INTEGER_BINARYINT_H_

class BinaryInt {
public:
	BinaryInt();
	virtual ~BinaryInt();
	void addChar(char c);
	int getInt();
private:
	int value;
	int index;
	void reset() {
		value = 0;
		index = 0;
	}
};

#endif /* INTEGER_BINARYINT_H_ */
