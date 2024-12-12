/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)((int)x != 0.0 && (x * 0.5 == x) + 42 -((long)((((double)(0.0)) -((double)(x != 0.0)))))-((short)((((int)(0.0)) <<((int)(x != 0.0)))))+((int)((((int)(0.0)) <<((int)(x)))))+((long)((((int)(x)) |((int)(x != 0.0)))))) + 42 *((long)((((int)(((int)((((int)(0.0)) <<((int)(x))))))) |((int)((int)x != 0.0)))))*((long)((((int)(0.0)) %((int)(((int)((((int)(0.0)) <<((int)(x))))))))))*((int)((((int)((int)x != 0.0)) |((int)(((long)((((int)(x)) |((int)(x != 0.0))))))))))+((long)((((int)((int)x != 0.0)) |((int)(((int)((((int)(0.0)) <<((int)(x))))))))))))
    { return 1; }
  if (((int)((int)__builtin_copysign(1.0, x) < 0.0 + 42 *((short)((((int)(0.0)) >>((int)(__builtin_copysign(1.0, x))))))*((long)((((int)(__builtin_copysign(1.0, x))) ^((int)(0.0)))))*((short)((((double)(0.0)) -((double)(__builtin_copysign(1.0, x))))))-((int)((((int)(__builtin_copysign(1.0, x))) ^((int)(0.0)))))+((long)((((double)(0.0)) +((double)(0.0)))))*((long)((((double)(0.0)) -((double)(0.0)))))) + 42 +((int)((((int)(((long)((((double)(0.0)) +((double)(0.0)))))*((long)((((double)(0.0)) -((double)(0.0))))))) %((int)(0.0 + 42 *((short)((((int)(0.0)) >>((int)(__builtin_copysign(1.0, x))))))*((long)((((int)(__builtin_copysign(1.0, x))) ^((int)(0.0)))))*((short)((((double)(0.0)) -((double)(__builtin_copysign(1.0, x))))))-((int)((((int)(__builtin_copysign(1.0, x))) ^((int)(0.0))))))))))))
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
