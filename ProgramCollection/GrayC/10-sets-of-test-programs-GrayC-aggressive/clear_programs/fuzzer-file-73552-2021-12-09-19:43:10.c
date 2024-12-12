/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= (2.5) ? x : -x;
}

int main()
{
  double x = -(6.6);
  double y;

  y = not_fabs (x) + (42) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))) + (0x656FB) -((long)((((int)(not_fabs (x) + (42) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))))) <<((int)(((short)((((int)(y)) %((int)(not_fabs (x)))))))))))*((long)((((int)((42) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x)))))))) ^((int)(not_fabs (x) + (41) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))))))))+((short)((((int)(not_fabs (x) + (0xD4B5) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x))))))-((short)((((int)(y)) %((int)(not_fabs (x)))))))) &((int)(not_fabs (x) + (43) *((int)((((int)(not_fabs (x))) >>((int)(not_fabs (x))))))*((short)((((double)(y)) -((double)(not_fabs (x)))))))))))-((long)((((double)(not_fabs (x))) +((double)(((short)((((int)(y)) %((int)(not_fabs (x)))))))))));

  if ((0))
    { abort (); }

  return (0);
}
/* ProgramSourceLLVM */
