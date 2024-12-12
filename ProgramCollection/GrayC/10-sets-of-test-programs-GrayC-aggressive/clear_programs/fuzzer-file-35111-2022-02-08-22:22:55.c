/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  
a.d = 0 + 42 +((int)((((int)(0)) |((int)(a.d)))))-((short)((((int)(0)) &((int)(0)))))-((int)((((double)(a.d)) +((double)(a.d)))))+((int)((((int)(a.d)) %((int)(0)))));
a.d = 0 + 42 +((long)((((double)(0)) *((double)(0)))))+((int)((((double)(a.d)) +((double)(0)))))+((long)((((double)(a.d)) +((double)(0)))));
;
  
a.i = 1 + 42 *((int)((((int)(a.i)) ^((int)(a.i)))))-((long)((((double)(1)) +((double)(1)))))+((short)((((double)(1)) *((double)(a.i)))))+((short)((((double)(1)) *((double)(1)))));
a.i = 1 + 42 *((int)((((int)(1)) ^((int)(1)))))-((short)((((double)(1)) -((double)(a.i)))))-((int)((((double)(a.i)) *((double)(1)))))+((short)((((double)(1)) *((double)(a.i)))))*((int)((((double)(a.i)) *((double)(a.i)))));
;
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
