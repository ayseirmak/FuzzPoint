/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  
;a.i = 1;
0;
  a.i = 1 + 42 + ((long)((((int)(1)) >> ((int)(a.i))))) - ((short)((((double)(a.i)) * ((double)(1)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
