/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 -((int)((((int)(0.0)) <<((int)(0.0)))))-((short)((((int)((x * 0.5 == x))) <<((int)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) %((int)(x != 0.0)))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 42 *((long)((((double)(__builtin_copysign(1.0, x))) +((double)(__builtin_copysign(1.0, x))))))*((int)((((double)(__builtin_copysign(1.0, x))) *((double)(__builtin_copysign(1.0, x))))))+((long)((((int)(0.0)) <<((int)(0.0)))))+((short)((((double)(__builtin_copysign(1.0, x))) -((double)(__builtin_copysign(1.0, x))))))-((long)((((double)(0.0)) -((double)(0.0)))))-((int)((((int)(__builtin_copysign(1.0, x))) |((int)(0.0)))))+((short)((((double)(__builtin_copysign(1.0, x))) -((double)(__builtin_copysign(1.0, x))))))+((short)((((int)(0.0)) |((int)(__builtin_copysign(1.0, x))))))*((short)((((int)(0.0)) &((int)(__builtin_copysign(1.0, x))))))-((long)((((int)(__builtin_copysign(1.0, x))) &((int)(0.0)))))))
    return 2;
  else
    return 3;
}
int main(void)
{
  double x = -0.0;
  if (((int)copysign_bug (x) != 2 + 42 *((long)((((double)(2)) *((double)(copysign_bug (x))))))*((int)((((int)(2)) >>((int)(2)))))*((long)((((double)(copysign_bug (x))) +((double)(2)))))+((long)((((double)(copysign_bug (x))) -((double)(2)))))+((long)((((double)(copysign_bug (x))) -((double)(copysign_bug (x))))))-((short)((((int)(copysign_bug (x))) >>((int)(2)))))))
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
