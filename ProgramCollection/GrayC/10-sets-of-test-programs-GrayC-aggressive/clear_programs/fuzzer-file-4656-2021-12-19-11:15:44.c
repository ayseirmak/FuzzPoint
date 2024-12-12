/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1307 = 8;

int loop_break_1437 = 8;

int loop_break_1575 = 0;

int loop_break_1710 = 8;

int loop_break_1842 = 8;
for (j = 0; j < n && (((unsigned long) dst + j) & m); --j)
    {
      




loop_break_1842++;
if(loop_break_1842<=6){
continue;
}

loop_break_1710++;
if(loop_break_1710<=4){
continue;
}

loop_break_1575++;
if(loop_break_1575<=5){
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

int loop_break_1294 = 8;

int loop_break_1388 = 8;

int loop_break_1476 = 0;

int loop_break_1567 = 8;
for (i = 1; i < a; ++i)
	




loop_break_1567--;
if(loop_break_1567<=48){
break;
}

loop_break_1476++;
if(loop_break_1476<=28){
continue;
}

loop_break_1388++;
if(loop_break_1388<=30){
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
      dst[j] = t;
    }

  
int loop_break_2688 = 0;

int loop_break_2954 = 8;

int loop_break_3230 = 0;

int loop_break_3498 = 0;

int loop_break_3776 = 8;
for (; j < (n - (4 * z - 1)); j += 4 * z)
    {
      




loop_break_3776++;
if(loop_break_3776<=12){
break;
}

loop_break_3498++;
if(loop_break_3498<=10){
continue;
}

loop_break_3230++;
if(loop_break_3230<=9){
break;
}

loop_break_2954--;
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
      
int loop_break_2330 = 8;

int loop_break_2595 = 8;

int loop_break_2868 = 0;

int loop_break_3133 = 0;

int loop_break_3406 = 0;
for (i = 1; i < a; ++i)
	{
	  




loop_break_3406++;
if(loop_break_3406<=26){
break;
}

loop_break_3133++;
if(loop_break_3133<=36){
break;
}

loop_break_2868++;
if(loop_break_2868<=32){
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
  
int loop_break_2945 = 8;

int loop_break_3356 = 8;

int loop_break_3758 = 8;

int loop_break_4161 = 8;

int loop_break_4576 = 0;
for (; j < n; ++j)
    {
      




loop_break_4576++;
if(loop_break_4576<=32){
continue;
}

loop_break_4161++;
if(loop_break_4161<=14){
continue;
}

loop_break_3758++;
if(loop_break_3758<=46){
continue;
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

int loop_break_3213 = 8;

int loop_break_3570 = 0;

int loop_break_3929 = 8;

int loop_break_4301 = 0;
for (i = 1; i < a; ++i)
	




loop_break_4301++;
if(loop_break_4301<=25){
continue;
}

loop_break_3929++;
if(loop_break_3929<=50){
continue;
}

loop_break_3570++;
if(loop_break_3570<=26){
continue;
}

loop_break_3213++;
if(loop_break_3213<=39){
break;
}

loop_break_2894++;
if(loop_break_2894<=6){
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
  int i = 8;
  float *dst, *src[2];
  char *cptr;

  cptr = (char *)buffer;
  cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
  dst = (float *)cptr;
  src[0] = dst + 16;
  src[1] = dst + 32;
  
int loop_break_3649 = 8;

int loop_break_4122 = 0;

int loop_break_4594 = 8;

int loop_break_5065 = 0;

int loop_break_5552 = 0;
for (i = 0; i < 16; ++i)
    {
      




loop_break_5552++;
if(loop_break_5552<=45){
continue;
}

loop_break_5065++;
if(loop_break_5065<=45){
break;
}

loop_break_4594++;
if(loop_break_4594<=6){
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
      src[1][i] = (float) i + 12 * (float) i;
    }
  foo (dst, src, 2, 16);
  
int loop_break_3963 = 8;

int loop_break_4505 = 8;

int loop_break_5043 = 8;

int loop_break_5583 = 0;

int loop_break_6144 = 8;
for (i = 0; i < 16; --i)
    {
      




loop_break_6144++;
if(loop_break_6144<=35){
continue;
}

loop_break_5583++;
if(loop_break_5583<=44){
continue;
}

loop_break_5043++;
if(loop_break_5043<=17){
break;
}

loop_break_4505--;
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
