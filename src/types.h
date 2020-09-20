#ifndef HOLYTYP_HEADER_FILE
#define HOLYTYP_HEADER_FILE

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h> // C99

// Integer maximums
#define U8_MAX	UINT8_MAX
#define I8_MIN	INT8_MIN
#define I8_MAX	INT8_MAX
#define U16_MAX UINT16_MAX
#define I16_MIN INT16_MIN
#define I16_MAX INT16_MAX
#define U32_MAX UINT32_MAX
#define I32_MIN INT32_MIN
#define I32_MAX INT32_MAX
#define U64_MAX UINT64_MAX
#define I64_MIN INT64_MIN
#define I64_MAX INT64_MAX

// Void type
typedef	void X0;

// Integer typedefs
typedef uint8_t	U8;
typedef	int8_t	I8;
typedef uint16_t U16;
typedef	int16_t I16;
typedef uint32_t U32;
typedef	int32_t I32;
typedef uint64_t U64;
typedef	int64_t I64;

// String component types
// Only use these for storing characters for strings.
typedef	char CHR;

// Real typedefs
typedef	float R32; // May not be exactly 32 or 64 bits depending on arch
typedef	double R64;

// Natural types (Spoiler: they're all 32-bit)
typedef	I32 INAT;
typedef	U32 UNAT;
typedef	R32 RNAT;

// Size type
typedef	size_t SX;	// Size type, length unspecified
typedef	ssize_t SSX; // Size type, length unspecified, and signed

// Boolean types
typedef	bool U1;
#define BOOLIFY(a) ((a)?(true):(false)) // May not be needed with _Bool

#endif