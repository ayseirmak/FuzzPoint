/* corpus/990127-2.c */
/* { dg-options "-mpc64"  { target { i?86-*-* x86_64-*-* } } } */

extern void abort (void);
extern void exit (int);

void
fpEq (double x, double y)
{
  if ((0))
    { abort (); }
}

void
fpTest (double x, double y)
{
  double result1 = ((5.8) * (7.5)) / (7.5);
  double result2 = (x * (10.2)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((6.1), (7.4));
  exit ((131072));
}
/* ProgramSourceLLVM */
