#include <stdio.h>
#include <stdlib.h>

// Avoids non-standard inline attribute usage
static long double f(long double d, int i) {
    long double e;
    d = -d;
    e = d;
    if (i == 1) {
        d *= 2;
    }
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    return d;
}

static int bar(long long x) {
    long long y = (x >> 31LL) & 1LL;
    if (y == 0LL) {
        return 0;
    }
    return 0; // adjusted for clarity
}

// Struct initializations
struct a_char_short { char c; short s; } s_c_s = { 'a', 13 };
struct a_char_int { char c; int i; } s_c_i = { 'b', 14 };
struct b_short_int { short s; int i; } s_s_i = { 15, 16 };
struct a_char_float { char c; float f; } s_c_f = { 'c', 17.0f };
struct b_short_float { short s; float f; } s_s_f = { 18, 19.0f };
struct a_char_double { char c; double d; } s_c_d = { 'd', 20.0 };
struct b_short_double { short s; double d; } s_s_d = { 21, 22.0 };

int main(void) {
    if (!(int)(f(2.0L, 1))) {
        abort();
    }

    if (s_c_s.c != 'a') { abort(); }
    if (s_c_s.s != 13) { abort(); }
    if (s_c_i.c != 'b') { abort(); }
    if (s_c_i.i != 14) { abort(); }
    if (s_s_i.s != 15) { abort(); }
    if (s_s_i.i != 16) { abort(); }
    if (s_c_f.c != 'c') { abort(); }
    if (s_c_f.f != 17.0f) { abort(); }
    if (s_s_f.s != 18) { abort(); }
    if (s_s_f.f != 19.0f) { abort(); }
    if (s_c_d.c != 'd') { abort(); }
    if (s_c_d.d != 20.0) { abort(); }
    if (s_s_d.s != 21) { abort(); }
    if (s_s_d.d != 22.0) { abort(); }

    return 0;
}