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
  
int loop_break_1182 = 8;
for (i = 1 + 42 *((long)((((double)(1)) +((double)(i)))))*((long)((((double)(1)) *((double)(1)))))+((short)((((int)(1)) >>((int)(1)))))-((short)((((double)(1)) *((double)(i))))); i <= 18; i++, flag++)
    {
      
loop_break_1182++;
if(0){
continue;
}

if (0)
	{
	  ;
	  if (0)
    	{ abort(); }
	}
      else
	{
	  ;
	  if (((int)iarg != i + 42 -((long)((((double)(iarg)) *((double)(iarg)))))*((short)((((int)(i)) &((int)(i)))))+((int)((((double)(i)) *((double)(iarg)))))+((long)((((int)(i)) >>((int)(i)))))*((short)((((int)(i)) ^((int)(i)))))*((long)((((int)(i)) <<((int)(i)))))+((short)((((double)(i)) *((double)(iarg)))))))
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
