/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = 0x1.0p-500L + 42 - ((short)(((double)(0x1.0p-500L)) + ((double)(x)))) * ((long)(((int)(x)) ^ ((int)(0x1.0p-500L))));
  x *= 0x1.0p-522L + 42 * ((long)(((int)(x)) ^ ((int)(x)))) + ((int)(((double)(x)) - ((double)(0x1.0p-522L)))) + ((short)(((int)(x)) | ((int)(x)))) + ((short)(((int)(0x1.0p-522L)) >> ((int)(0x1.0p-522L))));
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
