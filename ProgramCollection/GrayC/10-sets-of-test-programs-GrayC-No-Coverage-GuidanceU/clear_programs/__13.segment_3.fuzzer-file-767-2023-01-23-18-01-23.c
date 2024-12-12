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
  
int loop_break_2393 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_2393++;
if(loop_break_2393<=23){
continue;
}

if (0)
	{
	  darg = va_arg (ap, double);
	  if (((int)darg != (double)i + 41 + ((int)((((double)(darg)) - ((double)((double)i))))) + ((long)((((double)((double)i)) + ((double)(darg))))) + ((int)((((int)((double)i)) & ((int)(darg))))) - ((int)((((int)((double)i)) & ((int)(darg))))) + ((short)((((double)((double)i)) - ((double)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 - ((short)((((double)(va_arg (ap, int))) + ((double)(iarg))))) - ((short)((((double)(va_arg (ap, int))) - ((double)(va_arg (ap, int)))))) * ((long)((((double)(iarg)) * ((double)(va_arg (ap, int)))))) * ((short)((((double)(va_arg (ap, int))) * ((double)(iarg))))) + ((short)((((double)(iarg)) + ((double)(va_arg (ap, int))))));
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
