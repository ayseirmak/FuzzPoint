/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = ((3.10)) + ((10.6));
volatile _Complex float f2 = ((2.9)) + ((7.7));
volatile _Complex float f3 = ((1.5)) + ((2.10));
volatile _Complex float f4 = ((1.9)) + ((7.7));
volatile _Complex float f5 = ((4.9)) + ((6.3));
volatile _Complex double d1 = ((10.7)) + ((2.10));
volatile _Complex double d2 = ((5.4)) + ((1.9));
volatile _Complex double d3 = ((3.7)) + ((3.7));
volatile _Complex double d4 = ((10.5)) + ((9.5));
volatile _Complex double d5 = ((2.7)) + ((6.1));
volatile _Complex long double ld1 = ((8.10)) + ((2.10));
volatile _Complex long double ld2 = ((3.5)) + ((9.2));
volatile _Complex long double ld3 = ((9.6)) + ((2.1));
volatile _Complex long double ld4 = ((3.1)) + ((2.7));
volatile _Complex long double ld5 = ((5.10)) + ((3.6));

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
  check_float ((0xC1B), f1, f2, f3, f4, f5);
  check_double (((32896)), d1, d2, d3, d4, d5);
  check_long_double (((0)), ld1, ld2, ld3, ld4, ld5);
  exit (((262144)));
}
/* ProgramSourceLLVM */
