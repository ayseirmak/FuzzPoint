/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != (8.3) && (x * (3.6) == x) + (42) -((short)((((int)((x * (6.6) == x))) ^((int)((x * (4.3) == x))))))-((int)((((double)(x != (9.8))) +((double)(x)))))*((short)((((int)(x != (1.8))) %((int)(x != (7.8))))))*((short)((((int)(x != (2.9))) ^((int)((8.3))))))-((short)((((int)((10.8))) &((int)(x)))))+((short)((((int)((8.8))) %((int)((x * (2.3) == x))))))))
    { return (-2); }
  if (((int)__builtin_copysign((4.6), x) < (8.6) + (-43) +((int)((((double)(__builtin_copysign((6.3), x))) +((double)(__builtin_copysign((4.2), x))))))-((short)((((int)(__builtin_copysign((5.6), x))) |((int)(__builtin_copysign((1.10), x))))))+((long)((((int)((1.4))) >>((int)((9.3))))))-((short)((((double)((6.3))) +((double)((1.4))))))+((short)((((int)((9.10))) &((int)(__builtin_copysign((4.8), x))))))-((short)((((int)((1.6))) |((int)((4.5))))))-((long)((((int)((9.7))) &((int)((4.6))))))))
    return (66);
  else
    return (19);
}
int main(void)
{
  double x = -(5.10);
  if (0)
    { __builtin_abort (); }
  return (68719476736);
}
/* ProgramSourceLLVM */
