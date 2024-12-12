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
  
int loop_break_3750 = 8;

int loop_break_3809 = 0;
for (i = 1 + 42 +((long)((((int)(i)) %((int)(i)))))+((int)((((double)(i)) -((double)(i)))))-((short)((((double)(i)) -((double)(1)))))+((short)((((int)(i)) %((int)(1))))); i <= 18; i++, flag++)
    {
      

loop_break_3809++;
if(loop_break_3809<=2){
break;
}

loop_break_3750++;
if(0){
continue;
}

if (0)
	{
	  darg = va_arg (ap, double) + 42 *((short)((((double)(darg)) *((double)(va_arg (ap, double))))))+((long)((((int)(darg)) >>((int)(va_arg (ap, double))))));
	  if (((int)darg != (double)i + 42 -((long)((((double)((double)i)) -((double)(darg)))))+((long)((((double)(darg)) *((double)(darg)))))-((short)((((int)((double)i)) >>((int)((double)i)))))-((int)((((double)(darg)) *((double)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 +((long)((((double)(va_arg (ap, int))) +((double)(va_arg (ap, int))))));
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
