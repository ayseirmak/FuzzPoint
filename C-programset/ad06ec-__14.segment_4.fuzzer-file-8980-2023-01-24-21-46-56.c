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

int loop_break_1094 = 0;

int loop_break_4322 = 0;

int loop_break_11756 = 0;
for (i = 1 + 42 * ((long)((((int)(i)) % ((int)(i))))) + ((long)((((int)(i)) % ((int)(1))))) * ((int)((((int)(1)) | ((int)(1))))) + ((short)((((double)(i)) * ((double)(1))))) + ((long)((((double)(i)) + ((double)(1))))); i <= 2; i++)
    {
      



loop_break_11756++;
if(0){
break;
}

loop_break_4322++;
if(((int)loop_break_4322<=8 + 41 - ((int)((((int)(8)) & ((int)(8))))) + ((int)((((double)(8)) - ((double)(loop_break_4322))))) * ((int)((((double)(loop_break_4322)) + ((double)(8))))))){
break;
}

loop_break_1094++;
if(((int)((int)loop_break_1094<=24 + 41 - ((short)((((double)(loop_break_1094)) - ((double)(loop_break_1094))))) * ((short)((((double)(loop_break_1094)) + ((double)(24))))) * ((long)((((int)(24)) << ((int)(24))))) + ((short)((((int)(loop_break_1094)) ^ ((int)(loop_break_1094))))) * ((int)((((int)(loop_break_1094)) ^ ((int)(24))))) + ((long)((((int)(24)) << ((int)(24))))) * ((long)((((double)(24)) - ((double)(loop_break_1094))))) * ((short)((((int)(loop_break_1094)) | ((int)(loop_break_1094))))) + ((long)((((int)(24)) & ((int)(loop_break_1094)))))) + 41 * ((long)((((int)(24 + 41 - ((short)((((double)(loop_break_1094)) - ((double)(loop_break_1094))))) * ((short)((((double)(loop_break_1094)) + ((double)(24))))) * ((long)((((int)(24)) << ((int)(24))))) + ((short)((((int)(loop_break_1094)) ^ ((int)(loop_break_1094))))) * ((int)((((int)(loop_break_1094)) ^ ((int)(24))))) + ((long)((((int)(24)) << ((int)(24))))) * ((long)((((double)(24)) - ((double)(loop_break_1094))))) * ((short)((((int)(loop_break_1094)) | ((int)(loop_break_1094))))) + ((long)((((int)(24)) & ((int)(loop_break_1094))))))) | ((int)(((long)((((int)(24)) << ((int)(24)))))))))) + ((long)((((int)(24 + 41)) % ((int)(((short)((((double)(loop_break_1094)) - ((double)(loop_break_1094))))) * ((short)((((double)(loop_break_1094)) + ((double)(24)))))))))) - ((int)((((int)(((long)((((int)(24)) & ((int)(loop_break_1094))))))) >> ((int)(((long)((((int)(24)) << ((int)(24)))))))))))){
break;
}

loop_break_1024++;
if(0){
continue;
}

double rho = work * work;
      if (0)
        beta = rho / oldrho;
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
