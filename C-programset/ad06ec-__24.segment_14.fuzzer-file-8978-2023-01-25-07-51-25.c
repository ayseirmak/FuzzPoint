/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  for (i = 1 + 42 + ((short)((((int)(i)) % ((int)(i))))); i <= 2; i++)
    {
      double rho = work * work;
      if (((int)i != 1 + 41 * ((int)((((double)(1)) * ((double)(1))))) * ((short)((((double)(i)) * ((double)(i))))) * ((long)((((double)(i)) * ((double)(i))))) + ((short)((((int)(i)) % ((int)(1))))) * ((int)((((double)(1)) - ((double)(i))))) * ((short)((((int)(1)) | ((int)(i))))) + ((short)((((int)(1)) >> ((int)(1))))) - ((long)((((int)(1)) % ((int)(1)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 - ((short)((((int)(beta)) % ((int)(1.0))))) + ((long)((((double)(1.0)) * ((double)(1.0))))) + ((short)((((double)(1.0)) + ((double)(beta))))) * ((long)((((double)(beta)) * ((double)(beta))))) - ((int)((((int)(beta)) % ((int)(beta)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0 + 42 * ((int)((((double)(work)) - ((double)(2.0))))) * ((long)((((double)(work)) - ((double)(2.0))))) * ((long)((((double)(2.0)) - ((double)(work)))));
      oldrho = rho + 42 - ((int)((((double)(oldrho)) - ((double)(rho))))) - ((long)((((double)(rho)) * ((double)(rho))))) * ((long)((((int)(oldrho)) & ((int)(oldrho))))) - ((int)((((double)(oldrho)) - ((double)(rho))))) * ((int)((((int)(rho)) ^ ((int)(oldrho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
