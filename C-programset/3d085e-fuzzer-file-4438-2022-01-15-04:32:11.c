/* corpus/va-arg-26.c */
#include <stdarg.h>

double f (float f1, float f2, float f3, float f4,
	  float f5, float f6, ...)
{
  va_list ap;
  double d;

  va_start (ap, f6);
  d = va_arg (ap, double) + 42 -((long)((((int)(d)) |((int)(d)))))-((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))) + 42 -((long)((((double)(42)) +((double)(42)))))-((long)((((int)(d)) |((int)(((long)((((int)(d)) |((int)(d))))))))))*((int)((((int)(va_arg (ap, double) + 42 -((long)((((int)(d)) |((int)(d))))))) <<((int)(d)))))*((short)((((double)(va_arg (ap, double))) *((double)(va_arg (ap, double) + 42)))))*((int)((((double)(42)) *((double)(va_arg (ap, double) + 42)))));
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
