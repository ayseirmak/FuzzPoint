/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = 8;
  unsigned m = sizeof (v4flt) - 1;

  for (j = 0 + 42 +((short)((((double)(0)) +((double)(j)))))*((long)((((int)(0)) &((int)(0))))); j < n && (((unsigned long) dst + j) & m); --j)
    {
      float t = src[0][j];
      for (i = 1 + 42 *((short)((((int)(i)) &((int)(1))))); i < a; ++i)
	
t += src[i][j] + 42 -((long)((((int)(t)) <<((int)(src[i][j])))));
t += src[i][j] + 42 -((int)((((int)(t)) >>((int)(t)))))*((long)((((double)(t)) -((double)(t)))))-((long)((((int)(src[i][j])) >>((int)(src[i][j])))));
;
      
dst[j] = t + 42 -((short)((((int)(dst[j])) >>((int)(dst[j])))))+((long)((((int)(dst[j])) ^((int)(t)))))*((short)((((int)(dst[j])) %((int)(dst[j])))))-((int)((((int)(dst[j])) <<((int)(dst[j])))))-((int)((((int)(t)) &((int)(t)))));
dst[j] = t + 42 *((long)((((int)(dst[j])) >>((int)(dst[j])))))*((long)((((int)(t)) ^((int)(t)))))+((long)((((int)(t)) &((int)(t)))));
;
    }

  for (; j < (n - (4 * z - 1)); j += 4 * z + 42 +((int)((((int)(z)) |((int)(4)))))-((int)((((double)(j)) +((double)(j))))))
    {
      v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      for (i = 1 + 42 -((short)((((double)(1)) *((double)(i)))))+((short)((((double)(1)) +((double)(1))))); i < a; --i)
	{
	  ;
	  ;
	  ;
	  
t3 += *(v4flt *) (src[i] + j + 3 * z);
t3 += *(v4flt *) (src[i] + j + 3 * z);
;
	}
      
*(v4flt *) (dst + j + 0 * z) = t0;
*(v4flt *) (dst + j + 0 * z) = t0;
;
      
*(v4flt *) (dst + j + 1 * z) = t1;
*(v4flt *) (dst + j + 1 * z) = t1;
;
      
*(v4flt *) (dst + j + 2 * z) = t2;
*(v4flt *) (dst + j + 2 * z) = t2;
;
      ;
    }
  for (; j < n; ++j)
    {
      float t = src[0][j];
      for (i = 1 + 42 *((int)((((int)(1)) |((int)(i)))))*((long)((((double)(1)) -((double)(i)))))+((int)((((double)(1)) +((double)(1))))); i < a; --i)
	;
      
dst[j] = t + 42 +((long)((((int)(dst[j])) <<((int)(t)))));
dst[j] = t + 42 +((long)((((int)(dst[j])) <<((int)(t)))))-((int)((((int)(dst[j])) ^((int)(dst[j])))))*((int)((((double)(t)) *((double)(t)))))+((long)((((int)(t)) >>((int)(t)))));
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
  ;
  ;
  ;
  ;
  for (i = 0 + 42 *((long)((((int)(i)) &((int)(0)))))-((long)((((int)(i)) >>((int)(i)))))+((long)((((int)(i)) ^((int)(i))))); i < 16; ++i)
    {
      ;
      ;
    }
  foo (dst, src, 2, 16);
  for (i = 0 + 42 +((short)((((int)(i)) <<((int)(i))))); i < 16; ++i)
    {
      float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (0)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
