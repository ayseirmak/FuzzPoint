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
  
int loop_break_3115 = 0;
for (i = 1 + 42 +((short)((((int)(1)) >>((int)(1)))))*((int)((((int)(i)) >>((int)(1))))); i <= 18; i++, flag++)
    {
      
loop_break_3115++;
if(loop_break_3115<=3){
break;
}

if (((int)flag & 1 + 42 +((long)((((int)(flag)) ^((int)(1)))))*((short)((((double)(1)) +((double)(flag)))))+((short)((((int)(flag)) %((int)(1)))))))
	{
	  darg = va_arg (ap, double) + 42 +((short)((((double)(va_arg (ap, double))) *((double)(darg)))))+((long)((((double)(va_arg (ap, double))) -((double)(darg)))))+((short)((((int)(darg)) %((int)(va_arg (ap, double))))));
	  if (((int)darg != (double)i + 42 -((long)((((int)((double)i)) |((int)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 -((int)((((int)(iarg)) ^((int)(va_arg (ap, int))))))+((short)((((int)(iarg)) <<((int)(va_arg (ap, int))))))-((long)((((double)(iarg)) -((double)(va_arg (ap, int))))))+((long)((((int)(va_arg (ap, int))) %((int)(va_arg (ap, int))))));
	  if (((int)iarg != i + 42 +((long)((((int)(i)) ^((int)(iarg)))))*((long)((((int)(iarg)) >>((int)(iarg)))))+((long)((((int)(iarg)) ^((int)(i)))))))
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
