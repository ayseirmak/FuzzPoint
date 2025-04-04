/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return 1; }
  if (((int)((int)__builtin_copysign(1.0, x) < 0.0 + 42 +((short)((((int)(__builtin_copysign(1.0, x))) |((int)(0.0)))))*((int)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x))))))-((int)((((double)(0.0)) -((double)(0.0)))))) + 42 *((long)((((int)(0.0 + 42 +((short)((((int)(__builtin_copysign(1.0, x))) |((int)(0.0)))))*((int)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x)))))))) &((int)(0.0 + 42)))))*((int)((((int)(((short)((((int)(__builtin_copysign(1.0, x))) |((int)(0.0)))))*((int)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x)))))))) %((int)(0.0)))))-((int)((((int)(0.0 + 42 +((short)((((int)(__builtin_copysign(1.0, x))) |((int)(0.0)))))*((int)((((int)(0.0)) %((int)(__builtin_copysign(1.0, x)))))))) &((int)(((int)((((double)(0.0)) -((double)(0.0))))))))))))
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
