#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned short int UV __attribute__((vector_size(16)));
typedef short int SV __attribute__((vector_size(16)));

void abort_custom(void) {
    printf("Abort called!\n");
    exit(1);
}

#define TEST(a, b, c, d, e, f, g, h)                                      \
    __attribute__((noinline)) void uq##a##b##c##d##e##f##g##h(UV *x, UV *y) { \
        *x = *y / ((UV){a, b, c, d, e, f, g, h});                           \
    }                                                                      \
                                                                           \
    __attribute__((noinline)) void ur##a##b##c##d##e##f##g##h(UV *x, UV *y) { \
        *x = *y % ((UV){a, b, c, d, e, f, g, h});                           \
    }                                                                      \
                                                                           \
    __attribute__((noinline)) void sq##a##b##c##d##e##f##g##h(SV *x, SV *y) { \
        *x = *y / ((SV){a, b, c, d, e, f, g, h});                           \
    }                                                                      \
                                                                           \
    __attribute__((noinline)) void sr##a##b##c##d##e##f##g##h(SV *x, SV *y) { \
        *x = *y % ((SV){a, b, c, d, e, f, g, h});                           \
    }

#define TESTS                                             \
    TEST(4, 4, 4, 4, 4, 4, 4, 4)                          \
    TEST(1, 4, 2, 8, 16, 64, 32, 128)                     \
    TEST(3, 3, 3, 3, 3, 3, 3, 3)                          \
    TEST(6, 5, 6, 5, 6, 5, 6, 5)                          \
    TEST(14, 14, 14, 6, 14, 6, 14, 14)                    \
    TEST(7, 7, 7, 7, 7, 7, 7, 7)

UV u[] = {
    ((UV){73U, 65531U, 0U, 174U, 921U, 65535U, 17U, 178U}),
    ((UV){1U, 8173U, 65535U, 90372U, 12U, 29612U, 128U, 8912U})};

SV s[] = {
    ((SV){73, -9123, 32761, 8191, 16371, 1201, 12701, 9999}),
    ((SV){9903, -1, -7323, 0, -7, -323, 9124, -9199})};

int main(void) {
    UV ur;
    SV sr;
    int i;

#undef TEST
#define TEST(a, b, c, d, e, f, g, h)                                      \
    uq##a##b##c##d##e##f##g##h(&ur, u + i);                               \
    assert(ur[0] == u[i][0] / a && ur[3] == u[i][3] / d);                 \
    ur##a##b##c##d##e##f##g##h(&ur, u + i);                               \
    assert(ur[0] == u[i][0] % a && ur[3] == u[i][3] % d);

    for (i = 0; i < sizeof(u) / sizeof(u[0]); i++) {
        TESTS
    }

#undef TEST
#define TEST(a, b, c, d, e, f, g, h)                                      \
    sq##a##b##c##d##e##f##g##h(&sr, s + i);                               \
    assert(sr[0] == s[i][0] / a && sr[3] == s[i][3] / d);                 \
    sr##a##b##c##d##e##f##g##h(&sr, s + i);                               \
    assert(sr[0] == s[i][0] % a && sr[3] == s[i][3] % d);

    for (i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
        TESTS
    }

    printf("All tests passed successfully.\n");
    return 0;
}