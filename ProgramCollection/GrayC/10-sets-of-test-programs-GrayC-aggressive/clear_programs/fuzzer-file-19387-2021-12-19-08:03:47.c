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
  double result1 = ((6.8) * (6.8)) / (4.4);
  double result2 = (x * (9.9)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((10.9), (6.5));
  exit ((0xD0700));
}
/* ProgramSourceLLVM */
