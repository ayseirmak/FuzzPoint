/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 8;
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  for (i = 1 + 42 -((short)((((int)(1)) >>((int)(1)))))+((int)((((double)(i)) *((double)(1)))))*((long)((((int)(1)) ^((int)(1)))))-((short)((((double)(i)) -((double)(1)))))*((long)((((int)(i)) %((int)(1))))); i <= 18; i--, flag++)
    {
      if (((int)flag & 1 + 42 +((long)((((int)(flag)) |((int)(1)))))*((int)((((double)(1)) *((double)(flag)))))-((long)((((double)(1)) *((double)(flag)))))*((int)((((double)(flag)) +((double)(1)))))+((int)((((int)(1)) %((int)(1)))))*((short)((((double)(flag)) +((double)(1)))))+((int)((((double)(1)) +((double)(flag)))))))
	{
	  
darg = va_arg (ap, double) + 42 +((int)((((double)(darg)) -((double)(va_arg (ap, double))))))+((long)((((int)(va_arg (ap, double))) |((int)(darg)))))*((short)((((int)(darg)) <<((int)(va_arg (ap, double))))));
darg = va_arg (ap, double) + 42 *((int)((((double)(va_arg (ap, double))) -((double)(va_arg (ap, double))))))+((long)((((double)(va_arg (ap, double))) *((double)(darg)))))-((long)((((double)(darg)) *((double)(darg)))));
;
	  if (0)
    	{ abort(); }
	}
      else
	{
	  
iarg = va_arg (ap, int) + 42 *((long)((((int)(va_arg (ap, int))) |((int)(iarg)))))-((int)((((double)(iarg)) -((double)(va_arg (ap, int))))))*((int)((((double)(va_arg (ap, int))) *((double)(va_arg (ap, int))))))-((long)((((double)(iarg)) *((double)(iarg)))));
iarg = va_arg (ap, int) + 42 +((long)((((double)(iarg)) +((double)(iarg)))))+((int)((((int)(iarg)) ^((int)(va_arg (ap, int))))))+((int)((((double)(va_arg (ap, int))) *((double)(iarg)))));
;
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
