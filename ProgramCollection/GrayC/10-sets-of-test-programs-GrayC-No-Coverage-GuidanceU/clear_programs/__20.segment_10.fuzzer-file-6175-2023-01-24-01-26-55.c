/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)((int)x == y + 41 + ((int)((((double)(y)) - ((double)(x))))) + ((short)((((double)(y)) - ((double)(y)))))) + 41 * ((int)((((double)(((int)((((double)(y)) - ((double)(x))))))) - ((double)(y + 41 + ((int)((((double)(y)) - ((double)(x))))) + ((short)((((double)(y)) - ((double)(y)))))))))) - ((long)((((double)((int)x)) + ((double)(y + 41 + ((int)((((double)(y)) - ((double)(x))))))))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)((int)x != y + 41 - ((short)((((int)(x)) ^ ((int)(x))))) + ((long)((((int)(x)) << ((int)(y))))) - ((short)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(y)) + ((double)(x))))) - ((int)((((double)(y)) - ((double)(y))))) * ((int)((((double)(y)) - ((double)(y))))) - ((long)((((double)(y)) + ((double)(x))))) - ((long)((((int)(y)) ^ ((int)(y))))) * ((short)((((double)(x)) * ((double)(x))))) * ((short)((((double)(y)) - ((double)(x)))))) + 41 - ((int)((((int)(((short)((((int)(x)) ^ ((int)(x))))))) << ((int)(y + 41))))) * ((int)((((int)(((int)((((double)(y)) - ((double)(y))))) * ((int)((((double)(y)) - ((double)(y))))))) | ((int)((int)x))))) * ((int)((((double)(y + 41 - ((short)((((int)(x)) ^ ((int)(x))))) + ((long)((((int)(x)) << ((int)(y))))))) + ((double)(((long)((((double)(y)) + ((double)(x)))))))))) + ((short)((((int)(y + 41 - ((short)((((int)(x)) ^ ((int)(x))))) + ((long)((((int)(x)) << ((int)(y))))) - ((short)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(y)) + ((double)(x))))))) << ((int)(y + 41 - ((short)((((int)(x)) ^ ((int)(x))))) + ((long)((((int)(x)) << ((int)(y))))) - ((short)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(y)) + ((double)(x))))) - ((int)((((double)(y)) - ((double)(y))))) * ((int)((((double)(y)) - ((double)(y))))) - ((long)((((double)(y)) + ((double)(x))))) - ((long)((((int)(y)) ^ ((int)(y))))) * ((short)((((double)(x)) * ((double)(x))))) * ((short)((((double)(y)) - ((double)(x)))))))))) * ((long)((((int)(((short)((((int)(x)) ^ ((int)(x))))))) >> ((int)(y + 41 - ((short)((((int)(x)) ^ ((int)(x))))) + ((long)((((int)(x)) << ((int)(y))))) - ((short)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(y)) + ((double)(x))))) - ((int)((((double)(y)) - ((double)(y))))) * ((int)((((double)(y)) - ((double)(y))))) - ((long)((((double)(y)) + ((double)(x)))))))))) - ((int)((((int)(y + 41 - ((short)((((int)(x)) ^ ((int)(x))))) + ((long)((((int)(x)) << ((int)(y))))) - ((short)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(y)) + ((double)(x))))))) % ((int)(((int)((((double)(y)) - ((double)(y))))) * ((int)((((double)(y)) - ((double)(y))))))))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)((int)x < y + 41 * ((short)((((int)(x)) | ((int)(y))))) * ((short)((((double)(x)) + ((double)(x))))) + ((short)((((double)(x)) + ((double)(y))))) + ((short)((((double)(x)) - ((double)(x))))) * ((short)((((int)(y)) << ((int)(y))))) + ((long)((((int)(x)) >> ((int)(y)))))) + 41 - ((short)((((int)(y + 41 * ((short)((((int)(x)) | ((int)(y))))) * ((short)((((double)(x)) + ((double)(x))))) + ((short)((((double)(x)) + ((double)(y))))) + ((short)((((double)(x)) - ((double)(x))))) * ((short)((((int)(y)) << ((int)(y))))))) & ((int)((int)x)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)((int)x >= y + 41 * ((int)((((double)(x)) * ((double)(y))))) * ((short)((((int)(y)) | ((int)(x))))) * ((long)((((int)(y)) << ((int)(y))))) - ((int)((((double)(x)) - ((double)(y))))) * ((int)((((double)(x)) - ((double)(x)))))) + 41 + ((int)((((int)(y)) ^ ((int)(y)))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + 41 - ((long)((((int)(x)) << ((int)(x))))) - ((short)((((int)(x)) << ((int)(y))))) - ((short)((((int)(x)) & ((int)(y)))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 41 + ((int)((((double)(x)) - ((double)(x))))) * ((int)((((double)(y)) * ((double)(y)))))))
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

  
int loop_break_15895 = 8;
for (i = 0; i < 8; i--)
    {
      
loop_break_15895++;
if(((int)loop_break_15895<=10 + 41 + ((long)((((int)(loop_break_15895)) ^ ((int)(10))))))){
break;
}

float arg0 = args[i];
      for (j = 0 + 42 * ((short)((((double)(0)) - ((double)(j))))) * ((long)((((int)(j)) | ((int)(j))))) * ((long)((((double)(0)) - ((double)(0))))) * ((short)((((double)(0)) * ((double)(j))))) * ((int)((((int)(0)) << ((int)(j))))); j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 41 - ((short)((((int)(feq (arg0, arg1))) % ((int)(*res++))))) - ((int)((((int)(feq (arg0, arg1))) ^ ((int)(feq (arg0, arg1)))))) - ((int)((((int)(feq (arg0, arg1))) << ((int)(*res++))))) - ((int)((((int)(feq (arg0, arg1))) >> ((int)(*res++))))) - ((long)((((double)(feq (arg0, arg1))) - ((double)(feq (arg0, arg1)))))) + ((short)((((int)(feq (arg0, arg1))) | ((int)(feq (arg0, arg1)))))) - ((short)((((int)(feq (arg0, arg1))) >> ((int)(*res++))))) + ((long)((((int)(feq (arg0, arg1))) >> ((int)(*res++))))) - ((short)((((double)(feq (arg0, arg1))) - ((double)(feq (arg0, arg1)))))) * ((short)((((int)(*res--)) ^ ((int)(feq (arg0, arg1))))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 41 * ((short)((((int)(*res++)) & ((int)(*res++))))) + ((long)((((int)(*res++)) ^ ((int)(fne (arg0, arg1)))))) - ((long)((((int)(*res++)) >> ((int)(fne (arg0, arg1)))))) * ((short)((((int)(*res++)) >> ((int)(fne (arg0, arg1)))))) - ((long)((((int)(*res++)) >> ((int)(fne (arg0, arg1)))))) * ((long)((((int)(*res++)) & ((int)(*res++))))) + ((int)((((int)(*res++)) % ((int)(*res++))))) - ((int)((((int)(fne (arg0, arg1))) % ((int)(fne (arg0, arg1)))))) - ((int)((((int)(*res++)) >> ((int)(*res++))))) * ((short)((((int)(fne (arg0, arg1))) >> ((int)(fne (arg0, arg1))))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 41 * ((long)((((int)(flt (arg0, arg1))) & ((int)(*res++))))) * ((short)((((int)(*res++)) & ((int)(*res++)))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 41 + ((short)((((int)(*res++)) & ((int)(fge (arg0, arg1)))))) * ((long)((((int)(*res++)) & ((int)(*res++))))) - ((long)((((int)(*res--)) % ((int)(*res++))))) - ((short)((((int)(*res++)) | ((int)(fge (arg0, arg1)))))) + ((long)((((int)(*res++)) % ((int)(fge (arg0, arg1)))))) * ((int)((((int)(fge (arg0, arg1))) & ((int)(*res++)))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 41 * ((long)((((int)(fgt (arg0, arg1))) | ((int)(fgt (arg0, arg1)))))) - ((short)((((int)(fgt (arg0, arg1))) >> ((int)(*res++))))) + ((long)((((int)(*res++)) % ((int)(fgt (arg0, arg1)))))) * ((long)((((int)(*res++)) >> ((int)(fgt (arg0, arg1)))))) * ((int)((((int)(fgt (arg0, arg1))) & ((int)(*res++))))) + ((short)((((int)(*res++)) >> ((int)(fgt (arg0, arg1)))))) - ((int)((((int)(*res++)) >> ((int)(*res++))))) * ((int)((((int)(fgt (arg0, arg1))) & ((int)(*res++))))) * ((long)((((int)(fgt (arg0, arg1))) << ((int)(*res++)))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 * ((int)((((int)(*res++)) & ((int)(*res--))))) * ((long)((((double)(fle (arg0, arg1))) + ((double)(fle (arg0, arg1)))))) * ((int)((((int)(fle (arg0, arg1))) << ((int)(*res++))))) - ((int)((((int)(*res++)) >> ((int)(fle (arg0, arg1)))))) + ((int)((((int)(*res++)) << ((int)(*res++))))) * ((short)((((double)(fle (arg0, arg1))) * ((double)(fle (arg0, arg1)))))) - ((long)((((int)(fle (arg0, arg1))) | ((int)(*res++))))) * ((short)((((int)(fle (arg0, arg1))) & ((int)(fle (arg0, arg1)))))) * ((int)((((double)(fle (arg0, arg1))) - ((double)(fle (arg0, arg1)))))) * ((int)((((int)(*res--)) | ((int)(fle (arg0, arg1))))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
