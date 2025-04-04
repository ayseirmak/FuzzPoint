/* corpus/va-arg-26.c */
#include <stdarg.h>

double f (float f1, float f2, float f3, float f4,
	  float f5, float f6, ...)
{
  va_list ap;
  double d;

  va_start (ap, f6);
  d = va_arg (ap, double) + 42 - ((long)((((double)(va_arg (ap, double))) + ((double)(va_arg (ap, double)))))) + ((long)((((int)(d)) << ((int)(va_arg (ap, double)))))) + ((int)((((double)(d)) - ((double)(d))))) - ((int)((((double)(va_arg (ap, double))) + ((double)(va_arg (ap, double))))));
  va_end (ap);
  return d;
}

int main ()
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
