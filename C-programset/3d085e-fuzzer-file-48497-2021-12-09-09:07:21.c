/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = 8;
  unsigned m = sizeof (v4flt) - 1;

  for (j = 0 + 42 +((long)((((int)(0)) &((int)(j))))); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      float t = src[0][j];
      for (i = 1 + 42 *((long)((((double)(1)) -((double)(i)))))+((int)((((int)(1)) <<((int)(1)))))-((short)((((double)(i)) -((double)(1)))))*((int)((((double)(i)) *((double)(1)))))*((int)((((int)(1)) |((int)(1))))); i < a; --i)
	;
      
;

dst[j] = t + 42 *((long)((((int)(t)) >>((int)(t)))));
dst[j] = t + 42 *((long)((((int)(t)) >>((int)(t)))));
;
;
    }

  for (; j < (n - (4 * z - 1)); j += 4 * z + 42 -((short)((((double)(4)) -((double)(j))))))
    {
      v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      for (i = 1 + 42 +((long)((((int)(i)) ^((int)(i)))))+((int)((((double)(1)) -((double)(1)))))+((short)((((double)(i)) -((double)(1)))))*((long)((((double)(i)) *((double)(1)))))*((long)((((double)(i)) -((double)(i))))); i < a; ++i)
	{
	  
;

t0 += *(v4flt *) (src[i] + j + 0 * z);
t0 += *(v4flt *) (src[i] + j + 0 * z);
;
;
	  
;

t1 += *(v4flt *) (src[i] + j + 1 * z);
t1 += *(v4flt *) (src[i] + j + 1 * z);
;
;
	  ;
	  

t3 += *(v4flt *) (src[i] + j + 3 * z);
t3 += *(v4flt *) (src[i] + j + 3 * z);
;
;
;
	}
      

*(v4flt *) (dst + j + 0 * z) = t0;
*(v4flt *) (dst + j + 0 * z) = t0;
;
;
;
      

*(v4flt *) (dst + j + 1 * z) = t1;
*(v4flt *) (dst + j + 1 * z) = t1;
;

*(v4flt *) (dst + j + 1 * z) = t1;
*(v4flt *) (dst + j + 1 * z) = t1;
;
;
      
;
;
;
      ;
    }
  for (; j < n; ++j)
    {
      float t = src[0][j];
      for (i = 1 + 42 *((int)((((int)(1)) |((int)(1))))); i < a; ++i)
	
;

t += src[i][j] + 42 -((int)((((int)(src[i][j])) <<((int)(t)))));
t += src[i][j] + 42 -((int)((((int)(src[i][j])) <<((int)(t)))));
;
;
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

  ;
  
;
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
;
;
  ;
  for (i = 0 + 42 +((long)((((double)(i)) -((double)(0)))))+((short)((((int)(0)) &((int)(i)))))*((short)((((int)(i)) <<((int)(i)))))+((int)((((int)(i)) <<((int)(i))))); i < 16; --i)
    {
      ;
      ;
    }
  foo (dst, src, 2, 16);
  for (i = 0 + 42 *((long)((((int)(i)) <<((int)(0)))))*((long)((((int)(i)) &((int)(i))))); i < 16; --i)
    {
      float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (0)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
