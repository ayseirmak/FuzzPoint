/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1024 = 0;
for (i = 1; i <= 2; i++)
    {
      
loop_break_1024++;
if(((int)loop_break_1024<=35 + 41 - ((short)((((double)(loop_break_1024)) * ((double)(loop_break_1024))))))){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 - ((long)((((int)(1)) << ((int)(i))))) - ((long)((((int)(i)) % ((int)(1))))) - ((short)((((int)(1)) % ((int)(i))))) - ((long)((((int)(i)) | ((int)(1))))) - ((short)((((int)(1)) | ((int)(i))))) * ((short)((((int)(1)) << ((int)(i))))) * ((int)((((int)(i)) << ((int)(1))))) - ((short)((((int)(1)) << ((int)(i))))) + ((long)((((int)(i)) % ((int)(1)))))))
        beta = rho / oldrho + 42 * ((int)((((double)(beta)) * ((double)(oldrho)))));
      if (((int)beta == 1.0 + 41 + ((short)((((int)(1.0)) << ((int)(1.0))))) - ((short)((((double)(beta)) + ((double)(1.0))))) - ((long)((((int)(beta)) >> ((int)(beta))))) - ((int)((((int)(1.0)) >> ((int)(beta))))) - ((long)((((double)(1.0)) * ((double)(beta))))) + ((long)((((int)(1.0)) >> ((int)(beta))))) + ((int)((((int)(1.0)) & ((int)(beta))))) * ((int)((((int)(1.0)) ^ ((int)(1.0))))) + ((long)((((double)(1.0)) - ((double)(beta)))))))
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
