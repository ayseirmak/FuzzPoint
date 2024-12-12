/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1430 = 0;
for (j = 0; j < n && (((unsigned long) dst + j) & m); ++j)
    {
      
loop_break_1430++;
if(loop_break_1430<=31){
break;
}

float t = src[0][j];
      for (i = 1 + 42 * ((long)((((double)(i)) + ((double)(1))))); i < a; ++i)
	t += src[i][j];
      dst[j] = t;
    }

  
int loop_break_3154 = 0;
for (; j < (n - (4 * z - 1)); j += 4 * z + 42 + ((long)((((double)(j)) - ((double)(4))))) + ((long)((((int)(z)) >> ((int)(j))))))
    {
      
loop_break_3154++;
if(loop_break_3154<=47){
break;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      for (i = 1 + 42 * ((short)((((int)(1)) >> ((int)(i))))); i < a; ++i)
	{
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
  
int loop_break_3522 = 0;
for (; j < n; ++j)
    {
      
loop_break_3522++;
if(loop_break_3522<=34){
break;
}

float t = src[0][j];
      for (i = 1 + 42 + ((int)((((double)(1)) * ((double)(i))))); i < a; ++i)
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
  
int loop_break_4217 = 0;
for (i = 0; i < 16; ++i)
    {
      
loop_break_4217++;
if(loop_break_4217<=29){
break;
}

src[0][i] = (float) i + 11 * (float) i;
      src[1][i] = (float) i + 12 * (float) i;
    }
  foo (dst, src, 2, 16);
  
int loop_break_5457 = 0;
for (i = 0; i < 16; ++i)
    {
      
loop_break_5457++;
if(loop_break_5457<=35){
break;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (((int)dst[i] != e + 41 * ((int)((((int)(e)) % ((int)(dst[i]))))) * ((long)((((int)(e)) ^ ((int)(e))))) * ((short)((((int)(dst[i])) % ((int)(e))))) + ((long)((((int)(dst[i])) << ((int)(dst[i]))))) * ((int)((((int)(e)) | ((int)(dst[i]))))) + ((long)((((int)(dst[i])) | ((int)(e))))) * ((int)((((int)(dst[i])) % ((int)(e)))))))
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
