/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  ;
  
a.i = 1 + 42 -((short)((((int)(1)) &((int)(a.i)))))*((long)((((double)(1)) -((double)(a.i)))))+((short)((((int)(a.i)) >>((int)(a.i)))));
a.i = 1 + 42 *((long)((((double)(1)) +((double)(a.i)))))-((long)((((double)(a.i)) -((double)(1)))));
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
