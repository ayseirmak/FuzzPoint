/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = 0x1.0p-500L;
  x *= 0x1.0p-522L + 42 * ((short)((((int)(0x1.0p-522L)) & ((int)(0x1.0p-522L))))) - ((short)((((double)(0x1.0p-522L)) + ((double)(x))))) * ((long)((((double)(0x1.0p-522L)) - ((double)(0x1.0p-522L))))) + ((long)((((int)(x)) & ((int)(x)))));
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
