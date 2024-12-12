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
  
int loop_break_3562 = 0;

int loop_break_3619 = 0;
for (i = 1 + 42 *((long)((((double)(i)) +((double)(i)))))+((long)((((int)(i)) ^((int)(1)))))*((short)((((int)(1)) >>((int)(i)))))-((int)((((double)(i)) +((double)(1))))); i <= 18; i++, flag--)
    {
      

loop_break_3619++;
if(0){
break;
}

loop_break_3562++;
if(0){
break;
}

if (0)
	{
	  darg = va_arg (ap, double) + 42 *((long)((((int)(va_arg (ap, double))) <<((int)(va_arg (ap, double))))))-((int)((((double)(va_arg (ap, double))) *((double)(darg)))))*((int)((((double)(darg)) +((double)(va_arg (ap, double))))));
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 +((long)((((double)(va_arg (ap, int))) *((double)(iarg)))));
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
