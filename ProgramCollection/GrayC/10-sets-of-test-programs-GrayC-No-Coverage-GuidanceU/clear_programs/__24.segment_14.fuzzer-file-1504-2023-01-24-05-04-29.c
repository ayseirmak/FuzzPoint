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
      if (((int)i != 1 + 41 - ((short)((((double)(i)) + ((double)(1))))) * ((int)((((double)(i)) + ((double)(i)))))))
        
;work /= 2.0 + 42 * ((short)((((double)(2.0)) - ((double)(work))))) * ((short)((((int)(2.0)) & ((int)(2.0))))) + ((int)((((int)(work)) & ((int)(work))))) * ((int)((((double)(2.0)) + ((double)(work))))) - ((long)((((double)(2.0)) * ((double)(work)))));
rho / oldrho;
      if (0)
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;oldrho = rho;
work /= 2.0 + 42 - ((long)((((double)(work)) * ((double)(work))))) - ((short)((((int)(work)) ^ ((int)(work)))));
      oldrho = rho + 42 * ((int)((((int)(oldrho)) >> ((int)(rho))))) - ((short)((((int)(oldrho)) ^ ((int)(oldrho))))) + ((int)((((double)(oldrho)) * ((double)(oldrho))))) + ((int)((((double)(rho)) * ((double)(rho))))) - ((short)((((int)(oldrho)) & ((int)(oldrho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
