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
  double result1 = ((3.2) * (10.7)) / (7.5);
  double result2 = (x * (6.5)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((9.7), (5.8));
  exit ((0));
}
/* ProgramSourceLLVM */
