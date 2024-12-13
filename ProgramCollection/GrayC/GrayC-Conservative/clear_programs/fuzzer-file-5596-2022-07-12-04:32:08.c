/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = 0x1.0p-500L + 42 - ((short)(((int)(x)) << ((int)(0x1.0p-500L)))) + 42 + ((short)(((int)(0x1.0p-500L)) | ((int)((short)(((int)(x)) << ((int)(0x1.0p-500L))))))) + ((short)(((int)42) >> ((int)(x)))) * ((int)(((int)(x)) & ((int)(0x1.0p-500L))));
  0x1.0p-522L;
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
