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
  double result1 = ((7.3) * (8.1)) / (8.6);
  double result2 = (x * (1.1)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((5.9), (4.4));
  exit ((0));
}
/* ProgramSourceLLVM */
