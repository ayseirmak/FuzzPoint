/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1024 = 0;
for (i = 1 + 42 - ((int)((((double)(i)) + ((double)(i))))); i <= 2; i++)
    {
      
loop_break_1024++;
if(((int)loop_break_1024<=43 + 41 * ((short)((((int)(43)) & ((int)(loop_break_1024))))))){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 - ((int)((((double)(1)) * ((double)(i))))) - ((int)((((int)(1)) & ((int)(i))))) * ((long)((((double)(i)) - ((double)(i)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 + ((long)((((double)(beta)) * ((double)(beta))))) * ((short)((((int)(1.0)) % ((int)(beta))))) - ((int)((((int)(1.0)) << ((int)(beta))))) * ((short)((((int)(beta)) | ((int)(1.0))))) * ((short)((((double)(1.0)) - ((double)(beta))))) * ((long)((((int)(1.0)) ^ ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0;
      oldrho = rho + 42 + ((long)((((double)(rho)) + ((double)(rho))))) * ((short)((((double)(rho)) * ((double)(rho))))) + ((long)((((int)(oldrho)) | ((int)(oldrho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
