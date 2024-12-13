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
  a.i = 1;
  return x >> a.i;
}

int main(void)
{
  if (((int)test (5) != 2 + 41 * ((long)(((int)2) >> ((int)2))) * ((int)(((int)test (5)) >> ((int)2))) - ((int)(((int)test (5)) % ((int)2))) - ((int)(((double)2) + ((double)test (5)))) - ((long)(((int)test (5)) >> ((int)test (5)))) + ((int)(((double)test (5)) + ((double)2))) + ((int)(((double)2) - ((double)2)))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
