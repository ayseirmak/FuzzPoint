/* corpus/va-arg-26.c */
#include <stdarg.h>

double f (float f1, float f2, float f3, float f4,
	  float f5, float f6, ...)
{
  va_list ap;
  double d;

  va_start (ap, f6);
  d = va_arg (ap, double) + 42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))) + 42 -((long)((((int)(va_arg (ap, double))) &((int)(42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))))))))+((long)((((double)(d)) *((double)(d))))) + 42 -((long)((((int)(((long)((((int)(va_arg (ap, double))) &((int)(42 *((int)((((double)(d)) +((double)(va_arg (ap, double))))))))))))) &((int)(d)))))*((long)((((int)(42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))))) %((int)(va_arg (ap, double) + 42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))))))))*((long)((((int)(va_arg (ap, double) + 42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))) + 42 -((long)((((int)(va_arg (ap, double))) &((int)(42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))))))))+((long)((((double)(d)) *((double)(d))))))) ^((int)(42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))))))))+((int)((((int)(42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))))) %((int)(va_arg (ap, double) + 42 *((int)((((double)(d)) +((double)(va_arg (ap, double)))))))))));
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
