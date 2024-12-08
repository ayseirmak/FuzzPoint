#include <stdio.h>
#include <stdlib.h>  // For `exit`

// Providing definitions for undefined types from the broken source
typedef int int_type1;

int a_f() {
    return 20;
}

int b_f() {
    return 10;
}

#define gen_sw(a) _Generic((a), const char *: 1, default: 8, int: 123)

int main() {
    int i = 0;
    signed long int l = 2;  // Though declared, 'l' is unused in our operations
    struct b titi;
    const int * const ptr = NULL;  // Using a simple NULL pointer for deterministic behavior
    const char *ti = "example";
    int_type1 i2 = 0;  // Initializing this 'int_type1' variable to zero

    // Utilizing _Generic to resolve types according to C11 generic selections
    i = _Generic(0, int: a_f, const int: b_f)();
    printf("%d\n", i);

    i = _Generic(0, int: a_f() / 2, const int: b_f() / 2);
    printf("%d\n", i);

    i = _Generic(ptr, int *: 1, int * const: 2, default: 20);
    printf("%d\n", i);

    i = gen_sw(0);
    printf("%d\n", i);

    i = _Generic(titi, struct a: 1, struct b: 2, default: 0);
    printf("%d\n", i);

    i = _Generic(i2, char: 1, int: 0);
    printf("%d\n", i);

    i = _Generic(0, char: 1, int [4]: 2, default: 5);
    printf("%d\n", i);

    i = _Generic(17, int: 1, int **: 2);
    printf("%d\n", i);

    // Part of the original program checking floating-point calculations
    long double x = 0x1.0p-500L;
    x *= 0x1.0p-522L;
    if (x != 0x1.0p-1022L) {
        abort();
    }

    return 0;
}