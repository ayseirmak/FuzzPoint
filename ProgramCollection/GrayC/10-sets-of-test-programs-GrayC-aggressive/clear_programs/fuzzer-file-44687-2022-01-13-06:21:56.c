/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1217 = 8;
for (j = 0; j < n && (((unsigned long) dst + j) & m); ++j)
    {
      
loop_break_1217++;
if(loop_break_1217<=7){
break;
}

float t = src[0][j];
      
int loop_break_1201 = 0;
for (i = 1; i < a; --i)
	;
      ;
    }

  
int loop_break_2660 = 0;
for (; j < (n - (4 * z - 1)); j += 4 * z)
    {
      
loop_break_2660++;
if(loop_break_2660<=6){
continue;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      
int loop_break_2462 = 0;
for (i = 1; i < a; ++i)
	{
	  

loop_break_2462++;
if(loop_break_2462<=21){
continue;
}


t0 += *(v4flt *) (src[i] + j + 0 * z);
t0 += *(v4flt *) (src[i] + j + 0 * z);
;
;
;
	  ;
	  

t2 += *(v4flt *) (src[i] + j + 2 * z);
t2 += *(v4flt *) (src[i] + j + 2 * z);
;

t2 += *(v4flt *) (src[i] + j + 2 * z);
t2 += *(v4flt *) (src[i] + j + 2 * z);
;
;
	  
;

t3 += *(v4flt *) (src[i] + j + 3 * z);
t3 += *(v4flt *) (src[i] + j + 3 * z);
;
;
	}
      ;
      ;
      ;
      
;

*(v4flt *) (dst + j + 3 * z) = t3;
*(v4flt *) (dst + j + 3 * z) = t3;
;
;
    }
  
int loop_break_2943 = 0;
for (; j < n; ++j)
    {
      
loop_break_2943++;
if(loop_break_2943<=17){
continue;
}

float t = src[0][j];
      
int loop_break_2866 = 0;
for (i = 1; i < a; ++i)
	

loop_break_2866++;
if(loop_break_2866<=40){
continue;
}


t += src[i][j];
t += src[i][j];
;
;
;
      ;
    }
}

float buffer[64];

int
main (void)
{
  int i;
  float *dst, *src[2];
  char *cptr;

  

cptr = (char *)buffer;
cptr = (char *)buffer;
;

cptr = (char *)buffer;
cptr = (char *)buffer;
;
;
  

cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
;

cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
;
;
  
;

dst = (float *)cptr;
dst = (float *)cptr;
;
;
  ;
  ;
  
int loop_break_3925 = 0;
for (i = 0; i < 16; ++i)
    {
      

loop_break_3925++;
if(loop_break_3925<=15){
break;
}

;
;
;
      

src[1][i] = (float) i + 12 * (float) i;
src[1][i] = (float) i + 12 * (float) i;
;
;
;
    }
  foo (dst, src, 2, 16);
  
int loop_break_4205 = 8;
for (i = 0; i < 16; ++i)
    {
      
loop_break_4205++;
if(loop_break_4205<=42){
continue;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (0)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
