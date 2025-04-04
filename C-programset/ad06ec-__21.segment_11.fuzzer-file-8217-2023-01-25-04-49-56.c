/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_2838 = 0;
for (i = 1 + 42 + ((int)((((double)(1)) - ((double)(1))))) + ((int)((((double)(1)) + ((double)(1))))); i <= 2; i++)
    {
      
loop_break_2838++;
if(loop_break_2838<=2){
continue;
}

double rho = work * work;
      if (0)
        
;2.0;
rho / oldrho;
      if (((int)beta == 1.0 + 41 * ((long)((((double)(beta)) + ((double)(beta))))) + ((int)((((int)(1.0)) ^ ((int)(beta))))) - ((short)((((double)(1.0)) + ((double)(1.0))))) + ((short)((((int)(1.0)) & ((int)(beta))))) * ((long)((((double)(beta)) + ((double)(1.0))))) - ((long)((((int)(beta)) & ((int)(1.0))))) * ((long)((((int)(beta)) & ((int)(beta))))) + ((int)((((double)(beta)) * ((double)(beta))))) - ((short)((((int)(1.0)) >> ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;
;work /= 2.0;
rho + 42 - ((long)((((int)(oldrho)) & ((int)(oldrho))))) + ((int)((((int)(oldrho)) & ((int)(oldrho))))) - ((long)((((int)(rho)) ^ ((int)(oldrho)))));

;oldrho = rho;
work /= 2.0;
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
