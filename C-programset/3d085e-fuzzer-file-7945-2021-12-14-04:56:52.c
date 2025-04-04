/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (x != (4.1) && (x * (1.3) == x))
    { return (0xC787); }
  if (__builtin_copysign((9.5), x) < (1.8))
    return (0x4225);
  else
    return (0x4C);
}
int main(void)
{
  double x = -(6.5);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
