#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int i;
double d;

typedef enum { hot, dog, poo, bear } dingos;
typedef enum { janette, laura, amanda } cranberry;

typedef float same1;
typedef float same2;

int static_foo(int b, int c) {
    if (b != 0 && b != 1 && c != 0) {
        b = 0;
    }
    return b;
}

int main(void) {
    // Check compatible types
    assert(__builtin_types_compatible_p(int, const int));
    assert(__builtin_types_compatible_p(typeof(hot), int));
    assert(__builtin_types_compatible_p(typeof(hot), typeof(laura)));
    assert(__builtin_types_compatible_p(int[5], int[]));
    assert(__builtin_types_compatible_p(same1, same2));

    // Check incompatible types
    assert(!__builtin_types_compatible_p(char *, int));
    assert(!__builtin_types_compatible_p(typeof(dingos), typeof(cranberry)));
    assert(!__builtin_types_compatible_p(char, int));

    // Test static function logic
    assert(static_foo(1, 2) != 0);

    printf("All assertions passed.\n");
    exit(0);
}