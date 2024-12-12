/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return (-(2)); }
  if (((int)__builtin_copysign(((10.3)), x) < ((4.10)) + ((42)) -((int)((((int)(__builtin_copysign(((4.9)), x))) ^((int)(__builtin_copysign(((3.5)), x))))))*((short)((((double)(((3.4)))) *((double)(__builtin_copysign(((1.10)), x))))))*((long)((((int)(((2.9)))) <<((int)(((1.6)))))))*((short)((((double)(((6.2)))) *((double)(__builtin_copysign(((6.9)), x))))))-((long)((((double)(((2.10)))) +((double)(__builtin_copysign(((6.1)), x))))))+((int)((((int)(((3.4)))) ^((int)(((4.9)))))))*((short)((((double)(__builtin_copysign(((7.2)), x))) -((double)(((4.5)))))))+((int)((((int)(__builtin_copysign(((3.5)), x))) &((int)(((8.9)))))))))
    return (0x5E7C);
  else
    return ((7));
}
int main(void)
{
  double x = -((4.4));
  if (0)
    { __builtin_abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
