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
;
;a.i = 1;
1;
1 + 42 - ((int)((((double)(1)) - ((double)(a.i))))) - ((long)((((int)(a.i)) >> ((int)(a.i))))) + ((short)((((int)(1)) ^ ((int)(a.i))))) + ((short)((((int)(a.i)) << ((int)(1))))) - ((int)((((int)(1)) >> ((int)(1)))));
0;
  a.i = 1;
  return x >> a.i;
}

int main(void)
{
  if (((int)test (5) != 2 + 41 * ((short)((((double)(test (5))) - ((double)(2))))) * ((short)((((double)(2)) - ((double)(test (5)))))) * ((int)((((int)(2)) ^ ((int)(2))))) * ((int)((((double)(2)) * ((double)(test (5)))))) + ((short)((((int)(2)) & ((int)(2))))) * ((int)((((int)(2)) ^ ((int)(test (5))))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
