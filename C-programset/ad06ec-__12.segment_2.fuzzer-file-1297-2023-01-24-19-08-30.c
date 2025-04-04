/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  
;a.i = 1 + 42 - ((int)((((double)(1)) - ((double)(a.i))))) - ((long)((((int)(a.i)) >> ((int)(a.i))))) + ((short)((((int)(1)) ^ ((int)(a.i))))) + ((short)((((int)(a.i)) << ((int)(1))))) - ((int)((((int)(1)) >> ((int)(1)))));
0;
  a.i = 1;
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
