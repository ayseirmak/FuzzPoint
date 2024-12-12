/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = (-1) + (42) *((short)((((double)((0x4957B))) -((double)((524288))))))*((short)((((double)((0))) -((double)(a.d)))))-((short)((((int)(a.d)) &((int)((0))))))*((short)((((double)((4))) +((double)(a.d)))));
  a.i = (0xB7) + (42) +((int)((((int)(a.i)) >>((int)((0x908))))))*((int)((((double)((1))) +((double)((33))))))+((long)((((double)((-2))) +((double)((129))))))-((int)((((double)(a.i)) +((double)(a.i)))))*((short)((((int)(a.i)) &((int)(a.i)))));
  return x >> a.i;
}

int main(void)
{
  if ((0))
    { abort (); }
  exit ((4096));
}
/* ProgramSourceLLVM */
