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

    
int loop_break_1393 = 8;
for (i=0; i<4; i++) {
	

loop_break_1393++;
if(0){
break;
}

k = 3 - i;
k = 3 - i;
;
	;
	
int loop_break_1377 = 8;
for(j=k+1; j<4; j++) {
	    
loop_break_1377--;
if(0){
continue;
}

;
	}
    }
    ;
    ;
    
x[2] = tmp[2];
x[2] = tmp[2];
;
    
x[3] = tmp[3];
x[3] = tmp[3];
;
}
/* ProgramSourceLLVM */
