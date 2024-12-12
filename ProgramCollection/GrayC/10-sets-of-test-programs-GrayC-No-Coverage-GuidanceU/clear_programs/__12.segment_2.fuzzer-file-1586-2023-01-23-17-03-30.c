/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = 8;
  int flag = 0;
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_3281 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_3281++;
if(loop_break_3281<=24){
continue;
}

if (((int)flag & 1 + 41 * ((int)((((int)(1)) | ((int)(flag)))))))
	{
	  darg = va_arg (ap, double);
	  if (((int)darg != (double)i + 41 * ((int)((((double)((double)i)) * ((double)(darg))))) * ((long)((((double)((double)i)) + ((double)(darg))))) * ((int)((((double)(darg)) + ((double)((double)i))))) * ((long)((((double)(darg)) - ((double)(darg))))) * ((int)((((double)(darg)) + ((double)((double)i))))) - ((long)((((int)(darg)) | ((int)(darg))))) * ((long)((((int)((double)i)) | ((int)(darg))))) - ((long)((((double)(darg)) * ((double)((double)i))))) * ((long)((((double)(darg)) - ((double)((double)i))))) * ((int)((((double)((double)i)) * ((double)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
	  if (((int)iarg != i + 41 * ((short)((((double)(i)) - ((double)(i))))) + ((long)((((double)(i)) - ((double)(i))))) * ((long)((((double)(i)) * ((double)(i))))) + ((short)((((int)(iarg)) | ((int)(iarg))))) - ((long)((((int)(iarg)) << ((int)(iarg))))) - ((int)((((int)(iarg)) << ((int)(i))))) + ((short)((((int)(i)) & ((int)(i)))))))
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
