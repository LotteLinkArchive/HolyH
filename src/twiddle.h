#ifndef HOLYTWD_HEADER_FILE
#define HOLYTWD_HEADER_FILE

#include "types.h"

inline __attribute__((always_inline)) U32 u32rup2(U32 v) {
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;

	return v;
}

#define UINTP2CHK(n) (((n) & ((n) - 1) == 0) && (n) != 0)

#endif