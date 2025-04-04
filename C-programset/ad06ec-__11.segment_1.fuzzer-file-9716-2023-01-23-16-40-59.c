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
  for (i = 1; i <= 18; i++, flag++)
    {
      if (0)
	{
	  darg = va_arg (ap, double) + 42 - ((long)((((double)(darg)) - ((double)(darg))))) + ((int)((((int)(va_arg (ap, double))) & ((int)(darg))))) * ((long)((((double)(darg)) - ((double)(darg))))) - ((long)((((int)(va_arg (ap, double))) | ((int)(darg)))));
	  if (((int)darg != (double)i + 41 + ((short)((((int)((double)i)) >> ((int)(darg))))) - ((short)((((int)(darg)) >> ((int)((double)i))))) * ((long)((((int)((double)i)) >> ((int)(darg))))) - ((long)((((double)(darg)) + ((double)(darg))))) - ((short)((((double)((double)i)) - ((double)(darg))))) - ((long)((((int)((double)i)) >> ((int)(darg))))) - ((long)((((double)(darg)) * ((double)(darg))))) - ((short)((((double)(darg)) + ((double)(darg)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 * ((long)((((int)(va_arg (ap, int))) & ((int)(iarg)))));
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
