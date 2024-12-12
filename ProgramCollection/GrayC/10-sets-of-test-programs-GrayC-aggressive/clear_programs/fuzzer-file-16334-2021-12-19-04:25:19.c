/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return ((0xFA7E07)); }
  if (0)
    return (-(131));
  else
    return ((0xBFDF5));
}
int main(void)
{
  double x = -((9.1));
  if (0)
    { __builtin_abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
