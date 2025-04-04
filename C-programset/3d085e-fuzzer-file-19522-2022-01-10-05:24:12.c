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
  for (i = 1 + 42 *((long)((((double)(i)) *((double)(1)))))-((int)((((double)(1)) *((double)(1)))))+((short)((((double)(1)) -((double)(i))))); i <= 18; i++, flag++)
    {
      if (0)
	{
	  darg = va_arg (ap, double) + 42 +((long)((((double)(va_arg (ap, double))) +((double)(va_arg (ap, double))))));
	  if (((int)darg != (double)i + 42 -((int)((((double)((double)i)) -((double)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 -((long)((((double)(iarg)) -((double)(iarg)))));
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
