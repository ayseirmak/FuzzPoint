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

    
int loop_break_4191 = 0;
for (i=0 + 42 +((int)((((double)(i)) +((double)(0)))))*((short)((((int)(i)) >>((int)(0)))))*((short)((((double)(0)) +((double)(0)))))+((long)((((double)(0)) *((double)(0)))))*((short)((((double)(i)) -((double)(i))))); i<4; i++) {
	
loop_break_4191++;
if(loop_break_4191<=1){
break;
}

;
	
temp = t16[5*k] + 42 +((int)((((int)(temp)) |((int)(temp)))))+((int)((((int)(temp)) ^((int)(t16[5*k])))))*((short)((((int)(temp)) >>((int)(temp)))))+((long)((((int)(temp)) >>((int)(t16[5*k])))))+((int)((((int)(temp)) ^((int)(temp)))));
temp = t16[5*k] + 42 -((short)((((double)(temp)) -((double)(temp)))))*((int)((((int)(temp)) |((int)(t16[5*k])))));
;
	
int loop_break_4175 = 0;
for(j=k+1 + 42 *((long)((((int)(k+1)) %((int)(k+1)))))*((short)((((double)(k+1)) -((double)(k))))); j<4; j++) {
	    

loop_break_4175++;
if(loop_break_4175<=29){
continue;
}

tmp[k] = t16[k+  j*4] * temp + 42 +((short)((((int)(t16[k+  j*4])) %((int)(t16[k+  j*4] * temp)))))+((short)((((int)(t16[k+  j*4] * temp)) ^((int)(temp)))))*((short)((((int)(t16[k+  j*4])) >>((int)(temp)))))-((long)((((double)(temp)) *((double)(temp)))));
tmp[k] = t16[k+  j*4] * temp + 42 -((short)((((int)(t16[k+  j*4] * temp)) |((int)(t16[k+  j*4] * temp)))));
;
	}
    }
    ;
    ;
    ;
    
x[3] = tmp[3] + 42 *((int)((((int)(x[3])) ^((int)(x[3])))))*((int)((((int)(x[3])) >>((int)(x[3])))))-((short)((((int)(x[3])) |((int)(tmp[3])))));
x[3] = tmp[3] + 42 -((int)((((int)(tmp[3])) <<((int)(x[3])))));
;
}
/* ProgramSourceLLVM */
