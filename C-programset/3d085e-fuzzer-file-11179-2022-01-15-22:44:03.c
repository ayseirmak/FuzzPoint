/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = 8;
  int flag = 0;
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  for (i = 1 + 42 *((short)((((int)(1)) %((int)(1)))))+((short)((((double)(1)) -((double)(i))))); i <= 18; i++, flag++)
    {
      if (0)
	{
	  
darg = va_arg (ap, double) + 42 +((int)((((int)(va_arg (ap, double))) <<((int)(va_arg (ap, double))))))+((int)((((int)(va_arg (ap, double))) %((int)(va_arg (ap, double))))));
darg = va_arg (ap, double) + 42 *((int)((((double)(darg)) -((double)(darg)))))+((short)((((double)(darg)) +((double)(va_arg (ap, double))))));
;
	  if (((int)darg != (double)i + 42 *((short)((((double)(darg)) +((double)(darg)))))+((short)((((double)((double)i)) -((double)((double)i)))))*((long)((((double)((double)i)) +((double)(darg)))))+((int)((((int)(darg)) &((int)((double)i)))))+((int)((((int)(darg)) >>((int)((double)i)))))*((long)((((double)(darg)) -((double)((double)i)))))))
    	{ abort(); }
	}
      else
	{
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
