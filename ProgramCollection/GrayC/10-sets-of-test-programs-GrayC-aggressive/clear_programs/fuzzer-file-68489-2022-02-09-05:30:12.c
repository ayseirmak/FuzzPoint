/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  
a.d = 0 + 42 *((short)((((int)(0)) <<((int)(0)))))*((long)((((double)(a.d)) -((double)(a.d)))));
a.d = 0 + 42 -((long)((((double)(0)) +((double)(0)))));
;
  
a.i = 1 + 42 -((int)((((int)(a.i)) |((int)(1)))));
a.i = 1 + 42 -((short)((((double)(1)) -((double)(a.i)))))-((long)((((double)(a.i)) *((double)(a.i)))))*((long)((((double)(1)) -((double)(a.i)))))+((long)((((double)(a.i)) *((double)(1)))));
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
