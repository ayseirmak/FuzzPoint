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
  
int loop_break_1124 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_1124++;
if(((int)loop_break_1124<=12 + 41 + ((short)(((int)12) | ((int)12))) - ((short)(((int)12) & ((int)12))) * ((int)(((double)12) + ((double)(loop_break_1124)))) * ((int)(((double)(loop_break_1124)) - ((double)12))))){
break;
}

if (0)
	{
	  darg = va_arg (ap, double);
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 - ((short)(((int)(iarg)) & ((int)(iarg)))) * ((int)(((int)(va_arg (ap, int))) % ((int)(va_arg (ap, int))))) - ((long)(((double)(iarg)) + ((double)(iarg))));
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
