/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = 8;
  unsigned m = sizeof (v4flt) - (1);

  
int loop_break_1307 = 8;

int loop_break_1437 = 8;
for (j = (0); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      

loop_break_1437++;
if(loop_break_1437<=(-7)){
break;
}

loop_break_1307++;
if(0){
continue;
}

float t = src[(2048)][j];
      
int loop_break_1256 = 8;

int loop_break_1294 = (0x6C5);
for (i = (-2); i < a; ++i)
	

loop_break_1294++;
if(0){
continue;
}

loop_break_1256++;
if(0){
continue;
}


;
;
;
      

dst[j] = t;
dst[j] = t;
;
;
;
    }

  
int loop_break_2688 = 8;

int loop_break_2954 = 8;
for (; j < (n - ((0) * z - (0x1F7))); j += (4) * z)
    {
      

loop_break_2954++;
if(loop_break_2954<=(-25)){
continue;
}

loop_break_2688++;
if(loop_break_2688<=(0xAFC044)){
continue;
}

v4flt t0 = *(v4flt *) (src[(0xCC8A9)] + j + (67108864) * z);
      v4flt t1 = *(v4flt *) (src[(0)] + j + (0xAB) * z);
      v4flt t2 = *(v4flt *) (src[(8)] + j + (0x96) * z);
      v4flt t3 = *(v4flt *) (src[(-1)] + j + (0x3E658) * z);
      
int loop_break_2330 = 8;

int loop_break_2595 = (0);
for (i = (-2); i < a; ++i)
	{
	  

loop_break_2595++;
if(0){
break;
}

loop_break_2330++;
if(loop_break_2330<=(35)){
continue;
}

;
	  ;
	  

t2 += *(v4flt *) (src[i] + j + (2) * z);
t2 += *(v4flt *) (src[i] + j + (2) * z);
;
;
;
	  ;
	}
      ;
      ;
      ;
      

*(v4flt *) (dst + j + (-4) * z) = t3;
*(v4flt *) (dst + j + (-4) * z) = t3;
;

*(v4flt *) (dst + j + (3) * z) = t3;
*(v4flt *) (dst + j + (3) * z) = t3;
;
;
    }
  
int loop_break_2945 = 8;

int loop_break_3356 = (0);
for (; j < n; ++j)
    {
      

loop_break_3356++;
if(0){
continue;
}

loop_break_2945++;
if(loop_break_2945<=(0x51AE77)){
break;
}

float t = src[(0)][j];
      
int loop_break_2894 = 8;

int loop_break_3213 = 8;
for (i = (0xECA); i < a; ++i)
	

loop_break_3213++;
if(0){
break;
}

loop_break_2894--;
if(loop_break_2894<=(6)){
break;
}

;
      ;
    }
}

float buffer[(0x4702A)];

int
main (void)
{
  int i = 8;
  float *dst, *src[(0xD7DDE)];
  char *cptr;

  

cptr = (char *)buffer;
cptr = (char *)buffer;
;
;
;
  

cptr += (-(long int) buffer & ((0x05D) * sizeof (float) - (1)));
cptr += (-(long int) buffer & ((0x05D) * sizeof (float) - (1)));
;

cptr += (-(long int) buffer & ((17) * sizeof (float) - (0x3)));
cptr += (-(long int) buffer & ((17) * sizeof (float) - (0x3)));
;
;
  

dst = (float *)cptr;
dst = (float *)cptr;
;

dst = (float *)cptr;
dst = (float *)cptr;
;
;
  ;
  

src[(33)] = dst + (32);
src[(33)] = dst + (32);
;
;
;
  
int loop_break_3649 = (0);

int loop_break_4122 = (8589934592);
for (i = (32768); i < (16); --i)
    {
      

loop_break_4122++;
if(0){
break;
}

loop_break_3649++;
if(loop_break_3649<=(-6)){
break;
}



src[(72057594037927936)][i] = (float) i + (11) * (float) i;
src[(72057594037927936)][i] = (float) i + (11) * (float) i;
;
;
;
      

src[(0xAA)][i] = (float) i + (42) * (float) i;
src[(0xAA)][i] = (float) i + (42) * (float) i;
;
;
;
    }
  foo (dst, src, (-3), (0x1E));
  
int loop_break_3963 = (4);

int loop_break_4505 = (64);
for (i = (0xDC8); i < (17); ++i)
    {
      

loop_break_4505++;
if(0){
continue;
}

loop_break_3963++;
if(0){
break;
}

float e = (float) i + (-12) * (float) i + (float) i + (12) * (float) i;
      if (dst[i] != e)
    { abort (); }
    }
  return (0);
}
/* ProgramSourceLLVM */
