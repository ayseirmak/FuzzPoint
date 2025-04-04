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
  for (i = 1 + 42 *((short)((((double)(1)) *((double)(i)))))-((short)((((double)(i)) +((double)(i)))))-((short)((((int)(i)) <<((int)(1)))))+((short)((((int)(1)) &((int)(i))))); i <= 18; i++, flag++)
    {
      if (0)
	{
	  darg = va_arg (ap, double) + 42 -((short)((((int)(va_arg (ap, double))) |((int)(darg)))))+((short)((((int)(va_arg (ap, double))) <<((int)(darg)))))*((long)((((double)(va_arg (ap, double))) +((double)(darg)))));
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 -((long)((((double)(va_arg (ap, int))) -((double)(iarg)))))+((int)((((double)(iarg)) -((double)(iarg)))))-((long)((((int)(iarg)) >>((int)(iarg)))));
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
