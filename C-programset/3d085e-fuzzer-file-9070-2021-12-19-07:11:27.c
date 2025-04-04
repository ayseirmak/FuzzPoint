/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 -((short)((((double)(x != 0.0)) *((double)(0.0)))))-((long)((((double)(0.0)) *((double)(x)))))-((short)((((int)(x != 0.0)) >>((int)(x != 0.0)))))*((int)((((int)(0.0)) |((int)(x)))))*((short)((((double)(0.0)) -((double)(x)))))-((short)((((double)(x != 0.0)) +((double)(0.0)))))*((int)((((double)(x)) *((double)(x)))))*((long)((((int)(x != 0.0)) &((int)(x != 0.0)))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 42 +((long)((((double)(__builtin_copysign(1.0, x))) *((double)(__builtin_copysign(1.0, x))))))-((short)((((double)(0.0)) +((double)(__builtin_copysign(1.0, x))))))))
    return 2;
  else
    return 3;
}
int main(void)
{
  double x = -0.0;
  if (((int)copysign_bug (x) != 2 + 42 *((long)((((int)(copysign_bug (x))) %((int)(2)))))+((short)((((int)(copysign_bug (x))) >>((int)(copysign_bug (x))))))+((short)((((int)(copysign_bug (x))) >>((int)(2)))))))
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
