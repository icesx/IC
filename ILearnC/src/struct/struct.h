/*
 * struct.h
 *
 *  Created on: Feb 10, 2018
 *      Author: i
 */

#ifndef STRUCT_STRUCT_H_
#define STRUCT_STRUCT_H_

#define ATT_MTU_SIZE                     24
typedef struct {
	char value[ATT_MTU_SIZE - 3]; //!< Value of the attribute to be written
} attWriteReq_t;




#endif /* STRUCT_STRUCT_H_ */
