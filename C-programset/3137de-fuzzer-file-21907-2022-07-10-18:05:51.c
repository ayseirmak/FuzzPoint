/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_999 = 0;

int loop_break_3019 = 0;
for (i = 1; i <= 2; i++)
    {
      

loop_break_3019++;
if(loop_break_3019<=11){
break;
}

loop_break_999++;
if(((int)loop_break_999<=10 + 41 * ((int)(((int)(loop_break_999)) >> ((int)10))) + ((int)(((double)10) + ((double)10))) + ((short)(((double)(loop_break_999)) * ((double)10))) * ((int)(((int)(loop_break_999)) | ((int)10))) - ((int)(((double)(loop_break_999)) - ((double)(loop_break_999)))) - ((long)(((double)10) + ((double)(loop_break_999)))) * ((int)(((double)10) + ((double)10))) - ((int)(((int)(loop_break_999)) << ((int)(loop_break_999)))) * ((long)(((double)(loop_break_999)) * ((double)10))))){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 * ((int)(((double)(i)) - ((double)1))) - ((short)(((int)1) << ((int)1))) * ((long)(((double)(i)) + ((double)1))) - ((short)(((double)(i)) - ((double)(i)))) * ((long)(((double)(i)) - ((double)(i)))) + ((long)(((double)(i)) + ((double)(i)))) + ((long)(((double)(i)) + ((double)(i))))))
        rho / oldrho;
      if (((int)beta == 1.0 + 41 + ((int)(((int)(1.0)) >> ((int)(beta)))) * ((short)(((double)(1.0)) - ((double)(1.0)))) + ((short)(((double)(beta)) + ((double)(beta)))) + ((short)(((double)(beta)) + ((double)(beta))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      
;rho;
2.0;
      rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
