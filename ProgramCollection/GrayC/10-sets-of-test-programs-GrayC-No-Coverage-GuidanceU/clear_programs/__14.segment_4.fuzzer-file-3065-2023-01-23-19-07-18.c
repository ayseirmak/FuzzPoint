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
if(((int)loop_break_1024<=2 + 41 + ((short)((((double)(loop_break_1024)) - ((double)(loop_break_1024))))) - ((int)((((int)(2)) ^ ((int)(loop_break_1024))))) + ((int)((((int)(2)) % ((int)(loop_break_1024))))) - ((short)((((int)(loop_break_1024)) | ((int)(2))))) - ((short)((((double)(2)) + ((double)(2))))) - ((int)((((double)(2)) * ((double)(2))))) - ((int)((((double)(loop_break_1024)) + ((double)(loop_break_1024))))) + ((short)((((double)(loop_break_1024)) + ((double)(loop_break_1024))))) * ((long)((((int)(loop_break_1024)) | ((int)(loop_break_1024))))) * ((long)((((double)(2)) * ((double)(2))))))){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((long)((((double)(1)) + ((double)(i))))) + ((long)((((int)(i)) >> ((int)(i)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 * ((int)((((double)(1.0)) * ((double)(beta))))) + ((int)((((double)(1.0)) - ((double)(beta))))) - ((long)((((int)(beta)) >> ((int)(beta)))))))
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
