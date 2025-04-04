#include <stdio.h>  // For printf (used for logging the results)
#include <stdlib.h> // For abort (used here to mimic the original abort behavior)

// Struct definitions with initialized values
struct a_short { char c; short s; } s_c_s = { 'a', 13 };
struct a_int { char c; int i; } s_c_i = { 'b', 14 };
struct b_int { short s; int i; } s_s_i = { 15, 16 };
struct a_float { char c; float f; } s_c_f = { 'c', 17.0f };
struct b_float { short s; float f; } s_s_f = { 18, 19.0f };
struct a_double { char c; double d; } s_c_d = { 'd', 20.0 };
struct b_double { short s; double d; } s_s_d = { 21, 22.0 };
struct c_double { int i; double d; } s_i_d = { 23, 24.0 };
struct d_double { float f; double d; } s_f_d = { 25.0f, 26.0 };
struct a_ldouble { char c; long double ld; } s_c_ld = { 'e', 27.0L };
struct b_ldouble { int i; long double ld; } s_i_ld = { 30, 31.0L };
struct d_ldouble { float f; long double ld; } s_f_ld = { 32.0f, 33.0L };
struct e_ldouble { double d; long double ld; } s_d_ld = { 34.0, 35.0L };

int main() {
    // Assertions using printf
    if (s_c_s.c != 'a') { printf("Assertion failed: s_c_s.c\n"); abort(); }
    if (s_c_s.s != 13) { printf("Assertion failed: s_c_s.s\n"); abort(); }
    if (s_c_i.c != 'b') { printf("Assertion failed: s_c_i.c\n"); abort(); }
    if (s_c_i.i != 14) { printf("Assertion failed: s_c_i.i\n"); abort(); }
    if (s_s_i.s != 15) { printf("Assertion failed: s_s_i.s\n"); abort(); }
    if (s_s_i.i != 16) { printf("Assertion failed: s_s_i.i\n"); abort(); }
    if (s_c_f.c != 'c') { printf("Assertion failed: s_c_f.c\n"); abort(); }
    if (s_c_f.f != 17.0f) { printf("Assertion failed: s_c_f.f\n"); abort(); }
    if (s_s_f.s != 18) { printf("Assertion failed: s_s_f.s\n"); abort(); }
    if (s_s_f.f != 19.0f) { printf("Assertion failed: s_s_f.f\n"); abort(); }
    if (s_c_d.c != 'd') { printf("Assertion failed: s_c_d.c\n"); abort(); }
    if (s_c_d.d != 20.0) { printf("Assertion failed: s_c_d.d\n"); abort(); }
    if (s_s_d.s != 21) { printf("Assertion failed: s_s_d.s\n"); abort(); }
    if (s_s_d.d != 22.0) { printf("Assertion failed: s_s_d.d\n"); abort(); }
    if (s_i_d.i != 23) { printf("Assertion failed: s_i_d.i\n"); abort(); }
    if (s_i_d.d != 24.0) { printf("Assertion failed: s_i_d.d\n"); abort(); }
    if (s_f_d.f != 25.0f) { printf("Assertion failed: s_f_d.f\n"); abort(); }
    if (s_f_d.d != 26.0) { printf("Assertion failed: s_f_d.d\n"); abort(); }
    if (s_c_ld.c != 'e') { printf("Assertion failed: s_c_ld.c\n"); abort(); }
    if (s_c_ld.ld != 27.0L) { printf("Assertion failed: s_c_ld.ld\n"); abort(); }
    if (s_i_ld.i != 30) { printf("Assertion failed: s_i_ld.i\n"); abort(); }
    if (s_i_ld.ld != 31.0L) { printf("Assertion failed: s_i_ld.ld\n"); abort(); }
    if (s_f_ld.f != 32.0f) { printf("Assertion failed: s_f_ld.f\n"); abort(); }
    if (s_f_ld.ld != 33.0L) { printf("Assertion failed: s_f_ld.ld\n"); abort(); }
    if (s_d_ld.d != 34.0) { printf("Assertion failed: s_d_ld.d\n"); abort(); }
    if (s_d_ld.ld != 35.0L) { printf("Assertion failed: s_d_ld.ld\n"); abort(); }

    printf("All assertions passed.\n");

    return 0;
}