/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if ((-1))
    { return (0xE12C7); }
  if (((int)__builtin_copysign((6.4), x) < (8.7) + (106) *((int)((((double)((8.8))) *((double)(__builtin_copysign((6.5), x))))))-((short)((((double)(__builtin_copysign((1.6), x))) +((double)(__builtin_copysign((5.9), x))))))))
    return (0x1);
  else
    return (3);
}
int main(void)
{
  double x = -(8.7);
  if ((0))
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
