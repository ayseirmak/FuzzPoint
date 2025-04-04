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

    
int loop_break_1448 = 0;

int loop_break_1515 = 0;

int loop_break_1585 = 0;

int loop_break_1653 = 0;
for (i=0; i<4; i++) {
	



loop_break_1653++;
if(((int)loop_break_1653<=11 + 41 - ((short)(((double)(loop_break_1653)) - ((double)11))) + ((long)(((double)11) - ((double)(loop_break_1653)))) + ((int)(((double)11) * ((double)(loop_break_1653)))) * ((short)(((int)(loop_break_1653)) >> ((int)(loop_break_1653)))) * ((short)(((int)11) ^ ((int)(loop_break_1653)))) * ((long)(((int)11) & ((int)(loop_break_1653)))))){
break;
}

loop_break_1585++;
if(((int)loop_break_1585<=8 + 41 * ((long)(((int)8) % ((int)8))) * ((long)(((int)8) ^ ((int)8))))){
continue;
}

loop_break_1515++;
if(((int)loop_break_1515<=12 + 41 - ((short)(((double)(loop_break_1515)) + ((double)(loop_break_1515)))))){
break;
}

loop_break_1448++;
if(((int)loop_break_1448<=11 + 41 + ((long)(((int)(loop_break_1448)) % ((int)11))) - ((int)(((double)(loop_break_1448)) * ((double)(loop_break_1448)))) - ((long)(((double)(loop_break_1448)) + ((double)(loop_break_1448)))) + ((short)(((double)(loop_break_1448)) + ((double)(loop_break_1448)))) - ((short)(((double)11) + ((double)(loop_break_1448)))) * ((int)(((int)(loop_break_1448)) ^ ((int)(loop_break_1448)))))){
continue;
}

3 - i;
	t16[5*k];
	for(j=k+1 + 42 - ((long)(((int)1) | ((int)(j)))); j<4; j++) {
	    t16[k+  j*4] * temp;
	}
    }
    tmp[0];
    tmp[1];
    tmp[2];
    x[3];
}
/* ProgramSourceLLVM */
