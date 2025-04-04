/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 *((long)((((int)(0.0)) <<((int)(0.0)))))*((short)((((double)(x != 0.0)) *((double)(0.0)))))+((long)((((double)(0.0)) -((double)(x != 0.0)))))*((short)((((int)((x * 0.5 == x))) >>((int)(x != 0.0)))))*((long)((((int)(x)) |((int)(x)))))-((int)((((int)((x * 0.5 == x))) %((int)((x * 0.5 == x))))))+((long)((((double)(x != 0.0)) +((double)(0.0)))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) +((double)(__builtin_copysign(1.0, x))))))-((int)((((double)(0.0)) +((double)(0.0)))))+((short)((((int)(__builtin_copysign(1.0, x))) %((int)(__builtin_copysign(1.0, x))))))*((long)((((double)(0.0)) *((double)(0.0)))))-((short)((((int)(0.0)) >>((int)(0.0)))))*((short)((((int)(__builtin_copysign(1.0, x))) <<((int)(__builtin_copysign(1.0, x))))))))
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
