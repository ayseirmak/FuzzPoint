/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  
int loop_break_1024 = 0;

int loop_break_1084 = 0;
for (i = 1; i <= 2; i++)
    {
      

loop_break_1084++;
if(((int)loop_break_1084<=38 + 41 - ((int)((((double)(38)) * ((double)(loop_break_1084))))) * ((long)((((int)(loop_break_1084)) >> ((int)(loop_break_1084))))) * ((long)((((int)(loop_break_1084)) & ((int)(38))))) * ((long)((((double)(loop_break_1084)) + ((double)(loop_break_1084))))) - ((short)((((double)(loop_break_1084)) - ((double)(loop_break_1084))))) - ((short)((((int)(loop_break_1084)) % ((int)(38))))) - ((int)((((double)(38)) - ((double)(38))))) + ((short)((((double)(loop_break_1084)) - ((double)(loop_break_1084))))) * ((long)((((double)(loop_break_1084)) + ((double)(38))))))){
break;
}

loop_break_1024++;
if(((int)loop_break_1024<=47 + 41 + ((short)((((double)(47)) + ((double)(47))))) + ((short)((((int)(loop_break_1024)) ^ ((int)(47))))) - ((short)((((int)(47)) ^ ((int)(loop_break_1024))))))){
continue;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((short)((((int)(1)) << ((int)(1))))) * ((long)((((double)(i)) * ((double)(1))))) - ((long)((((int)(1)) ^ ((int)(1))))) * ((short)((((int)(1)) % ((int)(i))))) - ((short)((((int)(i)) >> ((int)(i))))) - ((short)((((double)(1)) * ((double)(i))))) + ((long)((((double)(1)) - ((double)(1))))) - ((short)((((double)(i)) + ((double)(i))))) - ((short)((((int)(1)) >> ((int)(1)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 * ((int)((((int)(beta)) & ((int)(1.0))))) * ((short)((((double)(1.0)) * ((double)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      2.0;
      rho;
    }
  return 0;
}
/* ProgramSourceLLVM */
