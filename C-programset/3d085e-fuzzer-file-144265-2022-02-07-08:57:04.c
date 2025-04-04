/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = ((5.7)) + ((2.1));
volatile _Complex float f2 = ((1.6)) + ((9.2));
volatile _Complex float f3 = ((5.9)) + ((4.8));
volatile _Complex float f4 = ((9.3)) + ((9.1));
volatile _Complex float f5 = ((3.7)) + ((8.4));
volatile _Complex double d1 = ((3.9)) + ((3.4));
volatile _Complex double d2 = ((8.9)) + ((2.7));
volatile _Complex double d3 = ((3.10)) + ((1.1));
volatile _Complex double d4 = ((3.10)) + ((7.6));
volatile _Complex double d5 = ((8.1)) + ((6.4));
volatile _Complex long double ld1 = ((8.10)) + ((4.4));
volatile _Complex long double ld2 = ((8.5)) + ((9.10));
volatile _Complex long double ld3 = ((3.9)) + ((3.9));
volatile _Complex long double ld4 = ((7.10)) + ((6.2));
volatile _Complex long double ld5 = ((2.7)) + ((4.1));

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
  check_float (((0)), f1, f2, f3, f4, f5);
  check_double (((-1048577)), d1, d2, d3, d4, d5);
  check_long_double (((0x7AC)), ld1, ld2, ld3, ld4, ld5);
  exit (((0)));
}
/* ProgramSourceLLVM */
