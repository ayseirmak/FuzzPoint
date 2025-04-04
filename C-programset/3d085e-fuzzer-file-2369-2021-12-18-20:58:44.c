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
  double result1 = ((6.6) * (8.5)) / (9.1);
  double result2 = (x * (9.6)) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest ((2.9), (2.1));
  exit ((67108864));
}
/* ProgramSourceLLVM */
