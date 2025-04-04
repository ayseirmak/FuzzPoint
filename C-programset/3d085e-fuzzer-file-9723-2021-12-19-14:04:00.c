/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1307 = 8;

int loop_break_1437 = 0;

int loop_break_1575 = 0;
for (j = 0; j < n && (((unsigned long) dst + j) & m); ++j)
    {
      


loop_break_1575--;
if(0){
break;
}

loop_break_1437--;
if(loop_break_1437<=6){
break;
}

loop_break_1307++;
if(loop_break_1307<=3){
continue;
}

float t = src[0][j];
      
int loop_break_1256 = 8;

int loop_break_1294 = 0;

int loop_break_1388 = 8;
for (i = 1; i < a; ++i)
	


loop_break_1388++;
if(0){
break;
}

loop_break_1294++;
if(loop_break_1294<=19){
continue;
}

loop_break_1256++;
if(loop_break_1256<=7){
continue;
}

;
      ;
    }

  
int loop_break_2688 = 8;

int loop_break_2954 = 8;

int loop_break_3230 = 8;
for (; j < (n - (4 * z - 1)); j += 4 * z)
    {
      


loop_break_3230++;
if(0){
break;
}

loop_break_2954++;
if(loop_break_2954<=24){
continue;
}

loop_break_2688++;
if(0){
continue;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      
int loop_break_2330 = 0;

int loop_break_2595 = 0;

int loop_break_2868 = 8;
for (i = 1; i < a; ++i)
	{
	  


loop_break_2868++;
if(loop_break_2868<=32){
break;
}

loop_break_2595--;
if(loop_break_2595<=20){
break;
}

loop_break_2330++;
if(0){
continue;
}

;
	  ;
	  ;
	  ;
	}
      ;
      
*(v4flt *) (dst + j + 1 * z) = t1;
*(v4flt *) (dst + j + 1 * z) = t1;
;
      
*(v4flt *) (dst + j + 2 * z) = t2;
*(v4flt *) (dst + j + 2 * z) = t2;
;
      ;
    }
  
int loop_break_2945 = 8;

int loop_break_3356 = 8;

int loop_break_3758 = 0;
for (; j < n; ++j)
    {
      


loop_break_3758++;
if(loop_break_3758<=46){
continue;
}

loop_break_3356++;
if(0){
continue;
}

loop_break_2945++;
if(0){
break;
}

float t = src[0][j];
      
int loop_break_2894 = 8;

int loop_break_3213 = 8;

int loop_break_3570 = 0;
for (i = 1; i < a; ++i)
	


loop_break_3570++;
if(loop_break_3570<=26){
continue;
}

loop_break_3213++;
if(0){
break;
}

loop_break_2894++;
if(0){
break;
}

;
      
dst[j] = t;
dst[j] = t;
;
    }
}

float buffer[64];

int
main (void)
{
  int i = 8;
  float *dst, *src[2];
  char *cptr;

  
cptr = (char *)buffer;
cptr = (char *)buffer;
;
  
cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
;
  
dst = (float *)cptr;
dst = (float *)cptr;
;
  
src[0] = dst + 16;
src[0] = dst + 16;
;
  ;
  
int loop_break_3649 = 8;

int loop_break_4122 = 0;

int loop_break_4594 = 8;
for (i = 0; i < 16; ++i)
    {
      


loop_break_4594++;
if(0){
continue;
}

loop_break_4122++;
if(loop_break_4122<=32){
break;
}

loop_break_3649++;
if(loop_break_3649<=5){
break;
}

;
      ;
    }
  foo (dst, src, 2, 16);
  
int loop_break_3963 = 8;

int loop_break_4505 = 0;

int loop_break_5043 = 0;
for (i = 0; i < 16; --i)
    {
      


loop_break_5043++;
if(loop_break_5043<=17){
break;
}

loop_break_4505++;
if(loop_break_4505<=47){
continue;
}

loop_break_3963++;
if(loop_break_3963<=46){
break;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (0)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
