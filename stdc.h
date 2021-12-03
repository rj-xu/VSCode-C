#pragma once

#include <assert.h>      // Conditionally compiled macro that compares its argument to zero
#include <complex.h>     // (C99) Complex number arithmetic
#include <ctype.h>       // Functions to determine the type contained in character data
#include <errno.h>       // Macros reporting error conditions
#include <fenv.h>        // (C99) Floating-point environment
#include <float.h>       // Limits of floating-piont types
#include <inttypes.h>    // (C99) Format conversion of integer types
#include <iso646.h>      // (C95) Alternative operator spellings
#include <limits.h>      // Sizes of basic types
#include <locale.h>      // Localization utilities
#include <math.h>        // Common mathematics functions
#include <setjmp.h>      // Nonlocal jumps
#include <signal.h>      // Signal handling
#include <stdalign.h>    // (C11) alignas and alignof convenience macros
#include <stdarg.h>      // Variable arguments
#include <stdatomic.h>   // (C11) Atomic operations
#include <stdbool.h>     // (C99) Macros for boolean type
#include <stddef.h>      // Common macro definitions
#include <stdint.h>      // (C99) Fixed-width integer types
#include <stdio.h>       // Input/output
#include <stdlib.h>      // General utilities: memory management, program utilities, string conversions, random numbers, algorithms
#include <stdnoreturn.h> // (C11) noreturn convenience macro
#include <string.h>      // String handling
#include <tgmath.h>      // (C99) Type-generic math (macros wrapping math.h and complex.h)
// #include <threads.h>     // (C11) Thread library
#include <time.h>        // Time/date utilities
#include <uchar.h>       // (C11) UTF-16 and UTF-32 character utilities
#include <wchar.h>       // (C95) Extended multibyte and wide character utilities
#include <wctype.h>      // (C95) Functions to determine the type contained in wide character data

typedef unsigned int uint;

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

struct ListNode
{
    int val;
    struct ListNode *next;
};
