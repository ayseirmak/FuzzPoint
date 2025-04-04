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
  for (i = 1 + 42 - ((int)(((int)1) >> ((int)(i)))); i <= 18; i++, flag++)
    {
      if (((int)flag & 1 + 41 + ((int)(((double)1) + ((double)(flag)))) + ((int)(((int)1) << ((int)1))) * ((short)(((int)(flag)) | ((int)(flag)))) + ((int)(((int)(flag)) % ((int)1))) - ((short)(((int)1) << ((int)(flag)))) + ((int)(((int)(flag)) >> ((int)(flag)))) + ((long)(((double)(flag)) + ((double)1)))))
	{
	  darg = va_arg (ap, double);
	  if (((int)darg != (double)i + 41 + ((long)(((int)((double)i)) | ((int)(darg)))) - ((int)(((double)(darg)) + ((double)(darg)))) + ((long)(((double)((double)i)) * ((double)(darg))))))
    	{ abort(); }
	}
      else
	{
	  va_arg (ap, int) + 42 + ((long)(((int)(iarg)) >> ((int)(va_arg (ap, int))))) + ((long)(((double)(iarg)) + ((double)(iarg)))) * ((long)(((double)(va_arg (ap, int))) + ((double)(iarg)))) + ((int)(((double)(iarg)) - ((double)(va_arg (ap, int)))));
	  if (((int)iarg != i + 41 - ((short)(((int)(i)) % ((int)(i)))) - ((long)(((double)(i)) - ((double)(iarg)))) * ((short)(((double)(i)) - ((double)(i)))) + ((short)(((double)(iarg)) * ((double)(iarg)))) + ((int)(((double)(i)) + ((double)(iarg)))) + ((long)(((double)(i)) + ((double)(i)))) - ((int)(((double)(iarg)) - ((double)(iarg)))) - ((long)(((double)(i)) * ((double)(iarg)))) * ((long)(((int)(i)) | ((int)(iarg))))))
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
