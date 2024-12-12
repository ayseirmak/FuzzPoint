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
  
int loop_break_1142 = 0;

int loop_break_22778 = 0;

int loop_break_51519 = 0;
for (i = 1 + 42 - ((short)((((int)(i)) & ((int)(1))))) + ((long)((((double)(1)) + ((double)(i))))) * ((long)((((int)(i)) & ((int)(i))))) + ((short)((((int)(i)) ^ ((int)(i))))) + 42 - ((short)((((int)(i)) & ((int)(1 + 42 - ((short)((((int)(i)) & ((int)(1))))) + ((long)((((double)(1)) + ((double)(i))))) * ((long)((((int)(i)) & ((int)(i))))) + ((short)((((int)(i)) ^ ((int)(i)))))))))) + ((long)((((int)(1 + 42 - ((short)((((int)(i)) & ((int)(1))))) + ((long)((((double)(1)) + ((double)(i))))) * ((long)((((int)(i)) & ((int)(i))))) + ((short)((((int)(i)) ^ ((int)(i))))))) << ((int)(i))))) * ((long)((((int)(i)) & ((int)(i))))) + ((short)((((int)(i)) ^ ((int)(i))))); i <= 18; i++, flag++)
    {
      


loop_break_51519++;
if(loop_break_51519<=43){
break;
}

loop_break_22778++;
if(0){
continue;
}

loop_break_1142++;
if(0){
continue;
}

if (0)
	{
	  darg = va_arg (ap, double);
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 * ((int)((((int)(iarg)) & ((int)(va_arg (ap, int)))))) - ((long)((((int)(va_arg (ap, int))) % ((int)(iarg))))) + 42 * ((int)((((int)(iarg)) & ((int)(va_arg (ap, int) + 42 * ((int)((((int)(iarg)) & ((int)(va_arg (ap, int)))))) - ((long)((((int)(va_arg (ap, int))) % ((int)(iarg)))))))))) - ((long)((((int)(va_arg (ap, int) + 42 * ((int)((((int)(iarg)) & ((int)(va_arg (ap, int)))))) - ((long)((((int)(va_arg (ap, int))) % ((int)(iarg))))))) % ((int)(iarg)))));
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
