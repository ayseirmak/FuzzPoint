/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = (4.1);
  x *= (2.4) + 42 + ((int)(((double)(x)) + ((double)(x)))) - ((short)(((double)(x)) - ((double)(2.4)))) * ((int)(((double)(x)) - ((double)(2.4)))) + ((long)(((double)(2.4)) * ((double)(2.4)))) + ((int)(((double)(x)) - ((double)(x))));
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
