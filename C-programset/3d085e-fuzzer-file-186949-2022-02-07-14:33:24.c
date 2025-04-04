/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (8.3) + (5.5);
volatile _Complex float f2 = (1.9) + (1.4);
volatile _Complex float f3 = (10.2) + (10.4);
volatile _Complex float f4 = (7.5) + (5.10);
volatile _Complex float f5 = (9.5) + (6.10);
volatile _Complex double d1 = (5.4) + (3.10);
volatile _Complex double d2 = (5.6) + (3.9);
volatile _Complex double d3 = (4.1) + (8.3);
volatile _Complex double d4 = (4.4) + (1.9);
volatile _Complex double d5 = (7.8) + (3.4);
volatile _Complex long double ld1 = (5.1) + (6.1);
volatile _Complex long double ld2 = (4.6) + (1.3);
volatile _Complex long double ld3 = (6.7) + (2.9);
volatile _Complex long double ld4 = (6.9) + (8.10);
volatile _Complex long double ld5 = (7.9) + (3.3);

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
  check_float ((0x74), f1, f2, f3, f4, f5);
  check_double ((8796093022208), d1, d2, d3, d4, d5);
  check_long_double ((0x9C74), ld1, ld2, ld3, ld4, ld5);
  exit ((0));
}
/* ProgramSourceLLVM */
