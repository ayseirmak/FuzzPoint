/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return (0xEC9); }
  if (0)
    return (10);
  else
    return (-4);
}
int main(void)
{
  double x = -(4.4);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
