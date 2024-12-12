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

int loop_break_1079 = 0;
for (i = 1 + 42 * ((short)((((int)(1)) >> ((int)(1))))); i <= 2; i++)
    {
      

loop_break_1079++;
if(((int)((int)loop_break_1079<=12 + 41 - ((short)((((double)(loop_break_1079)) - ((double)(12)))))) + 41 + ((short)((((double)((int)loop_break_1079)) * ((double)(12 + 41))))) + ((short)((((double)(((short)((((double)(loop_break_1079)) - ((double)(12))))))) - ((double)(12 + 41))))) - ((int)((((double)(12 + 41 - ((short)((((double)(loop_break_1079)) - ((double)(12))))))) - ((double)(12 + 41 - ((short)((((double)(loop_break_1079)) - ((double)(12)))))))))) * ((int)((((double)((int)loop_break_1079)) + ((double)((int)loop_break_1079))))) - ((int)((((int)((int)loop_break_1079)) & ((int)(12))))) - ((int)((((double)(12)) + ((double)((int)loop_break_1079))))))){
continue;
}

loop_break_1008++;
if(((int)((int)loop_break_1008<=45 + 41 + ((short)((((int)(loop_break_1008)) ^ ((int)(loop_break_1008))))) + ((int)((((int)(45)) ^ ((int)(loop_break_1008))))) - ((int)((((int)(45)) << ((int)(45))))) - ((short)((((double)(45)) + ((double)(45))))) + ((long)((((int)(loop_break_1008)) & ((int)(loop_break_1008)))))) + 41 - ((short)((((double)(((long)((((int)(loop_break_1008)) & ((int)(loop_break_1008))))))) - ((double)((int)loop_break_1008))))) * ((long)((((int)(45 + 41 + ((short)((((int)(loop_break_1008)) ^ ((int)(loop_break_1008))))) + ((int)((((int)(45)) ^ ((int)(loop_break_1008))))) - ((int)((((int)(45)) << ((int)(45))))) - ((short)((((double)(45)) + ((double)(45))))))) >> ((int)(45 + 41 + ((short)((((int)(loop_break_1008)) ^ ((int)(loop_break_1008))))) + ((int)((((int)(45)) ^ ((int)(loop_break_1008))))) - ((int)((((int)(45)) << ((int)(45))))) - ((short)((((double)(45)) + ((double)(45))))) + ((long)((((int)(loop_break_1008)) & ((int)(loop_break_1008)))))))))) - ((short)((((double)(45 + 41 + ((short)((((int)(loop_break_1008)) ^ ((int)(loop_break_1008))))) + ((int)((((int)(45)) ^ ((int)(loop_break_1008))))) - ((int)((((int)(45)) << ((int)(45))))) - ((short)((((double)(45)) + ((double)(45))))))) + ((double)(45 + 41 + ((short)((((int)(loop_break_1008)) ^ ((int)(loop_break_1008))))) + ((int)((((int)(45)) ^ ((int)(loop_break_1008))))) - ((int)((((int)(45)) << ((int)(45))))) - ((short)((((double)(45)) + ((double)(45))))) + ((long)((((int)(loop_break_1008)) & ((int)(loop_break_1008)))))))))))){
continue;
}

double rho = work * work;
      if (((int)((int)i != 1 + 41 * ((long)((((int)(i)) | ((int)(1))))) * ((int)((((double)(i)) - ((double)(1))))) + ((int)((((int)(i)) & ((int)(1)))))) + 41 - ((short)((((int)(41)) ^ ((int)(41 * ((long)((((int)(i)) | ((int)(1)))))))))) - ((short)((((int)(((int)((((double)(i)) - ((double)(1))))))) | ((int)(1 + 41 * ((long)((((int)(i)) | ((int)(1))))) * ((int)((((double)(i)) - ((double)(1)))))))))) + ((short)((((int)(1 + 41 * ((long)((((int)(i)) | ((int)(1))))) * ((int)((((double)(i)) - ((double)(1))))) + ((int)((((int)(i)) & ((int)(1))))))) ^ ((int)(((int)((((double)(i)) - ((double)(1)))))))))) + ((short)((((int)(1 + 41 * ((long)((((int)(i)) | ((int)(1))))) * ((int)((((double)(i)) - ((double)(1))))))) ^ ((int)(((int)((((double)(i)) - ((double)(1)))))))))) - ((int)((((int)(41 * ((long)((((int)(i)) | ((int)(1))))) * ((int)((((double)(i)) - ((double)(1))))))) % ((int)(41))))) - ((int)((((double)(((int)((((double)(i)) - ((double)(1))))))) - ((double)((int)i))))) * ((long)((((int)(41 * ((long)((((int)(i)) | ((int)(1))))) * ((int)((((double)(i)) - ((double)(1))))))) << ((int)((int)i)))))))
        beta = rho / oldrho + 42 * ((int)((((double)(rho)) - ((double)(rho / oldrho)))));
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
