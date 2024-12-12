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
  double result1 = ((5.1) * (9.1)) / (9.7);
  double result2 = (x * (1.7)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((9.9), (10.10));
  exit ((536870912));
}
/* ProgramSourceLLVM */
