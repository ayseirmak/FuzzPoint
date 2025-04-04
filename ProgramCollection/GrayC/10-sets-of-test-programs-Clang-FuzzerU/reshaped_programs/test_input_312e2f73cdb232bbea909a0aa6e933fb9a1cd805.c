#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define CHAR_BIT 8

#if INT_MAX > 2147483647L
# if INT_MAX >= 9223372036854775807L
#  define BITSIZEOF_INT 64
# else
#  define BITSIZEOF_INT 32
# endif
#else
# if INT_MAX >= 2147483647L
#  define BITSIZEOF_INT 32
# else
#  define BITSIZEOF_INT 16
# endif
#endif

#if LONG_MAX > 2147483647L
# if LONG_MAX >= 9223372036854775807L
#  define BITSIZEOF_LONG 64
# else
#  define BITSIZEOF_LONG 32
# endif
#else
# define BITSIZEOF_LONG 32
#endif

#if LLONG_MAX > 2147483647L
# if LLONG_MAX >= 9223372036854775807L
#  define BITSIZEOF_LONG_LONG 64
# else
#  define BITSIZEOF_LONG_LONG 32
# endif
#else
# define BITSIZEOF_LONG_LONG 32
#endif

#define MAKE_FUNS(suffix, type)                                            \
int my_ffs##suffix(type x) {                                               \
    int i = 0;                                                             \
    if (x == 0) return 0;                                                  \
    for (i = 0; i < CHAR_BIT * sizeof(type); i++)                          \
        if (x & ((type) 1 << i))                                           \
            break;                                                         \
    return i + 1;                                                          \
}                                                                          \
                                                                           \
int my_ctz##suffix(type x) {                                               \
    int i = 0;                                                             \
    for (i = 0; i < CHAR_BIT * sizeof(type); i++)                          \
        if (x & ((type) 1 << i))                                           \
            break;                                                         \
    return i;                                                              \
}                                                                          \
                                                                           \
int my_clz##suffix(type x) {                                               \
    int i = 0;                                                             \
    for (i = 0; i < CHAR_BIT * sizeof(type); i++)                          \
        if (x & ((type) 1 << ((CHAR_BIT * sizeof(type)) - i - 1)))         \
            break;                                                         \
    return i;                                                              \
}                                                                          \
                                                                           \
int my_clrsb##suffix(type x) {                                             \
    int i = 1;                                                             \
    int leading = (x >> CHAR_BIT * sizeof(type) - 1) & 1;                  \
    for (i = 1; i < CHAR_BIT * sizeof(type); i++)                          \
        if (((x >> ((CHAR_BIT * sizeof(type)) - i - 1)) & 1)               \
            != leading)                                                    \
            break;                                                         \
    return i - 1;                                                          \
}                                                                          \
                                                                           \
int my_popcount##suffix(type x) {                                          \
    int i = 0;                                                             \
    int count = 0;                                                         \
    for (i = 0; i < CHAR_BIT * sizeof(type); i++)                          \
        if (x & ((type) 1 << i))                                           \
            count++;                                                       \
    return count;                                                          \
}                                                                          \
                                                                           \
int my_parity##suffix(type x) {                                            \
    int i = 0;                                                             \
    int count = 0;                                                         \
    for (i = 0; i < CHAR_BIT * sizeof(type); i++)                          \
        if (x & ((type) 1 << i))                                           \
            count++;                                                       \
    return count & 1;                                                      \
}

MAKE_FUNS(, unsigned)
MAKE_FUNS(l, unsigned long)
MAKE_FUNS(ll, unsigned long long)

#define NUMS16 {0x0000U, 0x0001U, 0x8000U, 0x0002U, 0x4000U, 0x0100U, 0x0080U, 0xa5a5U, 0x5a5aU, 0xcafeU, 0xffffU}

#define NUMS32 {0x00000000UL, 0x00000001UL, 0x80000000UL, 0x00000002UL, 0x40000000UL, 0x00010000UL, 0x00008000UL, 0xa5a5a5a5UL, 0x5a5a5a5aUL, 0xcafe0000UL, 0x00cafe00UL, 0x0000cafeUL, 0xffffffffUL}

#define NUMS64 {0x0000000000000000ULL, 0x0000000000000001ULL, 0x8000000000000000ULL, 0x0000000000000002ULL, 0x4000000000000000ULL, 0x0000000100000000ULL, 0x0000000080000000ULL, 0xa5a5a5a5a5a5a5a5ULL, 0x5a5a5a5a5a5a5a5aULL, 0xcafecafe00000000ULL, 0x0000cafecafe0000ULL, 0x00000000cafecafeULL, 0xffffffffffffffffULL}

unsigned int ints[] =
#if BITSIZEOF_INT == 64
NUMS64
#elif BITSIZEOF_INT == 32
NUMS32
#else
NUMS16
#endif
;

unsigned long longs[] =
#if BITSIZEOF_LONG == 64
NUMS64
#else
NUMS32
#endif
;

unsigned long long longlongs[] =
#if BITSIZEOF_LONG_LONG == 64
NUMS64
#else
NUMS32
#endif
;

#define N(table) (sizeof(table) / sizeof(table[0]))

int main(void) {
    int i;

    for (i = 0; i < N(ints); i++) {
        if (ints[i] != 0 && (__builtin_ffs(ints[i]) != my_ffs(ints[i]) ||
                              __builtin_clz(ints[i]) != my_clz(ints[i]) ||
                              __builtin_ctz(ints[i]) != my_ctz(ints[i]))) {
            abort();
        }
        if (__builtin_clrsb(ints[i]) != my_clrsb(ints[i]) ||
            __builtin_popcount(ints[i]) != my_popcount(ints[i]) ||
            __builtin_parity(ints[i]) != my_parity(ints[i])) {
            abort();
        }
    }

    for (i = 0; i < N(longs); i++) {
        if (longs[i] != 0 && (__builtin_ffsl(longs[i]) != my_ffsl(longs[i]) ||
                              __builtin_clzl(longs[i]) != my_clzl(longs[i]) ||
                              __builtin_ctzl(longs[i]) != my_ctzl(longs[i]))) {
            abort();
        }
        if (__builtin_clrsbl(longs[i]) != my_clrsbl(longs[i]) ||
            __builtin_popcountl(longs[i]) != my_popcountl(longs[i]) ||
            __builtin_parityl(longs[i]) != my_parityl(longs[i])) {
            abort();
        }
    }

    for (i = 0; i < N(longlongs); i++) {
        if (longlongs[i] != 0 && (__builtin_ffsll(longlongs[i]) != my_ffsll(longlongs[i]) ||
                                  __builtin_clzll(longlongs[i]) != my_clzll(longlongs[i]) ||
                                  __builtin_ctzll(longlongs[i]) != my_ctzll(longlongs[i]))) {
            abort();
        }
        if (__builtin_clrsbll(longlongs[i]) != my_clrsbll(longlongs[i]) ||
            __builtin_popcountll(longlongs[i]) != my_popcountll(longlongs[i]) ||
            __builtin_parityll(longlongs[i]) != my_parityll(longlongs[i])) {
            abort();
        }
    }

    exit(0);
}