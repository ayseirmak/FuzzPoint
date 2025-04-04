/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i = 8;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1024 = 0;
for (i = 1; i <= 2; i++)
    {
      
loop_break_1024++;
if(((int)loop_break_1024<=31 + 41 + ((short)((((double)(loop_break_1024)) - ((double)(loop_break_1024))))))){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((long)((((double)(i)) + ((double)(i))))) - ((int)((((int)(1)) % ((int)(1))))) + ((int)((((double)(i)) + ((double)(i))))) + ((long)((((int)(1)) % ((int)(i)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 * ((long)((((double)(1.0)) - ((double)(1.0))))) - ((long)((((int)(1.0)) >> ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0 + 42 + ((long)((((double)(2.0)) * ((double)(2.0))))) + ((long)((((int)(work)) ^ ((int)(2.0))))) - ((int)((((int)(work)) & ((int)(work)))));
      oldrho = rho + 42 - ((short)((((int)(rho)) >> ((int)(rho))))) + ((long)((((int)(oldrho)) ^ ((int)(oldrho))))) + ((int)((((double)(rho)) + ((double)(oldrho))))) * ((int)((((int)(oldrho)) | ((int)(oldrho))))) * ((int)((((double)(rho)) * ((double)(oldrho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
