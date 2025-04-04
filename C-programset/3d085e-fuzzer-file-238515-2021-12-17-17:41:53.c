/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = ((((1.7)))) + ((((10.8))));
volatile _Complex float f2 = ((((10.8)))) + ((((10.9))));
volatile _Complex float f3 = ((((8.8)))) + ((((9.6))));
volatile _Complex float f4 = ((((2.9)))) + ((((1.1))));
volatile _Complex float f5 = ((((8.7)))) + ((((6.8))));
volatile _Complex double d1 = ((((4.7)))) + ((((1.9))));
volatile _Complex double d2 = ((((5.8)))) + ((((1.8))));
volatile _Complex double d3 = ((((1.2)))) + ((((10.5))));
volatile _Complex double d4 = ((((8.6)))) + ((((8.1))));
volatile _Complex double d5 = ((((3.9)))) + ((((7.9))));
volatile _Complex long double ld1 = ((((10.9)))) + ((((8.7))));
volatile _Complex long double ld2 = ((((4.4)))) + ((((4.10))));
volatile _Complex long double ld3 = ((((8.2)))) + ((((9.9))));
volatile _Complex long double ld4 = ((((5.2)))) + ((((3.4))));
volatile _Complex long double ld5 = ((((5.8)))) + ((((9.8))));

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
  check_float (((((4352)))), f1, f2, f3, f4, f5);
  check_double ((0xD), d1, d2, d3, d4, d5);
  check_long_double (((((288230380446679040)))), ld1, ld2, ld3, ld4, ld5);
  exit ((-(-((0)))));
}
/* ProgramSourceLLVM */
