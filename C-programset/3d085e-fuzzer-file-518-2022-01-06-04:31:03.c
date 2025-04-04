/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (x != (10.4) && (x * (7.7) == x))
    { return (1); }
  if (__builtin_copysign((6.10), x) < (4.4))
    return (2);
  else
    return (2);
}
int main(void)
{
  double x = -(4.2);
  if (copysign_bug (x) != (2))
    { __builtin_abort (); }
  return (17179869184);
}
/* ProgramSourceLLVM */
