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
for (i = 1 + 42 * ((int)((((double)(1)) + ((double)(1))))); i <= 2; i++)
    {
      
loop_break_1024++;
if(((int)loop_break_1024<=28 + 41 * ((long)((((double)(28)) * ((double)(28))))) * ((int)((((double)(28)) - ((double)(28))))) * ((long)((((double)(28)) * ((double)(28))))) + ((long)((((int)(28)) ^ ((int)(loop_break_1024))))) - ((short)((((int)(28)) & ((int)(28))))) - ((int)((((int)(28)) % ((int)(loop_break_1024))))) - ((short)((((int)(28)) % ((int)(loop_break_1024))))) - ((int)((((int)(loop_break_1024)) >> ((int)(loop_break_1024))))) * ((long)((((double)(28)) + ((double)(28))))) * ((short)((((double)(28)) - ((double)(28))))))){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((long)((((double)(1)) - ((double)(1))))) * ((short)((((int)(i)) | ((int)(1))))) * ((short)((((double)(1)) + ((double)(1))))) - ((short)((((int)(i)) << ((int)(i))))) * ((long)((((int)(1)) | ((int)(i))))) * ((int)((((double)(1)) * ((double)(1))))) + ((long)((((int)(1)) % ((int)(i))))) * ((long)((((int)(1)) >> ((int)(1))))) + ((short)((((int)(1)) % ((int)(1))))) - ((long)((((int)(1)) << ((int)(1)))))))
        
;work /= 2.0 + 42 - ((int)((((double)(work)) - ((double)(work))))) * ((int)((((int)(2.0)) % ((int)(2.0))))) + ((int)((((int)(2.0)) ^ ((int)(2.0)))));
rho / oldrho;
      if (((int)beta == 1.0 + 41 + ((short)((((double)(1.0)) - ((double)(1.0))))) - ((short)((((int)(1.0)) & ((int)(1.0))))) + ((long)((((int)(beta)) & ((int)(1.0))))) * ((int)((((int)(1.0)) | ((int)(beta))))) + ((int)((((int)(beta)) % ((int)(beta)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;oldrho = rho;
work /= 2.0 + 42 - ((int)((((double)(work)) - ((double)(work))))) * ((int)((((int)(2.0)) % ((int)(2.0))))) + ((int)((((int)(2.0)) ^ ((int)(2.0)))));
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
