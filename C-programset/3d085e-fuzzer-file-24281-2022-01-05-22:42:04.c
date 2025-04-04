/* corpus/980205.c */
#include <stdarg.h>

void fdouble (double one, ...)
{
  double value;
  va_list ap;

  va_start (ap, one);
  value = va_arg (ap, double);
  va_end (ap);

  if (0)
    { abort (); }
}

int main ()
{
  fdouble ((10.1), (4.9));
  exit ((0));
}
/* ProgramSourceLLVM */
