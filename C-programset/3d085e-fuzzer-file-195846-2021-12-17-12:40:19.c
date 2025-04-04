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
for (j = 0; j < n && (((unsigned long) dst + j) & m); ++j)
    {
      

loop_break_1437++;
if(loop_break_1437<=5){
continue;
}

loop_break_1307++;
if(loop_break_1307<=3){
break;
}

float t = src[0][j];
      
int loop_break_1256 = 0;

int loop_break_1294 = 0;
for (i = 1; i < a; ++i)
	

loop_break_1294++;
if(loop_break_1294<=9){
break;
}

loop_break_1256++;
if(loop_break_1256<=50){
break;
}

t += src[i][j];
      dst[j] = t;
    }

  
int loop_break_2688 = 0;

int loop_break_2954 = 0;
for (; j < (n - (4 * z - 1)); j += 4 * z)
    {
      

loop_break_2954++;
if(loop_break_2954<=50){
continue;
}

loop_break_2688++;
if(loop_break_2688<=43){
break;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      
int loop_break_2330 = 0;

int loop_break_2595 = 0;
for (i = 1; i < a; ++i)
	{
	  

loop_break_2595++;
if(loop_break_2595<=8){
break;
}

loop_break_2330++;
if(loop_break_2330<=19){
continue;
}

t0 += *(v4flt *) (src[i] + j + 0 * z);
	  t1 += *(v4flt *) (src[i] + j + 1 * z);
	  t2 += *(v4flt *) (src[i] + j + 2 * z);
	  t3 += *(v4flt *) (src[i] + j + 3 * z);
	}
      *(v4flt *) (dst + j + 0 * z) = t0;
      *(v4flt *) (dst + j + 1 * z) = t1;
      *(v4flt *) (dst + j + 2 * z) = t2;
      *(v4flt *) (dst + j + 3 * z) = t3;
    }
  
int loop_break_2945 = 0;

int loop_break_3356 = 0;
for (; j < n; ++j)
    {
      

loop_break_3356++;
if(loop_break_3356<=4){
continue;
}

loop_break_2945++;
if(loop_break_2945<=18){
break;
}

float t = src[0][j];
      
int loop_break_2894 = 0;

int loop_break_3213 = 0;
for (i = 1; i < a; ++i)
	

loop_break_3213++;
if(loop_break_3213<=15){
break;
}

loop_break_2894++;
if(loop_break_2894<=32){
break;
}

t += src[i][j];
      dst[j] = t;
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
  cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
  dst = (float *)cptr;
  src[0] = dst + 16;
  src[1] = dst + 32;
  
int loop_break_3649 = 0;

int loop_break_4122 = 0;
for (i = 0; i < 16; ++i)
    {
      

loop_break_4122++;
if(loop_break_4122<=26){
continue;
}

loop_break_3649++;
if(loop_break_3649<=6){
break;
}

src[0][i] = (float) i + 11 * (float) i;
      src[1][i] = (float) i + 12 * (float) i;
    }
  foo (dst, src, 2, 16);
  
int loop_break_3963 = 0;

int loop_break_4505 = 0;
for (i = 0; i < 16; ++i)
    {
      

loop_break_4505++;
if(loop_break_4505<=42){
continue;
}

loop_break_3963++;
if(loop_break_3963<=20){
continue;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (dst[i] != e)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
