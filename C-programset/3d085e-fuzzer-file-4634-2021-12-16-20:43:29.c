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
  double result1 = ((3.7) * (4.9)) / (7.8);
  double result2 = (x * (2.1)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((7.8), (6.1));
  exit ((16384));
}
/* ProgramSourceLLVM */
