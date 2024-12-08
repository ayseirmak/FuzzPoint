#include <stdio.h>

#define VECTOR_SIZE_CHAR 16
#define VECTOR_SIZE_SHORT 8
#define VECTOR_SIZE_INT 4
#define VECTOR_SIZE_LONG 2

void check_char_vector(const char *v0, const char *v1, char expected, char operator) {
    for (int i = 0; i < VECTOR_SIZE_CHAR; i++) {
        if (v1[i] != v0[i] + expected) {
            printf("Check failed for char vector at index %d\n", i);
            return;
        }
    }
}

void check_short_vector(const short *v0, const short *v1, short expected, char operator) {
    for (int i = 0; i < VECTOR_SIZE_SHORT; i++) {
        if (v1[i] != v0[i] + expected) {
            printf("Check failed for short vector at index %d\n", i);
            return;
        }
    }
}

void check_int_vector(const int *v0, const int *v1, int expected, char operator) {
    for (int i = 0; i < VECTOR_SIZE_INT; i++) {
        if (v1[i] != v0[i] * expected) {
            printf("Check failed for int vector at index %d\n", i);
            return;
        }
    }
}

void check_long_vector(const long *v0, const long *v1, long expected, char operator) {
    for (int i = 0; i < VECTOR_SIZE_LONG; i++) {
        if (v1[i] != v0[i] * expected) {
            printf("Check failed for long vector at index %d\n", i);
            return;
        }
    }
}

int main(void) {
    char c0[VECTOR_SIZE_CHAR] = {1, 1, 2, 3, 4, 5, 6, 7, 1, 1, 2, 3, 4, 5, 6, 7};
    char c1[VECTOR_SIZE_CHAR];
    short s0[VECTOR_SIZE_SHORT] = {1, 1, 2, 3, 4, 5, 6, 7};
    short s1[VECTOR_SIZE_SHORT];
    int i0[VECTOR_SIZE_INT] = {1, 1, 2, 3};
    int i1[VECTOR_SIZE_INT];
    long l0[VECTOR_SIZE_LONG] = {1, 1};
    long l1[VECTOR_SIZE_LONG];

    char vchr_val = (char)42;
    short vsrt_val = (short)42;
    int vint_val = (int)43;

    // Vector operations
    for (int i = 0; i < VECTOR_SIZE_CHAR; i++) {
        c1[i] = vchr_val + c0[i];
    }
    check_char_vector(c0, c1, vchr_val, '+');

    for (int i = 0; i < VECTOR_SIZE_SHORT; i++) {
        s1[i] = vsrt_val + s0[i];
    }
    check_short_vector(s0, s1, vsrt_val, '+');

    for (int i = 0; i < VECTOR_SIZE_INT; i++) {
        i1[i] = vint_val * i0[i];
    }
    check_int_vector(i0, i1, vint_val, '*');

    for (int i = 0; i < VECTOR_SIZE_LONG; i++) {
        l1[i] = vsrt_val * l0[i];
    }
    check_long_vector(l0, l1, vsrt_val, '*');

    return 0;
}