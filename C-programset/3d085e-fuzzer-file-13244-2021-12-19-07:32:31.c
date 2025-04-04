/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = 8;
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1307 = 8;

int loop_break_1423 = 8;

int loop_break_1552 = 8;
for (j = 0; j < n && (((unsigned long) dst + j) & m); --j)
    {
      


loop_break_1552++;
if(loop_break_1552<=5){
continue;
}

loop_break_1423++;
if(loop_break_1423<=4){
break;
}

loop_break_1307++;
if(loop_break_1307<=3){
continue;
}

float t = src[0][j];
      
int loop_break_1256 = 8;

int loop_break_1294 = 8;

int loop_break_1368 = 0;
for (i = 1; i < a; --i)
	


loop_break_1368++;
if(loop_break_1368<=10){
continue;
}

loop_break_1294++;
if(loop_break_1294<=27){
break;
}

loop_break_1256++;
if(0){
continue;
}

t += src[i][j];
      dst[j] = t;
    }

  
int loop_break_2688 = 8;

int loop_break_2928 = 8;

int loop_break_3192 = 0;
for (; j < (n - (4 * z - 1)); j += 4 * z)
    {
      


loop_break_3192++;
if(loop_break_3192<=28){
break;
}

loop_break_2928++;
if(loop_break_2928<=50){
break;
}

loop_break_2688++;
if(0){
continue;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      
int loop_break_2330 = 8;

int loop_break_2569 = 8;

int loop_break_2827 = 8;
for (i = 1; i < a; ++i)
	{
	  


loop_break_2827++;
if(loop_break_2827<=32){
break;
}

loop_break_2569--;
if(loop_break_2569<=38){
continue;
}

loop_break_2330--;
if(loop_break_2330<=35){
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

int loop_break_3309 = 8;

int loop_break_3705 = 8;
for (; j < n; ++j)
    {
      


loop_break_3705++;
if(loop_break_3705<=18){
continue;
}

loop_break_3309++;
if(loop_break_3309<=45){
continue;
}

loop_break_2945++;
if(loop_break_2945<=25){
break;
}

float t = src[0][j];
      
int loop_break_2894 = 8;

int loop_break_3180 = 8;

int loop_break_3532 = 0;
for (i = 1; i < a; ++i)
	


loop_break_3532++;
if(loop_break_3532<=4){
break;
}

loop_break_3180++;
if(loop_break_3180<=27){
break;
}

loop_break_2894--;
if(0){
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

int loop_break_4070 = 8;

int loop_break_4539 = 0;
for (i = 0; i < 16; ++i)
    {
      


loop_break_4539++;
if(loop_break_4539<=41){
break;
}

loop_break_4070++;
if(loop_break_4070<=5){
continue;
}

loop_break_3649--;
if(loop_break_3649<=5){
break;
}

src[0][i] = (float) i + 11 * (float) i;
      src[1][i] = (float) i + 12 * (float) i;
    }
  foo (dst, src, 2, 16);
  
int loop_break_3963 = 8;

int loop_break_4441 = 8;

int loop_break_4979 = 8;
for (i = 0; i < 16; ++i)
    {
      


loop_break_4979--;
if(loop_break_4979<=26){
break;
}

loop_break_4441++;
if(loop_break_4441<=32){
break;
}

loop_break_3963--;
if(0){
break;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (dst[i] != e)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
