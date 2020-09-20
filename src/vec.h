#ifndef HOLYVEC_HEADER_FILE
#define HOLYVEC_HEADER_FILE
#ifndef HOLY_NO_VECTORS
#include <xmmintrin.h>
#include <pmmintrin.h>
#include "types.h"

// Vector definition macro
#define DEF_VECTYPE(name, element_type, elements) \
typedef element_type name __attribute__ \
((vector_size (sizeof(element_type) * elements)));
// TODO: Automatically round up to power of two for vector size

// Useful vector types
DEF_VECTYPE(R64VEC_4D, R64, 4)
DEF_VECTYPE(R64VEC_2D, R64, 2)
typedef R64VEC_4D R64VEC_3D; // Only power of 2 vectors are allowed
DEF_VECTYPE(R32VEC_4D, R32, 4)
DEF_VECTYPE(R32VEC_2D, R32, 2)
typedef R32VEC_4D R32VEC_3D;
DEF_VECTYPE(U32VEC_4D, U32, 4)
DEF_VECTYPE(U32VEC_2D, U32, 2)
typedef U32VEC_4D U32VEC_3D;
DEF_VECTYPE(I32VEC_4D, I32, 4)
DEF_VECTYPE(I32VEC_2D, I32, 2)
typedef I32VEC_4D I32VEC_3D;

// These specific ones are useful for colour manipulation
DEF_VECTYPE(U8x8, U8, 8)
DEF_VECTYPE(U8x4, U8, 4)
DEF_VECTYPE(U16x8, U16, 8)
DEF_VECTYPE(U16x4, U16, 4)

// Sensible aliases
typedef R64VEC_4D R64x4;
typedef R32VEC_4D R32x4;
typedef I32VEC_4D I32x4;
typedef U32VEC_4D U32x4;

typedef R64VEC_3D R64x3;
typedef R32VEC_3D R32x3;
typedef I32VEC_3D I32x3;
typedef U32VEC_3D U32x3;

typedef R64VEC_2D R64x2;
typedef R32VEC_2D R32x2;
typedef I32VEC_2D I32x2;
typedef U32VEC_2D U32x2;
// TODO: Do this the other way round (e.g R64VEC_4D points to R64x4)

// Vector macros
#define hcl_vector_convert __builtin_convertvector
/* See https://github.com/simd-everywhere/simde
 * This is a much better library for doing vector stuff anywhere, but the good
 * news is that you ought to be able to do most things without it assuming
 * you're on GCC or Clang. (E.g vector shuffling can be done simply by
 * defining a new vector containing elements from other vectors, and the
 * compiler ought to optimize it automatically. This should work anywhere, but
 * it'll just look kinda ugly.)
 * 
 * In the future, this header may be expanded to create its own simple,
 * standardized vector interface.
 */
#endif
#endif