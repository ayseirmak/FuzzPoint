/* corpus/va-arg-26.c */
#include <stdarg.h>

double f (float f1, float f2, float f3, float f4,
	  float f5, float f6, ...)
{
  va_list ap;
  double d;

  va_start (ap, f6);
  d = va_arg (ap, double) + 42 - ((short)((((int)(va_arg (ap, double))) % ((int)(d))))) + ((short)((((int)(d)) % ((int)(d))))) - ((short)((((int)(va_arg (ap, double))) & ((int)(va_arg (ap, double)))))) + ((long)((((double)(d)) * ((double)(d))))) + 42 - ((short)((((int)(((short)((((int)(va_arg (ap, double))) % ((int)(d))))))) % ((int)(d))))) + ((short)((((int)(va_arg (ap, double) + 42)) % ((int)(va_arg (ap, double) + 42 - ((short)((((int)(va_arg (ap, double))) % ((int)(d)))))))))) - ((short)((((int)(((short)((((int)(va_arg (ap, double))) & ((int)(va_arg (ap, double)))))))) & ((int)(((long)((((double)(d)) * ((double)(d)))))))))) + ((long)((((double)(va_arg (ap, double) + 42 - ((short)((((int)(va_arg (ap, double))) % ((int)(d))))))) * ((double)(va_arg (ap, double) + 42 - ((short)((((int)(va_arg (ap, double))) % ((int)(d))))) + ((short)((((int)(d)) % ((int)(d))))))))));
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
