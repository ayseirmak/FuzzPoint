/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 *((short)((((double)(x)) -((double)(0.0)))))*((long)((((int)((x * 0.5 == x))) |((int)(0.0)))))*((short)((((int)(0.0)) %((int)((x * 0.5 == x))))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 42 -((short)((((double)(0.0)) -((double)(__builtin_copysign(1.0, x))))))*((int)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x))))))*((int)((((double)(0.0)) *((double)(__builtin_copysign(1.0, x))))))+((short)((((int)(__builtin_copysign(1.0, x))) >>((int)(0.0)))))+((short)((((double)(__builtin_copysign(1.0, x))) -((double)(0.0)))))*((short)((((double)(__builtin_copysign(1.0, x))) +((double)(__builtin_copysign(1.0, x))))))-((long)((((int)(__builtin_copysign(1.0, x))) >>((int)(__builtin_copysign(1.0, x))))))))
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
