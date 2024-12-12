/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return (-2); }
  if (0)
    return (-3);
  else
    return (3);
}
int main(void)
{
  double x = -(4.7);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
