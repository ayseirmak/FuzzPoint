/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = ((4.2)) + ((1.4));
volatile _Complex float f2 = ((1.3)) + ((2.5));
volatile _Complex float f3 = ((7.8)) + ((7.5));
volatile _Complex float f4 = ((7.8)) + ((4.6));
volatile _Complex float f5 = ((1.2)) + ((4.5));
volatile _Complex double d1 = ((5.6)) + ((10.8));
volatile _Complex double d2 = ((3.9)) + ((2.3));
volatile _Complex double d3 = ((10.3)) + ((3.1));
volatile _Complex double d4 = ((10.3)) + ((7.4));
volatile _Complex double d5 = ((1.6)) + ((7.5));
volatile _Complex long double ld1 = ((3.10)) + ((4.9));
volatile _Complex long double ld2 = ((9.6)) + ((10.6));
volatile _Complex long double ld3 = ((4.5)) + ((6.7));
volatile _Complex long double ld4 = ((8.10)) + ((3.7));
volatile _Complex long double ld5 = ((9.8)) + ((10.6));

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
  if (a1 != d1 || a2 != d2 || a3 != d3 || a4 != d4 || a5 != d5)
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
  check_float (((0x3C4)), f1, f2, f3, f4, f5);
  check_double (((135266304)), d1, d2, d3, d4, d5);
  check_long_double (((-3)), ld1, ld2, ld3, ld4, ld5);
  exit (((65536)));
}
/* ProgramSourceLLVM */
