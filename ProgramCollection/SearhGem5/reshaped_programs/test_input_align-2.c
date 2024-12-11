#include <stdio.h>
#include <stdlib.h>

struct a_short { char c; short s; } s_c_s;
struct a_int { char c ; int i; } s_c_i;
struct b_int { short s; int i; } s_s_i;
struct a_float { char c; float f; } s_c_f;
struct b_float { short s; float f; } s_s_f;
struct a_double { char c; double d; } s_c_d;
struct b_double { short s; double d; } s_s_d;
struct c_double { int i; double d; } s_i_d;
struct d_double { float f; double d; } s_f_d;
struct a_ldouble { char c; long double ld; } s_c_ld;
struct b_ldouble { short s; long double ld; } s_s_ld;
struct c_ldouble { int i; long double ld; } s_i_ld;
struct d_ldouble { float f; long double ld; } s_f_ld;
struct e_ldouble { double d; long double ld; } s_d_ld;

int main() {
  // Initializing the structures with predefined values
  s_c_s.c = 'a';
  s_c_s.s = 13;
  s_c_i.c = 'b';
  s_c_i.i = 14;
  s_s_i.s = 15;
  s_s_i.i = 16;
  s_c_f.c = 'c';
  s_c_f.f = 17.0f;
  s_s_f.s = 18;
  s_s_f.f = 19.0f;
  s_c_d.c = 'd';
  s_c_d.d = 20.0;
  s_s_d.s = 21;
  s_s_d.d = 22.0;
  s_i_d.i = 23;
  s_i_d.d = 24.0;
  s_f_d.f = 25.0f;
  s_f_d.d = 26.0;
  s_c_ld.c = 'e';
  s_c_ld.ld = 27.0;
  s_s_ld.s = 28;
  s_s_ld.ld = 29.0;
  s_i_ld.i = 30;
  s_i_ld.ld = 31.0;
  s_f_ld.f = 32.0f;
  s_f_ld.ld = 33.0;
  s_d_ld.d = 34.0;
  s_d_ld.ld = 35.0;

  // Check if all values are properly assigned
  if (s_c_s.c != 'a') printf("Test failed: s_c_s.c\n");
  if (s_c_s.s != 13) printf("Test failed: s_c_s.s\n");
  if (s_c_i.c != 'b') printf("Test failed: s_c_i.c\n");
  if (s_c_i.i != 14) printf("Test failed: s_c_i.i\n");
  if (s_s_i.s != 15) printf("Test failed: s_s_i.s\n");
  if (s_s_i.i != 16) printf("Test failed: s_s_i.i\n");
  if (s_c_f.c != 'c') printf("Test failed: s_c_f.c\n");
  if (s_c_f.f != 17.0f) printf("Test failed: s_c_f.f\n");
  if (s_s_f.s != 18) printf("Test failed: s_s_f.s\n");
  if (s_s_f.f != 19.0f) printf("Test failed: s_s_f.f\n");
  if (s_c_d.c != 'd') printf("Test failed: s_c_d.c\n");
  if (s_c_d.d != 20.0) printf("Test failed: s_c_d.d\n");
  if (s_s_d.s != 21) printf("Test failed: s_s_d.s\n");
  if (s_s_d.d != 22.0) printf("Test failed: s_s_d.d\n");
  if (s_i_d.i != 23) printf("Test failed: s_i_d.i\n");
  if (s_i_d.d != 24.0) printf("Test failed: s_i_d.d\n");
  if (s_f_d.f != 25.0f) printf("Test failed: s_f_d.f\n");
  if (s_f_d.d != 26.0) printf("Test failed: s_f_d.d\n");
  if (s_c_ld.c != 'e') printf("Test failed: s_c_ld.c\n");
  if (s_c_ld.ld != 27.0) printf("Test failed: s_c_ld.ld\n");
  if (s_s_ld.s != 28) printf("Test failed: s_s_ld.s\n");
  if (s_s_ld.ld != 29.0) printf("Test failed: s_s_ld.ld\n");
  if (s_i_ld.i != 30) printf("Test failed: s_i_ld.i\n");
  if (s_i_ld.ld != 31.0) printf("Test failed: s_i_ld.ld\n");
  if (s_f_ld.f != 32.0f) printf("Test failed: s_f_ld.f\n");
  if (s_f_ld.ld != 33.0) printf("Test failed: s_f_ld.ld\n");
  if (s_d_ld.d != 34.0) printf("Test failed: s_d_ld.d\n");
  if (s_d_ld.ld != 35.0) printf("Test failed: s_d_ld.ld\n");

  return 0;
}