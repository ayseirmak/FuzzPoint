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
  for (i = 1 + 42 *((long)((((double)(i)) +((double)(i)))))+((long)((((int)(i)) ^((int)(1)))))*((short)((((int)(1)) >>((int)(i)))))-((int)((((double)(i)) +((double)(1))))); i <= 18; i++, flag--)
    {
      if (((int)flag & 1 + 42 *((long)((((int)(1)) ^((int)(flag)))))*((int)((((double)(flag)) +((double)(flag)))))*((long)((((double)(1)) +((double)(1)))))))
	{
	  darg = va_arg (ap, double) + 42 *((long)((((int)(va_arg (ap, double))) <<((int)(va_arg (ap, double))))))-((int)((((double)(va_arg (ap, double))) *((double)(darg)))))*((int)((((double)(darg)) +((double)(va_arg (ap, double))))));
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 +((long)((((double)(va_arg (ap, int))) *((double)(iarg)))));
	  if (((int)iarg != i + 42 *((int)((((double)(iarg)) +((double)(i)))))-((short)((((int)(iarg)) %((int)(i)))))+((long)((((int)(i)) >>((int)(iarg)))))-((int)((((int)(iarg)) &((int)(iarg)))))+((int)((((int)(iarg)) >>((int)(iarg)))))*((long)((((int)(iarg)) |((int)(i)))))*((long)((((double)(i)) +((double)(i)))))+((int)((((double)(i)) *((double)(iarg)))))+((long)((((double)(i)) +((double)(iarg)))))-((int)((((double)(iarg)) *((double)(i)))))))
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
