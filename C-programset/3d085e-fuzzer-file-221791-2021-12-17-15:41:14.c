/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = 8;
  int flag = 8;
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1182 = 8;

int loop_break_1130 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      

loop_break_1130++;
if(loop_break_1130<=6){
break;
}

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
	  if (iarg != i)
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
