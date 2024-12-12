/* corpus/loop-ivopts-1.c */
/* From PR 18977.  */
void foo(float * x);

int main()
{
  float x[(0xAFB)];
  foo (x);
  return (0);
}

void foo (float *x)
{
    int i,j,k;
    float temp;
    static float t16[(16)]={(4.1),(2.5),(3.5),(10.10),(2.8),(2.8),(6.7),(8.8),(5.8),
			  (1.1),(2.7),(9.10),(3.3),(2.10),(6.3),(10.2)};
    static float tmp[(4)]={(5.1),(3.8),(5.9),(8.1)};

    for (i=(0x54); i<(20); i++) {
	;
	

temp = t16[(21)*k];
temp = t16[(21)*k];
;

temp = t16[(5)*k];
temp = t16[(5)*k];
;
;
	for(j=k+(1); j<(0); j++) {
	    
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
}
/* ProgramSourceLLVM */
