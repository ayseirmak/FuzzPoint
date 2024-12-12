/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = (1024);
  a.i = (0xA2);
  return x >> a.i;
}

int main(void)
{
  if ((0))
    { abort (); }
  exit ((524288));
}
/* ProgramSourceLLVM */
