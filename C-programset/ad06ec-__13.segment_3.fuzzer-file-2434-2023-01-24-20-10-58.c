/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)((int)x != 0.0 && (x * 0.5 == x) + 41 * ((short)((((double)(x != 0.0)) * ((double)(0.0))))) * ((long)((((double)(x)) * ((double)(x != 0.0))))) * ((long)((((double)(x)) + ((double)(x))))) + ((short)((((double)(x != 0.0)) * ((double)(0.0))))) - ((short)((((int)(x != 0.0)) % ((int)(x))))) + ((int)((((int)((x * 0.5 == x))) >> ((int)(0.0))))) * ((int)((((int)((x * 0.5 == x))) << ((int)(x != 0.0))))) * ((long)((((double)(0.0)) * ((double)(0.0))))) + ((short)((((double)(0.0)) + ((double)(0.0)))))) + 41 * ((long)((((int)(((int)((((int)((x * 0.5 == x))) >> ((int)(0.0))))) * ((int)((((int)((x * 0.5 == x))) << ((int)(x != 0.0))))) * ((long)((((double)(0.0)) * ((double)(0.0))))))) << ((int)(((long)((((double)(x)) + ((double)(x)))))))))) + ((short)((((int)(41 * ((short)((((double)(x != 0.0)) * ((double)(0.0))))))) >> ((int)(41 * ((short)((((double)(x != 0.0)) * ((double)(0.0)))))))))) * ((long)((((int)(((short)((((double)(0.0)) + ((double)(0.0))))))) ^ ((int)(((short)((((int)(x != 0.0)) % ((int)(x)))))))))) * ((int)((((int)(0.0)) | ((int)(((long)((((double)(x)) * ((double)(x != 0.0)))))))))) + ((long)((((int)((x * 0.5 == x) + 41 * ((short)((((double)(x != 0.0)) * ((double)(0.0))))) * ((long)((((double)(x)) * ((double)(x != 0.0))))) * ((long)((((double)(x)) + ((double)(x))))) + ((short)((((double)(x != 0.0)) * ((double)(0.0))))))) | ((int)(((int)((((int)((x * 0.5 == x))) >> ((int)(0.0))))) * ((int)((((int)((x * 0.5 == x))) << ((int)(x != 0.0))))) * ((long)((((double)(0.0)) * ((double)(0.0)))))))))) + ((int)((((int)(((short)((((double)(x != 0.0)) * ((double)(0.0))))))) % ((int)((x * 0.5 == x) + 41 * ((short)((((double)(x != 0.0)) * ((double)(0.0))))) * ((long)((((double)(x)) * ((double)(x != 0.0))))) * ((long)((((double)(x)) + ((double)(x))))) + ((short)((((double)(x != 0.0)) * ((double)(0.0))))) - ((short)((((int)(x != 0.0)) % ((int)(x))))) + ((int)((((int)((x * 0.5 == x))) >> ((int)(0.0))))) * ((int)((((int)((x * 0.5 == x))) << ((int)(x != 0.0))))) * ((long)((((double)(0.0)) * ((double)(0.0)))))))))) + ((short)((((int)((x * 0.5 == x) + 41 * ((short)((((double)(x != 0.0)) * ((double)(0.0))))) * ((long)((((double)(x)) * ((double)(x != 0.0))))) * ((long)((((double)(x)) + ((double)(x))))) + ((short)((((double)(x != 0.0)) * ((double)(0.0))))) - ((short)((((int)(x != 0.0)) % ((int)(x))))))) >> ((int)(41 * ((short)((((double)(x != 0.0)) * ((double)(0.0)))))))))) + ((short)((((int)((x * 0.5 == x))) | ((int)((x * 0.5 == x) + 41 * ((short)((((double)(x != 0.0)) * ((double)(0.0))))) * ((long)((((double)(x)) * ((double)(x != 0.0))))) * ((long)((((double)(x)) + ((double)(x))))) + ((short)((((double)(x != 0.0)) * ((double)(0.0)))))))))) - ((short)((((double)(((short)((((double)(0.0)) + ((double)(0.0))))))) * ((double)((int)x != 0.0))))) + ((short)((((int)((int)x != 0.0)) ^ ((int)(41 * ((short)((((double)(x != 0.0)) * ((double)(0.0))))))))))))
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
