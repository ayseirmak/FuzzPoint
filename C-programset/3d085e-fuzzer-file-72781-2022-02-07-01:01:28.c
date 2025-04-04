/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = (12);
  unsigned m = sizeof (v4flt) - (-2);

  
int loop_break_1385 = (-1);

int loop_break_1522 = (0);
for (j = (524288); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      

loop_break_1522++;
if((0)){
continue;
}

loop_break_1385++;
if(loop_break_1385<=(0xA)){
break;
}

float t = src[(-1)][j];
      
int loop_break_1232 = (0);

int loop_break_1277 = (8796093022208);
for (i = (0xF4); i < a; ++i)
	


loop_break_1277++;
if(loop_break_1277<=(43)){
continue;
}

loop_break_1232++;
if(loop_break_1232<=(18)){
break;
}



t += src[i][j];
t += src[i][j];
;
;
;
;
;
      
;
;
;
    }

  
int loop_break_2451 = (0);

int loop_break_2723 = (0);
for (; j < (n - ((-5) * z - (-2))); j += (0) * z)
    {
      

loop_break_2723++;
if((4398046511104)){
break;
}

loop_break_2451++;
if(loop_break_2451<=(16)){
break;
}

v4flt t0 = *(v4flt *) (src[(0x42)] + j + (8) * z);
      v4flt t1 = *(v4flt *) (src[(2048)] + j + (0x3A56C) * z);
      v4flt t2 = *(v4flt *) (src[(0)] + j + (2) * z);
      v4flt t3 = *(v4flt *) (src[(0)] + j + (0x1982) * z);
      
int loop_break_2423 = (0xF);

int loop_break_2692 = (0x0);
for (i = (0); i < a; ++i)
	{
	  


loop_break_2692++;
if((64)){
break;
}

loop_break_2423++;
if(loop_break_2423<=(0x88EFE)){
break;
}

;

;

t0 += *(v4flt *) (src[i] + j + (0xBD) * z);
t0 += *(v4flt *) (src[i] + j + (0) * z);
;
;
;
	  ;
	  

;

t2 += *(v4flt *) (src[i] + j + (34) * z);
t2 += *(v4flt *) (src[i] + j + (0x9482F) * z);
;
;


t2 += *(v4flt *) (src[i] + j + (-3) * z);
t2 += *(v4flt *) (src[i] + j + (2) * z);
;
;
;
;
	  ;
	}
      ;
      ;
      ;
      ;
    }
  
int loop_break_2696 = (0);

int loop_break_3060 = (0);
for (; j < n; ++j)
    {
      

loop_break_3060++;
if((0)){
break;
}

loop_break_2696++;
if((0x3760)){
break;
}

float t = src[(0)][j];
      
int loop_break_2604 = (0);

int loop_break_2965 = (0);
for (i = (1); i < a; ++i)
	;
      
;


dst[j] = t;
dst[j] = t;
;
;
;
;
    }
}

float buffer[(04)];

int
main (void)
{
  int i = (8);
  float *dst, *src[(2)];
  char *cptr;

  

;

cptr = (char *)buffer;
cptr = (char *)buffer;
;
;


cptr = (char *)buffer;
cptr = (char *)buffer;
;

cptr = (char *)buffer;
cptr = (char *)buffer;
;
;
;
  
;
;
;
  ;
  ;
  
;

;
;
;
;
  
int loop_break_3498 = (0x7C4BC);

int loop_break_3939 = (32768);
for (i = (0x7A6EB); i < (-17); ++i)
    {
      

loop_break_3939++;
if((0xF)){
continue;
}

loop_break_3498++;
if((0)){
break;
}

;
      
;

;

src[(0xB675)][i] = (float) i + (44) * (float) i;
src[(-2)][i] = (float) i + (0x84) * (float) i;
;
;
;
    }
  foo (dst, src, (-3), (0xC68));
  
int loop_break_3813 = (1);

int loop_break_4321 = (0xBEDF7);
for (i = (0x099); i < (0x110); ++i)
    {
      

loop_break_4321++;
if((4)){
break;
}

loop_break_3813++;
if(loop_break_3813<=(34)){
break;
}

float e = (float) i + (-12) * (float) i + (float) i + (44) * (float) i;
      if ((0x940))
    { abort (); }
    }
  return (0);
}
/* ProgramSourceLLVM */
