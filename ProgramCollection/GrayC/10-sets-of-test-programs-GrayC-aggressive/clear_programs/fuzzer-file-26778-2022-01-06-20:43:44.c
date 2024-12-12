/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = (1024) + 42 -((long)((((double)(a.d)) +((double)(a.d)))));
  a.i = (0xA2) + 42 *((int)((((int)((0xA2))) ^((int)(a.i)))))*((long)((((double)((0xA2))) +((double)(a.i)))))+((long)((((double)((0xA2))) -((double)((0xA2))))))+((short)((((int)((0xA2))) %((int)((0xA2))))));
  return x >> a.i;
}

int main(void)
{
  if ((0))
    { abort (); }
  exit ((524288));
}
/* ProgramSourceLLVM */
