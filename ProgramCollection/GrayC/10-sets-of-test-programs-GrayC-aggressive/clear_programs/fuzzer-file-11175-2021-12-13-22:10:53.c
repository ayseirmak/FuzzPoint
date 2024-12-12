/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0 + 42 -((int)((((int)(0)) <<((int)(a.d)))))*((long)((((int)(a.d)) |((int)(0)))))*((long)((((int)(a.d)) %((int)(a.d)))));
  a.i = 1 + 42 -((int)((((int)(1)) %((int)(a.i)))))*((long)((((int)(1)) ^((int)(1)))))-((short)((((int)(1)) &((int)(1)))))*((short)((((double)(a.i)) +((double)(1)))))*((int)((((int)(1)) |((int)(1)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
