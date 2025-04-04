/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = 0x1.0p-500L + 42 + ((long)(((double)(x)) + ((double)(0x1.0p-500L))));
  x *= 0x1.0p-522L;
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
