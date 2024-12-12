/* corpus/990127-2.c */
/* { dg-options "-mpc64"  { target { i?86-*-* x86_64-*-* } } } */

extern void abort (void);
extern void exit (int);

void
fpEq (double x, double y)
{
  if (0)
    { abort (); }
}

void
fpTest (double x, double y)
{
  double result1 = ((5.1) * (3.10)) / (3.9);
  double result2 = (x * (7.10)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((4.10), (2.10));
  exit ((0));
}
/* ProgramSourceLLVM */
