/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= (1.2) ? x : -x;
}

int main()
{
  double x = -(3.9);
  double y;

  
y = not_fabs (x) + (0x9A69F0) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x))))));
y = not_fabs (x) + (0x9A69F0) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x))))));
;

  if ((0))
    { abort (); }

  return (0);
}
/* ProgramSourceLLVM */
