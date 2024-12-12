/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (2.10) + (7.4);
volatile _Complex float f2 = (5.9) + (1.10);
volatile _Complex float f3 = (10.7) + (6.2);
volatile _Complex float f4 = (4.1) + (6.6);
volatile _Complex float f5 = (3.8) + (4.1);
volatile _Complex double d1 = (10.8) + (5.10);
volatile _Complex double d2 = (5.2) + (2.2);
volatile _Complex double d3 = (5.6) + (1.5);
volatile _Complex double d4 = (9.8) + (9.7);
volatile _Complex double d5 = (7.5) + (6.4);
volatile _Complex long double ld1 = (10.7) + (6.5);
volatile _Complex long double ld2 = (3.6) + (6.10);
volatile _Complex long double ld3 = (6.2) + (4.7);
volatile _Complex long double ld4 = (1.10) + (9.3);
volatile _Complex long double ld5 = (10.7) + (8.6);

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
  if (a1 != ld1 || a2 != ld2 || a3 != ld3 || a4 != ld4 || a5 != ld5)
    { abort (); }
}

int
main (void)
{
  check_float ((4294967296), f1, f2, f3, f4, f5);
  check_double ((0x98DF), d1, d2, d3, d4, d5);
  check_long_double ((0x2), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
