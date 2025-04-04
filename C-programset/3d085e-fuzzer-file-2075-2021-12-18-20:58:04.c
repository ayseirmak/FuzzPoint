/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 *((short)((((int)(x != 0.0)) |((int)(x)))))+((int)((((double)(x)) -((double)(x)))))+((long)((((int)(x)) &((int)(x != 0.0)))))*((long)((((double)(x)) +((double)(x)))))*((long)((((int)(x)) %((int)(x)))))-((int)((((int)(0.0)) <<((int)((x * 0.5 == x))))))-((int)((((int)((x * 0.5 == x))) ^((int)(0.0)))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 42 +((short)((((int)(__builtin_copysign(1.0, x))) |((int)(0.0)))))*((int)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x))))))-((int)((((double)(0.0)) -((double)(0.0)))))))
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
