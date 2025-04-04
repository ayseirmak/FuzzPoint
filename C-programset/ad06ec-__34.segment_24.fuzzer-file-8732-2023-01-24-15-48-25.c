/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 41 * ((int)((((double)(y)) - ((double)(x))))) - ((int)((((int)(x)) >> ((int)(x)))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)x != y + 41 - ((short)((((int)(x)) >> ((int)(x))))) * ((long)((((double)(y)) + ((double)(x)))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)x < y + 41 - ((int)((((double)(y)) * ((double)(x))))) - ((int)((((int)(x)) ^ ((int)(x))))) * ((int)((((double)(y)) - ((double)(y))))) + ((int)((((double)(x)) - ((double)(x))))) * ((int)((((double)(x)) + ((double)(x))))) - ((long)((((int)(y)) >> ((int)(y)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)x >= y + 41 - ((int)((((int)(y)) % ((int)(y))))) - ((int)((((int)(y)) | ((int)(x))))) + ((int)((((double)(y)) * ((double)(x))))) - ((int)((((double)(y)) * ((double)(x))))) - ((long)((((double)(x)) - ((double)(x))))) - ((short)((((double)(y)) * ((double)(x))))) * ((long)((((double)(x)) + ((double)(x)))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (0)
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (0)
    return T;
  else
    return F;
}

float args[] =
{
  0.0F,
  1.0F,
  -1.0F,
  __FLT_MAX__,
  __FLT_MIN__,
  0.0000000000001F,
  123456789.0F,
  -987654321.0F
};

int correct_results[] =
{
 T, F, F, T, F, T,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 T, F, F, T, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 T, F, F, T, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 T, F, F, T, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 T, F, F, T, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 T, F, F, T, F, T,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, F, T, T, F,
 F, T, F, T, T, F,
 T, F, F, T, F, T,
 F, T, F, T, T, F,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 F, T, T, F, F, T,
 T, F, F, T, F, T,
};

int
main (void)
{
  int i, j, *res = correct_results;

  
int loop_break_9310 = 0;
for (i = 0; i < 8; i++)
    {
      
loop_break_9310++;
if(loop_break_9310<=37){
break;
}

float arg0 = args[i];
      for (j = 0 + 42 * ((int)((((int)(0)) % ((int)(j))))); j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 41 - ((short)((((int)(feq (arg0, arg1))) << ((int)(*res++)))))))
    { abort (); }
	  if (0)
    { abort (); }
	  if (0)
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 41 + ((long)((((int)(fge (arg0, arg1))) ^ ((int)(*res++))))) * ((int)((((double)(fge (arg0, arg1))) - ((double)(fge (arg0, arg1)))))) + ((long)((((int)(fge (arg0, arg1))) << ((int)(*res++))))) * ((int)((((int)(*res++)) << ((int)(*res++))))) - ((long)((((int)(*res++)) & ((int)(fge (arg0, arg1)))))) + ((int)((((int)(*res++)) << ((int)(fge (arg0, arg1))))))))
    { abort (); }
	  if (0)
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 - ((int)((((int)(*res++)) | ((int)(fle (arg0, arg1)))))) * ((long)((((int)(*res++)) >> ((int)(*res++))))) - ((short)((((int)(*res++)) << ((int)(*res++))))) + ((short)((((int)(*res++)) & ((int)(*res++))))) + ((short)((((double)(fle (arg0, arg1))) - ((double)(fle (arg0, arg1)))))) + ((long)((((int)(*res++)) >> ((int)(*res++)))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
