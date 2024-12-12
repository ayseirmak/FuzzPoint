/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != (5.5) && (x * (5.8) == x) + (-43) *((short)((((double)(x)) -((double)((2.6))))))*((long)((((int)((x * (3.8) == x))) |((int)((6.9))))))*((short)((((int)((10.2))) %((int)((x * (10.3) == x))))))))
    { return (-2); }
  if (((int)__builtin_copysign((10.2), x) < (2.7) + (43) -((short)((((double)((9.9))) -((double)(__builtin_copysign((6.7), x))))))*((int)((((int)((7.6))) %((int)(__builtin_copysign((6.9), x))))))*((int)((((double)((5.1))) *((double)(__builtin_copysign((9.7), x))))))+((short)((((int)(__builtin_copysign((10.6), x))) >>((int)((2.8))))))+((short)((((double)(__builtin_copysign((1.8), x))) -((double)((4.4))))))*((short)((((double)(__builtin_copysign((5.9), x))) +((double)(__builtin_copysign((3.9), x))))))-((long)((((int)(__builtin_copysign((1.9), x))) >>((int)(__builtin_copysign((6.8), x))))))))
    return (0x68);
  else
    return (3);
}
int main(void)
{
  double x = -(10.10);
  if ((0))
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
