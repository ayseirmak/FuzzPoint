/* corpus/980205.c */
#include <stdarg.h>

void fdouble (double one, ...)
{
  double value;
  va_list ap;

  va_start (ap, one);
  ;
  va_end (ap);

  if (0)
    { abort (); }
}

int main ()
{
  fdouble ((2.5), (5.10));
  exit ((0));
}
/* ProgramSourceLLVM */
