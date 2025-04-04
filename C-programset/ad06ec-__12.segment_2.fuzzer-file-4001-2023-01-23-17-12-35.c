/* corpus/va-arg-26.c */
#include <stdarg.h>

double f (float f1, float f2, float f3, float f4,
	  float f5, float f6, ...)
{
  va_list ap;
  double d;

  va_start (ap, f6);
  d = va_arg (ap, double);
  va_end (ap);
  return d;
}

int main ()
{
  if (((int)f (1, 2, 3, 4, 5, 6, 7.0) != 7.0 + 41 * ((short)((((int)(f (1, 2, 3, 4, 5, 6, 7.0))) >> ((int)(f (1, 2, 3, 4, 5, 6, 7.0)))))) * ((long)((((int)(7.0)) ^ ((int)(f (1, 2, 3, 4, 5, 6, 7.0)))))) * ((short)((((double)(f (1, 2, 3, 4, 5, 6, 7.0))) * ((double)(7.0)))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
