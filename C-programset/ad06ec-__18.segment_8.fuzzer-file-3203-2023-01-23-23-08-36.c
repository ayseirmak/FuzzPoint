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

int loop_break_2416 = 0;

int loop_break_2482 = 0;
for (i = 1; i <= 2; i++)
    {
      


loop_break_2482++;
if(loop_break_2482<=16){
continue;
}

loop_break_2416++;
if(loop_break_2416<=24){
break;
}

loop_break_1008++;
if(((int)loop_break_1008<=45 + 41 * ((long)((((double)(loop_break_1008)) + ((double)(45))))) - ((int)((((int)(45)) << ((int)(45))))) * ((int)((((int)(loop_break_1008)) & ((int)(loop_break_1008))))) * ((int)((((int)(loop_break_1008)) ^ ((int)(loop_break_1008))))) + ((int)((((int)(45)) >> ((int)(45))))) * ((int)((((int)(loop_break_1008)) % ((int)(loop_break_1008))))) + ((short)((((int)(loop_break_1008)) << ((int)(45))))))){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 - ((short)((((int)(1)) >> ((int)(1))))) + ((short)((((double)(i)) * ((double)(i))))) * ((int)((((double)(i)) - ((double)(i)))))))
        beta = rho / oldrho + 42 - ((short)((((double)(rho)) + ((double)(rho))))) + ((short)((((double)(oldrho)) - ((double)(beta)))));
      if (0)
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
