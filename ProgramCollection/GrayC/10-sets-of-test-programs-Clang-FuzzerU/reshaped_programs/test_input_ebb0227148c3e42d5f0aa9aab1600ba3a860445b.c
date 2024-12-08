#include <stdio.h>
#include <stdlib.h>

// Function to perform arithmetic operations
long double f(long double d, int i) {
    long double e;
    d = -d;
    e = d;
    if (i == 1) {
        d *= 2;
    }
    // Perform repetitive operation
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    return d;
}

__attribute__((noinline)) int bar(long long x) {
    long long y = (x >> 31LL) & 1LL;
    if (y == 0LL) {
        return 0;
    }
    return -0;
}

int main() {
    // Check the function f with fixed inputs
    if (!(int)(f(2.0L, 1))) {
        abort();
    }

    // Check size of long long
    if (sizeof(long long) != 8) {
        return 0;
    }

    // Check function bar with a test value
    if (bar(0x1682a9aaaULL)) {
        abort();
    }

    // Struct checks
    struct a_short { char c; short s; } s_c_s = { 'a', 13 };
    struct a_int { char c; int i; } s_c_i = { 'b', 14 };
    struct b_int { short s; int i; } s_s_i  = { 89, 16 };
    struct a_float { char c; float f; } s_c_f = { 'c', 17.0 };
    struct b_float { short s; float f; } s_s_f = { 18, 19.0 };
    struct a_double { char c; double d; } s_c_d = { 'd', 34.0 };

    if (s_c_s.c != 'a') { abort(); }
    if (s_c_s.s != 13) { abort(); }
    if (s_c_i.c != 'b') { abort(); }
    if (s_c_i.i != 14) { abort(); }
    if (s_s_i.s != 89) { abort(); }
    if (s_s_i.i != 16) { abort(); }
    if (s_c_f.c != 'c') { abort(); }
    if (s_c_f.f != 17.0) { abort(); }
    if (s_s_f.s != 18) { abort(); }
    if (s_s_f.f != 19.0) { abort(); }
    if (s_c_d.c != 'd') { abort(); }
    if (s_c_d.d != 34.0) { abort(); }

    return 0;
}