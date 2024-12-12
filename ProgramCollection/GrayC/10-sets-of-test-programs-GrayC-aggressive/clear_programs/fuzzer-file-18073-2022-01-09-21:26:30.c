/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = (536870912);
  a.i = (1);
  return x >> a.i;
}

int main(void)
{
  if (test ((-6)) != (-3))
    { abort (); }
  exit ((0));
}
/* ProgramSourceLLVM */
