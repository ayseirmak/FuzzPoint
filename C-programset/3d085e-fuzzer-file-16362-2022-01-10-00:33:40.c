/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0 + 42 *((short)((((double)(0)) -((double)(0)))))*((short)((((double)(0)) -((double)(a.d)))))-((short)((((int)(a.d)) &((int)(0)))))*((short)((((double)(0)) +((double)(a.d)))));
  a.i = 1 + 42 +((int)((((int)(a.i)) >>((int)(1)))))*((int)((((double)(1)) +((double)(1)))))+((long)((((double)(1)) +((double)(1)))))-((int)((((double)(a.i)) +((double)(a.i)))))*((short)((((int)(a.i)) &((int)(a.i)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
