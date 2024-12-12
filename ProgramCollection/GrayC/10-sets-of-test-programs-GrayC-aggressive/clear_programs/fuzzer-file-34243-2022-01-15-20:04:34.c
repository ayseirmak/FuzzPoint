/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)((int)x != 0.0 && (x * 0.5 == x) + 42 -((long)((((int)(0.0)) |((int)(x != 0.0)))))-((long)((((int)((x * 0.5 == x))) <<((int)((x * 0.5 == x))))))+((long)((((double)(x != 0.0)) +((double)(0.0)))))*((long)((((int)(0.0)) |((int)(x)))))+((long)((((int)((x * 0.5 == x))) <<((int)(x)))))) + 42 *((short)((((int)(((long)((((double)(x != 0.0)) +((double)(0.0)))))*((long)((((int)(0.0)) |((int)(x))))))) <<((int)((int)x != 0.0)))))-((int)((((int)((x * 0.5 == x) + 42)) &((int)(((long)((((int)((x * 0.5 == x))) <<((int)((x * 0.5 == x)))))))))))*((int)((((int)((x * 0.5 == x) + 42 -((long)((((int)(0.0)) |((int)(x != 0.0))))))) ^((int)((x * 0.5 == x) + 42 -((long)((((int)(0.0)) |((int)(x != 0.0))))))))))*((int)((((int)(((long)((((int)(0.0)) |((int)(x))))))) ^((int)(((long)((((double)(x != 0.0)) +((double)(0.0))))))))))+((int)((((int)((int)x != 0.0)) >>((int)((x * 0.5 == x) + 42)))))+((short)((((int)((x * 0.5 == x) + 42 -((long)((((int)(0.0)) |((int)(x != 0.0)))))-((long)((((int)((x * 0.5 == x))) <<((int)((x * 0.5 == x))))))+((long)((((double)(x != 0.0)) +((double)(0.0)))))*((long)((((int)(0.0)) |((int)(x)))))+((long)((((int)((x * 0.5 == x))) <<((int)(x))))))) |((int)(((long)((((int)(0.0)) |((int)(x != 0.0))))))))))-((short)((((int)(0.0)) &((int)(((long)((((double)(x != 0.0)) +((double)(0.0))))))))))*((long)((((int)((x * 0.5 == x) + 42 -((long)((((int)(0.0)) |((int)(x != 0.0)))))-((long)((((int)((x * 0.5 == x))) <<((int)((x * 0.5 == x)))))))) >>((int)(0.0)))))))
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
