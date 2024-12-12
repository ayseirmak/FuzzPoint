/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (9.5) + (4.5);
volatile _Complex float f2 = (6.2) + (3.1);
volatile _Complex float f3 = (2.3) + (3.9);
volatile _Complex float f4 = (7.2) + (2.7);
volatile _Complex float f5 = (1.1) + (8.6);
volatile _Complex double d1 = (5.7) + (4.3);
volatile _Complex double d2 = (8.5) + (3.10);
volatile _Complex double d3 = (3.1) + (8.8);
volatile _Complex double d4 = (10.10) + (5.10);
volatile _Complex double d5 = (10.9) + (3.9);
volatile _Complex long double ld1 = (1.8) + (4.3);
volatile _Complex long double ld2 = (7.1) + (2.6);
volatile _Complex long double ld3 = (9.7) + (5.4);
volatile _Complex long double ld4 = (2.7) + (1.9);
volatile _Complex long double ld5 = (9.6) + (4.9);

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
  if ((0))
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
  check_float ((288230376151711744), f1, f2, f3, f4, f5);
  check_double ((0xA), d1, d2, d3, d4, d5);
  check_long_double ((0), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
