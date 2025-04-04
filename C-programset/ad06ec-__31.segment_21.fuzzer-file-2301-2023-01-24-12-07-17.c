/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  for (i = 1 + 42 + ((int)((((int)(i)) | ((int)(i))))) * ((long)((((double)(i)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(1))))) + 42 * ((short)((((int)(1 + 42 + ((int)((((int)(i)) | ((int)(i))))) * ((long)((((double)(i)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(1))))))) & ((int)(1 + 42 + ((int)((((int)(i)) | ((int)(i))))) * ((long)((((double)(i)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(1)))))))))) + ((short)((((int)(1 + 42 + ((int)((((int)(i)) | ((int)(i))))) * ((long)((((double)(i)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(1))))))) | ((int)(1 + 42 + ((int)((((int)(i)) | ((int)(i))))) * ((long)((((double)(i)) + ((double)(1))))) + ((long)((((double)(1)) - ((double)(1)))))))))); i <= 2; i++)
    {
      double rho = work * work;
      if (0)
        rho / oldrho;
      if (((int)((int)beta == 1.0 + 41 - ((int)((((double)(1.0)) * ((double)(beta))))) * ((short)((((int)(1.0)) >> ((int)(1.0))))) * ((long)((((double)(beta)) - ((double)(beta)))))) + 41 * ((int)((((int)(41)) % ((int)(((int)((((double)(1.0)) * ((double)(beta))))) * ((short)((((int)(1.0)) >> ((int)(1.0))))) * ((long)((((double)(beta)) - ((double)(beta)))))))))) * ((short)((((int)(1.0 + 41)) << ((int)(1.0 + 41 - ((int)((((double)(1.0)) * ((double)(beta))))) * ((short)((((int)(1.0)) >> ((int)(1.0))))) * ((long)((((double)(beta)) - ((double)(beta)))))))))) + ((short)((((double)(41)) * ((double)((int)beta))))) + ((long)((((int)(1.0 + 41 - ((int)((((double)(1.0)) * ((double)(beta))))) * ((short)((((int)(1.0)) >> ((int)(1.0))))) * ((long)((((double)(beta)) - ((double)(beta))))))) | ((int)(41))))) + ((int)((((int)(41)) & ((int)(1.0 + 41))))) - ((short)((((int)(41)) ^ ((int)((int)beta))))) - ((long)((((int)(((int)((((double)(1.0)) * ((double)(beta))))) * ((short)((((int)(1.0)) >> ((int)(1.0))))) * ((long)((((double)(beta)) - ((double)(beta))))))) | ((int)(1.0 + 41))))) * ((short)((((int)(1.0)) % ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;oldrho = rho + 42 * ((int)((((double)(oldrho)) - ((double)(oldrho))))) + ((short)((((int)(oldrho)) << ((int)(rho))))) + ((long)((((int)(rho)) << ((int)(oldrho))))) - ((long)((((int)(rho)) >> ((int)(oldrho))))) - ((long)((((double)(oldrho)) - ((double)(oldrho)))));
2.0 + 42 - ((short)((((int)(2.0)) >> ((int)(2.0))))) * ((short)((((double)(work)) * ((double)(2.0)))));
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
