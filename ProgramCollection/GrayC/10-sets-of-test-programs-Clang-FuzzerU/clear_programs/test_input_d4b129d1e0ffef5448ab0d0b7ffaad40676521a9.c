#include <stdio.h>
#include <stdlib.h>

// Define structures for vector types according to common practice
typedef unsigned int UV __attribute__((vector_size(16)));
typedef int SV __attribute__((vector_size(16)));

// Function to compute a complex number with real and imaginary parts
_Complex double foo_double(int x) {
    _Complex double r;
    __real__ r = x + 1;
    __imag__ r = x - 1;
    return r;
}

void bar_double(double *x) {
    *x = __real__ foo_double(5);
}

void baz_double(double *x) {
    *x = __imag__ foo_double(0);
}

// Macro to define test functions for division and modulus operations
#define TEST(a, b, c, d)                   \
void uq##a##b##c##d(UV *x, UV *y) {       \
    *x = *y / ((UV){a, b, c, d});         \
}                                         \
void ur##a##b##c##d(UV *x, UV *y) {       \
    *x = *y % ((UV){a, b, c, d});         \
}                                         \
void sq##a##b##c##d(SV *x, SV *y) {       \
    *x = *y / ((SV){a, b, c, d});         \
}                                         \
void sr##a##b##c##d(SV *x, SV *y) {       \
    *x = *y % ((SV){a, b, c, d});         \
}

// Apply the TEST macro to create specific test functions
TEST(4, 4, 4, 4)
TEST(1, 4, 2, 8)
TEST(3, 3, 3, 3)
TEST(6, 5, 6, 5)
TEST(14, 14, 14, 6)
TEST(7, 7, 7, 7)

UV u[] = {
    {73U, 65531U, 0U, 174U},
    {1U, 8173U, ~0U, ~0U - 63U}
};
SV s[] = {
    {73, -9123, 32761, 8191},
    {9903, -1, -7323, 0}
};

int main() {
    UV ur;
    SV sr;
    int i;

    for (i = 0; i < sizeof(u) / sizeof(u[0]); ++i) {
        // Test cases for unsigned vectors
        uq4444(&ur, &u[i]);
        ur4444(&ur, &u[i]);

        // Test cases for signed vectors
        sq4444(&sr, &s[i]);
        sr4444(&sr, &s[i]);
    }
    
    double real_part, imag_part;
    bar_double(&real_part);
    baz_double(&imag_part);

    printf("Real part from foo_double: %f\n", real_part);
    printf("Imaginary part from foo_double: %f\n", imag_part);

    return 0;
}