/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 41 * ((int)((((double)(0.0)) - ((double)(__builtin_copysign(1.0, x)))))) - ((int)((((double)(__builtin_copysign(1.0, x))) + ((double)(__builtin_copysign(1.0, x)))))) * ((short)((((int)(__builtin_copysign(1.0, x))) | ((int)(0.0)))))))
    return 2;
  else
    return 3;
}
int main(void)
{
  double x = -0.0;
  if (0)
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
