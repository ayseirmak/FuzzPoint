/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= 0.0 ? x : -x;
}

int main()
{
  double x = -0.0;
  double y;

  y = not_fabs (x) + 42 * ((int)((((double)(y)) - ((double)(y))))) - ((int)((((int)(y)) << ((int)(not_fabs (x))))));

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
