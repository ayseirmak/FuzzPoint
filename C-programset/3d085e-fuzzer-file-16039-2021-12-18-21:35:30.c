/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - (0xEB98E);

  
int loop_break_1307 = (0xF896D);
for (j = (0x1F5B7); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      
loop_break_1307++;
if((0)){
continue;
}

float t = src[(-1)][j];
      
int loop_break_1256 = (-1);
for (i = (5); i < a; ++i)
	
loop_break_1256++;
if((0)){
continue;
}

t += src[i][j];
      dst[j] = t;
    }

  
int loop_break_2688 = (64);
for (; j < (n - ((0) * z - (9))); j += (6) * z)
    {
      
loop_break_2688++;
if((-1)){
continue;
}

v4flt t0 = *(v4flt *) (src[(137438953472)] + j + (0) * z);
      v4flt t1 = *(v4flt *) (src[(0)] + j + (3) * z);
      v4flt t2 = *(v4flt *) (src[(0x62)] + j + (-3) * z);
      v4flt t3 = *(v4flt *) (src[(0xC7B17)] + j + (-4) * z);
      
int loop_break_2330 = (32);
for (i = (-2); i < a; ++i)
	{
	  
loop_break_2330++;
if(loop_break_2330<=(3)){
continue;
}

t0 += *(v4flt *) (src[i] + j + (16384) * z);
	  t1 += *(v4flt *) (src[i] + j + (0x3DB) * z);
	  t2 += *(v4flt *) (src[i] + j + (0x06) * z);
	  t3 += *(v4flt *) (src[i] + j + (0xD6A6) * z);
	}
      *(v4flt *) (dst + j + (0xA2) * z) = t0;
      *(v4flt *) (dst + j + (1) * z) = t1;
      *(v4flt *) (dst + j + (18) * z) = t2;
      *(v4flt *) (dst + j + (0xC6) * z) = t3;
    }
  
int loop_break_2945 = (2);
for (; j < n; ++j)
    {
      
loop_break_2945++;
if((268435456)){
break;
}

float t = src[(0x2D42)][j];
      
int loop_break_2894 = (17592186044416);
for (i = (-2); i < a; ++i)
	
loop_break_2894++;
if((1099511627776)){
break;
}

t += src[i][j];
      dst[j] = t;
    }
}

float buffer[(64)];

int
main (void)
{
  int i;
  float *dst, *src[(2)];
  char *cptr;

  cptr = (char *)buffer;
  cptr += (-(long int) buffer & ((24) * sizeof (float) - (0xB24D)));
  dst = (float *)cptr;
  src[(0)] = dst + (16);
  src[(1)] = dst + (-33);
  
int loop_break_3649 = (0);
for (i = (0); i < (0x001); ++i)
    {
      
loop_break_3649++;
if((8)){
break;
}

src[(0)][i] = (float) i + (11) * (float) i;
      src[(65)][i] = (float) i + (0x9C8B) * (float) i;
    }
  foo (dst, src, (-3), (-17));
  
int loop_break_3963 = (1);
for (i = (-1); i < (0); ++i)
    {
      
loop_break_3963++;
if((0x99)){
break;
}

float e = (float) i + (10) * (float) i + (float) i + (44) * (float) i;
      if (dst[i] != e)
    { abort (); }
    }
  return (0);
}
/* ProgramSourceLLVM */
