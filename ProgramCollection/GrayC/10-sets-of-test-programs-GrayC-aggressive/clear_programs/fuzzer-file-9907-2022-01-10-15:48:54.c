/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return 1; }
  if (__builtin_copysign(1.0, x) < 0.0)
    return 2;
  else
    return 3;
}
int main(void)
{
  double x = -0.0;
  if (copysign_bug (x) != 2)
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
