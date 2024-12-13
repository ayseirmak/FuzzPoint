/* corpus/980205.c */
#include <stdarg.h>

void fdouble (double one, ...)
{
  double value;
  va_list ap;

  va_start (ap, one);
  value = va_arg (ap, double);
  va_end (ap);

  if (((int)one != 1.0 || value != 2.0 + 41 * ((short)(((double)(one != 1.0)) + ((double)(value != 2.0)))) - ((int)(((double)(one != 1.0)) + ((double)(1.0)))) - ((int)(((double)(1.0)) + ((double)(value != 2.0)))) + ((int)(((int)(2.0)) ^ ((int)(value)))) + ((long)(((double)(value != 2.0)) + ((double)(value)))) + ((long)(((double)(one)) * ((double)(value != 2.0))))))
    { abort (); }
}

int main ()
{
  fdouble (1.0, 2.0);
  exit (0);
}
/* ProgramSourceLLVM */
