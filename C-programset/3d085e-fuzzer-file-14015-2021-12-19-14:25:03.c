/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1307 = 0;

int loop_break_1437 = 0;

int loop_break_1681 = 0;
for (j = 0; j < n && (((unsigned long) dst + j) & m); ++j)
    {
      


loop_break_1681++;
if(loop_break_1681<=3){
break;
}

loop_break_1437++;
if(loop_break_1437<=6){
break;
}

loop_break_1307++;
if(loop_break_1307<=3){
continue;
}

float t = src[0][j];
      
int loop_break_1256 = 0;

int loop_break_1294 = 0;

int loop_break_1388 = 0;
for (i = 1; i < a; ++i)
	


loop_break_1388++;
if(loop_break_1388<=8){
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


t += src[i][j];
t += src[i][j];
;
      
dst[j] = t;
dst[j] = t;
;
    }

  
int loop_break_2688 = 0;

int loop_break_2954 = 0;

int loop_break_2984 = 0;
for (; j < (n - (4 * z - 1)); j += 4 * z)
    {
      


loop_break_2984++;
if(loop_break_2984<=10){
continue;
}

loop_break_2954++;
if(loop_break_2954<=24){
continue;
}

loop_break_2688++;
if(loop_break_2688<=19){
continue;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      
int loop_break_2330 = 0;

int loop_break_2595 = 0;

int loop_break_2780 = 0;
for (i = 1; i < a; ++i)
	{
	  


loop_break_2780++;
if(loop_break_2780<=41){
break;
}

loop_break_2595++;
if(loop_break_2595<=20){
break;
}

loop_break_2330++;
if(loop_break_2330<=35){
continue;
}

;
	  ;
	  
t2 += *(v4flt *) (src[i] + j + 2 * z);
t2 += *(v4flt *) (src[i] + j + 2 * z);
;
	  ;
	}
      ;
      ;
      ;
      
*(v4flt *) (dst + j + 3 * z) = t3;
*(v4flt *) (dst + j + 3 * z) = t3;
;
    }
  
int loop_break_2945 = 0;

int loop_break_3356 = 0;

int loop_break_3421 = 0;
for (; j < n; ++j)
    {
      


loop_break_3421++;
if(loop_break_3421<=48){
break;
}

loop_break_3356++;
if(loop_break_3356<=16){
continue;
}

loop_break_2945++;
if(loop_break_2945<=25){
break;
}

float t = src[0][j];
      
int loop_break_2894 = 0;

int loop_break_3213 = 0;

int loop_break_3324 = 0;
for (i = 1; i < a; ++i)
	


loop_break_3324++;
if(loop_break_3324<=33){
break;
}

loop_break_3213++;
if(loop_break_3213<=39){
break;
}

loop_break_2894++;
if(loop_break_2894<=6){
break;
}

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
  
cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
;
  
dst = (float *)cptr;
dst = (float *)cptr;
;
  ;
  
src[1] = dst + 32;
src[1] = dst + 32;
;
  
int loop_break_3649 = 0;

int loop_break_4122 = 0;

int loop_break_4621 = 0;
for (i = 0; i < 16; ++i)
    {
      


loop_break_4621++;
if(loop_break_4621<=33){
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


src[0][i] = (float) i + 11 * (float) i;
src[0][i] = (float) i + 11 * (float) i;
;
      
src[1][i] = (float) i + 12 * (float) i;
src[1][i] = (float) i + 12 * (float) i;
;
    }
  foo (dst, src, 2, 16);
  
int loop_break_3963 = 0;

int loop_break_4505 = 0;

int loop_break_5069 = 0;
for (i = 0; i < 16; ++i)
    {
      


loop_break_5069++;
if(loop_break_5069<=23){
continue;
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
      if (dst[i] != e)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
