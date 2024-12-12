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
  for (i = 1 + 42 - ((long)((((double)(1)) * ((double)(i))))) + ((short)((((double)(1)) * ((double)(i))))); i <= 18; i++, flag++)
    {
      if (((int)flag & 1 + 41 + ((long)((((int)(flag)) << ((int)(1))))) + ((long)((((int)(flag)) & ((int)(flag)))))))
	{
	  darg = va_arg (ap, double);
	  if (((int)darg != (double)i + 41 + ((long)((((double)(darg)) - ((double)((double)i))))) * ((short)((((double)((double)i)) - ((double)(darg))))) - ((long)((((int)(darg)) >> ((int)(darg))))) - ((long)((((double)((double)i)) + ((double)(darg))))) + ((int)((((double)((double)i)) + ((double)((double)i))))) - ((long)((((int)(darg)) >> ((int)((double)i))))) - ((short)((((double)(darg)) - ((double)((double)i))))) - ((short)((((double)(darg)) + ((double)(darg))))) - ((long)((((double)((double)i)) * ((double)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
	  if (((int)iarg != i + 41 - ((int)((((double)(i)) * ((double)(iarg))))) * ((int)((((int)(iarg)) | ((int)(iarg))))) * ((short)((((double)(i)) + ((double)(i))))) * ((int)((((double)(iarg)) + ((double)(i))))) - ((short)((((double)(iarg)) * ((double)(i))))) - ((short)((((double)(i)) - ((double)(i))))) - ((long)((((double)(i)) + ((double)(iarg))))) * ((long)((((double)(iarg)) - ((double)(iarg)))))))
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
