/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (8.8) + (8.3);
volatile _Complex float f2 = (5.1) + (9.4);
volatile _Complex float f3 = (4.7) + (3.3);
volatile _Complex float f4 = (2.5) + (1.4);
volatile _Complex float f5 = (1.3) + (1.5);
volatile _Complex double d1 = (1.10) + (8.2);
volatile _Complex double d2 = (10.4) + (5.8);
volatile _Complex double d3 = (10.7) + (10.6);
volatile _Complex double d4 = (10.2) + (8.9);
volatile _Complex double d5 = (3.8) + (4.8);
volatile _Complex long double ld1 = (5.8) + (8.2);
volatile _Complex long double ld2 = (1.8) + (8.2);
volatile _Complex long double ld3 = (10.8) + (6.9);
volatile _Complex long double ld4 = (1.4) + (10.8);
volatile _Complex long double ld5 = (9.1) + (2.4);

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
  check_float ((0), f1, f2, f3, f4, f5);
  check_double ((0x3), d1, d2, d3, d4, d5);
  check_long_double ((0), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
