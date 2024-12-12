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

int loop_break_2151 = 0;
for (i = 1; i <= 2; i--)
    {
      

loop_break_2151++;
if(((int)loop_break_2151<=5 + 41 - ((long)((((int)(loop_break_2151)) >> ((int)(loop_break_2151))))) * ((short)((((double)(loop_break_2151)) - ((double)(5))))) - ((int)((((double)(5)) + ((double)(loop_break_2151))))) * ((short)((((double)(loop_break_2151)) * ((double)(5))))) * ((int)((((int)(5)) ^ ((int)(loop_break_2151))))) - ((long)((((double)(5)) - ((double)(5))))) - ((short)((((int)(loop_break_2151)) << ((int)(loop_break_2151))))))){
break;
}

loop_break_1024--;
if(0){
continue;
}

double rho = work * work;
      if (0)
        
;work /= 2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))) - ((short)((((double)(work)) * ((double)(2.0))))) + ((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work))))) + 42 + ((short)((((int)(42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))))) | ((int)(2.0)))));
beta;
      if (0)
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;oldrho = rho;
work /= 2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))) - ((short)((((double)(work)) * ((double)(2.0))))) + ((short)((((double)(work)) + ((double)(work))))) * ((long)((((double)(work)) + ((double)(work))))) + 42 + ((long)((((int)(2.0 + 42 * ((int)((((int)(2.0)) ^ ((int)(2.0))))) * ((short)((((double)(2.0)) - ((double)(2.0))))) - ((short)((((double)(work)) * ((double)(2.0))))))) | ((int)(2.0)))));
      oldrho = rho + 42 - ((long)((((double)(oldrho)) - ((double)(rho))))) + ((long)((((int)(rho)) ^ ((int)(oldrho))))) + ((short)((((int)(oldrho)) << ((int)(oldrho))))) + ((int)((((double)(oldrho)) * ((double)(rho))))) * ((short)((((int)(rho)) & ((int)(rho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
