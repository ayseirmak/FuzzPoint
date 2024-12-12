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

int loop_break_1832 = 0;

int loop_break_1896 = 8;
for (i = 1 + 42 - ((int)((((int)(1)) ^ ((int)(i))))) - ((long)((((int)(i)) % ((int)(i))))); i <= 2; i++)
    {
      



loop_break_1896++;
if(((int)loop_break_1896<=2 + 41 * ((int)((((int)(loop_break_1896)) >> ((int)(loop_break_1896))))) - ((short)((((double)(2)) * ((double)(loop_break_1896))))) + ((long)((((double)(loop_break_1896)) - ((double)(2))))) - ((int)((((int)(2)) << ((int)(loop_break_1896))))))){
break;
}

loop_break_1832++;
if(((int)loop_break_1832<=11 + 41 * ((long)((((int)(11)) << ((int)(11))))) + ((int)((((double)(11)) - ((double)(11))))) * ((int)((((int)(11)) | ((int)(11))))) + ((long)((((double)(loop_break_1832)) + ((double)(11))))) + ((long)((((double)(loop_break_1832)) * ((double)(loop_break_1832))))) - ((short)((((int)(11)) & ((int)(11))))) + ((long)((((double)(11)) - ((double)(11))))))){
continue;
}

loop_break_1084++;
if(0){
continue;
}

loop_break_1024++;
if(0){
break;
}

double rho = work * work;
      if (0)
        beta = rho / oldrho + 42 + ((short)((((double)(rho / oldrho)) * ((double)(oldrho))))) * ((int)((((int)(rho / oldrho)) % ((int)(beta)))));
      if (((int)((int)beta == 1.0 + 41 * ((short)((((double)(1.0)) + ((double)(beta))))) * ((long)((((double)(beta)) * ((double)(1.0))))) + ((long)((((int)(beta)) | ((int)(beta))))) * ((long)((((int)(beta)) << ((int)(1.0)))))) + 41 + ((long)((((int)((int)beta)) | ((int)(1.0 + 41 * ((short)((((double)(1.0)) + ((double)(beta))))) * ((long)((((double)(beta)) * ((double)(1.0))))) + ((long)((((int)(beta)) | ((int)(beta))))) * ((long)((((int)(beta)) << ((int)(1.0)))))))))) * ((int)((((int)((int)beta)) & ((int)(((long)((((int)(beta)) | ((int)(beta))))) * ((long)((((int)(beta)) << ((int)(1.0)))))))))) * ((short)((((int)(1.0)) << ((int)(((long)((((int)(beta)) | ((int)(beta))))) * ((long)((((int)(beta)) << ((int)(1.0)))))))))) + ((long)((((int)(41 * ((short)((((double)(1.0)) + ((double)(beta))))) * ((long)((((double)(beta)) * ((double)(1.0))))))) >> ((int)(1.0))))) + ((int)((((int)(1.0 + 41 * ((short)((((double)(1.0)) + ((double)(beta))))) * ((long)((((double)(beta)) * ((double)(1.0))))) + ((long)((((int)(beta)) | ((int)(beta))))) * ((long)((((int)(beta)) << ((int)(1.0))))))) >> ((int)(41 * ((short)((((double)(1.0)) + ((double)(beta))))) * ((long)((((double)(beta)) * ((double)(1.0))))))))))))
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
