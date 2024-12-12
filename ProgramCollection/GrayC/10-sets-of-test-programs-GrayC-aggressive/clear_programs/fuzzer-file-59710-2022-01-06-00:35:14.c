/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 -((long)((((int)(x)) >>((int)((x * 0.5 == x))))))*((int)((((double)(x)) *((double)(0.0)))))-((int)((((double)(0.0)) +((double)(x)))))-((int)((((int)((x * 0.5 == x))) %((int)(x != 0.0)))))*((int)((((double)(0.0)) -((double)(0.0)))))+((long)((((int)((x * 0.5 == x))) <<((int)(x)))))*((short)((((int)((x * 0.5 == x))) ^((int)(x)))))-((short)((((double)(x)) -((double)(x != 0.0)))))-((long)((((int)(0.0)) <<((int)((x * 0.5 == x))))))+((long)((((double)(x)) -((double)(0.0)))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 42 *((int)((((double)(0.0)) *((double)(__builtin_copysign(1.0, x))))))-((short)((((double)(__builtin_copysign(1.0, x))) +((double)(__builtin_copysign(1.0, x))))))))
    return 2;
  else
    return 3;
}
int main(void)
{
  double x = -0.0;
  if (0)
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
