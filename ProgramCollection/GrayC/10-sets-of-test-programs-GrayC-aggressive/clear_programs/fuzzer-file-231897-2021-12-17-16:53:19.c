/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= (1.6) ? x : -x;
}

int main()
{
  double x = -(7.1);
  double y;

  y = not_fabs (x) + (42) +((short)((((double)(not_fabs (x))) +((double)(y)))))+((long)((((double)(y)) +((double)(not_fabs (x))))))+((int)((((double)(y)) *((double)(y)))))+((long)((((double)(not_fabs (x))) +((double)(y)))));

  if (0)
    { abort (); }

  return (0);
}
/* ProgramSourceLLVM */
