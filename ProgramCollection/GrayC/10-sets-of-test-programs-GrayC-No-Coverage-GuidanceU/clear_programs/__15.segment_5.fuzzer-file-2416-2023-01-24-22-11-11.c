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
  
int loop_break_20420 = 0;

int loop_break_20480 = 0;
for (i = 1 + 42 * ((long)((((int)(i)) % ((int)(i))))) + ((long)((((int)(i)) % ((int)(1))))) * ((int)((((int)(1)) | ((int)(1))))) + ((short)((((double)(i)) * ((double)(1))))) + ((long)((((double)(i)) + ((double)(1))))); i <= 18; i++, flag++)
    {
      

loop_break_20480++;
if(loop_break_20480<=18){
continue;
}

loop_break_20420++;
if(loop_break_20420<=18){
continue;
}

if (((int)((int)flag & 1 + 41 - ((short)((((double)(flag)) - ((double)(flag))))) * ((short)((((double)(flag)) + ((double)(1))))) * ((long)((((int)(1)) << ((int)(1))))) + ((short)((((int)(flag)) ^ ((int)(flag))))) * ((int)((((int)(flag)) ^ ((int)(1))))) + ((long)((((int)(1)) << ((int)(1))))) * ((long)((((double)(1)) - ((double)(flag))))) * ((short)((((int)(flag)) | ((int)(flag))))) + ((long)((((int)(1)) & ((int)(flag)))))) + 41 - ((int)((((int)(((long)((((int)(1)) & ((int)(flag))))))) & ((int)(((short)((((double)(flag)) - ((double)(flag))))) * ((short)((((double)(flag)) + ((double)(1))))) * ((long)((((int)(1)) << ((int)(1)))))))))) + ((int)((((int)(1 + 41 - ((short)((((double)(flag)) - ((double)(flag))))) * ((short)((((double)(flag)) + ((double)(1))))) * ((long)((((int)(1)) << ((int)(1))))) + ((short)((((int)(flag)) ^ ((int)(flag))))) * ((int)((((int)(flag)) ^ ((int)(1))))) + ((long)((((int)(1)) << ((int)(1))))) * ((long)((((double)(1)) - ((double)(flag))))) * ((short)((((int)(flag)) | ((int)(flag))))) + ((long)((((int)(1)) & ((int)(flag))))))) % ((int)(((short)((((double)(flag)) - ((double)(flag))))) * ((short)((((double)(flag)) + ((double)(1)))))))))) * ((int)((((int)((int)flag)) ^ ((int)(((short)((((int)(flag)) ^ ((int)(flag))))) * ((int)((((int)(flag)) ^ ((int)(1))))))))))))
	{
	  darg = va_arg (ap, double) + 42 + ((long)((((double)(va_arg (ap, double))) * ((double)(darg))))) * ((int)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double)))))) + 42 * ((short)((((int)(va_arg (ap, double) + 42 + ((long)((((double)(va_arg (ap, double))) * ((double)(darg))))) * ((int)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double)))))))) % ((int)(42))))) - ((short)((((int)(va_arg (ap, double) + 42 + ((long)((((double)(va_arg (ap, double))) * ((double)(darg))))) * ((int)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double)))))))) << ((int)(va_arg (ap, double) + 42 + ((long)((((double)(va_arg (ap, double))) * ((double)(darg))))) * ((int)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double))))))))))) * ((long)((((int)(va_arg (ap, double) + 42 + ((long)((((double)(va_arg (ap, double))) * ((double)(darg))))) * ((int)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double)))))))) | ((int)(((long)((((double)(va_arg (ap, double))) * ((double)(darg))))) * ((int)((((int)(va_arg (ap, double))) >> ((int)(va_arg (ap, double)))))))))));
	  if (((int)((int)darg != (double)i + 41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i)))))) + 41 - ((int)((((int)(41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i))))))) | ((int)((int)darg))))) * ((long)((((int)(41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i))))))) & ((int)((double)i + 41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i)))))))))) * ((int)((((int)((double)i + 41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i))))))) | ((int)((int)darg))))) + ((short)((((int)(41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i))))))) | ((int)((double)i))))) + ((long)((((int)((double)i + 41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i))))))) << ((int)(41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i)))))))))) * ((int)((((int)(41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i))))))) & ((int)((int)darg))))) + ((long)((((int)((int)darg)) | ((int)(41 * ((short)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)(darg)) - ((double)((double)i))))))))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 + ((long)((((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int)))))) + ((long)((((double)(va_arg (ap, int))) + ((double)(va_arg (ap, int)))))) + 42 * ((long)((((int)(va_arg (ap, int) + 42 + ((long)((((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int)))))) + ((long)((((double)(va_arg (ap, int))) + ((double)(va_arg (ap, int)))))))) % ((int)(iarg))))) + ((int)((((int)(va_arg (ap, int) + 42 + ((long)((((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int)))))) + ((long)((((double)(va_arg (ap, int))) + ((double)(va_arg (ap, int)))))))) % ((int)(va_arg (ap, int) + 42 + ((long)((((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int)))))) + ((long)((((double)(va_arg (ap, int))) + ((double)(va_arg (ap, int))))))))))) - ((short)((((int)(va_arg (ap, int) + 42 + ((long)((((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int)))))) + ((long)((((double)(va_arg (ap, int))) + ((double)(va_arg (ap, int)))))))) | ((int)(va_arg (ap, int) + 42 + ((long)((((double)(va_arg (ap, int))) * ((double)(va_arg (ap, int)))))) + ((long)((((double)(va_arg (ap, int))) + ((double)(va_arg (ap, int)))))))))));
	  if (((int)((int)iarg != i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((long)((((int)(i)) << ((int)(iarg))))) * ((int)((((double)(i)) - ((double)(iarg))))) - ((short)((((int)(i)) % ((int)(iarg))))) + ((int)((((double)(i)) * ((double)(iarg))))) - ((int)((((double)(i)) + ((double)(i))))) + ((int)((((double)(i)) - ((double)(iarg)))))) + 41 - ((long)((((int)(((short)((((int)(i)) % ((int)(iarg))))))) & ((int)(((int)((((double)(i)) - ((double)(iarg)))))))))) + ((int)((((int)(((long)((((double)(i)) - ((double)(i))))))) >> ((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((long)((((int)(i)) << ((int)(iarg))))) * ((int)((((double)(i)) - ((double)(iarg))))) - ((short)((((int)(i)) % ((int)(iarg))))) + ((int)((((double)(i)) * ((double)(iarg))))) - ((int)((((double)(i)) + ((double)(i)))))))))) - ((short)((((double)(((int)((((double)(i)) + ((double)(i))))))) - ((double)(((int)((((double)(i)) + ((double)(i)))))))))) + ((short)((((int)(((int)((((double)(i)) - ((double)(iarg))))))) << ((int)(((long)((((int)(i)) << ((int)(iarg)))))))))) * ((long)((((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((long)((((int)(i)) << ((int)(iarg))))) * ((int)((((double)(i)) - ((double)(iarg))))) - ((short)((((int)(i)) % ((int)(iarg))))) + ((int)((((double)(i)) * ((double)(iarg))))))) ^ ((int)(((long)((((int)(i)) << ((int)(iarg)))))))))) - ((int)((((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((long)((((int)(i)) << ((int)(iarg))))) * ((int)((((double)(i)) - ((double)(iarg))))) - ((short)((((int)(i)) % ((int)(iarg))))) + ((int)((((double)(i)) * ((double)(iarg))))) - ((int)((((double)(i)) + ((double)(i))))))) >> ((int)(((int)((((double)(i)) - ((double)(iarg)))))))))) + ((long)((((int)(((int)((((double)(i)) - ((double)(iarg))))))) | ((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i)))))))))) - ((long)((((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))))) % ((int)(((int)((((double)(i)) - ((double)(iarg)))))))))) * ((int)((((int)(((long)((((int)(i)) << ((int)(iarg))))))) % ((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((long)((((int)(i)) << ((int)(iarg))))) * ((int)((((double)(i)) - ((double)(iarg))))) - ((short)((((int)(i)) % ((int)(iarg))))) + ((int)((((double)(i)) * ((double)(iarg))))) - ((int)((((double)(i)) + ((double)(i))))) + ((int)((((double)(i)) - ((double)(iarg)))))))))) * ((short)((((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((long)((((int)(i)) << ((int)(iarg))))) * ((int)((((double)(i)) - ((double)(iarg))))))) << ((int)(i + 41 * ((int)((((int)(i)) % ((int)(iarg))))) + ((short)((((int)(i)) ^ ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((long)((((int)(i)) << ((int)(iarg))))) * ((int)((((double)(i)) - ((double)(iarg))))) - ((short)((((int)(i)) % ((int)(iarg))))) + ((int)((((double)(i)) * ((double)(iarg))))))))))))
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
