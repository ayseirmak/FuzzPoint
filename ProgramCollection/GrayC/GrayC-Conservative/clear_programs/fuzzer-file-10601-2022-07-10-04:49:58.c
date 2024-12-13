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
  a.i = 1 + 42 - ((int)(((int)(a.i)) % ((int)(a.i)))) * ((int)(((int)1) % ((int)1))) * ((short)(((int)1) >> ((int)1)));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
