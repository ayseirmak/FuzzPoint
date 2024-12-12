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
for (i = 1 + 42 + ((int)((((double)(i)) - ((double)(1))))); i <= 18; i++, flag++)
    {
      
loop_break_1142++;
if(((int)loop_break_1142<=2 + 41 * ((int)((((int)(loop_break_1142)) ^ ((int)(2))))) + ((long)((((double)(2)) - ((double)(loop_break_1142))))) + ((long)((((int)(loop_break_1142)) % ((int)(loop_break_1142))))))){
continue;
}

if (((int)flag & 1 + 41 - ((int)((((int)(1)) & ((int)(1))))) * ((int)((((double)(1)) - ((double)(flag))))) + ((short)((((int)(flag)) ^ ((int)(1))))) + ((int)((((double)(1)) * ((double)(flag))))) - ((int)((((double)(flag)) * ((double)(1))))) - ((short)((((double)(flag)) + ((double)(1))))) + ((int)((((int)(flag)) % ((int)(1))))) + ((short)((((double)(1)) * ((double)(1))))) - ((short)((((double)(1)) + ((double)(flag)))))))
	{
	  va_arg (ap, double) + 42 + ((long)((((int)(va_arg (ap, double))) >> ((int)(darg))))) * ((long)((((int)(darg)) & ((int)(va_arg (ap, double)))))) - ((int)((((int)(darg)) & ((int)(darg))))) + ((short)((((double)(va_arg (ap, double))) * ((double)(darg)))));
	  if (0)
    	{ abort(); }
	}
      else
	{
	  va_arg (ap, int) + 42 - ((short)((((double)(va_arg (ap, int))) - ((double)(va_arg (ap, int)))))) - ((short)((((double)(va_arg (ap, int))) - ((double)(va_arg (ap, int))))));
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
