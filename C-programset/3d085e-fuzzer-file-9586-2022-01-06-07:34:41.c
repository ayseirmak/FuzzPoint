/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (x != (8.3) && (x * (8.3) == x))
    { return (0xE7); }
  if (__builtin_copysign((8.1), x) < (6.10))
    return (2);
  else
    return (-4);
}
int main(void)
{
  double x = -(10.10);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
