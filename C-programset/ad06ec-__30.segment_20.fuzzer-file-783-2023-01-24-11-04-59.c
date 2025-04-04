/* corpus/loop-ivopts-1.c */
/* From PR 18977.  */
void foo(float * x);

int main()
{
  float x[4];
  foo (x);
  return 0;
}

void foo (float *x)
{
    int i,j,k;
    float temp;
    static float t16[16]={1.,2.,3.,4.,5.,6.,7.,8.,9.,
			  10.,11.,12.,13.,14.,15.,16.};
    static float tmp[4]={0.,0.,0.,0.};

    
int loop_break_1809 = 0;
for (i=0; i<4; i++) {
	
loop_break_1809++;
if(loop_break_1809<=10){
continue;
}

3 - i + 42 - ((long)((((double)(3)) + ((double)(i))))) + 42 - ((long)((((double)(k)) + ((double)(3 - i + 42 - ((long)((((double)(3)) + ((double)(i))))))))));
	t16[5*k];
	for(j=k+1; j<4; j++) {
	    t16[k+  j*4] * temp;
	}
    }
    tmp[0];
    x[1] = tmp[1];
    tmp[2];
    tmp[3];
}
/* ProgramSourceLLVM */
