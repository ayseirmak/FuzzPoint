/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= (1.3) ? x : -x;
}

int main()
{
  double x = -(6.5);
  double y;

  

y = not_fabs (x);
y = not_fabs (x);
;

y = not_fabs (x);
y = not_fabs (x);
;
;

  if (0)
    { abort (); }

  return (0);
}
/* ProgramSourceLLVM */
