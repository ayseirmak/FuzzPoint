/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = ((7.4)) + ((5.10));
volatile _Complex float f2 = ((6.2)) + ((7.3));
volatile _Complex float f3 = ((8.4)) + ((8.9));
volatile _Complex float f4 = ((5.8)) + ((8.7));
volatile _Complex float f5 = ((2.9)) + ((4.4));
volatile _Complex double d1 = ((1.8)) + ((8.7));
volatile _Complex double d2 = ((10.4)) + ((8.4));
volatile _Complex double d3 = ((1.10)) + ((10.9));
volatile _Complex double d4 = ((5.1)) + ((1.1));
volatile _Complex double d5 = ((7.9)) + ((1.5));
volatile _Complex long double ld1 = ((10.7)) + ((3.4));
volatile _Complex long double ld2 = ((9.3)) + ((8.9));
volatile _Complex long double ld3 = ((1.10)) + ((6.8));
volatile _Complex long double ld4 = ((4.7)) + ((3.8));
volatile _Complex long double ld5 = ((6.1)) + ((3.7));

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
  check_float (((-1)), f1, f2, f3, f4, f5);
  check_double (((-1048577)), d1, d2, d3, d4, d5);
  check_long_double (((2)), ld1, ld2, ld3, ld4, ld5);
  exit (((0)));
}
/* ProgramSourceLLVM */
