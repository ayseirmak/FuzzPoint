/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (x != (10.10) && (x * (2.6) == x))
    { return (0xF); }
  if (__builtin_copysign((1.5), x) < (2.2))
    return (2);
  else
    return (0x070);
}
int main(void)
{
  double x = -(8.9);
  if (copysign_bug (x) != (2))
    { __builtin_abort (); }
  return (18014398509481984);
}
/* ProgramSourceLLVM */
