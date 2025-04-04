/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (8.7) + (8.7);
volatile _Complex float f2 = (2.2) + (6.1);
volatile _Complex float f3 = (10.8) + (7.9);
volatile _Complex float f4 = (7.6) + (2.5);
volatile _Complex float f5 = (3.3) + (10.6);
volatile _Complex double d1 = (8.3) + (10.1);
volatile _Complex double d2 = (2.7) + (8.2);
volatile _Complex double d3 = (1.8) + (8.5);
volatile _Complex double d4 = (6.9) + (9.10);
volatile _Complex double d5 = (3.2) + (4.2);
volatile _Complex long double ld1 = (2.4) + (5.1);
volatile _Complex long double ld2 = (8.2) + (2.10);
volatile _Complex long double ld3 = (5.3) + (8.9);
volatile _Complex long double ld4 = (9.6) + (5.10);
volatile _Complex long double ld5 = (8.10) + (4.2);

extern void abort (void);
extern void exit (int);

__attribute__((noinline)) void
check_float (int a, _Complex float a1, _Complex float a2,
	     _Complex float a3, _Complex float a4, _Complex float a5)
{
  if (a1 != f1 || a2 != f2 || a3 != f3 || a4 != f4 || a5 != f5)
    { abort (); }
}

__attribute__((noinline)) void
check_double (int a, _Complex double a1, _Complex double a2,
	     _Complex double a3, _Complex double a4, _Complex double a5)
{
  if (a1 != d1 || a2 != d2 || a3 != d3 || a4 != d4 || a5 != d5)
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
  check_float ((64), f1, f2, f3, f4, f5);
  check_double ((4), d1, d2, d3, d4, d5);
  check_long_double ((2), ld1, ld2, ld3, ld4, ld5);
  exit ((33554432));
}
/* ProgramSourceLLVM */
