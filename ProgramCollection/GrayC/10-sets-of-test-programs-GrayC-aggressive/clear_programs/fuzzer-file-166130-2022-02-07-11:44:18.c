/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = (8);
  unsigned m = sizeof (v4flt) - (129);

  
int loop_break_1307 = (-9);

int loop_break_1437 = (-9);
for (j = (0); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      

loop_break_1437--;
if(loop_break_1437<=(-7)){
continue;
}

loop_break_1307++;
if(loop_break_1307<=(0)){
continue;
}

float t = src[(0)][j];
      
int loop_break_1256 = (-9);

int loop_break_1294 = (0);
for (i = (129); i < a; ++i)
	

loop_break_1294++;
if(loop_break_1294<=(0xC086A0)){
break;
}

loop_break_1256++;
if(loop_break_1256<=(0xC20B9)){
continue;
}


t += src[i][j];
t += src[i][j];
;
      
dst[j] = t;
dst[j] = t;
;
    }

  
int loop_break_2688 = (40);

int loop_break_2954 = (0x9CE1);
for (; j < (n - ((0x9E9AC) * z - (1))); j += (0xD2CE0) * z)
    {
      

loop_break_2954++;
if(loop_break_2954<=(6)){
continue;
}

loop_break_2688++;
if(loop_break_2688<=(34)){
break;
}

v4flt t0 = *(v4flt *) (src[(0)] + j + (0) * z);
      v4flt t1 = *(v4flt *) (src[(2305843009213693952)] + j + (33) * z);
      v4flt t2 = *(v4flt *) (src[(0x6D19)] + j + (-3) * z);
      v4flt t3 = *(v4flt *) (src[(0x4)] + j + (3) * z);
      
int loop_break_2330 = (8);

int loop_break_2595 = (72);
for (i = (0x439); i < a; --i)
	{
	  

loop_break_2595++;
if(loop_break_2595<=(-45)){
continue;
}

loop_break_2330++;
if(loop_break_2330<=(48)){
continue;
}


t0 += *(v4flt *) (src[i] + j + (0xE8DE) * z);
t0 += *(v4flt *) (src[i] + j + (0xE8DE) * z);
;
	  
t1 += *(v4flt *) (src[i] + j + (3) * z);
t1 += *(v4flt *) (src[i] + j + (3) * z);
;
	  
t2 += *(v4flt *) (src[i] + j + (66) * z);
t2 += *(v4flt *) (src[i] + j + (66) * z);
;
	  
t3 += *(v4flt *) (src[i] + j + (-4) * z);
t3 += *(v4flt *) (src[i] + j + (-4) * z);
;
	}
      
*(v4flt *) (dst + j + (0) * z) = t0;
*(v4flt *) (dst + j + (0) * z) = t0;
;
      ;
      ;
      ;
    }
  
int loop_break_2945 = (0);

int loop_break_3356 = (0xBD);
for (; j < n; ++j)
    {
      

loop_break_3356--;
if(loop_break_3356<=(24)){
continue;
}

loop_break_2945++;
if(loop_break_2945<=(-5)){
continue;
}

float t = src[(0x48)][j];
      
int loop_break_2894 = (0x9143);

int loop_break_3213 = (-9);
for (i = (1); i < a; ++i)
	

loop_break_3213++;
if(loop_break_3213<=(15)){
break;
}

loop_break_2894++;
if(loop_break_2894<=(33)){
break;
}

;
      
dst[j] = t;
dst[j] = t;
;
    }
}

float buffer[(72)];

int
main (void)
{
  int i = (40);
  float *dst, *src[(0xEE84E)];
  char *cptr;

  
cptr = (char *)buffer;
cptr = (char *)buffer;
;
  ;
  
dst = (float *)cptr;
dst = (float *)cptr;
;
  ;
  ;
  
int loop_break_3649 = (8);

int loop_break_4122 = (8);
for (i = (0x1E1); i < (0); ++i)
    {
      

loop_break_4122++;
if(loop_break_4122<=(0xFC17F)){
continue;
}

loop_break_3649--;
if(loop_break_3649<=(0xD11E66)){
break;
}

;
      
src[(17)][i] = (float) i + (0x971) * (float) i;
src[(17)][i] = (float) i + (0x971) * (float) i;
;
    }
  foo (dst, src, (-3), (80));
  
int loop_break_3963 = (0x3EF);

int loop_break_4505 = (0);
for (i = (0x8B4B); i < (16); ++i)
    {
      

loop_break_4505++;
if(loop_break_4505<=(14)){
break;
}

loop_break_3963++;
if(loop_break_3963<=(1)){
break;
}

float e = (float) i + (0x7FD0E5) * (float) i + (float) i + (0xDC11A) * (float) i;
      if (dst[i] != e)
    { abort (); }
    }
  return (0);
}
/* ProgramSourceLLVM */
