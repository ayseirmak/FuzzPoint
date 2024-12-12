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

    
int loop_break_4495 = 0;
for (i=0; i<4; i++) {
	
loop_break_4495++;
if(loop_break_4495<=30){
continue;
}

k = 3 - i + 42 + ((int)((((double)(3)) - ((double)(3))))) - ((int)((((double)(k)) + ((double)(3 - i))))) - ((short)((((double)(i)) - ((double)(3 - i))))) - ((short)((((int)(i)) >> ((int)(k))))) - ((int)((((double)(3 - i)) + ((double)(3 - i))))) + 42 + ((int)((((double)(3 - i + 42 + ((int)((((double)(3)) - ((double)(3))))) - ((int)((((double)(k)) + ((double)(3 - i))))))) - ((double)(3 - i + 42 + ((int)((((double)(3)) - ((double)(3))))) - ((int)((((double)(k)) + ((double)(3 - i)))))))))) - ((int)((((double)(3 - i + 42 + ((int)((((double)(3)) - ((double)(3))))) - ((int)((((double)(k)) + ((double)(3 - i))))) - ((short)((((double)(i)) - ((double)(3 - i))))))) + ((double)(((int)((((double)(k)) + ((double)(3 - i)))))))))) - ((short)((((double)(((int)((((double)(3 - i)) + ((double)(3 - i))))))) - ((double)(42))))) - ((short)((((int)(((int)((((double)(3)) - ((double)(3))))))) >> ((int)(3 - i + 42 + ((int)((((double)(3)) - ((double)(3))))) - ((int)((((double)(k)) + ((double)(3 - i))))) - ((short)((((double)(i)) - ((double)(3 - i)))))))))) - ((int)((((double)(((int)((((double)(k)) + ((double)(3 - i))))))) + ((double)(((short)((((int)(i)) >> ((int)(k))))))))));
	temp = t16[5*k];
	for(j=k+1 + 42 * ((int)((((int)(j)) >> ((int)(k))))) + 42 * ((int)((((int)(j)) >> ((int)(42))))); j<4; j++) {
	    tmp[k] = t16[k+  j*4] * temp;
	}
    }
    x[0] = tmp[0];
    x[1] = tmp[1];
    x[2] = tmp[2];
    x[3] = tmp[3];
}
/* ProgramSourceLLVM */
