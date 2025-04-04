/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1307 = 0;
for (j = 0; j < n && (((unsigned long) dst + j) & m); ++j)
    {
      
loop_break_1307++;
if(((int)loop_break_1307<=38 + 41 - ((int)((((double)(loop_break_1307)) - ((double)(38))))) - ((long)((((int)(38)) | ((int)(loop_break_1307))))) - ((long)((((int)(38)) & ((int)(38))))) + ((long)((((double)(loop_break_1307)) + ((double)(loop_break_1307))))) * ((short)((((double)(loop_break_1307)) + ((double)(loop_break_1307))))) * ((int)((((int)(38)) | ((int)(loop_break_1307))))) + ((long)((((int)(loop_break_1307)) | ((int)(loop_break_1307))))) - ((int)((((double)(38)) + ((double)(loop_break_1307))))) + ((int)((((double)(loop_break_1307)) + ((double)(loop_break_1307))))) - ((long)((((double)(loop_break_1307)) - ((double)(38))))))){
break;
}

float t = src[0][j];
      for (i = 1 + 42 + ((long)((((int)(1)) << ((int)(i))))) + ((long)((((int)(1)) ^ ((int)(i))))); i < a; ++i)
	t += src[i][j];
      dst[j] = t;
    }

  
int loop_break_2688 = 0;
for (; j < (n - (4 * z - 1)); j += 4 * z + 42 - ((long)((((int)(4)) % ((int)(z))))) * ((short)((((int)(j)) | ((int)(4 * z))))) * ((short)((((int)(4)) & ((int)(4 * z))))))
    {
      
loop_break_2688++;
if(((int)loop_break_2688<=43 + 41 - ((short)((((double)(loop_break_2688)) * ((double)(43))))) - ((int)((((int)(43)) | ((int)(loop_break_2688))))) + ((short)((((double)(loop_break_2688)) - ((double)(loop_break_2688))))) + ((long)((((int)(loop_break_2688)) | ((int)(43))))) - ((int)((((int)(43)) & ((int)(loop_break_2688))))) - ((short)((((double)(43)) * ((double)(43))))))){
break;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      for (i = 1; i < a; ++i)
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
  
int loop_break_2945 = 0;
for (; j < n; ++j)
    {
      
loop_break_2945++;
if(0){
continue;
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
  int i = 8;
  float *dst, *src[2];
  char *cptr;

  cptr = (char *)buffer;
  cptr += (-(long int) buffer & (16 * sizeof (float) - 1));
  dst = (float *)cptr;
  src[0] = dst + 16;
  src[1] = dst + 32;
  
int loop_break_3649 = 0;
for (i = 0; i < 16; ++i)
    {
      
loop_break_3649++;
if(((int)loop_break_3649<=21 + 41 - ((long)((((double)(21)) * ((double)(loop_break_3649))))) - ((int)((((int)(loop_break_3649)) % ((int)(21))))) - ((int)((((int)(loop_break_3649)) ^ ((int)(21))))))){
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
if(((int)loop_break_3963<=6 + 41 - ((long)((((int)(loop_break_3963)) ^ ((int)(loop_break_3963))))))){
break;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (((int)dst[i] != e + 41 - ((int)((((int)(e)) >> ((int)(dst[i]))))) - ((short)((((int)(dst[i])) ^ ((int)(dst[i])))))))
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
