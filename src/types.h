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
#define U8_MAX  UINT8_MAX
#define I8_MIN  INT8_MIN
#define I8_MAX  INT8_MAX
#define U16_MAX UINT16_MAX
#define I16_MIN INT16_MIN
#define I16_MAX INT16_MAX
#define U32_MAX UINT32_MAX
#define I32_MIN INT32_MIN
#define I32_MAX INT32_MAX
#define U64_MAX UINT64_MAX
#define I64_MIN INT64_MIN
#define I64_MAX INT64_MAX

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

/* Natural types (Spoiler: they're all 32-bit) */
typedef	I32 INAT;
typedef	U32 UNAT;
typedef	R32 RNAT;

/* Size type
 * The length depends on the system. SSX is the signed variant (ssize_t)
 * 
 * You might not want to enable SSX because it won't work on things like MSYS2
 */
typedef	size_t SX;
#ifdef HOLY_ENABLE_SSX
typedef	ssize_t SSX;
#endif
#ifndef HOLY_DISABLE_OX
#include <stdio.h>
typedef	off_t OX;
#endif

/* Boolean types */
typedef	bool U1;
#define BOOLIFY(a) ((a)?(true):(false)) /* May not be needed with _Bool */

#endif
