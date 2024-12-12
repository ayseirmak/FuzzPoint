/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return 1; }
  if (((int)((int)__builtin_copysign(1.0, x) < 0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) *((double)(0.0)))))+((int)((((int)(0.0)) ^((int)(0.0)))))) + 42 +((int)((((int)(0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) *((double)(0.0)))))+((int)((((int)(0.0)) ^((int)(0.0))))))) |((int)(0.0)))))+((int)((((int)((int)__builtin_copysign(1.0, x))) %((int)(0.0 + 42)))))+((short)((((double)((int)__builtin_copysign(1.0, x))) -((double)(((int)((((int)(0.0)) ^((int)(0.0))))))))))+((long)((((int)((int)__builtin_copysign(1.0, x))) <<((int)(0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) *((double)(0.0))))))))))+((short)((((double)(((int)((((int)(0.0)) ^((int)(0.0))))))) *((double)(0.0)))))+((short)((((int)(0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) *((double)(0.0))))))) &((int)(42)))))-((long)((((int)(0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) *((double)(0.0)))))+((int)((((int)(0.0)) ^((int)(0.0))))))) &((int)((int)__builtin_copysign(1.0, x))))))-((short)((((int)(0.0 + 42 -((int)((((double)(__builtin_copysign(1.0, x))) *((double)(0.0))))))) %((int)(0.0 + 42)))))*((long)((((double)(42)) +((double)(((int)((((int)(0.0)) ^((int)(0.0))))))))))))
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
