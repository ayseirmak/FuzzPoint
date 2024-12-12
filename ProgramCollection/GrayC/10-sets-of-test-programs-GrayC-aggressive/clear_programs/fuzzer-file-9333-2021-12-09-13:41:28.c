/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= (6.5) ? x : -x;
}

int main()
{
  double x = -(10.1);
  double y;

  y = not_fabs (x) + (106) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))) + (12) -((long)((((int)(not_fabs (x) + (40) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))))) <<((int)(((short)((((int)(y)) %((int)(not_fabs (x)))))))))))*((long)((((int)((-43) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x)))))))) ^((int)(not_fabs (x) + (-43) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))))))))+((short)((((int)(not_fabs (x) + (-43) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))))) &((int)(not_fabs (x) + (42) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x)))))))))))-((long)((((double)(not_fabs (x))) +((double)(((short)((((int)(y)) %((int)(not_fabs (x)))))))))));

  if ((0))
    { abort (); }

  return (0);
}
/* ProgramSourceLLVM */
