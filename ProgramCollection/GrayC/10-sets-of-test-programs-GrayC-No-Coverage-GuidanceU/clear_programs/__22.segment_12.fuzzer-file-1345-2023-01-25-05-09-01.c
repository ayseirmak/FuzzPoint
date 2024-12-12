/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0;
  a.i = 1 + 42 + ((long)((((int)(1)) << ((int)(a.i))))) - ((int)((((double)(a.i)) * ((double)(a.i)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
