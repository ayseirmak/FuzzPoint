/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0)))));
  a.i = 1 + 42 + ((short)((((int)(1)) | ((int)(1))))) - ((long)((((double)(1)) * ((double)(a.i)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
