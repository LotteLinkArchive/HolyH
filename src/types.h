#ifndef HOLYTYP_HEADER_FILE
#define HOLYTYP_HEADER_FILE

#include "cstdv.h"

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

#endif
