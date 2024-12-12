/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_2595 = 8;
for (i = 1 + 42 - ((long)((((double)(1)) * ((double)(i))))) + ((short)((((double)(1)) * ((double)(i))))); i <= 2; i++)
    {
      
loop_break_2595++;
if(loop_break_2595<=12){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((long)((((int)(i)) << ((int)(1))))) + ((long)((((int)(i)) & ((int)(i)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 + ((long)((((double)(beta)) - ((double)(1.0))))) * ((short)((((double)(1.0)) - ((double)(beta))))) - ((long)((((int)(beta)) >> ((int)(beta))))) - ((long)((((double)(1.0)) + ((double)(beta))))) + ((int)((((double)(1.0)) + ((double)(1.0))))) - ((long)((((int)(beta)) >> ((int)(1.0))))) - ((short)((((double)(beta)) - ((double)(1.0))))) - ((short)((((double)(beta)) + ((double)(beta))))) - ((long)((((double)(1.0)) * ((double)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0;
      oldrho = rho + 42 * ((long)((((int)(oldrho)) ^ ((int)(rho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
