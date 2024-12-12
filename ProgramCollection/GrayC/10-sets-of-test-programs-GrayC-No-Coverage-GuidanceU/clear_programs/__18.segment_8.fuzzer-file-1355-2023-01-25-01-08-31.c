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

int loop_break_3112 = 0;
for (i = 1 + 42 + ((long)((((int)(i)) | ((int)(1))))) - ((short)((((int)(i)) << ((int)(i))))); i <= 18; i++, flag++)
    {
      

loop_break_3112++;
if(loop_break_3112<=37){
break;
}

loop_break_1142--;
if(((int)loop_break_1142<=18 + 41 * ((short)((((int)(loop_break_1142)) & ((int)(loop_break_1142))))) - ((short)((((int)(18)) ^ ((int)(loop_break_1142))))) + ((long)((((double)(loop_break_1142)) * ((double)(18))))) + ((int)((((int)(18)) << ((int)(18))))) * ((short)((((int)(18)) & ((int)(18))))) * ((int)((((double)(18)) - ((double)(loop_break_1142))))) * ((long)((((double)(loop_break_1142)) + ((double)(18))))) * ((int)((((double)(loop_break_1142)) * ((double)(18))))) * ((long)((((double)(loop_break_1142)) + ((double)(loop_break_1142))))) * ((short)((((double)(18)) - ((double)(loop_break_1142))))))){
continue;
}

if (((int)flag & 1 + 41 - ((long)((((double)(1)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(flag)))))))
	{
	  darg = va_arg (ap, double) + 42 + ((long)((((double)(darg)) + ((double)(darg))))) + ((long)((((double)(va_arg (ap, double))) + ((double)(va_arg (ap, double)))))) + ((int)((((int)(va_arg (ap, double))) << ((int)(darg)))));
	  if (0)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
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
