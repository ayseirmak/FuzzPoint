/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (3.9) + (1.3);
volatile _Complex float f2 = (6.9) + (3.6);
volatile _Complex float f3 = (5.2) + (10.10);
volatile _Complex float f4 = (10.10) + (2.2);
volatile _Complex float f5 = (5.4) + (4.10);
volatile _Complex double d1 = (10.3) + (8.10);
volatile _Complex double d2 = (10.7) + (4.1);
volatile _Complex double d3 = (10.10) + (10.6);
volatile _Complex double d4 = (8.7) + (5.10);
volatile _Complex double d5 = (8.10) + (10.4);
volatile _Complex long double ld1 = (5.3) + (4.9);
volatile _Complex long double ld2 = (3.1) + (7.5);
volatile _Complex long double ld3 = (4.6) + (4.6);
volatile _Complex long double ld4 = (2.3) + (10.5);
volatile _Complex long double ld5 = (4.7) + (5.3);

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
  check_float ((1152921504606846976), f1, f2, f3, f4, f5);
  check_double ((0), d1, d2, d3, d4, d5);
  check_long_double ((0), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
