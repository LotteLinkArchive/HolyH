#ifndef HOLYMCR_HEADER_FILE
#define HOLYMCR_HEADER_FILE

#include "types.h"

// Useful macros
#define MIN(a,b) __extension__ \
({ __typeof__ (a) _a = (a);    \
    __typeof__ (b) _b = (b);   \
    _a < _b ? _a : _b; })
#define MAX(a,b) __extension__ \
({ __typeof__ (a) _a = (a);    \
    __typeof__ (b) _b = (b);   \
    _a > _b ? _a : _b; })

#define forever for (;;)

// Fast unsigned power functions
#define UXPowGen(type, name)                                    \
inline __attribute__((always_inline)) type name(type x, type y) \
    { y = MAX((type)1, y); while ((y--) - 1) x *= x; return x; }
UXPowGen(U16, U16Pow)
UXPowGen(U32, U32Pow)
UXPowGen(U64, U64Pow)
#undef UXPowGen

#endif