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
  fdouble (((4.2)), ((9.8)));
  exit (((32768)));
}
/* ProgramSourceLLVM */
