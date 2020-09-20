#ifndef HOLYBFLG_HEADER_FILE
#define HOLYBFLG_HEADER_FILE

#include "types.h"
#include "macros.h"

#define HLYCHCKFLG(field, bit) \
	(BOOLIFY((field) & ((__typeof__ (field))0x01 << (bit))))
#define HLYSETFLG(field, bit) \
	((field) | ((__typeof__ (field))0x01 << (bit)))
#define HLYUNSETFLG(field, bit) \
	((field) & ~((__typeof__ (field))0x01 << (bit)))
#define HLYTOGLFLG(field, bit) \
	((field) ^ ((__typeof__ (field))0x01 << (bit)))

#define HLYRGEXTRCT(source, bits, position) \
	(source >> position & (U16Pow(2, bits) - 1))

#endif
