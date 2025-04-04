#include <stdio.h>

struct a_short { char c; short s; };
struct a_int { char c; int i; };
struct b_int { short s; int i; };
struct a_float { char c; float f; };
struct b_float { short s; float f; };
struct a_double { char c; double d; };
struct b_double { short s; double d; };
struct c_double { int i; double d; };
struct d_double { float f; double d; };
struct a_ldouble { char c; long double ld; };
struct b_ldouble { short s; long double ld; };
struct c_ldouble { int i; long double ld; };
struct d_ldouble { float f; long double ld; };
struct e_ldouble { double d; long double ld; };

int main() {
    struct a_short s_c_s = { 'a', 13 };
    struct a_int s_c_i = { 'b', 14 };
    struct b_int s_s_i = { 15, 16 };
    struct a_float s_c_f = { 'c', 17.0f };
    struct b_float s_s_f = { 18, 19.0f };
    struct a_double s_c_d = { 'd', 20.0 };
    struct b_double s_s_d = { 21, 22.0 };
    struct c_double s_i_d = { 23, 24.0 };
    struct d_double s_f_d = { 25.0f, 26.0 };
    struct a_ldouble s_c_ld = { 'e', 27.0L };
    struct b_ldouble s_s_ld = { 28, 29.0L };
    struct c_ldouble s_i_ld = { 30, 31.0L };
    struct d_ldouble s_f_ld = { 32.0f, 33.0L };
    struct e_ldouble s_d_ld = { 34.0, 35.0L };

    if (s_c_s.c != 'a') { printf("Error: s_c_s.c\n"); }
    if (s_c_s.s != 13) { printf("Error: s_c_s.s\n"); }
    if (s_c_i.c != 'b') { printf("Error: s_c_i.c\n"); }
    if (s_c_i.i != 14) { printf("Error: s_c_i.i\n"); }
    if (s_s_i.s != 15) { printf("Error: s_s_i.s\n"); }
    if (s_s_i.i != 16) { printf("Error: s_s_i.i\n"); }
    if (s_c_f.c != 'c') { printf("Error: s_c_f.c\n"); }
    if (s_c_f.f != 17.0f) { printf("Error: s_c_f.f\n"); }
    if (s_s_f.s != 18) { printf("Error: s_s_f.s\n"); }
    if (s_s_f.f != 19.0f) { printf("Error: s_s_f.f\n"); }
    if (s_c_d.c != 'd') { printf("Error: s_c_d.c\n"); }
    if (s_c_d.d != 20.0) { printf("Error: s_c_d.d\n"); }
    if (s_s_d.s != 21) { printf("Error: s_s_d.s\n"); }
    if (s_s_d.d != 22.0) { printf("Error: s_s_d.d\n"); }
    if (s_i_d.i != 23) { printf("Error: s_i_d.i\n"); }
    if (s_i_d.d != 24.0) { printf("Error: s_i_d.d\n"); }
    if (s_f_d.f != 25.0f) { printf("Error: s_f_d.f\n"); }
    if (s_f_d.d != 26.0) { printf("Error: s_f_d.d\n"); }
    if (s_c_ld.c != 'e') { printf("Error: s_c_ld.c\n"); }
    if (s_c_ld.ld != 27.0L) { printf("Error: s_c_ld.ld\n"); }
    if (s_s_ld.s != 28) { printf("Error: s_s_ld.s\n"); }
    if (s_s_ld.ld != 29.0L) { printf("Error: s_s_ld.ld\n"); }
    if (s_i_ld.i != 30) { printf("Error: s_i_ld.i\n"); }
    if (s_i_ld.ld != 31.0L) { printf("Error: s_i_ld.ld\n"); }
    if (s_f_ld.f != 32.0f) { printf("Error: s_f_ld.f\n"); }
    if (s_f_ld.ld != 33.0L) { printf("Error: s_f_ld.ld\n"); }
    if (s_d_ld.d != 34.0) { printf("Error: s_d_ld.d\n"); }
    if (s_d_ld.ld != 35.0L) { printf("Error: s_d_ld.ld\n"); }

    return 0;
}