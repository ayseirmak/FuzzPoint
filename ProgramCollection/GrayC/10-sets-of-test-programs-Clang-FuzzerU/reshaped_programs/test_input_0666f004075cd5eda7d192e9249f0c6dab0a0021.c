#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function prototypes
static double f(float a);
static double (*fp)(float a);

// Function implementation
static double f(float a) {
    return a;
}

int main() {
    // Assign the function pointer
    fp = f;

    // Call the function using the pointer and check the result
    // Adjusted to be a deterministic check with fixed value
    double result = fp(1.0f);
    if (result != 1.0) {
        printf("Error: Function pointer call returned incorrect result.\n");
        abort();
    }

    // Structure alignment and initialization checks
    struct a_short { char c; short s; } s_c_s = { 'a', 13 };
    struct a_int { char c; int i; } s_c_i = { 'b', 14 };
    struct b_int { short s; int i; } s_s_i = { 15, 16 };
    struct a_float { char c; float f; } s_c_f = { 'c', 17.0 };
    struct b_float { short s; float f; } s_s_f = { 18, 19.0 };
    struct a_double { char c; double d; } s_c_d = { 'd', 20.0 };
    struct b_double { short s; double d; } s_s_d = { 21, 22.0 };
    struct i_double { int i; double d; } s_i_d = { 23, 24.0 };
    struct f_double { float f; double d; } s_f_d = { 25.0, 26.0 };
    struct a_long_double { char c; long double ld; } s_c_ld = { 'e', 27.0 };
    struct s_long_double { short s; long double ld; } s_s_ld = { 28, 29.0 };
    struct i_long_double { int i; long double ld; } s_i_ld = { 30, 31.0 };
    struct f_long_double { float f; long double ld; } s_f_ld = { 32.0, 33.0 };
    struct d_long_double { double d; long double ld; } s_d_ld = { 34.0, 35.0 };

    // Assertions replace previous abort checks
    assert(s_c_s.c == 'a');
    assert(s_c_s.s == 13);
    assert(s_c_i.c == 'b');
    assert(s_c_i.i == 14);
    assert(s_s_i.s == 15);
    assert(s_s_i.i == 16);
    assert(s_c_f.c == 'c');
    assert(s_c_f.f == 17.0);
    assert(s_s_f.s == 18);
    assert(s_s_f.f == 19.0);
    assert(s_c_d.c == 'd');
    assert(s_c_d.d == 20.0);
    assert(s_s_d.s == 21);
    assert(s_s_d.d == 22.0);
    assert(s_i_d.i == 23);
    assert(s_i_d.d == 24.0);
    assert(s_f_d.f == 25.0);
    assert(s_f_d.d == 26.0);
    assert(s_c_ld.c == 'e');
    assert(s_c_ld.ld == 27.0);
    assert(s_s_ld.s == 28);
    assert(s_s_ld.ld == 29.0);
    assert(s_i_ld.i == 30);
    assert(s_i_ld.ld == 31.0);
    assert(s_f_ld.f == 32.0);
    assert(s_f_ld.ld == 33.0);
    assert(s_d_ld.d == 34.0);
    assert(s_d_ld.ld == 35.0);

    printf("All checks passed successfully.\n");
    return 0;
}