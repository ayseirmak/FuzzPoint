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

    for (i=0; i<4; i++) {
	k = 3 - i;
	t16[5*k];
	for(j=k+1; j<4; j++) {
	    t16[k+  j*4] * temp;
	}
    }
    x[0] = tmp[0];
    tmp[1];
    tmp[2];
    x[3];
}
/* ProgramSourceLLVM */
