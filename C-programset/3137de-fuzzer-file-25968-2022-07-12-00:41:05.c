/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = 0x1.0p-500L + 42 * ((short)(((int)(0x1.0p-500L)) & ((int)(0x1.0p-500L)))) - ((short)(((double)(0x1.0p-500L)) + ((double)(x)))) + ((short)(((double)(x)) + ((double)(x))));
  0x1.0p-522L + 42 - ((long)(((int)(0x1.0p-522L)) & ((int)(x)))) + ((short)(((int)(0x1.0p-522L)) & ((int)(0x1.0p-522L)))) + ((long)(((int)(x)) ^ ((int)(0x1.0p-522L)))) + ((int)(((double)(x)) + ((double)(0x1.0p-522L)))) + ((int)(((double)(0x1.0p-522L)) + ((double)(0x1.0p-522L))));
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
