/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  for (i = 1 + 42 - ((long)((((double)(1)) - ((double)(i))))); i <= 2; i++)
    {
      double rho = work * work;
      if (((int)i != 1 + 41 - ((int)((((double)(i)) + ((double)(i))))) + ((short)((((double)(i)) - ((double)(1))))) - ((long)((((double)(i)) * ((double)(1))))) * ((int)((((double)(i)) * ((double)(1))))) - ((short)((((double)(1)) + ((double)(i))))) - ((long)((((int)(i)) ^ ((int)(i))))) + ((long)((((double)(i)) + ((double)(i))))) * ((short)((((int)(i)) | ((int)(1))))) - ((int)((((double)(1)) - ((double)(i)))))))
        beta = rho / oldrho;
      if (0)
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0 + 42 - ((short)((((int)(2.0)) ^ ((int)(work))))) + ((int)((((double)(2.0)) - ((double)(work))))) + ((short)((((int)(2.0)) & ((int)(work))))) - ((int)((((int)(2.0)) & ((int)(2.0)))));
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
