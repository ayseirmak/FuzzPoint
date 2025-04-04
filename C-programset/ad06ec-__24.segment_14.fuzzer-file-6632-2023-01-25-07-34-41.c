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

int loop_break_1158 = 0;
for (i = 1 + 42 * ((int)((((int)(1)) | ((int)(1))))) - ((long)((((int)(1)) | ((int)(1))))); i <= 2; i++)
    {
      


loop_break_1158++;
if(((int)loop_break_1158<=29 + 41 + ((short)((((double)(loop_break_1158)) * ((double)(loop_break_1158))))) + ((short)((((int)(29)) >> ((int)(29))))) - ((int)((((double)(loop_break_1158)) + ((double)(loop_break_1158))))) + ((long)((((double)(29)) - ((double)(29))))) + ((int)((((double)(29)) - ((double)(29))))) - ((long)((((double)(29)) * ((double)(loop_break_1158))))) - ((long)((((double)(29)) * ((double)(29))))) + ((int)((((double)(loop_break_1158)) * ((double)(29))))) + ((int)((((double)(loop_break_1158)) * ((double)(loop_break_1158))))) + ((long)((((double)(loop_break_1158)) * ((double)(29))))))){
break;
}

loop_break_1084++;
if(((int)loop_break_1084<=32 + 41 * ((int)((((int)(32)) << ((int)(loop_break_1084))))) * ((long)((((int)(loop_break_1084)) << ((int)(loop_break_1084))))) + ((long)((((int)(loop_break_1084)) >> ((int)(32))))) - ((int)((((double)(loop_break_1084)) + ((double)(loop_break_1084))))) * ((int)((((int)(32)) >> ((int)(loop_break_1084))))) * ((long)((((int)(loop_break_1084)) % ((int)(32))))) * ((int)((((int)(32)) >> ((int)(32))))))){
continue;
}

loop_break_1024++;
if(((int)loop_break_1024<=35 + 41 * ((int)((((double)(loop_break_1024)) - ((double)(35))))) - ((short)((((int)(35)) | ((int)(35))))) + ((short)((((int)(loop_break_1024)) & ((int)(loop_break_1024))))) - ((short)((((double)(loop_break_1024)) - ((double)(35))))) + ((long)((((int)(35)) >> ((int)(35))))))){
break;
}

double rho = work * work;
      if (((int)i != 1 + 41 + ((long)((((int)(i)) & ((int)(i))))) + ((int)((((double)(1)) + ((double)(1)))))))
        beta = rho / oldrho;
      if (((int)beta == 1.0 + 41 * ((short)((((int)(1.0)) ^ ((int)(1.0))))) * ((long)((((int)(beta)) & ((int)(1.0)))))))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      work /= 2.0;
      oldrho = rho + 42 + ((short)((((double)(oldrho)) + ((double)(oldrho))))) - ((long)((((double)(oldrho)) + ((double)(rho))))) - ((short)((((double)(oldrho)) * ((double)(oldrho))))) * ((long)((((int)(oldrho)) ^ ((int)(rho))))) + ((long)((((double)(oldrho)) - ((double)(oldrho)))));
    }
  return 0;
}
/* ProgramSourceLLVM */
