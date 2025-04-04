/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 -((int)((((double)(x != 0.0)) *((double)(0.0)))))*((int)((((double)(x != 0.0)) -((double)(0.0)))))-((long)((((double)(x)) *((double)(0.0)))))*((long)((((double)(x != 0.0)) +((double)(x)))))-((short)((((double)(0.0)) -((double)(x)))))*((long)((((double)(x != 0.0)) +((double)(x)))))-((int)((((int)(0.0)) ^((int)((x * 0.5 == x))))))+((int)((((int)(x != 0.0)) <<((int)(x)))))-((int)((((int)(0.0)) %((int)(x != 0.0)))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 42 -((long)((((double)(0.0)) -((double)(__builtin_copysign(1.0, x))))))+((long)((((int)(__builtin_copysign(1.0, x))) %((int)(0.0)))))*((long)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x))))))-((int)((((double)(__builtin_copysign(1.0, x))) +((double)(__builtin_copysign(1.0, x))))))*((int)((((int)(__builtin_copysign(1.0, x))) ^((int)(__builtin_copysign(1.0, x))))))))
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
