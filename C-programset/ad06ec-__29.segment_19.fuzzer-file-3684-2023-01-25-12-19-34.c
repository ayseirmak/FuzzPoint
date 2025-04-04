/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_2578 = 0;
for (i = 1; i <= 2; i++)
    {
      
loop_break_2578++;
if(loop_break_2578<=4){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 - ((long)((((double)(1)) * ((double)(1))))) * ((short)((((int)(1)) ^ ((int)(1))))) - ((long)((((double)(1)) * ((double)(1))))) * ((long)((((int)(1)) ^ ((int)(1))))) - ((int)((((double)(1)) * ((double)(1))))) - ((int)((((double)(1)) * ((double)(i))))) * ((short)((((int)(1)) >> ((int)(i))))) - ((short)((((int)(i)) << ((int)(1)))))))
        beta = rho / oldrho + 42 + ((long)((((double)(beta)) - ((double)(rho / oldrho))))) * ((int)((((int)(rho)) % ((int)(rho)))));
      if (((int)beta == 1.0 + 41 * ((int)((((int)(1.0)) & ((int)(beta)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0;
      oldrho = rho + 42 * ((int)((((int)(rho)) << ((int)(oldrho))))) + ((int)((((int)(oldrho)) % ((int)(rho))))) * ((long)((((int)(oldrho)) << ((int)(oldrho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
