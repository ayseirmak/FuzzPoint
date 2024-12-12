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
  
int loop_break_3251 = 0;
for (i = 1 + 42 * ((long)((((int)(i)) >> ((int)(i))))) - ((int)((((double)(1)) - ((double)(i))))); i <= 18; i++, flag++)
    {
      
loop_break_3251++;
if(0){
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
	  va_arg (ap, int) + 42 - ((int)((((int)(iarg)) ^ ((int)(iarg)))));
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
