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

  y = not_fabs (x) + 42 -((short)((((int)(not_fabs (x))) %((int)(not_fabs (x))))))+((int)((((double)(y)) +((double)(y)))))*((long)((((double)(not_fabs (x))) *((double)(not_fabs (x))))))-((short)((((double)(y)) +((double)(not_fabs (x))))))*((long)((((int)(y)) ^((int)(y)))));

  if (0)
    { abort (); }

  return (0);
}
/* ProgramSourceLLVM */
