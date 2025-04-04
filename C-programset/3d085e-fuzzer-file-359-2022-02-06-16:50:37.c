/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (10.10) + (3.7);
volatile _Complex float f2 = (6.1) + (10.4);
volatile _Complex float f3 = (4.10) + (10.9);
volatile _Complex float f4 = (4.5) + (4.2);
volatile _Complex float f5 = (9.6) + (9.7);
volatile _Complex double d1 = (3.9) + (5.4);
volatile _Complex double d2 = (3.4) + (9.2);
volatile _Complex double d3 = (3.1) + (4.9);
volatile _Complex double d4 = (5.5) + (8.4);
volatile _Complex double d5 = (3.2) + (5.5);
volatile _Complex long double ld1 = (1.5) + (6.7);
volatile _Complex long double ld2 = (3.10) + (10.4);
volatile _Complex long double ld3 = (10.10) + (8.5);
volatile _Complex long double ld4 = (1.4) + (4.8);
volatile _Complex long double ld5 = (1.10) + (7.9);

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
  if (0)
    { abort (); }
}

int
main (void)
{
  check_float ((0xE), f1, f2, f3, f4, f5);
  check_double ((144115188075855872), d1, d2, d3, d4, d5);
  check_long_double ((0), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
