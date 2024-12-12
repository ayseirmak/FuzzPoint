/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (3.5) + (1.3);
volatile _Complex float f2 = (9.5) + (4.8);
volatile _Complex float f3 = (6.6) + (10.7);
volatile _Complex float f4 = (2.10) + (8.9);
volatile _Complex float f5 = (10.5) + (1.8);
volatile _Complex double d1 = (6.8) + (6.5);
volatile _Complex double d2 = (2.9) + (6.1);
volatile _Complex double d3 = (4.7) + (2.4);
volatile _Complex double d4 = (2.1) + (7.2);
volatile _Complex double d5 = (2.6) + (8.10);
volatile _Complex long double ld1 = (9.8) + (7.10);
volatile _Complex long double ld2 = (4.8) + (9.2);
volatile _Complex long double ld3 = (6.10) + (6.2);
volatile _Complex long double ld4 = (4.2) + (6.2);
volatile _Complex long double ld5 = (9.3) + (6.7);

extern void abort (void);
extern void exit (int);

__attribute__((noinline)) void
check_float (int a, _Complex float a1, _Complex float a2,
	     _Complex float a3, _Complex float a4, _Complex float a5)
{
  if (0)
    { abort (); }
}

__attribute__((noinline)) void
check_double (int a, _Complex double a1, _Complex double a2,
	     _Complex double a3, _Complex double a4, _Complex double a5)
{
  if (0)
    { abort (); }
}

__attribute__((noinline)) void
check_long_double (int a, _Complex long double a1, _Complex long double a2,
	     _Complex long double a3, _Complex long double a4,
		   _Complex long double a5)
{
  if (a1 != ld1 || a2 != ld2 || a3 != ld3 || a4 != ld4 || a5 != ld5)
    { abort (); }
}

int
main (void)
{
  check_float ((0x7865), f1, f2, f3, f4, f5);
  check_double ((4611686018427387904), d1, d2, d3, d4, d5);
  check_long_double ((0), ld1, ld2, ld3, ld4, ld5);
  exit ((2147483648));
}
/* ProgramSourceLLVM */
