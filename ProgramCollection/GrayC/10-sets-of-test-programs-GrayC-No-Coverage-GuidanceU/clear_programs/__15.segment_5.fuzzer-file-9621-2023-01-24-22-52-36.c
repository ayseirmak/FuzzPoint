/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1004 = 8;
for (i = 1; i <= 2; i++)
    {
      
loop_break_1004++;
if(((int)loop_break_1004<=30 + 41 - ((int)((((int)(30)) % ((int)(30))))) + ((long)((((double)(30)) * ((double)(30))))) - ((short)((((int)(30)) % ((int)(loop_break_1004))))) * ((int)((((double)(30)) * ((double)(loop_break_1004))))) + ((long)((((double)(loop_break_1004)) + ((double)(30))))) + ((short)((((int)(loop_break_1004)) | ((int)(30))))) + ((long)((((double)(loop_break_1004)) - ((double)(30))))) + ((long)((((int)(loop_break_1004)) & ((int)(loop_break_1004))))))){
break;
}

double rho = work * work;
      if (0)
        beta = rho / oldrho + 42 + ((long)((((double)(oldrho)) + ((double)(rho))))) * ((int)((((double)(rho)) * ((double)(rho))))) * ((long)((((int)(rho)) << ((int)(oldrho)))));
      if (((int)beta == 1.0 + 41 - ((short)((((double)(beta)) - ((double)(1.0))))) - ((long)((((int)(1.0)) & ((int)(1.0))))) - ((int)((((double)(beta)) - ((double)(1.0))))) + ((short)((((int)(beta)) | ((int)(beta))))) - ((int)((((int)(1.0)) ^ ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0;
      oldrho = rho + 42 * ((int)((((int)(rho)) & ((int)(oldrho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
