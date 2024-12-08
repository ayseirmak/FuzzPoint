#include <stdio.h>
#include <stdlib.h>

// Define the first version of struct S
struct S1 {
    double for_alignment;
    struct { int x, y, z; } a[16];
};

// Define operation on the first version of struct S
void f(struct S1 *s) __attribute__((noinline));

void f(struct S1 *s) {
    unsigned int i;
    for (i = 0; i < 16; ++i) {
        s->a[i].x = 0;
        s->a[i].z = 0;
    }
}

// Define the second version of struct S
struct S2 {
    unsigned short s[64];
};

// Define function foo with operations over struct S2
__attribute__((noinline, noclone)) void foo(struct S2 *s) {
    unsigned int i;
    // This function is unchanged from the original (static inputs)
    static int arr[2][3][5] = {
        {{ 0, 0, 3, 5, 0 }, { 1, 0, 0, 6, 7 }},
        {{ 1, 2, 0, 0, 7 }, { 0, 0, 0, 0, 0 }}
    };

    (void)arr; // suppress unused variable warning

    for (i = 0; i < 64; i++) {
        s->s[i] = i + ((64 - i) << 8);
    }
}

int main(void) {
    struct S1 s1;
    struct S2 s2;

    // Call function for struct S1
    f(&s1);

    // Call function for struct S2
    foo(&s2);

    unsigned int i;
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    for (i = 0; i < 64; i++) {
        if (s2.s[i] != (64 - i) + (i << 8)) {
            printf("Error: Mismatch at index %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    for (i = 0; i < 64; i++) {
        if (s2.s[i] != i + ((64 - i) << 8)) {
            printf("Error: Mismatch at index %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
#endif

    printf("Program executed successfully.\n");
    return 0;
}