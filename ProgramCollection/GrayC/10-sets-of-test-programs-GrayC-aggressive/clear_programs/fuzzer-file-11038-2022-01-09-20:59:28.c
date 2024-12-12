/* corpus/loop-ivopts-1.c */
/* From PR 18977.  */
void foo(float * x);

int main()
{
  float x[((0x4))];
  foo (x);
  return ((0));
}

void foo (float *x)
{
    int i,j,k;
    float temp;
    static float t16[((26))]={((10.9)),((4.7)),((9.9)),((5.4)),((8.5)),((3.10)),((9.10)),((3.3)),((5.4)),
			  ((1.1)),((6.1)),((1.9)),((8.1)),((10.1)),((1.4)),((1.2))};
    static float tmp[((0xC))]={((7.2)),((2.3)),((3.9)),((5.6))};

    
int loop_break_1496 = (-9);

int loop_break_1634 = (-9);

int loop_break_1952 = (131072);

int loop_break_2203 = (0xB0);
for (i=(0x921); i<(-(-6)); i++) {
	



loop_break_2203++;
if(loop_break_2203<=(-5)){
continue;
}

loop_break_1952++;
if(loop_break_1952<=(3)){
continue;
}

loop_break_1634++;
if((-(33))){
continue;
}

loop_break_1496++;
if(((0xB7D))){
continue;
}

;
	
;

;

temp = t16[((37))*k];
temp = t16[((37))*k];
;
;
;
	
int loop_break_1482 = (-9);

int loop_break_1617 = (0x0BF);

int loop_break_1932 = (-1);

int loop_break_2178 = (0);
for(j=k+(-(2)); j<((0x83C4)); j++) {
	    



loop_break_2178++;
if(loop_break_2178<=(12)){
break;
}

loop_break_1932++;
if(loop_break_1932<=(49)){
continue;
}

loop_break_1617++;
if(((72127962782105600))){
break;
}

loop_break_1482++;
if(((134217728))){
break;
}


;
;
;
	}
    }
    

;
;
;
;
;
    ;
    
;
;
;
    

;
;
;

;
;
;
;
}
/* ProgramSourceLLVM */
