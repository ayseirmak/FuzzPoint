/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 41 * ((short)((((int)((x * 0.5 == x))) | ((int)((x * 0.5 == x)))))) + ((long)((((int)((x * 0.5 == x))) & ((int)(0.0))))) + ((long)((((int)((x * 0.5 == x))) << ((int)((x * 0.5 == x)))))) - ((long)((((int)((x * 0.5 == x))) | ((int)(x != 0.0)))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 41 * ((long)((((double)(__builtin_copysign(1.0, x))) * ((double)(0.0)))))))
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
