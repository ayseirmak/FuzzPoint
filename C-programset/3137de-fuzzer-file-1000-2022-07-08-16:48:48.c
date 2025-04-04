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
if(((int)loop_break_1182<=9 + 41 - ((int)(((double)9) + ((double)(loop_break_1182)))))){
break;
}

if (((int)flag & 1 + 41 + ((short)(((int)(flag)) % ((int)1))) * ((int)(((int)(flag)) ^ ((int)1))) - ((long)(((int)1) >> ((int)1)))))
	{
	  darg = va_arg (ap, double) + 42 * ((long)(((int)(darg)) ^ ((int)(darg))));
	  if (((int)darg != (double)i + 41 + ((int)(((int)((double)i)) % ((int)((double)i)))) * ((long)(((double)((double)i)) * ((double)((double)i)))) - ((short)(((int)(darg)) ^ ((int)(darg)))) - ((int)(((int)(darg)) << ((int)((double)i)))) * ((int)(((double)((double)i)) * ((double)(darg)))) + ((short)(((int)(darg)) ^ ((int)(darg))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 * ((long)(((double)(iarg)) + ((double)(iarg))));
	  if (((int)iarg != i + 41 + ((short)(((int)(iarg)) >> ((int)(i)))) + ((long)(((int)(i)) >> ((int)(i)))) - ((int)(((int)(i)) >> ((int)(i)))) - ((long)(((double)(i)) - ((double)(iarg)))) + ((long)(((double)(iarg)) * ((double)(i)))) - ((short)(((int)(i)) | ((int)(iarg)))) + ((short)(((double)(i)) - ((double)(i)))) * ((short)(((int)(iarg)) ^ ((int)(i))))))
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
