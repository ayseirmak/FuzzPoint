/* corpus/pr68390.c */
/* { dg-do run }  */
/* { dg-options "-O2" } */

__attribute__ ((noinline))
double direct(int x, ...)
{
  return x*x;
}

__attribute__ ((noinline))
double broken(double (*indirect)(int x, ...), int v)
{
  return indirect(v);
}

int main ()
{
  double d1, d2;
  int i = 2;
  d1 = broken (direct, i) + 42 * ((short)(((int)(d1)) | ((int)broken (direct, i))));
  if (0)
    {
      __builtin_abort ();
    }
  return 0;
}
/* ProgramSourceLLVM */
