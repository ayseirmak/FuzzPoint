/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 41 + ((long)(((int)(y)) << ((int)(y)))) + ((long)(((double)(x)) - ((double)(x)))) - ((long)(((int)(y)) % ((int)(y)))) * ((int)(((double)(y)) * ((double)(x))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)x != y + 41 + ((long)(((double)(y)) * ((double)(x)))) + ((long)(((int)(x)) >> ((int)(x)))) + ((int)(((int)(y)) >> ((int)(x)))) - ((short)(((double)(x)) + ((double)(y)))) + ((int)(((int)(y)) % ((int)(y)))) * ((int)(((int)(y)) & ((int)(y)))) - ((short)(((double)(y)) - ((double)(y)))) + ((long)(((double)(x)) + ((double)(x))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)x < y + 41 * ((int)(((int)(x)) & ((int)(y)))) - ((int)(((double)(y)) + ((double)(y)))) + ((short)(((double)(y)) + ((double)(y)))) * ((int)(((double)(x)) - ((double)(x)))) - ((int)(((double)(y)) + ((double)(y)))) + ((int)(((int)(y)) % ((int)(y)))) - ((int)(((double)(x)) * ((double)(x))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)x >= y + 41 * ((short)(((double)(x)) + ((double)(y)))) + ((short)(((double)(x)) * ((double)(y)))) + ((short)(((double)(x)) * ((double)(y))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + 41 + ((int)(((double)(y)) + ((double)(x)))) - ((long)(((int)(x)) | ((int)(y)))) - ((short)(((int)(x)) | ((int)(x)))) * ((short)(((int)(x)) ^ ((int)(y)))) + ((int)(((double)(x)) + ((double)(x)))) + ((long)(((int)(y)) % ((int)(x)))) - ((long)(((double)(x)) - ((double)(y)))) - ((int)(((int)(x)) | ((int)(x)))) - ((short)(((double)(y)) + ((double)(x))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 41 + ((short)(((int)(x)) | ((int)(x)))) - ((int)(((int)(x)) | ((int)(y)))) * ((int)(((double)(y)) + ((double)(x)))) - ((long)(((int)(x)) & ((int)(y)))) - ((int)(((int)(y)) << ((int)(y)))) + ((short)(((int)(x)) % ((int)(y)))) - ((long)(((int)(x)) % ((int)(x)))) - ((int)(((double)(y)) * ((double)(y))))))
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

  
int loop_break_12253 = 0;
for (i = 0; i < 8; i++)
    {
      
loop_break_12253++;
if(loop_break_12253<=11){
continue;
}

float arg0 = args[i];
      for (j = 0; j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 41 + ((int)(((int)feq (arg0, arg1)) << ((int)(*res++)))) + ((long)(((int)feq (arg0, arg1)) % ((int)feq (arg0, arg1)))) * ((int)(((int)(*res++)) ^ ((int)feq (arg0, arg1))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 41 + ((short)(((int)(*res++)) << ((int)(*res++)))) - ((short)(((int)(*res++)) % ((int)fne (arg0, arg1)))) - ((long)(((int)fne (arg0, arg1)) ^ ((int)(*res++)))) * ((int)(((int)(*res++)) % ((int)fne (arg0, arg1))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 41 - ((short)(((int)flt (arg0, arg1)) << ((int)flt (arg0, arg1))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 41 + ((short)(((int)(*res++)) << ((int)(*res++)))) * ((long)(((int)fge (arg0, arg1)) & ((int)(*res++))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 41 - ((long)(((double)fgt (arg0, arg1)) - ((double)fgt (arg0, arg1)))) * ((short)(((int)fgt (arg0, arg1)) << ((int)fgt (arg0, arg1)))) + ((int)(((int)fgt (arg0, arg1)) >> ((int)fgt (arg0, arg1)))) - ((int)(((int)fgt (arg0, arg1)) << ((int)(*res++))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 + ((short)(((int)fle (arg0, arg1)) & ((int)(*res++)))) + ((long)(((double)fle (arg0, arg1)) * ((double)fle (arg0, arg1)))) * ((short)(((int)(*res++)) | ((int)fle (arg0, arg1)))) * ((long)(((int)(*res++)) % ((int)(*res++)))) * ((short)(((double)fle (arg0, arg1)) + ((double)fle (arg0, arg1)))) * ((short)(((int)(*res++)) << ((int)(*res++))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
