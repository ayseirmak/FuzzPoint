/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_3062 = 0;
for (i = 1; i <= 2; i++)
    {
      
loop_break_3062++;
if(loop_break_3062<=24){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((int)((((int)(1)) << ((int)(1))))) * ((int)((((int)(i)) << ((int)(1))))) + ((long)((((double)(1)) - ((double)(1))))) - ((long)((((int)(1)) ^ ((int)(1))))) * ((long)((((int)(1)) << ((int)(1))))) - ((short)((((double)(i)) - ((double)(1))))) * ((short)((((double)(1)) - ((double)(i))))) - ((long)((((int)(1)) % ((int)(i))))) * ((int)((((int)(i)) >> ((int)(1)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 + ((long)((((double)(beta)) + ((double)(beta))))) * ((short)((((double)(1.0)) - ((double)(1.0))))) * ((long)((((double)(1.0)) + ((double)(1.0))))) - ((short)((((int)(1.0)) << ((int)(beta))))) + ((short)((((int)(1.0)) % ((int)(1.0))))) + ((long)((((int)(beta)) | ((int)(1.0))))) * ((int)((((int)(beta)) % ((int)(beta))))) - ((int)((((double)(beta)) - ((double)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0 + 42 - ((long)((((double)(work)) + ((double)(2.0))))) - ((int)((((double)(2.0)) + ((double)(work)))));
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
