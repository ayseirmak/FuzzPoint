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
  for (i = 1 + 42 -((long)((((double)(1)) +((double)(i)))))+((long)((((int)(1)) <<((int)(i)))))+((long)((((int)(1)) &((int)(i))))); i <= 18; i++, flag++)
    {
      if (((int)flag & 1 + 42 -((int)((((int)(1)) |((int)(1)))))-((short)((((double)(1)) *((double)(1)))))*((long)((((int)(flag)) <<((int)(flag)))))*((short)((((double)(flag)) *((double)(flag)))))+((short)((((double)(1)) +((double)(flag)))))-((long)((((int)(flag)) >>((int)(1)))))))
	{
	  darg = va_arg (ap, double) + 42 *((short)((((int)(darg)) |((int)(darg)))))*((int)((((int)(darg)) |((int)(darg)))))-((long)((((double)(darg)) -((double)(va_arg (ap, double))))));
	  if (((int)darg != (double)i + 42 +((short)((((double)((double)i)) *((double)((double)i)))))-((int)((((int)(darg)) <<((int)(darg)))))*((short)((((double)((double)i)) *((double)(darg)))))*((int)((((int)((double)i)) %((int)((double)i)))))*((int)((((int)((double)i)) ^((int)(darg)))))+((short)((((double)(darg)) -((double)(darg)))))*((int)((((double)(darg)) *((double)((double)i)))))*((short)((((double)(darg)) -((double)((double)i)))))+((long)((((int)(darg)) |((int)(darg)))))+((long)((((double)((double)i)) *((double)(darg)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 -((int)((((int)(iarg)) ^((int)(iarg)))))+((long)((((double)(iarg)) *((double)(iarg)))))+((long)((((double)(iarg)) +((double)(iarg)))));
	  if (((int)iarg != i + 42 +((int)((((int)(i)) <<((int)(iarg)))))+((int)((((int)(iarg)) >>((int)(i)))))*((short)((((double)(iarg)) *((double)(iarg)))))-((int)((((int)(iarg)) <<((int)(i)))))+((long)((((double)(i)) *((double)(i)))))))
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
