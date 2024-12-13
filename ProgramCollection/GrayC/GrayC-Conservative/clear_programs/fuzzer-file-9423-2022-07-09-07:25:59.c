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
  
int loop_break_3101 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_3101++;
if(loop_break_3101<=9){
break;
}

if (0)
	{
	  darg = va_arg (ap, double);
	  if (((int)darg != (double)i + 41 + ((short)(((int)((double)i)) % ((int)((double)i)))) - ((int)(((double)((double)i)) + ((double)((double)i)))) * ((short)(((double)((double)i)) - ((double)((double)i)))) * ((long)(((int)(darg)) | ((int)((double)i)))) * ((long)(((int)(darg)) % ((int)(darg)))) * ((int)(((int)(darg)) | ((int)(darg)))) * ((int)(((int)((double)i)) | ((int)(darg)))) + ((long)(((double)(darg)) * ((double)((double)i)))) - ((long)(((double)((double)i)) - ((double)((double)i))))))
    	{ abort(); }
	}
      else
	{
	  va_arg (ap, int) + 42 - ((long)(((int)(iarg)) ^ ((int)(va_arg (ap, int))))) * ((long)(((int)(iarg)) << ((int)(iarg)))) - ((long)(((double)(iarg)) + ((double)(iarg)))) * ((long)(((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int))))) + ((short)(((int)(iarg)) ^ ((int)(iarg))));
	  if (((int)iarg != i + 41 - ((int)(((int)(iarg)) % ((int)(iarg)))) - ((short)(((double)(iarg)) + ((double)(iarg)))) * ((short)(((int)(i)) ^ ((int)(iarg))))))
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
