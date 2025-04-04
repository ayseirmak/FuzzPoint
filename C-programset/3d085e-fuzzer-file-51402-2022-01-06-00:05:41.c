/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 0;
  int i;
  va_list ap;

  va_start(ap, dummy);
  for (i = 1 + 42 -((long)((((double)(1)) *((double)(1))))); i <= 18; i++, flag++)
    {
      if (((int)flag & 1 + 42 +((int)((((double)(1)) +((double)(flag)))))-((int)((((int)(1)) ^((int)(1)))))+((short)((((int)(flag)) %((int)(1)))))*((short)((((double)(1)) +((double)(flag)))))+((int)((((double)(1)) +((double)(flag)))))+((short)((((int)(flag)) %((int)(1)))))*((int)((((double)(1)) *((double)(flag)))))-((int)((((double)(flag)) -((double)(flag)))))))
	{
	  
;

darg = va_arg (ap, double) + 42 -((int)((((double)(darg)) -((double)(darg)))))-((short)((((double)(darg)) -((double)(darg)))));
darg = va_arg (ap, double) + 42 +((int)((((int)(va_arg (ap, double))) |((int)(darg)))))+((long)((((int)(darg)) ^((int)(darg)))))*((int)((((int)(va_arg (ap, double))) >>((int)(darg)))));
;
;
	  if (((int)darg != (double)i + 42 *((int)((((int)((double)i)) &((int)((double)i)))))-((int)((((double)((double)i)) +((double)(darg)))))*((long)((((double)(darg)) -((double)(darg)))))+((short)((((int)(darg)) ^((int)((double)i)))))-((short)((((double)((double)i)) +((double)(darg)))))-((long)((((int)((double)i)) |((int)(darg)))))))
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
