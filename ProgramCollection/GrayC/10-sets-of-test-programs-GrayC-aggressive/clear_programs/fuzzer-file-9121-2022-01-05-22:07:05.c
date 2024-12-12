/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return (129); }
  if (__builtin_copysign((6.5), x) < (10.8))
    return (-3);
  else
    return (0xC);
}
int main(void)
{
  double x = -(7.3);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
