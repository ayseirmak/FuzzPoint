/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if ((-1))
    { return (-(0xE73)); }
  if (0)
    return (0x14);
  else
    return (0x3C9);
}
int main(void)
{
  double x = -((8.1));
  if (0)
    { __builtin_abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
