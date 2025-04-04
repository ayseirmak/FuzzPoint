/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_2132 = 0;
for (i = 1; i <= 2; i++)
    {
      
loop_break_2132++;
if(loop_break_2132<=11){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((int)((((int)(1)) >> ((int)(i))))) * ((short)((((double)(1)) * ((double)(1))))) - ((long)((((double)(i)) * ((double)(i))))) - ((long)((((double)(i)) * ((double)(1)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 + ((short)((((int)(beta)) ^ ((int)(beta))))) * ((int)((((int)(1.0)) ^ ((int)(1.0))))) + ((long)((((double)(beta)) + ((double)(beta))))) + ((long)((((double)(1.0)) - ((double)(beta))))) * ((short)((((int)(beta)) ^ ((int)(1.0))))) * ((short)((((int)(beta)) ^ ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0;
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
