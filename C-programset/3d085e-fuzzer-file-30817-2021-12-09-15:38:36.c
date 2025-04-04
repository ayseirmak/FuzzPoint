/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = 0x1.0p-500L + 42 +((int)((((double)(0x1.0p-500L)) +((double)(0x1.0p-500L)))))+((int)((((double)(x)) -((double)(0x1.0p-500L)))))*((int)((((int)(0x1.0p-500L)) &((int)(0x1.0p-500L)))));
  x *= 0x1.0p-522L + 42 -((int)((((double)(x)) *((double)(0x1.0p-522L)))));
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
