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
  
int loop_break_1182 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_1182++;
if(((int)loop_break_1182<=49 + 41 + ((int)((((double)(49)) * ((double)(49))))) - ((int)((((double)(49)) - ((double)(loop_break_1182))))) - ((short)((((int)(loop_break_1182)) | ((int)(49))))) * ((long)((((double)(49)) - ((double)(49))))) * ((short)((((double)(49)) + ((double)(49))))) * ((short)((((double)(49)) - ((double)(49))))) * ((long)((((int)(loop_break_1182)) % ((int)(49))))))){
break;
}

if (((int)flag & 1 + 41 + ((short)((((double)(1)) + ((double)(1)))))))
	{
	  darg = va_arg (ap, double) + 42 + ((short)((((double)(va_arg (ap, double))) - ((double)(va_arg (ap, double)))))) * ((short)((((int)(va_arg (ap, double))) % ((int)(darg)))));
	  if (((int)darg != (double)i + 41 * ((int)((((int)(darg)) % ((int)(darg))))) - ((short)((((int)(darg)) % ((int)((double)i))))) + ((long)((((int)(darg)) ^ ((int)(darg))))) - ((short)((((int)((double)i)) << ((int)(darg))))) - ((int)((((int)(darg)) & ((int)(darg))))) - ((long)((((double)(darg)) + ((double)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
	  if (((int)iarg != i + 41 - ((int)((((int)(iarg)) ^ ((int)(i))))) - ((short)((((double)(iarg)) - ((double)(i))))) * ((int)((((double)(iarg)) * ((double)(iarg))))) - ((int)((((int)(iarg)) % ((int)(i))))) + ((int)((((double)(i)) * ((double)(i))))) - ((int)((((int)(i)) & ((int)(iarg))))) + ((int)((((int)(i)) ^ ((int)(i))))) * ((short)((((double)(i)) + ((double)(iarg)))))))
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
