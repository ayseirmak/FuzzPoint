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
  int i = 8;
  d1 = broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))) - ((int)(((double)broken (direct, i)) + ((double)(d1)))) * ((int)(((int)broken (direct, i)) & ((int)(d1)))) - ((int)(((int)(d1)) >> ((int)(d1)))) + 42 - ((int)(((int)42) | ((int)(broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))) - ((int)(((double)broken (direct, i)) + ((double)(d1)))) * ((int)(((int)broken (direct, i)) & ((int)(d1)))))))) + ((short)(((int)(broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))))) >> ((int)(((int)(((double)broken (direct, i)) + ((double)(d1)))) * ((int)(((int)broken (direct, i)) & ((int)(d1)))))))) + ((int)(((int)(broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))) - ((int)(((double)broken (direct, i)) + ((double)(d1)))) * ((int)(((int)broken (direct, i)) & ((int)(d1)))) - ((int)(((int)(d1)) >> ((int)(d1)))))) & ((int)((int)(((int)(d1)) >> ((int)(d1))))))) + 42 + ((short)(((int)((short)(((int)(broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))))) >> ((int)(((int)(((double)broken (direct, i)) + ((double)(d1)))) * ((int)(((int)broken (direct, i)) & ((int)(d1))))))))) ^ ((int)(broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))))))) + ((long)(((int)((short)(((int)(broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))))) >> ((int)(((int)(((double)broken (direct, i)) + ((double)(d1)))) * ((int)(((int)broken (direct, i)) & ((int)(d1))))))))) | ((int)42))) - ((long)(((int)((int)(((int)(d1)) >> ((int)(d1))))) | ((int)(broken (direct, i) + 42 + ((int)(((double)(d1)) - ((double)(d1)))) - ((int)(((double)broken (direct, i)) + ((double)(d1)))) * ((int)(((int)broken (direct, i)) & ((int)(d1)))) - ((int)(((int)(d1)) >> ((int)(d1)))) + 42))));
  if (0)
    {
      __builtin_abort ();
    }
  return 0;
}
/* ProgramSourceLLVM */
