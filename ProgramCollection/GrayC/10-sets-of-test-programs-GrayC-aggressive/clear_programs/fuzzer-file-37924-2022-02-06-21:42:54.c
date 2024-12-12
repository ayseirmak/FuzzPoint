/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 0;
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  for (i = 1 + 42 *((short)((((int)(1)) &((int)(1)))))*((int)((((double)(i)) -((double)(1)))))*((long)((((int)(1)) <<((int)(i)))))+((long)((((int)(i)) |((int)(1)))))-((long)((((double)(1)) *((double)(1))))); i <= 18; i++, flag++)
    {
      if (0)
	{
	  
darg = va_arg (ap, double) + 42 *((int)((((double)(va_arg (ap, double))) +((double)(darg)))));
darg = va_arg (ap, double) + 42 *((int)((((double)(va_arg (ap, double))) +((double)(darg)))));
;
	  if (0)
    	{ abort(); }
	}
      else
	{
	  
iarg = va_arg (ap, int) + 42 *((short)((((double)(va_arg (ap, int))) *((double)(va_arg (ap, int))))))-((long)((((double)(va_arg (ap, int))) +((double)(iarg)))));
iarg = va_arg (ap, int) + 42 *((short)((((double)(va_arg (ap, int))) *((double)(va_arg (ap, int))))))-((long)((((double)(va_arg (ap, int))) +((double)(iarg)))));
;
	  if (((int)iarg != i + 42 *((int)((((int)(iarg)) ^((int)(iarg)))))-((long)((((double)(iarg)) -((double)(iarg)))))+((int)((((double)(iarg)) +((double)(i)))))+((short)((((double)(iarg)) *((double)(i)))))-((int)((((double)(i)) +((double)(i)))))-((long)((((int)(i)) &((int)(iarg)))))+((short)((((int)(i)) >>((int)(iarg)))))))
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
