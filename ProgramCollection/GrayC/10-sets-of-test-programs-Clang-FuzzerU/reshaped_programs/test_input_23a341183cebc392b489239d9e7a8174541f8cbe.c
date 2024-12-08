#include <stdio.h>
#include <stdlib.h>

// Defining structures
struct a_short { char c; short s; };
struct a_int { char c; int i; };
struct b_int { short s; int i; };
struct a_float { char c; float f; };
struct b_float { short s; float f; };
struct a_double { char c; double d; };
struct a_ldouble { char c; long double ld; };
struct b_ldouble { short s; long double ld; };
struct c_ldouble { int i; long double ld; };

// Defining and initializing structs
struct a_short s_c_s = { 'a', 13 };
struct a_int s_c_i = { 'b', 14 };
struct b_int s_s_i = { 89, 16 };
struct a_float s_c_f = { 'c', 17.0 };
struct b_float s_s_f = { 18, 19.0 };
struct a_double s_c_d = { 'd', 20.0 };
struct b_double s_s_d = { 21, 22.0 };
struct a_ldouble s_c_ld = { 'e', 27.0 };
struct b_ldouble s_s_ld = { 28, 29.0 };
struct c_ldouble s_i_d = { 23, 24.0 };

// Function prototypes for array operations
void f1 (void);
void f2 (void);
void f3 (void);
void f4 (void);
void f5 (void);
void f6 (void);
void f7 (void);
void f8 (void);
void f9 (void);
void f10 (void);
void f11 (void);
void f12 (void);

// Defining necessary arrays and constants
#define N 10
int a[N];
unsigned int b[N];
int c[N];
unsigned int d[N];

void init_arrays(void) {
    for (int i = 0; i < N; i++) {
        a[i] = i - N / 2;
        b[i] = i;
    }
    a[0] = -__INT_MAX__ - 1;
    a[1] = -__INT_MAX__;
    a[N - 1] = __INT_MAX__;
    b[N - 1] = ~0U;
}

__attribute__((noinline, noclone)) void f1(void) {
    for (int i = 0; i < N; i++) {
        c[i] = a[i] % 3;
    }
}

__attribute__((noinline, noclone)) void f2(void) {
    for (int i = 0; i < N; i++) {
        d[i] = b[i] % 3;
    }
}

int main(void) {
    init_arrays();

    f1();
    f2();
    for (int i = 0; i < N; i++) {
        if (c[i] != a[i] % 3 || d[i] != b[i] % 3) {
            printf("Test failure at index: %d\n", i);
            abort();
        }
    }

    f3();
    f4();
    for (int i = 0; i < N; i++) {
        if (c[i] != a[i] % 18 || d[i] != b[i] % 18) {
            printf("Test failure at index: %d\n", i);
            abort();
        }
    }

    f5();
    f6();
    for (int i = 0; i < N; i++) {
        if (c[i] != a[i] % 19 || d[i] != b[i] % 19) {
            printf("Test failure at index: %d\n", i);
            abort();
        }
    }

#if __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8
    f7();
    f8();
    for (int i = 0; i < N; i++) {
        if (c[i] != a[i] % 3 || d[i] != b[i] % 3) {
            printf("Test failure at index: %d\n", i);
            abort();
        }
    }

    f9();
    f10();
    for (int i = 0; i < N; i++) {
        if (c[i] != a[i] % 18 || d[i] != b[i] % 18) {
            printf("Test failure at index: %d\n", i);
            abort();
        }
    }

    f11();
    f12();
    for (int i = 0; i < N; i++) {
        if (c[i] != a[i] % 19 || d[i] != b[i] % 19) {
            printf("Test failure at index: %d\n", i);
            abort();
        }
    }
#endif

    return 0;
}