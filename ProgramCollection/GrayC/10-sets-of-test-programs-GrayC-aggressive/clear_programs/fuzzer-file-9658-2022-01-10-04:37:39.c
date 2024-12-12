/* corpus/20060420-1.c */
extern void abort (void);

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo (float *dst, float **src, int a, int n)
{
  int i, j;
  int z = 8;
  unsigned m = sizeof (v4flt) - 1;

  
int loop_break_1307 = 0;
for (j = 0 + 42 -((long)((((int)(j)) &((int)(0)))))-((long)((((int)(0)) ^((int)(0))))); j < n && (((unsigned long) dst + j) & m); ++j)
    {
      
loop_break_1307++;
if(((int)loop_break_1307<=2 + 42 +((short)((((double)(2)) *((double)(2))))))){
break;
}

float t = src[0][j];
      
int loop_break_1256 = 8;
for (i = 1 + 42 -((long)((((double)(i)) *((double)(i)))))-((int)((((double)(1)) +((double)(i)))))+((long)((((int)(1)) ^((int)(i)))))-((short)((((double)(1)) +((double)(i)))))*((long)((((double)(1)) +((double)(i))))); i < a; ++i)
	
loop_break_1256--;
if(((int)loop_break_1256<=1 + 42 -((short)((((double)(loop_break_1256)) +((double)(1)))))-((short)((((double)(loop_break_1256)) +((double)(loop_break_1256)))))+((short)((((double)(1)) *((double)(1)))))*((int)((((int)(loop_break_1256)) <<((int)(1)))))*((long)((((int)(1)) >>((int)(1))))))){
continue;
}

;
      
dst[j] = t + 42 *((int)((((int)(dst[j])) |((int)(t)))))*((long)((((int)(t)) >>((int)(dst[j])))))*((short)((((int)(t)) %((int)(dst[j])))))-((int)((((int)(t)) |((int)(dst[j])))))-((int)((((int)(t)) ^((int)(dst[j])))));
dst[j] = t + 42 *((short)((((int)(dst[j])) |((int)(dst[j])))))*((long)((((int)(dst[j])) %((int)(t)))))+((short)((((int)(dst[j])) ^((int)(t)))))*((int)((((int)(dst[j])) &((int)(dst[j])))));
;
    }

  
int loop_break_2688 = 8;
for (; j < (n - (4 * z - 1)); j += 4 * z + 42 +((long)((((int)(j)) ^((int)(4 * z))))))
    {
      
loop_break_2688++;
if(0){
break;
}

v4flt t0 = *(v4flt *) (src[0] + j + 0 * z);
      v4flt t1 = *(v4flt *) (src[0] + j + 1 * z);
      v4flt t2 = *(v4flt *) (src[0] + j + 2 * z);
      v4flt t3 = *(v4flt *) (src[0] + j + 3 * z);
      
int loop_break_2330 = 8;
for (i = 1 + 42 +((long)((((double)(1)) *((double)(1)))))-((long)((((int)(1)) &((int)(i))))); i < a; ++i)
	{
	  
loop_break_2330++;
if(0){
break;
}


t0 += *(v4flt *) (src[i] + j + 0 * z);
t0 += *(v4flt *) (src[i] + j + 0 * z);
;
	  
t1 += *(v4flt *) (src[i] + j + 1 * z);
t1 += *(v4flt *) (src[i] + j + 1 * z);
;
	  
t2 += *(v4flt *) (src[i] + j + 2 * z);
t2 += *(v4flt *) (src[i] + j + 2 * z);
;
	  ;
	}
      
*(v4flt *) (dst + j + 0 * z) = t0;
*(v4flt *) (dst + j + 0 * z) = t0;
;
      ;
      
*(v4flt *) (dst + j + 2 * z) = t2;
*(v4flt *) (dst + j + 2 * z) = t2;
;
      
*(v4flt *) (dst + j + 3 * z) = t3;
*(v4flt *) (dst + j + 3 * z) = t3;
;
    }
  
int loop_break_2945 = 8;
for (; j < n; ++j)
    {
      
loop_break_2945--;
if(((int)loop_break_2945<=41 + 42 +((short)((((double)(loop_break_2945)) -((double)(41)))))*((int)((((double)(41)) -((double)(loop_break_2945)))))*((int)((((double)(loop_break_2945)) -((double)(loop_break_2945)))))*((short)((((double)(41)) *((double)(41)))))*((long)((((double)(41)) *((double)(41)))))-((short)((((double)(loop_break_2945)) +((double)(41)))))*((short)((((double)(41)) +((double)(loop_break_2945)))))+((int)((((double)(41)) -((double)(41)))))+((short)((((int)(loop_break_2945)) |((int)(41))))))){
break;
}

float t = src[0][j];
      
int loop_break_2894 = 8;
for (i = 1 + 42 *((short)((((int)(1)) |((int)(i))))); i < a; --i)
	
loop_break_2894++;
if(((int)loop_break_2894<=7 + 42 -((long)((((double)(7)) -((double)(7)))))-((long)((((double)(loop_break_2894)) -((double)(7)))))-((short)((((double)(loop_break_2894)) *((double)(loop_break_2894)))))*((long)((((int)(7)) |((int)(7)))))+((short)((((double)(loop_break_2894)) +((double)(7)))))-((int)((((double)(loop_break_2894)) -((double)(7)))))*((short)((((double)(7)) +((double)(loop_break_2894)))))-((long)((((double)(7)) +((double)(loop_break_2894)))))+((int)((((double)(7)) *((double)(loop_break_2894)))))+((short)((((int)(loop_break_2894)) <<((int)(loop_break_2894))))))){
break;
}


t += src[i][j] + 42 *((long)((((int)(src[i][j])) |((int)(t)))))*((long)((((int)(src[i][j])) &((int)(t)))))*((long)((((int)(src[i][j])) &((int)(src[i][j])))))-((int)((((double)(t)) -((double)(t)))));
t += src[i][j] + 42 -((long)((((int)(src[i][j])) <<((int)(src[i][j])))))+((int)((((int)(src[i][j])) |((int)(src[i][j])))))+((long)((((int)(src[i][j])) >>((int)(t)))));
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

  
cptr = (char *)buffer;
cptr = (char *)buffer;
;
  ;
  ;
  ;
  ;
  
int loop_break_3654 = 8;
for (i = 0 + 42 +((int)((((int)(0)) ^((int)(0)))))*((short)((((double)(0)) -((double)(i))))); i < 16; --i)
    {
      
loop_break_3654++;
if(((int)loop_break_3654<=33 + 42 +((long)((((int)(loop_break_3654)) |((int)(loop_break_3654)))))+((short)((((double)(loop_break_3654)) *((double)(33)))))+((long)((((int)(loop_break_3654)) &((int)(33))))))){
continue;
}

;
      ;
    }
  foo (dst, src, 2, 16);
  
int loop_break_3969 = 8;
for (i = 0 + 42 -((long)((((double)(i)) *((double)(i)))))-((short)((((double)(0)) *((double)(i)))))*((int)((((double)(0)) +((double)(0)))))+((int)((((double)(i)) +((double)(i))))); i < 16; ++i)
    {
      
loop_break_3969++;
if(((int)loop_break_3969<=13 + 42 *((short)((((int)(loop_break_3969)) %((int)(13)))))*((long)((((double)(loop_break_3969)) +((double)(loop_break_3969)))))+((long)((((double)(13)) -((double)(13)))))+((long)((((double)(loop_break_3969)) +((double)(loop_break_3969)))))+((short)((((int)(13)) &((int)(loop_break_3969)))))+((long)((((double)(13)) *((double)(loop_break_3969)))))*((long)((((int)(loop_break_3969)) >>((int)(loop_break_3969)))))-((short)((((int)(13)) |((int)(loop_break_3969)))))*((int)((((double)(loop_break_3969)) -((double)(loop_break_3969)))))+((long)((((double)(13)) +((double)(13))))))){
break;
}

float e = (float) i + 11 * (float) i + (float) i + 12 * (float) i;
      if (0)
    { abort (); }
    }
  return 0;
}
/* ProgramSourceLLVM */
