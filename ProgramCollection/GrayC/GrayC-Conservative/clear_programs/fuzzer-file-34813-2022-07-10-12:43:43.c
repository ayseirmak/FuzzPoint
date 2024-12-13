/* corpus/complex-7.c */
/* Test argument passing of complex values.  The MIPS64 compiler had a
   bug when they were split between registers and the stack.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

volatile _Complex float f1 = (7.1) + (6.5);
volatile _Complex float f2 = (8.5) + (9.5);
volatile _Complex float f3 = (10.10) + (10.2);
volatile _Complex float f4 = (4.1) + (9.6);
volatile _Complex float f5 = (7.5) + (2.3);
volatile _Complex double d1 = (9.2) + (1.2);
volatile _Complex double d2 = (4.5) + (7.5);
volatile _Complex double d3 = (10.10) + (4.5);
volatile _Complex double d4 = (3.2) + (6.4);
volatile _Complex double d5 = (1.2) + (5.4);
volatile _Complex long double ld1 = (6.1) + (4.8);
volatile _Complex long double ld2 = (6.7) + (4.3);
volatile _Complex long double ld3 = (1.5) + (3.6);
volatile _Complex long double ld4 = (7.8) + (1.3);
volatile _Complex long double ld5 = (5.7) + (6.7);

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
  check_float (9491, f1, f2, f3, f4, f5);
  check_double (18261, d1, d2, d3, d4, d5);
  check_long_double (9602, ld1, ld2, ld3, ld4, ld5);
  exit (17152);
}
/* ProgramSourceLLVM */
