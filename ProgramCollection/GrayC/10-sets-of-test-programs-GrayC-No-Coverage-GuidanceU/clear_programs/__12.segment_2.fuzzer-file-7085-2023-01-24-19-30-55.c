/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  for (i = 1 + 42 - ((int)((((double)(i)) + ((double)(i))))) + 42 * ((long)((((int)(i)) % ((int)(i))))) + ((long)((((int)(1)) % ((int)(42))))) * ((int)((((int)(42)) | ((int)(42))))) + ((short)((((double)(i)) * ((double)(((int)((((double)(i)) + ((double)(i)))))))))) + ((long)((((double)(1)) + ((double)(1 + 42 - ((int)((((double)(i)) + ((double)(i)))))))))); i <= 2; i++)
    {
      double rho = work * work;
      if (((int)((int)i != 1 + 41 * ((short)((((int)(1)) & ((int)(i)))))) + 41 - ((short)((((double)(1)) - ((double)((int)i))))) * ((short)((((int)(1)) << ((int)(1 + 41 * ((short)((((int)(1)) & ((int)(i)))))))))) * ((long)((((int)(1 + 41 * ((short)((((int)(1)) & ((int)(i))))))) << ((int)(41 * ((short)((((int)(1)) & ((int)(i)))))))))) + ((short)((((int)((int)i)) ^ ((int)(1))))) * ((int)((((int)((int)i)) ^ ((int)(41 * ((short)((((int)(1)) & ((int)(i)))))))))) + ((long)((((int)(1 + 41 * ((short)((((int)(1)) & ((int)(i))))))) << ((int)(1 + 41 * ((short)((((int)(1)) & ((int)(i)))))))))) * ((long)((((double)(((short)((((int)(1)) & ((int)(i))))))) - ((double)((int)i))))) * ((short)((((int)(1)) | ((int)(41))))) + ((long)((((int)(1 + 41 * ((short)((((int)(1)) & ((int)(i))))))) & ((int)(1)))))))
        beta = rho / oldrho + 42 + ((long)((((double)(oldrho)) * ((double)(rho))))) * ((int)((((int)(oldrho)) >> ((int)(rho / oldrho)))));
      if (((int)((int)beta == 1.0 + 41 + ((short)((((double)(1.0)) + ((double)(1.0))))) - ((int)((((double)(1.0)) - ((double)(1.0))))) - ((int)((((double)(beta)) * ((double)(beta))))) - ((int)((((int)(1.0)) >> ((int)(beta))))) * ((short)((((double)(1.0)) - ((double)(1.0))))) - ((long)((((int)(beta)) << ((int)(1.0)))))) + 41 * ((short)((((int)(1.0 + 41 + ((short)((((double)(1.0)) + ((double)(1.0))))) - ((int)((((double)(1.0)) - ((double)(1.0))))) - ((int)((((double)(beta)) * ((double)(beta))))) - ((int)((((int)(1.0)) >> ((int)(beta))))) * ((short)((((double)(1.0)) - ((double)(1.0))))) - ((long)((((int)(beta)) << ((int)(1.0))))))) ^ ((int)(1.0 + 41 + ((short)((((double)(1.0)) + ((double)(1.0))))) - ((int)((((double)(1.0)) - ((double)(1.0))))) - ((int)((((double)(beta)) * ((double)(beta))))) - ((int)((((int)(1.0)) >> ((int)(beta))))) * ((short)((((double)(1.0)) - ((double)(1.0)))))))))) * ((short)((((int)((int)beta)) >> ((int)(((int)((((int)(1.0)) >> ((int)(beta))))) * ((short)((((double)(1.0)) - ((double)(1.0))))))))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0 + 42 + ((long)((((double)(2.0)) * ((double)(2.0))))) + ((long)((((double)(2.0)) + ((double)(2.0)))));
      oldrho = rho + 42 - ((long)((((int)(oldrho)) ^ ((int)(rho))))) + 42 * ((int)((((int)(42)) & ((int)(42))))) - ((long)((((double)(((long)((((int)(oldrho)) ^ ((int)(rho))))))) - ((double)(rho))))) * ((int)((((int)(rho + 42)) >> ((int)(rho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
