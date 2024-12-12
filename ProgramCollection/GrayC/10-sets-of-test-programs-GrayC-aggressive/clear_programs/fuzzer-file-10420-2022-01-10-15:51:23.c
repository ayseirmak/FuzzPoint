/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)((int)x != 0.0 && (x * 0.5 == x) + 42 +((int)((((int)(0.0)) |((int)((x * 0.5 == x))))))-((short)((((double)(x)) *((double)(x)))))-((int)((((int)(x)) &((int)(x)))))+((int)((((int)(x != 0.0)) |((int)((x * 0.5 == x))))))-((int)((((int)(x)) %((int)((x * 0.5 == x))))))-((short)((((int)((x * 0.5 == x))) %((int)(x)))))+((long)((((double)(x)) +((double)(x)))))-((long)((((int)(0.0)) &((int)(0.0)))))-((long)((((double)(x != 0.0)) *((double)(0.0)))))) + 42 +((short)((((int)(0.0)) >>((int)(0.0)))))*((short)((((int)(0.0)) |((int)(((long)((((int)(0.0)) &((int)(0.0))))))))))-((int)((((int)((x * 0.5 == x) + 42 +((int)((((int)(0.0)) |((int)((x * 0.5 == x))))))-((short)((((double)(x)) *((double)(x)))))-((int)((((int)(x)) &((int)(x)))))+((int)((((int)(x != 0.0)) |((int)((x * 0.5 == x))))))-((int)((((int)(x)) %((int)((x * 0.5 == x))))))-((short)((((int)((x * 0.5 == x))) %((int)(x)))))+((long)((((double)(x)) +((double)(x)))))-((long)((((int)(0.0)) &((int)(0.0))))))) ^((int)((int)x)))))-((int)((((int)((int)x != 0.0)) %((int)(((long)((((int)(0.0)) &((int)(0.0))))))))))*((short)((((int)((x * 0.5 == x) + 42 +((int)((((int)(0.0)) |((int)((x * 0.5 == x))))))-((short)((((double)(x)) *((double)(x)))))-((int)((((int)(x)) &((int)(x)))))+((int)((((int)(x != 0.0)) |((int)((x * 0.5 == x))))))-((int)((((int)(x)) %((int)((x * 0.5 == x))))))-((short)((((int)((x * 0.5 == x))) %((int)(x)))))+((long)((((double)(x)) +((double)(x)))))-((long)((((int)(0.0)) &((int)(0.0)))))-((long)((((double)(x != 0.0)) *((double)(0.0))))))) |((int)(((long)((((double)(x != 0.0)) *((double)(0.0))))))))))*((int)((((int)(((long)((((double)(x)) +((double)(x))))))) ^((int)(((long)((((int)(0.0)) &((int)(0.0))))))))))+((short)((((int)(((long)((((double)(x != 0.0)) *((double)(0.0))))))) <<((int)(((long)((((int)(0.0)) &((int)(0.0))))))))))))
    { return 1; }
  if (((int)((int)__builtin_copysign(1.0, x) < 0.0 + 42 *((long)((((double)(__builtin_copysign(1.0, x))) *((double)(__builtin_copysign(1.0, x))))))*((long)((((double)(0.0)) *((double)(0.0)))))+((short)((((double)(0.0)) +((double)(__builtin_copysign(1.0, x))))))+((int)((((int)(__builtin_copysign(1.0, x))) %((int)(0.0)))))-((int)((((double)(__builtin_copysign(1.0, x))) +((double)(__builtin_copysign(1.0, x))))))*((int)((((double)(__builtin_copysign(1.0, x))) -((double)(__builtin_copysign(1.0, x))))))+((short)((((double)(__builtin_copysign(1.0, x))) -((double)(0.0)))))+((int)((((double)(__builtin_copysign(1.0, x))) -((double)(__builtin_copysign(1.0, x))))))*((int)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x))))))) + 42 *((long)((((int)(((int)((((int)(__builtin_copysign(1.0, x))) %((int)(0.0))))))) |((int)(0.0 + 42 *((long)((((double)(__builtin_copysign(1.0, x))) *((double)(__builtin_copysign(1.0, x))))))*((long)((((double)(0.0)) *((double)(0.0)))))+((short)((((double)(0.0)) +((double)(__builtin_copysign(1.0, x))))))+((int)((((int)(__builtin_copysign(1.0, x))) %((int)(0.0))))))))))*((int)((((int)(((short)((((double)(__builtin_copysign(1.0, x))) -((double)(0.0))))))) ^((int)(0.0 + 42 *((long)((((double)(__builtin_copysign(1.0, x))) *((double)(__builtin_copysign(1.0, x))))))*((long)((((double)(0.0)) *((double)(0.0))))))))))))
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
