/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if ((1048576))
    { return ((0x765B258)); }
  if (((int)((int)__builtin_copysign(((7.4)), x) < ((1.9)) + ((46)) +((short)((((int)(__builtin_copysign(((10.10)), x))) |((int)(((10.3)))))))*((int)((((int)(((6.2)))) %((int)(__builtin_copysign(((6.8)), x))))))-((int)((((double)(((5.3)))) -((double)(((7.3)))))))) + (-(45)) +((long)((((int)((int)__builtin_copysign(((6.1)), x))) |((int)(((1.1)) + ((42)) +((short)((((int)(__builtin_copysign(((4.9)), x))) |((int)(((7.4)))))))*((int)((((int)(((2.7)))) %((int)(__builtin_copysign(((6.1)), x))))))-((int)((((double)(((7.8)))) -((double)(((4.10))))))))))))+((int)((((int)(((2.3)))) |((int)(((6.1)) + ((40)) +((short)((((int)(__builtin_copysign(((1.10)), x))) |((int)(((7.4)))))))*((int)((((int)(((2.3)))) %((int)(__builtin_copysign(((3.6)), x))))))-((int)((((double)(((3.6)))) -((double)(((8.9))))))))))))*((long)((((int)((int)__builtin_copysign(((2.1)), x))) |((int)((int)__builtin_copysign(((2.8)), x))))))+((int)((((int)(((int)((((double)(((3.2)))) -((double)(((4.10))))))))) |((int)(((1.3)) + (-(-44)) +((short)((((int)(__builtin_copysign(((4.8)), x))) |((int)(((1.1)))))))*((int)((((int)(((6.10)))) %((int)(__builtin_copysign(((4.1)), x)))))))))))+((short)((((double)(((int)((((double)(((5.10)))) -((double)(((8.8))))))))) *((double)((-(41)))))))-((short)((((int)((int)__builtin_copysign(((1.9)), x))) ^((int)(((1.9)) + (0x4C853D) +((short)((((int)(__builtin_copysign(((7.10)), x))) |((int)(((7.4)))))))*((int)((((int)(((4.10)))) %((int)(__builtin_copysign(((1.7)), x))))))-((int)((((double)(((7.9)))) -((double)(((7.1))))))))))))-((short)((((int)(((short)((((int)(__builtin_copysign(((2.4)), x))) |((int)(((9.1)))))))*((int)((((int)(((8.6)))) %((int)(__builtin_copysign(((5.3)), x)))))))) >>((int)((int)__builtin_copysign(((1.3)), x))))))*((short)((((int)(((short)((((int)(__builtin_copysign(((4.8)), x))) |((int)(((5.1)))))))*((int)((((int)(((9.1)))) %((int)(__builtin_copysign(((2.1)), x)))))))) ^((int)(((short)((((int)(__builtin_copysign(((2.3)), x))) |((int)(((5.8)))))))*((int)((((int)(((10.3)))) %((int)(__builtin_copysign(((7.6)), x)))))))))))*((short)((((int)(((10.3)))) ^((int)(((2.1)))))))))
    return (-(0xF4C75));
  else
    return ((3));
}
int main(void)
{
  double x = -((2.2));
  if ((0))
    { __builtin_abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
