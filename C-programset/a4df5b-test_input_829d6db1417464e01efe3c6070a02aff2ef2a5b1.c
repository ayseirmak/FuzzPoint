#include <stdio.h>  // For printf
#include <stdlib.h> // For abort
#include <string.h> // For memset

/* Define the necessary structs. */
struct a_short { char c; short s; } s_c_s = { 'a', 13 };
struct a_int { char c; int i; } s_c_i = { 'b', 14 };
struct b_int { short s; int i; } s_s_i = { 15, 16 };
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
struct extra_ldouble { double d; long double ld; } s_d_ld = { 34.0, 35.0 };

typedef struct {
    long r[(19 + sizeof(long)) / (sizeof(long))];
} realvaluetype;

typedef void *tree;

static realvaluetype real_value_from_int_cst(tree x, tree y) {
    realvaluetype r;
    int i;
    for (i = 0; i < sizeof(r.r) / sizeof(long); ++i)
        r.r[i] = -1;
    return r;
}

struct brfic_args {
    tree type;
    tree i;
    realvaluetype d;
};

static void build_real_from_int_cst_1(void *data) {
    struct brfic_args *args = (struct brfic_args *) data;
    args->d = real_value_from_int_cst(args->type, args->i);
}

int main() {
    struct brfic_args args;
    memset(&args, 0, sizeof(args));
    build_real_from_int_cst_1(&args);

    if (s_c_s.c != 'a') { abort(); }
    if (s_c_s.s != 13) { abort(); }
    if (s_c_i.c != 'b') { abort(); }
    if (s_c_i.i != 14) { abort(); }
    if (s_s_i.s != 15) { abort(); }
    if (s_s_i.i != 16) { abort(); }
    if (s_c_f.c != 'c') { abort(); }
    if (s_c_f.f != 17.0) { abort(); }
    if (s_s_f.s != 18) { abort(); }
    if (s_s_f.f != 19.0) { abort(); }
    if (s_c_d.c != 'd') { abort(); }
    if (s_c_d.d != 20.0) { abort(); }
    if (s_s_d.s != 21) { abort(); }
    if (s_s_d.d != 22.0) { abort(); }
    if (s_i_d.i != 23) { abort(); }
    if (s_i_d.d != 24.0) { abort(); }
    if (s_f_d.f != 25.0) { abort(); }
    if (s_f_d.d != 26.0) { abort(); }
    if (s_c_ld.c != 'e') { abort(); }
    if (s_c_ld.ld != 27.0) { abort(); }
    if (s_s_ld.s != 28) { abort(); }
    if (s_s_ld.ld != 29.0) { abort(); }
    if (s_i_ld.i != 30) { abort(); }
    if (s_i_ld.ld != 31.0) { abort(); }
    if (s_f_ld.f != 32.0) { abort(); }
    if (s_f_ld.ld != 33.0) { abort(); }
    if (s_d_ld.d != 34.0) { abort(); }
    if (s_d_ld.ld != 35.0) { abort(); }

    printf("All checks passed.\n");
    return 0;
}