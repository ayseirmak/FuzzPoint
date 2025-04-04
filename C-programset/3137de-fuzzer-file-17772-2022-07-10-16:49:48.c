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
  for (i = 1 + 42 * ((long)(((int)1) % ((int)(i)))); i <= 18; i++, flag++)
    {
      if (((int)flag & 1 + 41 + ((long)(((double)(flag)) + ((double)(flag)))) * ((long)(((int)1) % ((int)(flag)))) - ((short)(((double)1) - ((double)1))) * ((long)(((double)(flag)) * ((double)1))) + ((long)(((double)1) + ((double)(flag))))))
	{
	  darg = va_arg (ap, double);
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 * ((int)(((double)(iarg)) - ((double)(va_arg (ap, int)))));
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
