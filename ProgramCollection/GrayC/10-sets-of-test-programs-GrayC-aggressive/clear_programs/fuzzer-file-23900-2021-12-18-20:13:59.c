/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 42 *((short)((((int)((x * 0.5 == x))) >>((int)((x * 0.5 == x))))))*((long)((((int)(x != 0.0)) ^((int)(0.0)))))+((short)((((int)(x != 0.0)) <<((int)(x)))))-((int)((((int)(x != 0.0)) |((int)((x * 0.5 == x))))))*((short)((((int)(0.0)) >>((int)(x != 0.0)))))+((int)((((int)((x * 0.5 == x))) <<((int)(x != 0.0)))))+((long)((((double)(x != 0.0)) -((double)(x)))))))
    { return 1; }
  if (0)
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
