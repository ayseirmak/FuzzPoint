/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 41 * ((short)(((double)(x)) + ((double)(x != 0.0)))) + ((long)(((int)(x)) << ((int)(x)))) + ((short)(((int)(x)) >> ((int)(0.0)))) * ((long)(((int)(0.0)) >> ((int)(x != 0.0)))) * ((short)(((int)(x * 0.5 == x)) | ((int)(x))))))
    { return 1; }
  if (((int)__builtin_copysign(1.0, x) < 0.0 + 41 * ((int)(((int)(0.0)) | ((int)__builtin_copysign(1.0, x)))) * ((short)(((int)__builtin_copysign(1.0, x)) << ((int)__builtin_copysign(1.0, x)))) - ((short)(((int)__builtin_copysign(1.0, x)) | ((int)(0.0)))) - ((int)(((double)__builtin_copysign(1.0, x)) * ((double)(0.0)))) + ((int)(((int)__builtin_copysign(1.0, x)) | ((int)__builtin_copysign(1.0, x))))))
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
