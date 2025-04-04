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
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
