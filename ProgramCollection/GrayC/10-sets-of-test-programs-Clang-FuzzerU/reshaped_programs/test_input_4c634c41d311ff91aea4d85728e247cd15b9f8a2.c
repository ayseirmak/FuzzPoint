#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int i;
double d;

typedef enum { hot, dog, poo, bear } dingos;
typedef enum { janette, laura, amanda } cranberry;

typedef float same1;
typedef float same2;

int main(void) {
    /* Compatible types. */
    assert(__builtin_types_compatible_p (int, const int));
    assert(__builtin_types_compatible_p (int, int));
    assert(!__builtin_types_compatible_p (typeof(hot), int));
    assert(__builtin_types_compatible_p (typeof(hot), typeof(laura)));
    assert(__builtin_types_compatible_p (int[5], int[]));
    assert(__builtin_types_compatible_p (same1, same2));

    /* Incompatible types. */
    assert(!__builtin_types_compatible_p (char *, int));
    assert(!__builtin_types_compatible_p (char *, const char *));
    assert(!__builtin_types_compatible_p (long double, double));
    assert(!__builtin_types_compatible_p (typeof(i), typeof(d)));
    assert(!__builtin_types_compatible_p (typeof(dingos), typeof(cranberry)));
    assert(!__builtin_types_compatible_p (char, int));
    assert(!__builtin_types_compatible_p (char *, char **));

    printf("All type compatibility assertions passed.\n");
    return 0;
}