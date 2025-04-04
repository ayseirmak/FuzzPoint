/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 8;
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_3732 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_3732++;
if(loop_break_3732<=19){
break;
}

if (((int)flag & 1 + 41 - ((int)((((double)(1)) + ((double)(flag))))) * ((short)((((double)(flag)) - ((double)(1))))) - ((int)((((double)(1)) * ((double)(flag))))) * ((int)((((int)(1)) ^ ((int)(flag))))) + ((short)((((double)(flag)) + ((double)(flag))))) + ((short)((((double)(1)) - ((double)(1)))))))
	{
	  darg = va_arg (ap, double) + 42 + ((long)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double))))));
	  if (((int)darg != (double)i + 41 * ((int)((((double)(darg)) * ((double)((double)i))))) + ((long)((((double)(darg)) - ((double)((double)i))))) * ((long)((((double)((double)i)) * ((double)((double)i))))) + ((int)((((double)((double)i)) * ((double)((double)i))))) - ((long)((((double)(darg)) + ((double)((double)i))))) - ((short)((((int)(darg)) | ((int)(darg)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 - ((int)((((double)(va_arg (ap, int))) * ((double)(iarg)))));
	  if (((int)iarg != i + 41 * ((int)((((int)(iarg)) % ((int)(i))))) + ((long)((((double)(i)) * ((double)(iarg))))) - ((long)((((int)(iarg)) << ((int)(i))))) - ((int)((((double)(i)) + ((double)(iarg))))) * ((long)((((double)(i)) * ((double)(i))))) * ((long)((((double)(iarg)) * ((double)(i))))) - ((short)((((double)(i)) - ((double)(iarg))))) - ((int)((((int)(i)) & ((int)(iarg)))))))
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
