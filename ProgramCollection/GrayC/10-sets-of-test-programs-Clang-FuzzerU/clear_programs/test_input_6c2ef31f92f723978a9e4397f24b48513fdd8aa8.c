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
    // Compatibility check using the built-in types compatibility function.
    // Ensure compatibility check leads to a constant defining an array size.
    float rootbeer[__builtin_types_compatible_p(int, typeof(i)) ? 1 : -1];

    // Asserting different type compatibilities
    assert(__builtin_types_compatible_p(int, typeof(i)));
    assert(!__builtin_types_compatible_p(typeof(dingos), typeof(cranberry)));
    assert(!__builtin_types_compatible_p(char, int));
    assert(!__builtin_types_compatible_p(char *, char **));

    // If assertions hold, program succeeds without errors.
    printf("All type compatibility checks passed.\n");

    return 0;
}