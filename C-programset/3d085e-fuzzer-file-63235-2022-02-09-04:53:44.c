/* corpus/pr35456.c */
/* { dg-skip-if "signed zero not supported" { "vax-*-*" } } */
extern void abort (void);

double
__attribute__ ((noinline))
not_fabs (double x)
{
  return x >= ((3.8)) ? x : -x;
}

int main()
{
  double x = -((9.6));
  double y;

  
y = not_fabs (x) + (34) -((short)((((int)(not_fabs (x))) %((int)(not_fabs (x))))))+((int)((((double)(y)) +((double)(y)))))*((long)((((double)(not_fabs (x))) *((double)(not_fabs (x))))))-((short)((((double)(y)) +((double)(not_fabs (x))))))*((long)((((int)(y)) ^((int)(y)))));
y = not_fabs (x) + (34) -((short)((((int)(not_fabs (x))) %((int)(not_fabs (x))))))+((int)((((double)(y)) +((double)(y)))))*((long)((((double)(not_fabs (x))) *((double)(not_fabs (x))))))-((short)((((double)(y)) +((double)(not_fabs (x))))))*((long)((((int)(y)) ^((int)(y)))));
;

  if (0)
    { abort (); }

  return ((256));
}
/* ProgramSourceLLVM */
