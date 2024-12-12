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
for (i = 1 + 42 * ((long)((((int)(1)) ^ ((int)(i))))); i <= 2; i--)
    {
      
loop_break_1024--;
if(0){
continue;
}

double rho = work * work;
      if (0)
        
;work /= 2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))) - ((short)((((double)(work)) * ((double)(2.0))))) + ((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work))))) + 42 * ((int)((((int)(2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))) - ((short)((((double)(work)) * ((double)(2.0))))) + ((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work))))))) ^ ((int)(2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))) - ((short)((((double)(work)) * ((double)(2.0))))) + ((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work))))))))));
beta;
      if (0)
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;oldrho = rho;
work /= 2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))) - ((short)((((double)(work)) * ((double)(2.0))))) + ((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work))))) + 42 + ((long)((((int)(((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work))))))) % ((int)(((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work)))))))))) - ((int)((((int)(2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))))) >> ((int)(42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))))))));
      oldrho = rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
