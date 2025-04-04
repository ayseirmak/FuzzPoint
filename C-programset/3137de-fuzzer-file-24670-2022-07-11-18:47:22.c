/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)x != 0.0 && (x * 0.5 == x) + 41 - ((int)(((int)(x * 0.5 == x)) & ((int)(x != 0.0)))) + ((short)(((int)(x)) | ((int)(x * 0.5 == x)))) * ((int)(((double)(x != 0.0)) + ((double)(x != 0.0)))) + ((short)(((int)(x * 0.5 == x)) & ((int)(0.0)))) - ((int)(((double)(0.0)) - ((double)(x)))) + ((int)(((int)(0.0)) % ((int)(x * 0.5 == x)))) * ((int)(((int)(x)) % ((int)(x * 0.5 == x))))))
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
