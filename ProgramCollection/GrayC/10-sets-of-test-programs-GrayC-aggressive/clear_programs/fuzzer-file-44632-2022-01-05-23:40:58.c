/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = 8;
  int flag = 8;
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  for (i = 1 + 42 +((long)((((double)(i)) *((double)(i)))))+((int)((((int)(i)) <<((int)(i)))))+((short)((((double)(1)) -((double)(1)))))*((short)((((int)(i)) >>((int)(1))))); i <= 18; i++, flag++)
    {
      if (((int)flag & 1 + 42 +((long)((((double)(flag)) +((double)(flag)))))-((long)((((int)(1)) ^((int)(flag)))))-((long)((((int)(1)) %((int)(flag)))))+((int)((((int)(flag)) >>((int)(1)))))*((int)((((double)(flag)) +((double)(1)))))+((long)((((double)(flag)) +((double)(flag)))))+((int)((((double)(flag)) -((double)(1)))))*((long)((((int)(flag)) >>((int)(flag)))))*((long)((((int)(1)) ^((int)(flag)))))+((int)((((int)(flag)) &((int)(1)))))))
	{
	  darg = va_arg (ap, double) + 42 +((long)((((double)(darg)) +((double)(darg)))))+((int)((((int)(darg)) <<((int)(va_arg (ap, double))))))*((long)((((double)(va_arg (ap, double))) *((double)(darg)))))*((short)((((double)(darg)) +((double)(darg)))))*((int)((((int)(darg)) &((int)(darg)))));
	  if (((int)darg != (double)i + 42 +((short)((((double)(darg)) -((double)(darg)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 +((int)((((int)(va_arg (ap, int))) >>((int)(iarg)))))-((long)((((int)(iarg)) <<((int)(iarg)))))-((long)((((int)(va_arg (ap, int))) <<((int)(va_arg (ap, int))))));
	  if (0)
    	{ abort(); }
	}
    }
    va_end(ap);
}

int main (void)
{
  vafunction( "",
	1, 2.,
	3, 4.,
	5, 6.,
	7, 8.,
	9, 10.,
	11, 12.,
	13, 14.,
	15, 16.,
	17, 18. );
  exit(0);
  return 0;
}
/* ProgramSourceLLVM */
