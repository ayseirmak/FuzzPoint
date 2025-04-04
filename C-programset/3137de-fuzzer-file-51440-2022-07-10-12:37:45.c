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

    
int loop_break_1997 = 0;

int loop_break_2064 = 0;

int loop_break_2135 = 0;
for (i=0; i<4; i++) {
	


loop_break_2135++;
if(loop_break_2135<=9){
break;
}

loop_break_2064++;
if(loop_break_2064<=11){
break;
}

loop_break_1997++;
if(loop_break_1997<=12){
continue;
}

k = 3 - i;
	temp = t16[5*k];
	for(j=k+1 + 42 + ((long)(((double)1) * ((double)(k)))) + ((short)(((double)1) + ((double)(j)))) - ((long)(((double)(k)) * ((double)(j)))) * ((short)(((int)1) >> ((int)(k+1)))) - ((short)(((int)(k)) << ((int)(k)))); j<4; j++) {
	    tmp[k] = t16[k+  j*4] * temp;
	}
    }
    tmp[0];
    tmp[1];
    x[2] = tmp[2];
    tmp[3];
}
/* ProgramSourceLLVM */
