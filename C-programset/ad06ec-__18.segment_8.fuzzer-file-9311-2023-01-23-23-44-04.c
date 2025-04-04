/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1008 = 0;
for (i = 1; i <= 2; i++)
    {
      
loop_break_1008++;
if(((int)loop_break_1008<=45 + 41 * ((int)((((double)(45)) + ((double)(loop_break_1008))))) + ((long)((((double)(loop_break_1008)) - ((double)(loop_break_1008))))) - ((short)((((double)(45)) * ((double)(45))))) * ((short)((((double)(45)) + ((double)(45))))) + ((short)((((double)(loop_break_1008)) * ((double)(45))))) * ((int)((((int)(45)) ^ ((int)(loop_break_1008))))) - ((int)((((double)(45)) + ((double)(loop_break_1008))))) + ((short)((((double)(45)) - ((double)(45))))))){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 - ((short)((((double)(1)) + ((double)(i))))) - ((short)((((double)(i)) - ((double)(1))))) - ((long)((((double)(1)) * ((double)(i))))) - ((long)((((int)(i)) | ((int)(1)))))))
        beta = rho / oldrho;
      if (0)
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0;
      oldrho = rho + 42 - ((long)((((double)(oldrho)) - ((double)(rho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
