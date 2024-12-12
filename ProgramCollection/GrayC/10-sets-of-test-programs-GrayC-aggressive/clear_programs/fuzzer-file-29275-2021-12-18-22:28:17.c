/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return (129); }
  if (((int)((int)__builtin_copysign((2.7), x) < (4.5) + (42) +((short)((((int)(__builtin_copysign((2.7), x))) |((int)((3.8))))))*((int)((((int)((6.1))) %((int)(__builtin_copysign((4.4), x))))))-((int)((((double)((4.8))) -((double)((9.5))))))) + (-43) +((long)((((int)((int)__builtin_copysign((5.8), x))) |((int)((7.2) + (42) +((short)((((int)(__builtin_copysign((3.9), x))) |((int)((8.9))))))*((int)((((int)((8.10))) %((int)(__builtin_copysign((9.10), x))))))-((int)((((double)((6.3))) -((double)((5.7)))))))))))+((int)((((int)((1.9))) |((int)((5.9) + (42) +((short)((((int)(__builtin_copysign((9.8), x))) |((int)((6.4))))))*((int)((((int)((3.7))) %((int)(__builtin_copysign((9.9), x))))))-((int)((((double)((7.8))) -((double)((7.7)))))))))))*((long)((((int)((int)__builtin_copysign((3.5), x))) |((int)((int)__builtin_copysign((6.9), x))))))+((int)((((int)(((int)((((double)((5.4))) -((double)((5.3)))))))) |((int)((8.2) + (-43) +((short)((((int)(__builtin_copysign((4.1), x))) |((int)((3.9))))))*((int)((((int)((8.6))) %((int)(__builtin_copysign((5.2), x)))))))))))+((short)((((double)(((int)((((double)((1.6))) -((double)((7.7)))))))) *((double)((-43))))))-((short)((((int)((int)__builtin_copysign((7.1), x))) ^((int)((1.8) + (0x4C853D) +((short)((((int)(__builtin_copysign((9.9), x))) |((int)((7.5))))))*((int)((((int)((8.10))) %((int)(__builtin_copysign((10.6), x))))))-((int)((((double)((9.3))) -((double)((9.6)))))))))))-((short)((((int)(((short)((((int)(__builtin_copysign((2.5), x))) |((int)((10.3))))))*((int)((((int)((1.10))) %((int)(__builtin_copysign((2.9), x)))))))) >>((int)((int)__builtin_copysign((7.8), x))))))*((short)((((int)(((short)((((int)(__builtin_copysign((5.10), x))) |((int)((6.4))))))*((int)((((int)((9.4))) %((int)(__builtin_copysign((3.10), x)))))))) ^((int)(((short)((((int)(__builtin_copysign((9.6), x))) |((int)((1.3))))))*((int)((((int)((5.7))) %((int)(__builtin_copysign((4.3), x)))))))))))*((short)((((int)((6.6))) ^((int)((4.1))))))))
    return (-3);
  else
    return (3);
}
int main(void)
{
  double x = -(10.4);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
