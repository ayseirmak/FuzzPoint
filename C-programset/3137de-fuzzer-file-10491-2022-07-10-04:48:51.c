/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 0;
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1182 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      
loop_break_1182++;
if(((int)loop_break_1182<=11 + 41 - ((long)(((double)(loop_break_1182)) - ((double)11))) + ((int)(((int)(loop_break_1182)) ^ ((int)11))) * ((int)(((double)(loop_break_1182)) - ((double)(loop_break_1182)))))){
break;
}

if (((int)flag & 1 + 41 * ((int)(((int)(flag)) << ((int)1))) + ((int)(((int)1) & ((int)1))) * ((long)(((int)1) << ((int)1))) + ((short)(((double)1) - ((double)(flag)))) - ((short)(((int)(flag)) | ((int)1))) + ((int)(((double)(flag)) + ((double)(flag)))) + ((short)(((int)(flag)) ^ ((int)(flag)))) - ((int)(((double)(flag)) + ((double)1)))))
	{
	  darg = va_arg (ap, double);
	  if (((int)darg != (double)i + 41 - ((short)(((int)((double)i)) % ((int)((double)i)))) + ((short)(((int)((double)i)) % ((int)((double)i)))) * ((int)(((int)(darg)) % ((int)((double)i)))) + ((int)(((double)(darg)) * ((double)((double)i)))) - ((long)(((int)((double)i)) ^ ((int)((double)i)))) * ((long)(((double)(darg)) + ((double)(darg)))) + ((short)(((double)(darg)) + ((double)((double)i)))) * ((short)(((int)((double)i)) ^ ((int)((double)i)))) + ((int)(((int)((double)i)) << ((int)(darg))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 * ((long)(((int)(iarg)) & ((int)(va_arg (ap, int)))));
	  if (((int)iarg != i + 41 * ((long)(((double)(iarg)) * ((double)(iarg)))) - ((long)(((double)(iarg)) + ((double)(i)))) + ((int)(((double)(iarg)) * ((double)(iarg)))) + ((short)(((double)(iarg)) + ((double)(i)))) * ((int)(((int)(i)) % ((int)(i)))) - ((short)(((double)(i)) + ((double)(iarg)))) - ((short)(((int)(iarg)) >> ((int)(i)))) + ((long)(((double)(iarg)) + ((double)(iarg))))))
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
