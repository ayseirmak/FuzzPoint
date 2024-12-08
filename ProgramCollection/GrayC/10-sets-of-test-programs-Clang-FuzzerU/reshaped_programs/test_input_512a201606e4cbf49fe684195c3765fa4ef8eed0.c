#include <stdio.h>
#include <stdlib.h>

unsigned int count = 0;
unsigned int arr[10];

typedef struct {
    int c;
    int d;
} tiny;

unsigned int incr(void) {
    static unsigned int counter = 0;
    return ++counter;
}

unsigned int myrnd(void) {
    static unsigned int s = 1388815473;
    s *= 1103515245;
    s += 12345;
    // Deterministic calculation based on a fixed seed
    return (s / 65536) % 2048;
}

#define T(S)                        \
    struct S s##S;                  \
    struct S retme##S(struct S x) { \
        return x;                   \
    }

struct bitfield1 {
    unsigned int a : 5;
    unsigned int b : 6;
    unsigned int c : 21;
};

struct bitfield2 {
    unsigned short a : 3;
    unsigned short b : 10;
    unsigned short c : 3;
};

T(bitfield1)
T(bitfield2)

void testBitfield1(void) {
    struct bitfield1 bf1 = {1, 2, 3};
    struct bitfield1 result = retmebitfield1(bf1);
    if (result.a != 1 || result.b != 2 || result.c != 3) {
        printf("Test failed for bitfield1\n");
        exit(EXIT_FAILURE);
    }
    printf("Test passed for bitfield1\n");
}

void testBitfield2(void) {
    struct bitfield2 bf2 = {4, 5, 6};
    struct bitfield2 result = retmebitfield2(bf2);
    if (result.a != 4 || result.b != 5 || result.c != 6) {
        printf("Test failed for bitfield2\n");
        exit(EXIT_FAILURE);
    }
    printf("Test passed for bitfield2\n");
}

int main(void) {
    arr[count++] = incr();
    printf("Count after first increment: %u\n", count);

    tiny x[3] = {{10, 20}, {11, 21}, {12, 22}};
    for (int i = 0; i < 3; i++) {
        printf("Tiny[%d]: c = %d, d = %d\n", i, x[i].c, x[i].d);
    }

    testBitfield1();
    testBitfield2();

    printf("Deterministic random value: %u\n", myrnd());

    exit(EXIT_SUCCESS);
}