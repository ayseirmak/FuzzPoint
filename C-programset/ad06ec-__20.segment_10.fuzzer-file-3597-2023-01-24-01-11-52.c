/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (0)
    { return 1; }
  if (((int)((int)__builtin_copysign(1.0, x) < 0.0 + 41 - ((short)((((double)(0.0)) * ((double)(__builtin_copysign(1.0, x)))))) * ((long)((((int)(__builtin_copysign(1.0, x))) << ((int)(0.0))))) * ((int)((((double)(0.0)) - ((double)(0.0))))) + ((int)((((int)(__builtin_copysign(1.0, x))) & ((int)(__builtin_copysign(1.0, x))))))) + 41 - ((int)((((int)(0.0 + 41 - ((short)((((double)(0.0)) * ((double)(__builtin_copysign(1.0, x)))))) * ((long)((((int)(__builtin_copysign(1.0, x))) << ((int)(0.0))))) * ((int)((((double)(0.0)) - ((double)(0.0))))) + ((int)((((int)(__builtin_copysign(1.0, x))) & ((int)(__builtin_copysign(1.0, x)))))))) >> ((int)(((short)((((double)(0.0)) * ((double)(__builtin_copysign(1.0, x)))))) * ((long)((((int)(__builtin_copysign(1.0, x))) << ((int)(0.0))))) * ((int)((((double)(0.0)) - ((double)(0.0)))))))))) - ((long)((((double)(0.0)) + ((double)(0.0))))) * ((int)((((int)(0.0 + 41 - ((short)((((double)(0.0)) * ((double)(__builtin_copysign(1.0, x)))))) * ((long)((((int)(__builtin_copysign(1.0, x))) << ((int)(0.0))))) * ((int)((((double)(0.0)) - ((double)(0.0))))))) << ((int)(0.0 + 41 - ((short)((((double)(0.0)) * ((double)(__builtin_copysign(1.0, x)))))) * ((long)((((int)(__builtin_copysign(1.0, x))) << ((int)(0.0))))) * ((int)((((double)(0.0)) - ((double)(0.0))))) + ((int)((((int)(__builtin_copysign(1.0, x))) & ((int)(__builtin_copysign(1.0, x)))))))))))))
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
