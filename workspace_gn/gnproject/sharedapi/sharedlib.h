#ifndef SHAREDLIB_H__
#define SHAREDLIB_H__

#include "stdio.h"
#include "stdlib.h"

#ifdef _cplusplus
extern "C" {
#endif

int api_add(int a, int b);

int api_sub(int a, int b);

#ifdef _cplusplus
}
#endif

#endif
