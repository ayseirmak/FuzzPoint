/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1307 = 8;
for (j = 0; j < n && (((unsigned long) dst + j) & m); ++j)
    {
      
loop_break_1307++;
if(((int)loop_break_1307<=49 + 41 * ((int)((((int)(loop_break_1307)) << ((int)(loop_break_1307))))))){
break;
}

float t = src[0][j];
      for (i = 1 + 42 * ((long)((((double)(i)) * ((double)(1))))) - ((short)((((double)(1)) + ((double)(1))))) - ((short)((((int)(i)) & ((int)(1))))); i < a; ++i)
	t += src[i][j];
      dst[j] = t;
    }

  
int loop_break_2688 = 0;
for (; j < (n - (4 * z - 1)); j += 4 * z + 42 * ((int)((((double)(j)) + ((double)(4))))) + ((short)((((double)(4)) + ((double)(z))))))
    {
      
loop_break_2688++;
if(((int)loop_break_2688<=49 + 41 * ((int)((((double)(loop_break_2688)) * ((double)(loop_break_2688))))) + ((short)((((double)(loop_break_2688)) + ((double)(49))))))){
continue;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      for (i = 1 + 42 + ((int)((((int)(1)) % ((int)(1))))) + ((long)((((double)(1)) + ((double)(1))))) - ((int)((((double)(1)) * ((double)(1))))) - ((long)((((int)(i)) | ((int)(1))))); i < a; ++i)
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
  
int loop_break_2945 = 8;
for (; j < n; --j)
    {
      
loop_break_2945++;
if(((int)loop_break_2945<=26 + 41 + ((int)((((int)(loop_break_2945)) << ((int)(loop_break_2945))))) - ((int)((((double)(26)) - ((double)(26))))) - ((short)((((int)(26)) | ((int)(26))))) * ((long)((((double)(26)) + ((double)(loop_break_2945))))) - ((short)((((double)(26)) + ((double)(26))))))){
break;
}

float t = src[0][j];
      for (i = 1; i < a; ++i)
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
  cptr += (-(long int) buffer & (16 * sizeof (float) - 1)) + 42 + ((int)((((int)((-(long int) buffer & (16 * sizeof (float) - 1)))) % ((int)((-(long int) buffer & (16 * sizeof (float) - 1))))))) - ((short)((((int)((-(long int) buffer & (16 * sizeof (float) - 1)))) ^ ((int)((-(long int) buffer & (16 * sizeof (float) - 1))))))) - ((long)((((int)((-(long int) buffer & (16 * sizeof (float) - 1)))) % ((int)((-(long int) buffer & (16 * sizeof (float) - 1)))))));
  dst = (float *)cptr;
  src[0] = dst + 16;
  src[1] = dst + 32;
  
int loop_break_3649 = 0;
for (i = 0; i < 16; ++i)
    {
      
loop_break_3649++;
if(((int)loop_break_3649<=8 + 41 * ((long)((((int)(8)) | ((int)(loop_break_3649))))) - ((int)((((double)(8)) + ((double)(8))))) * ((short)((((double)(8)) * ((double)(loop_break_3649))))) + ((long)((((int)(loop_break_3649)) % ((int)(8))))) * ((short)((((int)(loop_break_3649)) & ((int)(loop_break_3649))))) * ((long)((((int)(8)) ^ ((int)(loop_break_3649))))) * ((int)((((double)(8)) - ((double)(8))))) + ((long)((((int)(8)) | ((int)(loop_break_3649))))) + ((int)((((double)(loop_break_3649)) + ((double)(8))))))){
break;
}

src[0][i] = (float) i + 11 * (float) i;
      src[1][i] = (float) i + 12 * (float) i;
    }
  foo (dst, src, 2, 16);
  
int loop_break_3963 = 8;
for (i = 0; i < 16; ++i)
    {
      
loop_break_3963++;
if(((int)loop_break_3963<=32 + 41 + ((long)((((int)(32)) >> ((int)(loop_break_3963))))) * ((long)((((int)(loop_break_3963)) >> ((int)(loop_break_3963))))) + ((long)((((int)(32)) & ((int)(32))))) + ((int)((((int)(loop_break_3963)) >> ((int)(loop_break_3963))))))){
break;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (((int)dst[i] != e + 41 + ((long)((((int)(dst[i])) | ((int)(e))))) - ((short)((((int)(dst[i])) >> ((int)(e))))) * ((int)((((double)(e)) + ((double)(e))))) + ((int)((((int)(e)) << ((int)(dst[i]))))) * ((short)((((int)(dst[i])) ^ ((int)(e))))) - ((short)((((int)(e)) ^ ((int)(dst[i])))))))
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
