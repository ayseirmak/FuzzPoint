/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= (5.1) ? x : -x;
}

int main()
{
  double x = -(8.9);
  double y;

  ;

  if (0)
    { abort (); }

  return (0);
}
/* ProgramSourceLLVM */
