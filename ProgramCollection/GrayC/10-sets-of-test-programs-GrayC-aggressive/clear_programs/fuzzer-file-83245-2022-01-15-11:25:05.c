/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (5.5) + (5.9);
volatile _Complex float f2 = (4.10) + (5.4);
volatile _Complex float f3 = (10.1) + (6.2);
volatile _Complex float f4 = (10.9) + (10.1);
volatile _Complex float f5 = (2.2) + (1.4);
volatile _Complex double d1 = (8.6) + (4.3);
volatile _Complex double d2 = (1.2) + (9.8);
volatile _Complex double d3 = (5.7) + (4.6);
volatile _Complex double d4 = (9.1) + (8.2);
volatile _Complex double d5 = (7.3) + (5.2);
volatile _Complex long double ld1 = (9.1) + (3.5);
volatile _Complex long double ld2 = (1.7) + (2.10);
volatile _Complex long double ld3 = (4.1) + (8.4);
volatile _Complex long double ld4 = (10.1) + (5.1);
volatile _Complex long double ld5 = (3.9) + (2.4);

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
  check_double ((0x6), d1, d2, d3, d4, d5);
  check_long_double ((0), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
