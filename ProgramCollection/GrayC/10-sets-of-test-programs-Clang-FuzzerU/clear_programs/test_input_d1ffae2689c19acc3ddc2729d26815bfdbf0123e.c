#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int UV __attribute__((vector_size (16)));
typedef short int SV __attribute__((vector_size (16)));

struct a_short { char c; short s; } s_c_s = { 'a', 13 };
struct a_int { char c ; int i; } s_c_i = { 'b', 14 };
struct a_float { char c; float f; } s_c_f = { 'c', 17.0 };
struct b_float { short s; float f; } s_s_f = { 18, 19.0 };
struct a_double { char c; double d; } s_c_d = { 'd', 20.0 };
struct b_double { short s; double d; } s_s_d = { 21, 22.0 };
struct c_double { int i; double d; } s_i_d = { 23, 24.0 };
struct d_double { float f; double d; } s_f_d = { 25.0, 26.0 };
struct a_ldouble { char c; long double ld; } s_c_ld = { 'e', 27.0 };
struct b_ldouble { short s; long double ld; } s_s_ld = { 28, 29.0 };
struct c_ldouble { int i; long double ld; } s_i_ld = { 30, 31.0 };
struct d_ldouble { float f; long double ld; } s_f_ld = { 32.0, 33.0 };
struct e_ldouble { double d; long double ld; } s_d_ld = { 34.0, 35.0 };

UV u[] = {
    {73U, 65531U, 0U, 174U, 921U, 65535U, 17U, 178U},
    {1U, 8173U, 65535U, 65472U, 12U, 29612U, 128U, 8912U}
};

SV s[] = {
    {73, -9123, 32761, 8191, 16371, 1201, 12701, 9999},
    {9903, -1, -7323, 0, -7, -323, 9124, -9199}
};

void abort_if_false(int condition) {
    if (!condition) {
        abort();
    }
}

int main() {
    abort_if_false(s_c_s.c == 'a');
    abort_if_false(s_c_s.s == 13);
    abort_if_false(s_c_i.c == 'b');
    abort_if_false(s_c_i.i == 14);

    abort_if_false(s_c_f.c == 'c');
    abort_if_false(s_c_f.f == 17.0f);
    abort_if_false(s_s_f.s == 18);
    abort_if_false(s_s_f.f == 19.0f);

    abort_if_false(s_c_d.c == 'd');
    abort_if_false(s_c_d.d == 20.0);
    abort_if_false(s_s_d.s == 21);
    abort_if_false(s_s_d.d == 22.0);
    abort_if_false(s_i_d.i == 23);
    abort_if_false(s_i_d.d == 24.0);
    abort_if_false(s_f_d.f == 25.0f);
    abort_if_false(s_f_d.d == 26.0);

    abort_if_false(s_c_ld.c == 'e');
    abort_if_false(s_c_ld.ld == 27.0L);
    abort_if_false(s_s_ld.s == 28);
    abort_if_false(s_s_ld.ld == 29.0L);
    abort_if_false(s_i_ld.i == 30);
    abort_if_false(s_i_ld.ld == 31.0L);
    abort_if_false(s_f_ld.f == 32.0f);
    abort_if_false(s_f_ld.ld == 33.0L);
    abort_if_false(s_d_ld.d == 34.0);
    abort_if_false(s_d_ld.ld == 35.0L);

    return 0;
}