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

int loop_break_1896 = 0;
for (i = 1; i <= 2; i++)
    {
      



loop_break_1896++;
if(loop_break_1896<=2){
break;
}

loop_break_1832++;
if(loop_break_1832<=11){
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
