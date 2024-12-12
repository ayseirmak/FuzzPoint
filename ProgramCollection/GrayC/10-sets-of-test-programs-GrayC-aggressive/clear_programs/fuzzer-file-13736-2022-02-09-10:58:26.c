/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return (3); }
  if ((-1))
    return (0x8);
  else
    return (7);
}
int main(void)
{
  double x = -(6.8);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
