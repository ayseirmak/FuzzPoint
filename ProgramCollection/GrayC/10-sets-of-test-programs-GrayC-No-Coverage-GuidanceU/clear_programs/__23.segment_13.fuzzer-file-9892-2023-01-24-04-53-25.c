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

int loop_break_1242 = 0;

int loop_break_1900 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      


loop_break_1900++;
if(loop_break_1900<=4){
break;
}

loop_break_1242++;
if(((int)loop_break_1242<=43 + 41 * ((int)((((int)(loop_break_1242)) << ((int)(43))))) + ((short)((((int)(loop_break_1242)) & ((int)(43))))) - ((int)((((int)(43)) | ((int)(loop_break_1242))))) + ((long)((((double)(loop_break_1242)) * ((double)(loop_break_1242))))) - ((int)((((int)(loop_break_1242)) >> ((int)(loop_break_1242))))) - ((short)((((int)(43)) ^ ((int)(loop_break_1242))))))){
continue;
}

loop_break_1182++;
if(0){
continue;
}

if (0)
	{
	  darg = va_arg (ap, double);
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
