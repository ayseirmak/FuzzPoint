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
  for (i = 1 + 42 *((long)((((int)(i)) ^((int)(1)))))*((int)((((double)(i)) *((double)(1)))))-((int)((((int)(i)) >>((int)(i))))); i <= 18; i++, flag++)
    {
      if (0)
	{
	  ;
	  if (0)
    	{ abort(); }
	}
      else
	{
	  
iarg = va_arg (ap, int) + 42 +((short)((((double)(va_arg (ap, int))) *((double)(va_arg (ap, int))))))+((short)((((double)(iarg)) *((double)(iarg)))))+((short)((((int)(va_arg (ap, int))) |((int)(iarg)))))-((short)((((int)(iarg)) >>((int)(iarg)))))+((int)((((double)(va_arg (ap, int))) -((double)(va_arg (ap, int))))));
iarg = va_arg (ap, int) + 42 +((short)((((double)(va_arg (ap, int))) *((double)(va_arg (ap, int))))))+((short)((((double)(iarg)) *((double)(iarg)))))+((short)((((int)(va_arg (ap, int))) |((int)(iarg)))))-((short)((((int)(iarg)) >>((int)(iarg)))))+((int)((((double)(va_arg (ap, int))) -((double)(va_arg (ap, int))))));
;
	  if (((int)iarg != i + 42 -((short)((((double)(iarg)) *((double)(i)))))+((int)((((double)(iarg)) *((double)(i)))))*((short)((((double)(iarg)) -((double)(iarg)))))-((short)((((double)(i)) -((double)(iarg)))))-((int)((((int)(iarg)) <<((int)(i)))))-((int)((((double)(iarg)) +((double)(i)))))-((int)((((int)(i)) %((int)(iarg)))))))
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
