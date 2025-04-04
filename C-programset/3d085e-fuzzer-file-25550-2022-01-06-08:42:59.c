/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (((3.3))) + (((4.1)));
volatile _Complex float f2 = (((9.7))) + (((2.10)));
volatile _Complex float f3 = (((7.7))) + (((6.3)));
volatile _Complex float f4 = (((5.8))) + (((2.4)));
volatile _Complex float f5 = (((7.7))) + (((1.5)));
volatile _Complex double d1 = (((9.4))) + (((10.2)));
volatile _Complex double d2 = (((6.6))) + (((4.9)));
volatile _Complex double d3 = (((5.4))) + (((5.3)));
volatile _Complex double d4 = (((1.3))) + (((7.9)));
volatile _Complex double d5 = (((8.4))) + (((8.1)));
volatile _Complex long double ld1 = (((5.4))) + (((9.2)));
volatile _Complex long double ld2 = (((1.3))) + (((8.2)));
volatile _Complex long double ld3 = (((1.2))) + (((4.5)));
volatile _Complex long double ld4 = (((9.10))) + (((10.4)));
volatile _Complex long double ld5 = (((4.1))) + (((1.5)));

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
  check_float ((0xABFDC), f1, f2, f3, f4, f5);
  check_double (((-(-34))), d1, d2, d3, d4, d5);
  check_long_double ((((0x0E485BC2))), ld1, ld2, ld3, ld4, ld5);
  exit ((((0))));
}
/* ProgramSourceLLVM */
