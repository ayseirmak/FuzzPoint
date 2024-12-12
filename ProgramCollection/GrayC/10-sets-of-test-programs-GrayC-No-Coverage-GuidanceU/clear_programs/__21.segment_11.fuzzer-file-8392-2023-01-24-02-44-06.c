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
  
int loop_break_1142 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_1142++;
if(((int)loop_break_1142<=2 + 41 + ((int)((((int)(loop_break_1142)) >> ((int)(loop_break_1142))))) - ((int)((((int)(2)) % ((int)(loop_break_1142))))) * ((long)((((double)(loop_break_1142)) * ((double)(loop_break_1142))))) + ((short)((((int)(2)) & ((int)(2))))) * ((int)((((double)(loop_break_1142)) * ((double)(2))))) + ((short)((((double)(loop_break_1142)) * ((double)(2))))) - ((long)((((int)(loop_break_1142)) % ((int)(loop_break_1142))))) * ((short)((((int)(2)) % ((int)(2))))))){
continue;
}

if (((int)flag & 1 + 41 - ((short)((((int)(1)) ^ ((int)(flag)))))))
	{
	  darg = va_arg (ap, double);
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 * ((long)((((int)(iarg)) | ((int)(iarg)))));
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
