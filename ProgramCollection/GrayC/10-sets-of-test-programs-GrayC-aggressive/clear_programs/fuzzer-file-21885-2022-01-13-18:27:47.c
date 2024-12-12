/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return 1; }
  if (((int)((int)__builtin_copysign(1.0, x) < 0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) *((double)(0.0)))))+((int)((((int)(0.0)) ^((int)(0.0)))))) + 42 -((short)((((int)(0.0)) &((int)((int)__builtin_copysign(1.0, x))))))*((long)((((double)(((int)((((int)(0.0)) ^((int)(0.0))))))) -((double)((int)__builtin_copysign(1.0, x))))))))
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
