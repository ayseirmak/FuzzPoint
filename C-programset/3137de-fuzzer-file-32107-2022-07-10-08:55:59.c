/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0 + 42 - ((long)(((double)0) + ((double)(a.d)))) + ((long)(((double)(a.d)) + ((double)0))) - ((int)(((double)(a.d)) + ((double)(a.d))));
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
