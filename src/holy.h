/* Standardization of C types and addition of a few useful macros
 * Inspired by Terry Davis' HolyC
 * 
 * May he rest in peace.
 */

#ifndef HOLY_HEADER_FILE
#define HOLY_HEADER_FILE

#ifndef HOLYSTDV_HEADER_FILE
#define HOLYSTDV_HEADER_FILE
#if defined(__STDC__)
# define C89
# if defined(__STDC_VERSION__)
#  define C90
#  if (__STDC_VERSION__ >= 199409L)
#   define C94
#  endif
#  if (__STDC_VERSION__ >= 199901L)
#   define C99
#  endif
#  if (__STDC_VERSION__ >= 201112L)
#   define C11
#  endif
# endif
#define CHOLYH
#endif
#endif

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#ifdef C99
#include <stdbool.h> /* stdbool.h is C99 Only! */
#else
#if !defined(bool) && !defined(true) && !defined(false)
#define bool  U8
#define true  1
#define false 0
#endif
#endif

/* Integer maximums */
#define U8_MAX UINT8_MAX
#define U8_MIN UINT8_MIN
#define U8_WIDTH UINT8_WIDTH
#define I8_MIN INT8_MIN
#define I8_MAX INT8_MAX
#define I8_WIDTH INT8_WIDTH
#define U16_MAX UINT16_MAX
#define U16_MIN UINT16_MIN
#define U16_WIDTH UINT16_WIDTH
#define I16_MIN INT16_MIN
#define I16_MAX INT16_MAX
#define I16_WIDTH INT16_WIDTH
#define U32_MAX UINT32_MAX
#define U32_MIN UINT32_MIN
#define U32_WIDTH UINT32_WIDTH
#define I32_MIN INT32_MIN
#define I32_MAX INT32_MAX
#define I32_WIDTH INT32_WIDTH
#define U64_MAX UINT64_MAX
#define U64_MIN UINT64_MIN
#define U64_WIDTH UINT64_WIDTH
#define I64_MIN INT64_MIN
#define I64_MAX INT64_MAX
#define I64_WIDTH INT64_WIDTH

/* Void type */
typedef	void X0;

/* Integer typedefs */
typedef uint8_t  U8;
typedef	int8_t   I8;
typedef uint16_t U16;
typedef	int16_t  I16;
typedef uint32_t U32;
typedef	int32_t  I32;
typedef uint64_t U64;
typedef	int64_t  I64;

/* String component types
 * Only use these for storing characters for strings.
 */
typedef	char CHR;

/* Real typedefs
 * May not be exactly 32 or 64 bits depending on arch, use at your own risk
 * 
 * (This may be fixed in the future)
 */
typedef	float R32;
typedef	double R64;

/* Natural types */
typedef	int INAT;
typedef	unsigned int UNAT;
typedef	float RNAT;

/* Size type
 * The length depends on the system. SSX is the signed variant (ssize_t)
 * 
 * You might not want to enable SSX because it won't work on things like MSYS2
 */
typedef	size_t SX;
#define SX_MAX SIZE_MAX
#define SX_MIN SIZE_MIN
#define SX_WIDTH SIZE_WIDTH
#ifdef HOLY_ENABLE_SSX
typedef	ssize_t SSX;
#endif
#ifndef HOLY_DISABLE_OX
#include <stdio.h>
typedef	off_t OX;
#endif
#ifndef HOLY_DISABLE_PTR
typedef ptrdiff_t DPTR;
typedef intptr_t  IPTR;
typedef uintptr_t UPTR;
#define DPTR_MAX PTRDIFF_MAX
#define DPTR_MIN PTRDIFF_MIN
#define DPTR_WIDTH PTRDIFF_WIDTH
#define IPTR_MAX INTPTR_MAX
#define IPTR_MIN INTPTR_MIN
#define IPTR_WIDTH INTPTR_WIDTH
#define UPTR_MAX UINTPTR_MAX
#define UPTR_MIN UINTPTR_MIN
#define UPTR_WIDTH UINTPTR_WIDTH
#endif

/* Boolean types */
typedef	bool U1;
#define BOOLIFY(a) ((a)?(true):(false)) /* May not be needed with _Bool */

#define UNS unsigned

#ifndef HOLY_NO_VECTORS

/* Vector definition macro */
#define DEF_VECTYPE(name, element_type, elements) \
typedef element_type name __attribute__ \
((vector_size (sizeof(element_type) * elements)));
/* TODO: Automatically round up to power of two for vector size */

/* Useful vector types */
DEF_VECTYPE(R64VEC_4D, R64, 4)
DEF_VECTYPE(R64VEC_2D, R64, 2)
typedef R64VEC_4D R64VEC_3D; /* Only power of 2 vectors are allowed */
DEF_VECTYPE(R32VEC_4D, R32, 4)
DEF_VECTYPE(R32VEC_2D, R32, 2)
typedef R32VEC_4D R32VEC_3D;
DEF_VECTYPE(U32VEC_4D, U32, 4)
DEF_VECTYPE(U32VEC_2D, U32, 2)
typedef U32VEC_4D U32VEC_3D;
DEF_VECTYPE(I32VEC_4D, I32, 4)
DEF_VECTYPE(I32VEC_2D, I32, 2)
typedef I32VEC_4D I32VEC_3D;

/* These specific ones are useful for colour manipulation */
DEF_VECTYPE(U8x8, U8, 8)
DEF_VECTYPE(U8x4, U8, 4)
DEF_VECTYPE(U16x8, U16, 8)
DEF_VECTYPE(U16x4, U16, 4)

/* Sensible aliases */
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
/* TODO: Do this the other way round (e.g R64VEC_4D points to R64x4) */

/* Potentially useful for alpha blending */
DEF_VECTYPE(U8x32  , U8 , 32 )
DEF_VECTYPE(U16x32 , U16, 32 )
DEF_VECTYPE(U8x16  , U8 , 16 )
DEF_VECTYPE(U16x16 , U16, 16 )
DEF_VECTYPE(U8x64  , U8 , 64 )
DEF_VECTYPE(U8x128 , U8 , 128)
DEF_VECTYPE(U16x64 , U16, 64 )
DEF_VECTYPE(U16x128, U16, 128)
DEF_VECTYPE(U32x32,  U32, 32 )
DEF_VECTYPE(U32x64,  U32, 64 )
DEF_VECTYPE(U64x8  , U64, 8  )
DEF_VECTYPE(U32x16 , U32, 16 )
DEF_VECTYPE(U32x8  , U32, 8  )
DEF_VECTYPE(R32x4  , R32, 4  )
DEF_VECTYPE(R64x4  , R64, 4  )
DEF_VECTYPE(R32x8  , R32, 8  )
DEF_VECTYPE(R64x8  , R64, 8  )
DEF_VECTYPE(R32x16 , R32, 16 )
DEF_VECTYPE(R64x16 , R64, 16 )

/* Vector macros */
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

/* Useful macros */
#define MIN(a,b) __extension__ \
({ __typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	_a < _b ? _a : _b; })
#define MAX(a,b) __extension__ \
({ __typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	_a > _b ? _a : _b; })

#define forever for (;;)

/* Fast unsigned power functions */
#define UXPowGen(type, name) \
inline __attribute__((always_inline)) type name(type x, type y) \
	{ y = MAX((type)1, y); while ((y--) - 1) x *= x; return x; }
UXPowGen(U16, U16Pow)
UXPowGen(U32, U32Pow)
UXPowGen(U64, U64Pow)
#undef UXPowGen

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

inline __attribute__((always_inline)) U32 u32rup2(U32 v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;

	return v;
}

#define UINTP2CHK(n) ((((n) & ((n) - 1)) == 0) && (n) != 0)

#endif
