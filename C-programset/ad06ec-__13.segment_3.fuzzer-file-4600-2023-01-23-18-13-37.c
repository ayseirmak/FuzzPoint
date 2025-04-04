/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 0;
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_4747 = 0;
for (i = 1 + 42 - ((long)((((int)(i)) % ((int)(i))))) * ((long)((((int)(i)) | ((int)(1))))); i <= 18; i++, flag++)
    {
      
loop_break_4747++;
if(loop_break_4747<=37){
continue;
}

if (((int)flag & 1 + 41 - ((short)((((int)(flag)) | ((int)(flag))))) - ((short)((((int)(flag)) << ((int)(flag))))) - ((short)((((int)(1)) ^ ((int)(flag))))) * ((int)((((int)(flag)) >> ((int)(1))))) - ((long)((((int)(flag)) % ((int)(1))))) + ((long)((((int)(1)) | ((int)(1))))) + ((short)((((int)(1)) << ((int)(1))))) * ((short)((((int)(1)) >> ((int)(flag))))) + ((long)((((double)(1)) - ((double)(flag)))))))
	{
	  darg = va_arg (ap, double) + 42 + ((int)((((int)(darg)) & ((int)(darg))))) - ((int)((((double)(darg)) - ((double)(darg))))) * ((long)((((double)(darg)) * ((double)(darg)))));
	  if (((int)darg != (double)i + 41 - ((int)((((double)(darg)) - ((double)(darg))))) * ((long)((((int)(darg)) >> ((int)((double)i))))) - ((int)((((double)((double)i)) + ((double)(darg))))) - ((short)((((int)((double)i)) & ((int)((double)i))))) + ((int)((((double)(darg)) * ((double)((double)i))))) * ((int)((((double)(darg)) * ((double)(darg))))) + ((short)((((double)(darg)) - ((double)(darg)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 - ((short)((((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int)))))) + ((int)((((int)(iarg)) | ((int)(va_arg (ap, int)))))) - ((long)((((int)(va_arg (ap, int))) | ((int)(va_arg (ap, int))))));
	  if (((int)iarg != i + 41 * ((long)((((int)(i)) ^ ((int)(iarg))))) - ((int)((((double)(i)) - ((double)(i))))) - ((int)((((int)(i)) | ((int)(i))))) + ((short)((((int)(iarg)) >> ((int)(i))))) - ((int)((((double)(i)) * ((double)(iarg))))) - ((long)((((int)(i)) ^ ((int)(i))))) + ((short)((((int)(iarg)) << ((int)(i)))))))
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
