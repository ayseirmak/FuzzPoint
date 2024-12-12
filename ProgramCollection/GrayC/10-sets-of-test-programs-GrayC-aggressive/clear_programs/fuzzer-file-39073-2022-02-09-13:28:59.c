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

  

y = not_fabs (x) + 42 *((long)((((int)(y)) &((int)(not_fabs (x))))))*((long)((((int)(y)) >>((int)(y)))))+((short)((((double)(y)) +((double)(not_fabs (x))))))+((int)((((double)(y)) *((double)(y)))));
y = not_fabs (x) + 42 *((long)((((double)(not_fabs (x))) +((double)(not_fabs (x))))))+((long)((((double)(not_fabs (x))) -((double)(y)))))-((int)((((int)(not_fabs (x))) |((int)(not_fabs (x))))));
;
;
;

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
