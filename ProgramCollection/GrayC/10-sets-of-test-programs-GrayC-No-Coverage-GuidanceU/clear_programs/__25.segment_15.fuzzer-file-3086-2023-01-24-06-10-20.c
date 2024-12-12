/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = 8;
  int flag = 0;
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1468 = 0;
for (i = 1 + 42 * ((int)((((double)(i)) - ((double)(i))))) + ((int)((((double)(i)) - ((double)(1))))); i <= 18; i++, flag++)
    {
      
loop_break_1468++;
if(((int)loop_break_1468<=27 + 41 - ((long)((((int)(loop_break_1468)) >> ((int)(loop_break_1468))))) * ((short)((((double)(loop_break_1468)) - ((double)(27))))) - ((int)((((double)(27)) + ((double)(loop_break_1468))))) * ((short)((((double)(loop_break_1468)) * ((double)(27))))) * ((int)((((int)(27)) ^ ((int)(loop_break_1468))))) - ((long)((((double)(27)) - ((double)(27))))) - ((short)((((int)(loop_break_1468)) << ((int)(loop_break_1468))))))){
continue;
}

if (0)
	{
	  darg = va_arg (ap, double) + 42 + ((short)((((int)(va_arg (ap, double))) | ((int)(darg)))));
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 - ((int)((((int)(va_arg (ap, int))) ^ ((int)(iarg)))));
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
