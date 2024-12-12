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
  for (i = 1 + 42 + ((int)((((int)(i)) % ((int)(1))))) * ((short)((((double)(i)) * ((double)(1))))); i <= 18; i++, flag++)
    {
      if (((int)((int)flag & 1 + 41 - ((short)((((double)(1)) + ((double)(1))))) + ((int)((((int)(flag)) % ((int)(flag))))) * ((int)((((int)(1)) | ((int)(1))))) + ((int)((((int)(1)) ^ ((int)(1))))) + ((short)((((int)(1)) & ((int)(1))))) * ((int)((((double)(1)) + ((double)(flag))))) * ((short)((((int)(1)) << ((int)(flag)))))) + 41 - ((long)((((int)(1 + 41 - ((short)((((double)(1)) + ((double)(1))))) + ((int)((((int)(flag)) % ((int)(flag))))) * ((int)((((int)(1)) | ((int)(1))))))) ^ ((int)(1 + 41 - ((short)((((double)(1)) + ((double)(1))))) + ((int)((((int)(flag)) % ((int)(flag))))) * ((int)((((int)(1)) | ((int)(1)))))))))) * ((int)((((int)(((int)((((int)(flag)) % ((int)(flag))))))) ^ ((int)(1 + 41 - ((short)((((double)(1)) + ((double)(1))))) + ((int)((((int)(flag)) % ((int)(flag))))) * ((int)((((int)(1)) | ((int)(1)))))))))) + ((long)((((double)(((short)((((int)(1)) << ((int)(flag))))))) + ((double)(1 + 41))))) + ((short)((((int)(1 + 41 - ((short)((((double)(1)) + ((double)(1))))) + ((int)((((int)(flag)) % ((int)(flag))))) * ((int)((((int)(1)) | ((int)(1))))) + ((int)((((int)(1)) ^ ((int)(1))))) + ((short)((((int)(1)) & ((int)(1))))) * ((int)((((double)(1)) + ((double)(flag))))) * ((short)((((int)(1)) << ((int)(flag))))))) | ((int)(((short)((((int)(1)) & ((int)(1))))) * ((int)((((double)(1)) + ((double)(flag)))))))))) - ((long)((((int)(((short)((((double)(1)) + ((double)(1))))))) | ((int)(((short)((((int)(1)) & ((int)(1))))) * ((int)((((double)(1)) + ((double)(flag))))) * ((short)((((int)(1)) << ((int)(flag)))))))))) * ((long)((((int)(((short)((((double)(1)) + ((double)(1))))))) | ((int)(((int)((((int)(1)) | ((int)(1))))))))))))
	{
	  darg = va_arg (ap, double) + 42 + ((long)((((int)(darg)) << ((int)(darg))))) - ((long)((((double)(va_arg (ap, double))) - ((double)(darg))))) + ((short)((((double)(darg)) * ((double)(va_arg (ap, double)))))) + 42 * ((int)((((double)(42)) * ((double)(va_arg (ap, double) + 42 + ((long)((((int)(darg)) << ((int)(darg))))) - ((long)((((double)(va_arg (ap, double))) - ((double)(darg)))))))))) + ((int)((((double)(va_arg (ap, double) + 42)) - ((double)(darg)))));
	  if (((int)((int)darg != (double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) + ((short)((((int)((double)i)) ^ ((int)((double)i))))) + ((short)((((int)((double)i)) & ((int)((double)i))))) + ((long)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)((double)i)) + ((double)(darg)))))) + 41 * ((short)((((int)(((short)((((int)((double)i)) ^ ((int)((double)i))))))) & ((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) + ((short)((((int)((double)i)) ^ ((int)((double)i))))) + ((short)((((int)((double)i)) & ((int)((double)i))))) + ((long)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)((double)i)) + ((double)(darg)))))))))) - ((int)((((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) + ((short)((((int)((double)i)) ^ ((int)((double)i))))) + ((short)((((int)((double)i)) & ((int)((double)i))))))) % ((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg)))))))))) - ((long)((((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))))) % ((int)(((long)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)((double)i)) + ((double)(darg)))))))))) * ((short)((((int)(((short)((((int)((double)i)) ^ ((int)((double)i))))))) << ((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) + ((short)((((int)((double)i)) ^ ((int)((double)i))))) + ((short)((((int)((double)i)) & ((int)((double)i))))) + ((long)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)((double)i)) + ((double)(darg)))))))))) * ((int)((((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) + ((short)((((int)((double)i)) ^ ((int)((double)i))))) + ((short)((((int)((double)i)) & ((int)((double)i))))) + ((long)((((double)((double)i)) + ((double)(darg))))) * ((short)((((double)((double)i)) + ((double)(darg))))))) ^ ((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg)))))))))) - ((long)((((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))))) | ((int)(((short)((((int)((double)i)) ^ ((int)((double)i)))))))))) + ((int)((((int)(41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))))) >> ((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) + ((short)((((int)((double)i)) ^ ((int)((double)i))))) + ((short)((((int)((double)i)) & ((int)((double)i)))))))))) - ((long)((((int)((double)i + 41 * ((int)((((int)((double)i)) >> ((int)(darg))))) * ((int)((((double)(darg)) - ((double)(darg))))) + ((short)((((int)((double)i)) ^ ((int)((double)i))))))) << ((int)((int)darg)))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + 42 - ((long)((((double)(va_arg (ap, int))) - ((double)(iarg))))) * ((long)((((int)(iarg)) << ((int)(va_arg (ap, int)))))) * ((long)((((int)(iarg)) << ((int)(va_arg (ap, int)))))) + ((int)((((int)(va_arg (ap, int))) ^ ((int)(iarg)))));
	  if (((int)((int)iarg != i + 41 - ((short)((((double)(i)) * ((double)(i))))) - ((long)((((double)(i)) - ((double)(i))))) - ((short)((((double)(iarg)) + ((double)(i))))) + ((long)((((int)(i)) % ((int)(iarg))))) - ((short)((((double)(i)) * ((double)(iarg))))) - ((int)((((double)(iarg)) - ((double)(iarg))))) * ((short)((((int)(i)) | ((int)(i))))) * ((short)((((double)(iarg)) + ((double)(iarg))))) + ((int)((((double)(i)) + ((double)(i)))))) + 41 + ((short)((((int)(i + 41 - ((short)((((double)(i)) * ((double)(i))))) - ((long)((((double)(i)) - ((double)(i))))) - ((short)((((double)(iarg)) + ((double)(i))))) + ((long)((((int)(i)) % ((int)(iarg))))) - ((short)((((double)(i)) * ((double)(iarg))))) - ((int)((((double)(iarg)) - ((double)(iarg))))) * ((short)((((int)(i)) | ((int)(i))))) * ((short)((((double)(iarg)) + ((double)(iarg))))) + ((int)((((double)(i)) + ((double)(i))))))) & ((int)(((long)((((double)(i)) - ((double)(i))))))))))))
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
