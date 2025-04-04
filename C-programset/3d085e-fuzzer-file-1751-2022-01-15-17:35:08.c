/* corpus/va-arg-26.c */
#include <stdarg.h>

double f (float f1, float f2, float f3, float f4,
	  float f5, float f6, ...)
{
  va_list ap;
  double d;

  va_start (ap, f6);
  d = va_arg (ap, double) + (0xC00C8E) -((long)((((int)(d)) |((int)(d)))))-((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))) + (40) -((long)((((double)((40))) +((double)((-43))))))-((long)((((int)(d)) |((int)(((long)((((int)(d)) |((int)(d))))))))))*((int)((((int)(va_arg (ap, double) + (46) -((long)((((int)(d)) |((int)(d))))))) <<((int)(d)))))*((short)((((double)(va_arg (ap, double))) *((double)(va_arg (ap, double) + (42))))))*((int)((((double)((0xF67))) *((double)(va_arg (ap, double) + (-43)))))) + (-43) *((int)((((int)((46))) %((int)(((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))))))))*((long)((((double)(va_arg (ap, double) + (0xFF88))) +((double)(va_arg (ap, double))))))-((long)((((int)(((long)((((int)(d)) |((int)(d))))))) |((int)(va_arg (ap, double) + (-43) -((long)((((int)(d)) |((int)(d)))))-((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))) + (-43))))))-((int)((((double)((40))) -((double)(d)))))*((int)((((int)(((long)((((int)(d)) |((int)(((long)((((int)(d)) |((int)(d))))))))))*((int)((((int)(va_arg (ap, double) + (-43) -((long)((((int)(d)) |((int)(d))))))) <<((int)(d)))))*((short)((((double)(va_arg (ap, double))) *((double)(va_arg (ap, double) + (-43))))))*((int)((((double)((0x05))) *((double)(va_arg (ap, double) + (0x319C)))))))) %((int)(va_arg (ap, double) + (-43) -((long)((((int)(d)) |((int)(d)))))-((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))) + (10) -((long)((((double)((42))) +((double)((-43))))))))))) + 42 -((short)((((int)(va_arg (ap, double))) %((int)(((int)((((double)((40))) -((double)(d)))))*((int)((((int)(((long)((((int)(d)) |((int)(((long)((((int)(d)) |((int)(d))))))))))*((int)((((int)(va_arg (ap, double) + (-43) -((long)((((int)(d)) |((int)(d))))))) <<((int)(d)))))*((short)((((double)(va_arg (ap, double))) *((double)(va_arg (ap, double) + (-43))))))*((int)((((double)((0x05))) *((double)(va_arg (ap, double) + (0x319C)))))))) %((int)(va_arg (ap, double) + (-43) -((long)((((int)(d)) |((int)(d)))))-((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))) + (10) -((long)((((double)((42))) +((double)((-43))))))))))))))))+((long)((((int)(va_arg (ap, double))) |((int)(va_arg (ap, double) + (0xC00C8E) -((long)((((int)(d)) |((int)(d)))))-((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))) + (40))))))-((long)((((int)(va_arg (ap, double) + (0xC00C8E) -((long)((((int)(d)) |((int)(d)))))-((long)((((int)(d)) >>((int)(va_arg (ap, double))))))*((int)((((double)(d)) +((double)(d)))))*((short)((((int)(d)) |((int)(va_arg (ap, double)))))) + (40))) ^((int)(va_arg (ap, double) + (0xC00C8E) -((long)((((int)(d)) |((int)(d))))))))));
  va_end (ap);
  return d;
}

int main ()
{
  if (0)
    { abort (); }
  exit ((0));
}
/* ProgramSourceLLVM */
