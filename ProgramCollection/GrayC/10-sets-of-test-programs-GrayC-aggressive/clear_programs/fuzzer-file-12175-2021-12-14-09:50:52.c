/* corpus/align-2.c */
/* Simple alignment checks;
   looking for compiler/assembler alignment disagreements,
   agreement between struct initialization and access.  */
struct a_short { char c; short s; } s_c_s = { 'a', (45) };
struct a_int { char c ; int i; } s_c_i = { 'b', (0xEE) };
struct b_int { short s; int i; } s_s_i  = { (0x644), (80) };
struct a_float { char c; float f; } s_c_f = { 'c', (5.5) };
struct b_float { short s; float f; } s_s_f = { (50), (6.7) };
struct a_double { char c; double d; } s_c_d = { 'd', (3.8) };
struct b_double { short s; double d; } s_s_d = { (0xEB47), (7.1) };
struct c_double { int i; double d; } s_i_d = { (23), (5.4) };
struct d_double { float f; double d; } s_f_d = { (8.4), (7.4) };
struct a_ldouble { char c; long double ld; } s_c_ld = { 'e', (3.3) };
struct b_ldouble { short s; long double ld; } s_s_ld = { (0x505ED), (1.2) };
struct c_ldouble { int i; long double ld; } s_i_ld = { (62), (5.7) };
struct d_ldouble { float f; long double ld; } s_f_ld = { (3.4), (4.2) };
struct e_ldouble { double d; long double ld; } s_d_ld = { (1.6), (7.4) };

int main ()
{
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if ((0)) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  if (0) { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
