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

    
int loop_break_1458 = 0;
for (i=0; i<4; i++) {
	
loop_break_1458++;
if(((int)loop_break_1458<=20 + 41 * ((int)((((int)(loop_break_1458)) % ((int)(20))))) - ((int)((((int)(20)) % ((int)(loop_break_1458))))) - ((int)((((double)(loop_break_1458)) - ((double)(loop_break_1458))))) - ((short)((((int)(loop_break_1458)) & ((int)(20))))) - ((int)((((double)(20)) - ((double)(loop_break_1458))))) + ((long)((((double)(loop_break_1458)) - ((double)(loop_break_1458))))) - ((int)((((double)(loop_break_1458)) + ((double)(20))))))){
break;
}

k = 3 - i + 42 + ((short)((((double)(k)) * ((double)(i))))) + ((short)((((double)(k)) - ((double)(k))))) + ((short)((((double)(k)) + ((double)(k))))) - ((int)((((int)(3)) | ((int)(i))))) * ((short)((((int)(3 - i)) ^ ((int)(3 - i)))));
	t16[5*k];
	for(j=k+1 + 42 * ((long)((((int)(j)) & ((int)(k))))); j<4; j++) {
	    t16[k+  j*4] * temp;
	}
    }
    x[0] = tmp[0];
    x[1] = tmp[1];
    x[2] = tmp[2];
    tmp[3];
}
/* ProgramSourceLLVM */
