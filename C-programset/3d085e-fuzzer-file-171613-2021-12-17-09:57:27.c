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
  
int loop_break_1184 = 8;

int loop_break_3568 = 0;

int loop_break_1610 = 8;
for (i = 1 + 42 +((short)((((int)(1)) <<((int)(i)))))-((long)((((int)(i)) &((int)(1)))))-((long)((((double)(1)) +((double)(i)))))+((int)((((int)(i)) &((int)(i))))); i <= 18; i++, flag++)
    {
      


loop_break_1610++;
if(loop_break_1610<=6){
break;
}

loop_break_3568++;
if(0){
continue;
}

loop_break_1184++;
if(0){
continue;
}

if (0)
	{
	  
;
;
;
	  if (0)
    	{ abort(); }
	}
      else
	{
	  ;
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
