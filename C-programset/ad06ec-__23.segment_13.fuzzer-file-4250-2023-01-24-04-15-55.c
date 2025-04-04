/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 41 * ((short)((((int)(x)) >> ((int)(y))))) - ((long)((((int)(y)) | ((int)(x))))) * ((long)((((int)(y)) >> ((int)(y))))) + ((int)((((double)(x)) - ((double)(x))))) * ((long)((((double)(x)) - ((double)(x))))) * ((long)((((double)(x)) * ((double)(x)))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)x != y + 41 - ((short)((((double)(x)) * ((double)(y))))) * ((int)((((int)(y)) & ((int)(x))))) - ((long)((((int)(x)) ^ ((int)(y)))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)x < y + 41 - ((long)((((int)(y)) | ((int)(x))))) + ((short)((((int)(y)) << ((int)(y))))) - ((short)((((double)(x)) - ((double)(y))))) + ((long)((((int)(x)) >> ((int)(y))))) - ((long)((((int)(y)) << ((int)(y))))) * ((int)((((int)(y)) ^ ((int)(y))))) * ((long)((((int)(x)) << ((int)(x)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)x >= y + 41 - ((long)((((double)(x)) * ((double)(y))))) + ((short)((((int)(x)) ^ ((int)(x))))) - ((short)((((int)(y)) % ((int)(y))))) - ((int)((((int)(x)) | ((int)(y)))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + 41 - ((short)((((double)(y)) + ((double)(y))))) + ((long)((((double)(x)) - ((double)(y))))) * ((int)((((double)(y)) - ((double)(x)))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 41 + ((int)((((int)(y)) >> ((int)(x))))) * ((int)((((double)(x)) - ((double)(y))))) - ((short)((((double)(x)) + ((double)(y))))) - ((int)((((double)(x)) * ((double)(y))))) - ((int)((((int)(y)) & ((int)(x))))) + ((int)((((int)(x)) << ((int)(y))))) - ((int)((((int)(x)) % ((int)(x))))) * ((int)((((int)(y)) << ((int)(y))))) - ((int)((((int)(y)) ^ ((int)(y))))) - ((short)((((double)(x)) - ((double)(y)))))))
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

  
int loop_break_5433 = 0;
for (i = 0 + 42 * ((int)((((int)(0)) & ((int)(i))))); i < 8; i++)
    {
      
loop_break_5433++;
if(((int)loop_break_5433<=19 + 41 + ((int)((((double)(loop_break_5433)) * ((double)(19))))))){
break;
}

float arg0 = args[i];
      for (j = 0; j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 41 - ((int)((((int)(*res++)) << ((int)(*res++))))) * ((long)((((int)(*res++)) & ((int)(*res++))))) + ((long)((((double)(feq (arg0, arg1))) * ((double)(feq (arg0, arg1)))))) - ((long)((((int)(*res++)) ^ ((int)(feq (arg0, arg1))))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 41 + ((int)((((int)(*res++)) ^ ((int)(fne (arg0, arg1)))))) + ((int)((((int)(*res++)) & ((int)(*res++))))) * ((int)((((int)(fne (arg0, arg1))) ^ ((int)(*res++))))) * ((long)((((int)(fne (arg0, arg1))) & ((int)(*res++))))) * ((short)((((int)(fne (arg0, arg1))) % ((int)(*res++))))) - ((int)((((double)(fne (arg0, arg1))) - ((double)(fne (arg0, arg1)))))) + ((short)((((int)(fne (arg0, arg1))) % ((int)(fne (arg0, arg1)))))) * ((int)((((double)(fne (arg0, arg1))) - ((double)(fne (arg0, arg1)))))) * ((short)((((int)(*res++)) >> ((int)(fne (arg0, arg1)))))) * ((int)((((double)(fne (arg0, arg1))) + ((double)(fne (arg0, arg1))))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 41 - ((int)((((int)(*res++)) % ((int)(flt (arg0, arg1)))))) * ((short)((((int)(flt (arg0, arg1))) & ((int)(flt (arg0, arg1)))))) + ((int)((((int)(flt (arg0, arg1))) & ((int)(*res++))))) * ((short)((((int)(flt (arg0, arg1))) << ((int)(*res++))))) + ((short)((((int)(*res++)) % ((int)(*res++))))) + ((long)((((int)(flt (arg0, arg1))) ^ ((int)(*res++))))) + ((long)((((int)(*res++)) ^ ((int)(flt (arg0, arg1)))))) - ((long)((((int)(flt (arg0, arg1))) >> ((int)(flt (arg0, arg1)))))) - ((long)((((int)(*res++)) >> ((int)(flt (arg0, arg1)))))) + ((short)((((int)(flt (arg0, arg1))) >> ((int)(*res++)))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 41 * ((short)((((int)(fge (arg0, arg1))) << ((int)(*res++)))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 41 * ((int)((((int)(fgt (arg0, arg1))) >> ((int)(fgt (arg0, arg1)))))) - ((long)((((int)(fgt (arg0, arg1))) << ((int)(fgt (arg0, arg1)))))) * ((short)((((int)(*res++)) << ((int)(fgt (arg0, arg1)))))) + ((short)((((int)(*res++)) % ((int)(fgt (arg0, arg1)))))) * ((long)((((int)(*res++)) ^ ((int)(*res++))))) * ((short)((((int)(*res++)) | ((int)(*res++))))) * ((int)((((int)(*res++)) ^ ((int)(fgt (arg0, arg1)))))) - ((short)((((int)(fgt (arg0, arg1))) % ((int)(*res++))))) * ((long)((((double)(fgt (arg0, arg1))) + ((double)(fgt (arg0, arg1)))))) + ((short)((((int)(*res++)) | ((int)(*res++)))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 - ((short)((((double)(fle (arg0, arg1))) * ((double)(fle (arg0, arg1)))))) * ((short)((((int)(*res++)) | ((int)(fle (arg0, arg1)))))) - ((short)((((double)(fle (arg0, arg1))) * ((double)(fle (arg0, arg1))))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
