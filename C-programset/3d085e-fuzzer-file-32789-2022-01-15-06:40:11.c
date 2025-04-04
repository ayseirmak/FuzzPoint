/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (2.7) + (1.4);
volatile _Complex float f2 = (10.2) + (6.2);
volatile _Complex float f3 = (7.5) + (9.6);
volatile _Complex float f4 = (5.1) + (5.1);
volatile _Complex float f5 = (5.10) + (1.2);
volatile _Complex double d1 = (1.7) + (10.2);
volatile _Complex double d2 = (3.3) + (4.10);
volatile _Complex double d3 = (3.9) + (1.9);
volatile _Complex double d4 = (4.2) + (4.9);
volatile _Complex double d5 = (10.2) + (5.10);
volatile _Complex long double ld1 = (7.6) + (9.1);
volatile _Complex long double ld2 = (6.2) + (6.5);
volatile _Complex long double ld3 = (6.6) + (6.3);
volatile _Complex long double ld4 = (10.3) + (9.9);
volatile _Complex long double ld5 = (8.3) + (4.2);

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
  check_float ((0x887D), f1, f2, f3, f4, f5);
  check_double ((16384), d1, d2, d3, d4, d5);
  check_long_double ((0), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
