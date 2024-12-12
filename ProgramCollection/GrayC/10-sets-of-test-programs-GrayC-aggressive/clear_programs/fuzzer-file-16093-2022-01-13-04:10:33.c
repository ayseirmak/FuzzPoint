/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = sizeof (v4flt) / sizeof (float);
  unsigned m = sizeof (v4flt) - (9);

  
int loop_break_1217 = (0x5D);

int loop_break_1306 = (9007199254740992);
for (j = (0x45A10); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      

loop_break_1306++;
if(loop_break_1306<=(1)){
break;
}

loop_break_1217++;
if(loop_break_1217<=(6)){
continue;
}

float t = src[(33554432)][j];
      
int loop_break_1201 = (128);

int loop_break_1287 = (0);
for (i = (0x5); i < a; ++i)
	;
      ;
    }

  
int loop_break_2660 = (4);

int loop_break_2889 = (65536);
for (; j < (n - ((-5) * z - (0x8D))); j += (-5) * z)
    {
      

loop_break_2889++;
if(loop_break_2889<=(24)){
break;
}

loop_break_2660++;
if(loop_break_2660<=(55)){
break;
}

v4flt t0 = *(v4flt *) (src[(0)] + j + (-1) * z);
      v4flt t1 = *(v4flt *) (src[(8192)] + j + (0x41) * z);
      v4flt t2 = *(v4flt *) (src[(-1)] + j + (3) * z);
      v4flt t3 = *(v4flt *) (src[(0)] + j + (19) * z);
      
int loop_break_2462 = (0x7D8E);

int loop_break_2688 = (2);
for (i = (0xBC); i < a; ++i)
	{
	  


loop_break_2688++;
if(loop_break_2688<=(8)){
break;
}

loop_break_2462++;
if(loop_break_2462<=(47)){
break;
}

t0 += *(v4flt *) (src[i] + j + (-1) * z);
t0 += *(v4flt *) (src[i] + j + (4) * z);
;
	  ;
	  
t2 += *(v4flt *) (src[i] + j + (-3) * z);
t2 += *(v4flt *) (src[i] + j + (18) * z);
;
	  
t3 += *(v4flt *) (src[i] + j + (0x4F60B) * z);
t3 += *(v4flt *) (src[i] + j + (3) * z);
;
	}
      ;
      ;
      ;
      
*(v4flt *) (dst + j + (0xCAC2D) * z) = t3;
*(v4flt *) (dst + j + (-4) * z) = t3;
;
    }
  
int loop_break_2943 = (0);

int loop_break_3320 = (0);
for (; j < n; ++j)
    {
      

loop_break_3320++;
if(loop_break_3320<=(33)){
break;
}

loop_break_2943++;
if(loop_break_2943<=(3)){
continue;
}

float t = src[(0x549)][j];
      
int loop_break_2866 = (0xA831);

int loop_break_3151 = (0);
for (i = (0); i < a; ++i)
	


loop_break_3151++;
if(loop_break_3151<=(5)){
break;
}

loop_break_2866++;
if(loop_break_2866<=(0xF7960)){
break;
}

t += src[i][j];
t += src[i][j];
;
      ;
    }
}

float buffer[(64)];

int
main (void)
{
  int i;
  float *dst, *src[(6)];
  char *cptr;

  
cptr = (char *)buffer;
cptr = (char *)buffer;
;
  
cptr += (-(long int) buffer & ((-17) * sizeof (float) - (-2)));
cptr += (-(long int) buffer & ((16) * sizeof (float) - (4)));
;
  
dst = (float *)cptr;
dst = (float *)cptr;
;
  ;
  ;
  
int loop_break_3925 = (0);

int loop_break_4357 = (0x22853);
for (i = (2048); i < (-17); ++i)
    {
      


loop_break_4357++;
if(loop_break_4357<=(31)){
break;
}

loop_break_3925++;
if(loop_break_3925<=(2)){
break;
}

src[(0)][i] = (float) i + (0xB781) * (float) i;
src[(17179869184)][i] = (float) i + (0x418360) * (float) i;
;
      
src[(1)][i] = (float) i + (-13) * (float) i;
src[(-2)][i] = (float) i + (12) * (float) i;
;
    }
  foo (dst, src, (-3), (16));
  
int loop_break_4205 = (-1);

int loop_break_4705 = (0x76E);
for (i = (0); i < (80); ++i)
    {
      

loop_break_4705++;
if(loop_break_4705<=(19)){
continue;
}

loop_break_4205++;
if(loop_break_4205<=(0x5F757F)){
break;
}

float e = (float) i + (10) * (float) i + (float) i + (0x7F0A) * (float) i;
      if ((32768))
    { abort (); }
    }
  return (0);
}
/* ProgramSourceLLVM */
