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

int loop_break_1310 = 0;
for (i = 1; i <= 18; i++, flag++)
    {
      


loop_break_1310++;
if(((int)loop_break_1310<=16 + 41 + ((long)((((int)(16)) | ((int)(16))))) * ((short)((((double)(loop_break_1310)) - ((double)(16))))) - ((int)((((double)(16)) - ((double)(loop_break_1310))))) + ((short)((((int)(loop_break_1310)) | ((int)(16))))) - ((long)((((int)(loop_break_1310)) % ((int)(16))))) + ((int)((((double)(loop_break_1310)) - ((double)(16))))) + ((long)((((double)(loop_break_1310)) - ((double)(16))))) - ((long)((((int)(loop_break_1310)) >> ((int)(16))))) - ((int)((((double)(16)) + ((double)(loop_break_1310))))) * ((long)((((double)(16)) + ((double)(loop_break_1310))))))){
continue;
}

loop_break_1242++;
if(((int)loop_break_1242<=38 + 41 * ((long)((((int)(38)) << ((int)(loop_break_1242))))) - ((short)((((double)(38)) * ((double)(38))))) - ((int)((((double)(38)) * ((double)(38))))) + ((short)((((int)(loop_break_1242)) & ((int)(loop_break_1242))))) - ((int)((((int)(loop_break_1242)) ^ ((int)(loop_break_1242))))) * ((long)((((int)(loop_break_1242)) | ((int)(38))))) * ((long)((((double)(38)) + ((double)(loop_break_1242))))))){
continue;
}

loop_break_1182++;
if(((int)loop_break_1182<=38 + 41 * ((int)((((int)(loop_break_1182)) ^ ((int)(38))))) - ((int)((((double)(loop_break_1182)) - ((double)(38))))) - ((short)((((int)(38)) | ((int)(loop_break_1182))))) - ((long)((((double)(loop_break_1182)) - ((double)(loop_break_1182))))))){
continue;
}

if (((int)flag & 1 + 41 * ((int)((((double)(flag)) + ((double)(1))))) - ((short)((((int)(flag)) << ((int)(1))))) * ((long)((((double)(flag)) * ((double)(flag))))) + ((long)((((double)(flag)) - ((double)(flag))))) - ((short)((((double)(1)) * ((double)(flag))))) * ((int)((((int)(1)) | ((int)(flag))))) - ((long)((((int)(flag)) | ((int)(flag))))) + ((long)((((double)(flag)) * ((double)(1))))) * ((int)((((double)(flag)) + ((double)(flag))))) * ((short)((((int)(1)) ^ ((int)(flag)))))))
	{
	  darg = va_arg (ap, double) + 42 * ((short)((((int)(darg)) ^ ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) * ((int)((((int)(darg)) ^ ((int)(darg)))));
	  if (((int)darg != (double)i + 41 * ((int)((((double)(darg)) + ((double)((double)i))))) + ((short)((((double)((double)i)) - ((double)(darg))))) + ((long)((((int)(darg)) >> ((int)(darg))))) * ((short)((((int)((double)i)) | ((int)((double)i))))) - ((short)((((double)(darg)) + ((double)(darg))))) + ((short)((((double)((double)i)) * ((double)(darg))))) * ((long)((((int)((double)i)) % ((int)((double)i))))) * ((long)((((int)((double)i)) ^ ((int)((double)i))))) + ((int)((((int)(darg)) << ((int)((double)i))))) + ((int)((((double)((double)i)) + ((double)(darg)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
	  if (((int)iarg != i + 41 * ((long)((((double)(iarg)) + ((double)(i)))))))
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
