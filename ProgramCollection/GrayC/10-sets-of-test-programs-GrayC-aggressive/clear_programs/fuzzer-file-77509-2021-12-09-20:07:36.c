/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0 + 42 -((short)((((int)(0)) <<((int)(a.d)))))+((short)((((double)(a.d)) *((double)(0)))))-((int)((((double)(0)) -((double)(0)))))+((short)((((double)(a.d)) +((double)(0)))))-((long)((((int)(0)) %((int)(a.d)))));
  a.i = 1 + 42 *((int)((((int)(1)) &((int)(1)))))+((short)((((int)(1)) %((int)(a.i)))))*((long)((((int)(a.i)) |((int)(a.i)))))+((long)((((int)(a.i)) >>((int)(a.i)))))*((int)((((double)(1)) +((double)(1)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
