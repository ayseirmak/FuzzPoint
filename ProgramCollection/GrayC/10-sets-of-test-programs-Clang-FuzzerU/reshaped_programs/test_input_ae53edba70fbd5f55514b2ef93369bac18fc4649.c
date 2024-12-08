#include <stdio.h>
#include <string.h> // For memset

struct a_short {
    char c;
    short s;
} s_c_s = { 'a', 13 };

struct a_int {
    char c;
    int i;
} s_c_i = { 'b', 14 };

struct b_int {
    short s;
    int i;
} s_s_i = { 15, 16 };

struct a_float {
    char c;
    float f;
} s_c_f = { 'c', 17.0 };

struct b_float {
    short s;
    float f;
} s_s_f = { 18, 19.0 };

struct a_double {
    char c;
    double d;
} s_c_d = { 'd', 20.0 };

struct b_double {
    short s;
    double d;
} s_s_d = { 21, 22.0 };

struct c_double {
    int i;
    double d;
} s_i_d = { 23, 24.0 };

struct d_double {
    float f;
    double d;
} s_f_d = { 25.0, 26.0 };

struct a_ldouble {
    char c;
    long double ld;
} s_c_ld = { 'e', 27.0 };

struct b_ldouble {
    short s;
    long double ld;
} s_s_ld = { 28, 29.0 };

struct c_ldouble {
    int i;
    long double ld;
} s_i_ld = { 30, 31.0 };

struct d_ldouble {
    float f;
    long double ld;
} s_f_ld = { 32.0, 33.0 };

struct e_ldouble {
    double d;
    long double ld;
} s_d_ld = { 34.0, 35.0 };

void custom_abort(const char *message) {
    printf("%s\n", message);
}

typedef struct {
    long r[1]; // Adjusted for simplicity
} realvaluetype;

typedef void *tree;

static realvaluetype real_value_from_int_cst(tree x, tree y) {
    realvaluetype r;
    for (int i = 0; i < 1; ++i) // Fixed size loop since r.r is of size 1
        r.r[i] = -1;
    return r;
}

struct brfic_args {
    tree type;
    tree i;
    realvaluetype d;
};

static void build_real_from_int_cst_1(void *data) {
    struct brfic_args *args = (struct brfic_args *)data;
    args->d = real_value_from_int_cst(args->type, args->i);
}

int main() {
    struct brfic_args args;
    memset(&args, 0, sizeof(args));
    build_real_from_int_cst_1(&args);
    
    if (s_c_s.c != 'a') custom_abort("Assertion failed: s_c_s.c != 'a'");
    if (s_c_s.s != 13) custom_abort("Assertion failed: s_c_s.s != 13");
    if (s_c_i.c != 'b') custom_abort("Assertion failed: s_c_i.c != 'b'");
    if (s_c_i.i != 14) custom_abort("Assertion failed: s_c_i.i != 14");
    if (s_s_i.s != 15) custom_abort("Assertion failed: s_s_i.s != 15");
    if (s_s_i.i != 16) custom_abort("Assertion failed: s_s_i.i != 16");
    if (s_c_f.c != 'c') custom_abort("Assertion failed: s_c_f.c != 'c'");
    if (s_c_f.f != 17.0) custom_abort("Assertion failed: s_c_f.f != 17.0");
    if (s_s_f.s != 18) custom_abort("Assertion failed: s_s_f.s != 18");
    if (s_s_f.f != 19.0) custom_abort("Assertion failed: s_s_f.f != 19.0");
    if (s_c_d.c != 'd') custom_abort("Assertion failed: s_c_d.c != 'd'");
    if (s_c_d.d != 20.0) custom_abort("Assertion failed: s_c_d.d != 20.0");
    if (s_s_d.s != 21) custom_abort("Assertion failed: s_s_d.s != 21");
    if (s_s_d.d != 22.0) custom_abort("Assertion failed: s_s_d.d != 22.0");
    if (s_i_d.i != 23) custom_abort("Assertion failed: s_i_d.i != 23");
    if (s_i_d.d != 24.0) custom_abort("Assertion failed: s_i_d.d != 24.0");
    if (s_f_d.f != 25.0) custom_abort("Assertion failed: s_f_d.f != 25.0");
    if (s_f_d.d != 26.0) custom_abort("Assertion failed: s_f_d.d != 26.0");
    if (s_c_ld.c != 'e') custom_abort("Assertion failed: s_c_ld.c != 'e'");
    if (s_c_ld.ld != 27.0) custom_abort("Assertion failed: s_c_ld.ld != 27.0");
    if (s_s_ld.s != 28) custom_abort("Assertion failed: s_s_ld.s != 28");
    if (s_s_ld.ld != 29.0) custom_abort("Assertion failed: s_s_ld.ld != 29.0");
    if (s_i_ld.i != 30) custom_abort("Assertion failed: s_i_ld.i != 30");
    if (s_i_ld.ld != 31.0) custom_abort("Assertion failed: s_i_ld.ld != 31.0");
    if (s_f_ld.f != 32.0) custom_abort("Assertion failed: s_f_ld.f != 32.0");
    if (s_f_ld.ld != 33.0) custom_abort("Assertion failed: s_f_ld.ld != 33.0");
    if (s_d_ld.d != 34.0) custom_abort("Assertion failed: s_d_ld.d != 34.0");
    if (s_d_ld.ld != 35.0) custom_abort("Assertion failed: s_d_ld.ld != 35.0");
    
    return 0;
}