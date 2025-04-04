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
  
int loop_break_2716 = 0;

int loop_break_1780 = 8;
for (i = 1; i <= 18; i++, flag++)
    {
      

loop_break_1780++;
if(loop_break_1780<=49){
continue;
}

loop_break_2716++;
if(0){
continue;
}

if (0)
	{
	  va_arg (ap, double) + 42 - ((long)((((double)(darg)) - ((double)(darg))))) + ((int)((((int)(va_arg (ap, double))) & ((int)(darg))))) * ((long)((((double)(darg)) - ((double)(darg))))) - ((long)((((int)(va_arg (ap, double))) | ((int)(darg)))));
	  if (0)
    	{ abort(); }
	}
      else
	{
	  va_arg (ap, int) + 42 * ((long)((((int)(va_arg (ap, int))) & ((int)(iarg)))));
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
