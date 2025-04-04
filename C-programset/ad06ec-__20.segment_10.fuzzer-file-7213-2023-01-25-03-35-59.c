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
  
int loop_break_1142 = 8;

int loop_break_3112 = 0;
for (i = 1 + 42 + ((long)((((int)(i)) | ((int)(1))))) - ((short)((((int)(i)) << ((int)(i))))); i <= 18; i++, flag++)
    {
      

loop_break_3112++;
if(((int)loop_break_3112<=10 + 41 + ((long)((((int)(10)) | ((int)(10))))) + ((short)((((double)(loop_break_3112)) + ((double)(loop_break_3112))))) + ((short)((((double)(loop_break_3112)) + ((double)(10))))) - ((long)((((int)(10)) >> ((int)(10))))) * ((int)((((double)(10)) - ((double)(loop_break_3112))))))){
break;
}

loop_break_1142++;
if(((int)((int)loop_break_1142<=18 + 41 * ((short)((((int)(loop_break_1142)) & ((int)(loop_break_1142))))) - ((short)((((int)(18)) ^ ((int)(loop_break_1142))))) + ((long)((((double)(loop_break_1142)) * ((double)(18))))) + ((int)((((int)(18)) << ((int)(18))))) * ((short)((((int)(18)) & ((int)(18))))) * ((int)((((double)(18)) - ((double)(loop_break_1142))))) * ((long)((((double)(loop_break_1142)) + ((double)(18))))) * ((int)((((double)(loop_break_1142)) * ((double)(18))))) * ((long)((((double)(loop_break_1142)) + ((double)(loop_break_1142))))) * ((short)((((double)(18)) - ((double)(loop_break_1142)))))) + 41 - ((long)((((int)(((short)((((double)(18)) - ((double)(loop_break_1142))))))) | ((int)(((long)((((double)(loop_break_1142)) * ((double)(18)))))))))))){
continue;
}

if (((int)((int)flag & 1 + 41 - ((long)((((double)(1)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(flag)))))) + 41 * ((long)((((double)(((long)((((double)(1)) + ((double)(1))))))) + ((double)((int)flag))))) - ((long)((((double)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))))) - ((double)(1 + 41))))) - ((int)((((double)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))))) + ((double)(1 + 41 - ((long)((((double)(1)) + ((double)(1)))))))))) - ((short)((((double)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(flag))))))) + ((double)(1 + 41))))) * ((int)((((int)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))))) << ((int)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(flag)))))))))) * ((long)((((int)(((long)((((double)(1)) - ((double)(flag))))))) | ((int)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(flag)))))))))) + ((short)((((int)(1 + 41)) >> ((int)(1 + 41))))) - ((short)((((int)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))))) >> ((int)(1 + 41 - ((long)((((double)(1)) + ((double)(1)))))))))) + ((int)((((double)((int)flag)) * ((double)(1 + 41 - ((long)((((double)(1)) + ((double)(1))))))))))))
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
