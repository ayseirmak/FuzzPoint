/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  
a.d = 0 + 42 +((short)((((int)(0)) |((int)(a.d)))))+((short)((((double)(0)) +((double)(a.d)))))+((short)((((int)(0)) ^((int)(a.d)))));
a.d = 0 + 42 +((long)((((int)(a.d)) %((int)(0)))))+((short)((((int)(0)) ^((int)(a.d)))));
;
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
