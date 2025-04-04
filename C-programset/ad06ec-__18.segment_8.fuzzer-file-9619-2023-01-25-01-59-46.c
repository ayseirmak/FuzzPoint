/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  for (i = 1; i <= 2; i++)
    {
      double rho = work * work;
      if (((int)i != 1 + 41 * ((int)((((int)(1)) & ((int)(1))))) - ((short)((((double)(1)) - ((double)(i))))) - ((short)((((int)(1)) ^ ((int)(i))))) - ((long)((((int)(i)) ^ ((int)(1))))) + ((long)((((double)(i)) + ((double)(i))))) * ((short)((((int)(1)) % ((int)(1))))) * ((int)((((double)(1)) - ((double)(1))))) * ((short)((((double)(i)) * ((double)(i))))) + ((short)((((double)(1)) - ((double)(1))))) * ((int)((((double)(i)) - ((double)(1)))))))
        
;work /= 2.0;
rho / oldrho;
      if (((int)beta == 1.0 + 41 - ((int)((((double)(1.0)) - ((double)(1.0))))) + ((int)((((double)(beta)) + ((double)(1.0))))) * ((long)((((double)(1.0)) + ((double)(1.0))))) * ((short)((((double)(beta)) * ((double)(beta))))) * ((short)((((int)(1.0)) << ((int)(beta))))) + ((long)((((int)(1.0)) | ((int)(beta))))) - ((short)((((double)(beta)) * ((double)(beta))))) - ((int)((((int)(1.0)) & ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;oldrho = rho;
work /= 2.0;
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
