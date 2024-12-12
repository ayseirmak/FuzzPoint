/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 8;
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1164 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_1164++;
if(((int)loop_break_1164<=35 + 41 - ((short)((((double)(35)) + ((double)(loop_break_1164))))))){
continue;
}

if (((int)flag & 1 + 41 * ((long)((((int)(flag)) << ((int)(1))))) * ((short)((((double)(1)) + ((double)(flag))))) + ((short)((((int)(flag)) % ((int)(flag)))))))
	{
	  darg = va_arg (ap, double) + 42 * ((int)((((double)(darg)) + ((double)(va_arg (ap, double)))))) * ((int)((((double)(va_arg (ap, double))) * ((double)(va_arg (ap, double)))))) - ((long)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double)))))) * ((long)((((double)(va_arg (ap, double))) * ((double)(va_arg (ap, double)))))) + ((long)((((int)(darg)) % ((int)(va_arg (ap, double))))));
	  if (((int)darg != (double)i + 41 * ((short)((((double)(darg)) - ((double)((double)i))))) + ((int)((((int)(darg)) & ((int)((double)i)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 * ((int)((((double)(va_arg (ap, int))) + ((double)(iarg))))) - ((short)((((double)(va_arg (ap, int))) + ((double)(va_arg (ap, int)))))) * ((short)((((int)(iarg)) >> ((int)(iarg)))));
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
