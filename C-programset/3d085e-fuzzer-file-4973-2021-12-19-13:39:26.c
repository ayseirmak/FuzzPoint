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

    
int loop_break_1333 = 0;

int loop_break_1468 = 0;
for (i=0; i<4; i++) {
	

loop_break_1468++;
if(loop_break_1468<=5){
continue;
}

loop_break_1333++;
if(loop_break_1333<=3){
break;
}

;
	;
	
int loop_break_1319 = 0;

int loop_break_1451 = 0;
for(j=k+1; j<4; j++) {
	    

loop_break_1451++;
if(loop_break_1451<=4){
break;
}

loop_break_1319++;
if(loop_break_1319<=12){
continue;
}

;
	}
    }
    
x[0] = tmp[0];
x[0] = tmp[0];
;
    ;
    ;
    
x[3] = tmp[3];
x[3] = tmp[3];
;
}
/* ProgramSourceLLVM */
