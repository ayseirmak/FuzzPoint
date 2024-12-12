/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1041 = 0;
for (i = 1; i <= 2; i++)
    {
      
loop_break_1041++;
if(loop_break_1041<=33){
continue;
}

double rho = work * work;
      if (i != 1)
        
;work /= 2.0;
rho / oldrho;
      if (0)
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;oldrho = rho;
work /= 2.0;
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
