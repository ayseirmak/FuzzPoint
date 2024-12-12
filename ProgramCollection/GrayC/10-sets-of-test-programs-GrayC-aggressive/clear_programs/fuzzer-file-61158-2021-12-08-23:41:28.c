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
  
a.i = (-2) + (0xF8B184) *((short)((((double)((-2))) -((double)((0))))))*((int)((((double)(a.i)) +((double)(a.i)))))*((long)((((int)(a.i)) &((int)((1))))))+((int)((((double)((-2))) -((double)((0x9743))))))+((short)((((double)(a.i)) -((double)((-2))))));
a.i = (-2) + (0xF8B184) *((short)((((double)((-2))) -((double)((0))))))*((int)((((double)(a.i)) +((double)(a.i)))))*((long)((((int)(a.i)) &((int)((1))))))+((int)((((double)((-2))) -((double)((0x9743))))))+((short)((((double)(a.i)) -((double)((-2))))));
;
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit ((0));
}
/* ProgramSourceLLVM */
