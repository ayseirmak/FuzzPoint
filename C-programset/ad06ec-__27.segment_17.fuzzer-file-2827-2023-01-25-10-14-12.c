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

int loop_break_1084 = 8;
for (i = 1; i <= 2; i++)
    {
      

loop_break_1084++;
if(((int)loop_break_1084<=32 + 41 - ((int)((((double)(32)) - ((double)(loop_break_1084))))) + ((short)((((double)(loop_break_1084)) * ((double)(32))))) * ((long)((((int)(loop_break_1084)) % ((int)(32))))) - ((long)((((int)(32)) << ((int)(loop_break_1084))))) * ((long)((((double)(32)) * ((double)(32))))) - ((long)((((double)(loop_break_1084)) - ((double)(loop_break_1084))))) + ((int)((((int)(32)) % ((int)(32))))) * ((int)((((double)(loop_break_1084)) * ((double)(loop_break_1084))))) * ((short)((((double)(loop_break_1084)) + ((double)(32))))) * ((int)((((int)(32)) >> ((int)(loop_break_1084))))))){
continue;
}

loop_break_1024++;
if(((int)loop_break_1024<=35 + 41 - ((int)((((double)(35)) - ((double)(35))))) * ((short)((((int)(loop_break_1024)) << ((int)(loop_break_1024))))) * ((long)((((int)(35)) ^ ((int)(loop_break_1024))))) + ((short)((((int)(loop_break_1024)) >> ((int)(loop_break_1024))))) * ((short)((((int)(35)) & ((int)(35))))) + ((int)((((int)(loop_break_1024)) >> ((int)(loop_break_1024))))) + ((short)((((int)(35)) & ((int)(35))))) - ((short)((((double)(35)) - ((double)(35))))))){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 * ((int)((((int)(1)) & ((int)(i))))) + ((long)((((int)(1)) << ((int)(i)))))))
        beta = rho / oldrho + 42 + ((short)((((double)(rho / oldrho)) * ((double)(oldrho))))) * ((int)((((int)(rho / oldrho)) % ((int)(beta)))));
      if (((int)beta == 1.0 + 41 * ((short)((((double)(1.0)) + ((double)(beta))))) * ((long)((((double)(beta)) * ((double)(1.0))))) + ((long)((((int)(beta)) | ((int)(beta))))) * ((long)((((int)(beta)) << ((int)(1.0)))))))
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
