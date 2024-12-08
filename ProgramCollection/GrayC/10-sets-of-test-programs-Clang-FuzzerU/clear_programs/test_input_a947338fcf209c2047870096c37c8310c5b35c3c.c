#include <stdio.h>  // Required for printf
#include <stdlib.h> // Required for abort

// Definition of various structs with proper alignment
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
} s_c_f = { 'c', 17.0f };

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
} s_f_d = { 31.0f, 32.0 };

int main(void) {
    int a = 1;
    a = ~(a && 1);

    if (!a) {
        printf("Test failed\n");
        abort();
    }

    // Additional checks on initialized struct members
    if (s_c_s.s != 13) { abort(); }
    if (s_c_i.i != 14) { abort(); }
    if (s_s_i.i != 16) { abort(); }
    if (s_c_f.f != 17.0f) { abort(); }
    if (s_c_d.d != 20.0) { abort(); }
    if (s_s_d.d != 22.0) { abort(); }
    if (s_i_d.d != 24.0) { abort(); }
    if (s_f_d.f != 31.0f) { abort(); }
    if (s_f_d.d != 32.0) { abort(); }

    printf("All tests passed.\n");
    return 0;
}