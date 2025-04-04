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
  double result1 = ((8.7) * (10.4)) / (1.1);
  double result2 = (x * (3.9)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((3.3), (1.1));
  exit ((0));
}
/* ProgramSourceLLVM */
