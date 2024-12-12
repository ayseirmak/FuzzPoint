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
  a.i = 1 + 42 * ((int)((((int)(1)) | ((int)(1))))) * ((long)((((double)(1)) + ((double)(a.i))))) + 42 * ((int)((((int)(1 + 42 * ((int)((((int)(1)) | ((int)(1))))) * ((long)((((double)(1)) + ((double)(a.i))))))) | ((int)(1 + 42 * ((int)((((int)(1)) | ((int)(1))))) * ((long)((((double)(1)) + ((double)(a.i)))))))))) * ((long)((((int)(1 + 42 * ((int)((((int)(1)) | ((int)(1))))) * ((long)((((double)(1)) + ((double)(a.i))))))) ^ ((int)(a.i)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
