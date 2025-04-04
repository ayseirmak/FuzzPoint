/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1024 = 8;
for (i = 1 + 42 * ((int)((((int)(1)) << ((int)(1))))) * ((short)((((double)(i)) * ((double)(i))))); i <= 2; i++)
    {
      
loop_break_1024++;
if(((int)loop_break_1024<=2 + 41 * ((int)((((int)(2)) % ((int)(2))))) - ((int)((((int)(loop_break_1024)) | ((int)(loop_break_1024))))) - ((long)((((int)(2)) | ((int)(2))))) * ((long)((((double)(loop_break_1024)) + ((double)(2))))) - ((int)((((double)(loop_break_1024)) * ((double)(2))))))){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 * ((short)((((int)(i)) >> ((int)(1))))) * ((int)((((double)(i)) - ((double)(i))))) - ((int)((((int)(i)) % ((int)(1))))) + ((long)((((double)(i)) * ((double)(i))))) + ((long)((((double)(1)) + ((double)(i))))) + ((int)((((double)(i)) * ((double)(1)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 + ((short)((((double)(beta)) - ((double)(beta))))) + ((int)((((int)(beta)) ^ ((int)(beta))))) * ((long)((((double)(1.0)) + ((double)(1.0))))) + ((short)((((double)(1.0)) * ((double)(beta)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0 + 42 * ((long)((((double)(2.0)) * ((double)(2.0))))) * ((int)((((int)(work)) << ((int)(2.0))))) + ((int)((((double)(2.0)) + ((double)(2.0)))));
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
