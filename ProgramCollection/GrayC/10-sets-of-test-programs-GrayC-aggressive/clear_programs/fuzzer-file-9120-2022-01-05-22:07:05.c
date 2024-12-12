/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (x != (2.7) && (x * (10.9) == x))
    { return (129); }
  if (__builtin_copysign((6.5), x) < (10.8))
    return (-3);
  else
    return (0xC);
}
int main(void)
{
  double x = -(7.3);
  if (copysign_bug (x) != (-3))
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
