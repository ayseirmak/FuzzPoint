/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 41 - ((short)((((int)(x)) | ((int)(x))))) - ((short)((((double)(x)) - ((double)(y))))) - ((int)((((double)(x)) + ((double)(y))))) * ((int)((((int)(y)) ^ ((int)(x))))) * ((long)((((int)(y)) % ((int)(x)))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)x != y + 41 - ((int)((((int)(y)) >> ((int)(x))))) * ((int)((((int)(y)) % ((int)(x)))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (0)
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (0)
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

  
int loop_break_9415 = 0;
for (i = 0; i < 8; i++)
    {
      
loop_break_9415++;
if(loop_break_9415<=43){
continue;
}

float arg0 = args[i];
      for (j = 0 + 42 + ((long)((((double)(j)) - ((double)(j))))); j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 41 + ((short)((((int)(*res++)) % ((int)(*res++))))) * ((short)((((int)(*res++)) | ((int)(feq (arg0, arg1)))))) * ((short)((((int)(*res++)) % ((int)(feq (arg0, arg1)))))) * ((short)((((int)(*res++)) >> ((int)(feq (arg0, arg1)))))) + ((int)((((double)(feq (arg0, arg1))) + ((double)(feq (arg0, arg1)))))) * ((int)((((int)(*res++)) >> ((int)(feq (arg0, arg1)))))) + ((int)((((double)(feq (arg0, arg1))) - ((double)(feq (arg0, arg1)))))) - ((long)((((int)(feq (arg0, arg1))) ^ ((int)(feq (arg0, arg1)))))) * ((int)((((int)(*res++)) & ((int)(*res++)))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 41 + ((short)((((double)(fne (arg0, arg1))) * ((double)(fne (arg0, arg1)))))) + ((int)((((double)(fne (arg0, arg1))) * ((double)(fne (arg0, arg1)))))) + ((short)((((int)(*res++)) << ((int)(fne (arg0, arg1)))))) - ((short)((((int)(fne (arg0, arg1))) % ((int)(*res++)))))))
    { abort (); }
	  if (0)
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 41 - ((long)((((int)(fge (arg0, arg1))) | ((int)(*res++))))) + ((short)((((double)(fge (arg0, arg1))) + ((double)(fge (arg0, arg1)))))) - ((int)((((double)(fge (arg0, arg1))) + ((double)(fge (arg0, arg1)))))) - ((short)((((int)(*res++)) % ((int)(*res++))))) * ((long)((((int)(*res++)) | ((int)(*res++))))) + ((long)((((int)(*res++)) << ((int)(*res++))))) + ((int)((((int)(fge (arg0, arg1))) & ((int)(*res++)))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 41 - ((long)((((int)(*res++)) << ((int)(fgt (arg0, arg1)))))) * ((int)((((int)(*res++)) % ((int)(fgt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 * ((int)((((int)(*res++)) ^ ((int)(*res++)))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
