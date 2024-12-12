/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != (5.1) && (x * (3.10) == x) + (0x13) *((int)((((int)(x != (10.7))) &((int)((x * (7.6) == x))))))+((long)((((int)((x * (7.1) == x))) <<((int)(x)))))-((int)((((int)((x * (5.8) == x))) >>((int)(x)))))*((int)((((int)((x * (6.4) == x))) &((int)((9.6))))))-((long)((((int)((x * (8.10) == x))) >>((int)(x)))))-((int)((((int)(x)) %((int)((x * (7.7) == x))))))*((long)((((double)(x != (4.8))) *((double)((10.8))))))-((long)((((int)((1.8))) %((int)((x * (1.4) == x))))))-((short)((((int)((x * (2.6) == x))) >>((int)((x * (5.5) == x))))))+((long)((((int)(x != (2.7))) >>((int)((x * (6.8) == x))))))))
    { return (0x57); }
  if (((int)__builtin_copysign((7.6), x) < (10.9) + (0xE5F9BC) -((int)((((double)((1.6))) +((double)((5.4))))))-((long)((((double)(__builtin_copysign((9.6), x))) -((double)(__builtin_copysign((7.9), x))))))+((short)((((double)(__builtin_copysign((4.6), x))) *((double)((10.4))))))))
    return (2);
  else
    return (6);
}
int main(void)
{
  double x = -(4.2);
  if (0)
    { __builtin_abort (); }
  return (0);
}
/* ProgramSourceLLVM */
