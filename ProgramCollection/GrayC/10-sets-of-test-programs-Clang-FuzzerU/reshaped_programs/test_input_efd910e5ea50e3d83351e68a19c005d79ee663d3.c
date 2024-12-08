#include <stdio.h>
#include <stdlib.h>

// Define vector types as arrays since __attribute__((vector_size)) is not portable or used properly here.
typedef unsigned short int UV[8];
typedef short int SV[8];

// Abort function to mimic the erroneous condition
void trigger_abort(void) {
    printf("Abort triggered!\n");
    exit(1);
}

// Update TEST macro to create divide and modulus operations using given vector
#define DEFINE_TESTS(a, b, c, d, e, f, g, h) \
void uq##a##b##c##d##e##f##g##h(UV *x, UV *y) { \
    for (int idx = 0; idx < 8; idx++) { \
        (*x)[idx] = (*y)[idx] / ((UV){a, b, c, d, e, f, g, h})[idx]; \
    } \
} \
void ur##a##b##c##d##e##f##g##h(UV *x, UV *y) { \
    for (int idx = 0; idx < 8; idx++) { \
        (*x)[idx] = (*y)[idx] % ((UV){a, b, c, d, e, f, g, h})[idx]; \
    } \
} \
void sq##a##b##c##d##e##f##g##h(SV *x, SV *y) { \
    for (int idx = 0; idx < 8; idx++) { \
        (*x)[idx] = (*y)[idx] / ((SV){a, b, c, d, e, f, g, h})[idx]; \
    } \
} \
void sr##a##b##c##d##e##f##g##h(SV *x, SV *y) { \
    for (int idx = 0; idx < 8; idx++) { \
        (*x)[idx] = (*y)[idx] % ((SV){a, b, c, d, e, f, g, h})[idx]; \
    } \
}

// Define the TESTS as intended
DEFINE_TESTS(5, 4, 4, 4, 4, 4, 4, 4)
DEFINE_TESTS(1, 4, 2, 8, 16, 64, 32, 128)
DEFINE_TESTS(3, 3, 3, 3, 3, 3, 3, 3)
DEFINE_TESTS(6, 5, 6, 5, 6, 5, 6, 5)
DEFINE_TESTS(14, 14, 14, 6, 14, 6, 14, 14)
DEFINE_TESTS(7, 7, 7, 7, 7, 7, 7, 7)

int main() {
    UV u[] = {
        {73U, 65531U, 0U, 174U, 921U, 65535U, 17U, 178U},
        {1U, 8173U, 65535U, 65472U, 12U, 29612U, 128U, 8912U}
    };

    SV s[] = {
        {73, -9123, 32761, 8191, 16371, 1201, 12701, 9999},
        {9903, -1, -7323, 0, -7, -323, 9124, -9199}
    };

    UV ur;
    SV sr;
    int i;

    for (i = 0; i < sizeof(u) / sizeof(u[0]); i++) {
        ur54444444(&ur, u + i);
        if (ur[6] != u[i][6] % 4 || ur[5] != u[i][5] % 4) trigger_abort();

        ur1428166432128(&ur, u + i);
        if (ur[6] != u[i][6] % 32 || ur[5] != u[i][5] % 64) trigger_abort();

        sr54444444(&sr, s + i);
        if (sr[4] != s[i][4] / 4 || sr[3] != s[i][3] % 4) trigger_abort();

        sr75757777(&sr, s + i);
        if (sr[6] != s[i][6] / 7 || sr[5] != s[i][5] / 7) trigger_abort();
    }

    return 0;
}