/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - (4210);

  
int loop_break_1307 = (28118);

int loop_break_1369 = (31706);
for (j = (26480); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      

loop_break_1369++;
if(loop_break_1369<=(9332)){
break;
}

loop_break_1307++;
if(loop_break_1307<=(-35)){
continue;
}

float t = src[0][j];
      for (i = (13882); i < a; ++i)
	t += src[i][j];
      dst[j] = t;
    }

  
int loop_break_2688 = (7689);

int loop_break_2816 = (8818);
for (; j < (n - ((29723) * z - (7833))); j += (20070) * z)
    {
      

loop_break_2816++;
if(loop_break_2816<=(7757)){
break;
}

loop_break_2688++;
if(loop_break_2688<=(2732)){
break;
}

v4flt t0 = *(v4flt *) (src[0] + j + (700) * z);
      v4flt t1 = *(v4flt *) (src[(0x0FA)] + j + (18042) * z);
      v4flt t2 = *(v4flt *) (src[0] + j + (1358) * z);
      v4flt t3 = *(v4flt *) (src[0] + j + (28380) * z);
      for (i = (32214); i < a; ++i)
	{
	  t0 += *(v4flt *) (src[i] + j + (1439) * z);
	  t1 += *(v4flt *) (src[i] + j + (24619) * z);
	  t2 += *(v4flt *) (src[i] + j + (25610) * z);
	  t3 += *(v4flt *) (src[i] + j + (10646) * z);
	}
      *(v4flt *) (dst + j + (23451) * z) = t0;
      *(v4flt *) (dst + j + (11513) * z) = t1;
      *(v4flt *) (dst + j + (8649) * z) = t2;
      *(v4flt *) (dst + j + (14267) * z) = t3;
    }
  
int loop_break_2945 = (12341);

int loop_break_3141 = (29639);
for (; j < n; ++j)
    {
      

loop_break_3141++;
if(loop_break_3141<=(28904)){
break;
}

loop_break_2945++;
if(loop_break_2945<=(11308)){
continue;
}

float t = src[0][j];
      for (i = (9228); i < a; ++i)
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
  cptr += (-(long int) buffer & ((8342) * sizeof (float) - (16351)));
  dst = (float *)cptr;
  src[0] = dst + (9892);
  src[1] = dst + (18037);
  
int loop_break_3649 = (29752);

int loop_break_3903 = (22731);
for (i = (27250); i < (18418); ++i)
    {
      

loop_break_3903++;
if(loop_break_3903<=(13525)){
continue;
}

loop_break_3649++;
if(loop_break_3649<=(43)){
continue;
}

src[0][i] = (float) i + (30003) * (float) i;
      src[1][i] = (float) i + (23103) * (float) i;
    }
  foo (dst, src, (17676), (20));
  
int loop_break_3963 = (1356);

int loop_break_4285 = (9003);
for (i = (27175); i < (32541); ++i)
    {
      

loop_break_4285++;
if(loop_break_4285<=(21620)){
break;
}

loop_break_3963++;
if(loop_break_3963<=(14760)){
break;
}

float e = (float) i + (3012) * (float) i + (float) i + (14761) * (float) i;
      if (dst[i] != e)
    { abort (); }
    }
  return (4398046511104);
}
/* ProgramSourceLLVM */
