#include <stdio.h>

const int a = 0;

struct a {
    int a;
};

struct b {
    int a;
};

int a_f() {
    return 20;
}

int b_f() {
    return 10;
}

typedef int (*fptr)(int);
int foo(int i) {
    return i;
}

typedef int int_type1;

#define gen_sw(a) _Generic(a, const char *: 1, default: 8, int: 123)

int main() {
    int i = 0;
    signed long int l = 2;
    struct b titi = {0};  // Initialize structure
    const int *const ptr = &a;  // Initialize pointer to a valid address
    const char *ti = "test";  // Initialize with a fixed string
    int_type1 i2 = 0;  // Initialize with a static value

    i = _Generic(a, int: a_f, const int: b_f)();
    printf("%d\n", i);

    i = _Generic(a, int: a_f() / 2, const int: b_f)();
    printf("%d\n", i);

    i = _Generic(ptr, int *: 1, int *const: 2, default: 20);
    printf("%d\n", i);

    i = gen_sw(a);
    printf("%d\n", i);

    i = _Generic(titi, struct a: 1, struct b: 2, default: 20);
    printf("%d\n", i);

    i = _Generic(i2, char: 1, int: 0);
    printf("%d\n", i);

    // _Generic usage incompatible with arrays in standard C
    i = _Generic(a, char: 1, int[4]: 2, default: 5);
    printf("%d\n", i);

    i = _Generic(17, int: 1, int **: 2);
    printf("%d\n", i);

    i = _Generic(17L, int: 1, long: 2, long long: 3);
    printf("%d\n", i);

    i = _Generic("17, io", char *: 3, const char *: 1);
    printf("%d\n", i);

    i = _Generic(ti, const unsigned char *: 1, const char *: 4, char *: 3,
                 const signed char *: 2);
    printf("%d\n", i);

    printf("%s\n", _Generic(i + 2L, long: "long", int: "int",
                             long long: "long long"));

    i = _Generic(l, long: 1, int: 2);
    printf("%d\n", i);

    i = _Generic(foo, fptr: 3, int: 4);
    printf("%d\n", i);

    // Print the sizes of various types, using default initialization.
    char a_var = 'a';
    int b_var = 42;
    double c_var = 3.14;

    printf("Size of char: %d\n", (int)sizeof(a_var));
    printf("Size of int: %d\n", (int)sizeof(b_var));
    printf("Size of double: %d\n", (int)sizeof(c_var));

    printf("Size of !a_var: %d\n", (int)sizeof(!a_var));

    return 0;
}