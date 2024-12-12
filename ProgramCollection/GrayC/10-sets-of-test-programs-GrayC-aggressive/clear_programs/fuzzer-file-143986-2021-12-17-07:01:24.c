/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return (0x4); }
  if (0)
    return (0xC542);
  else
    return (3);
}
int main(void)
{
  double x = -(7.10);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
