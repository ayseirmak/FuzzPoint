/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)((int)x == y + 41 + ((short)((((double)(y)) * ((double)(y))))) - ((long)((((int)(y)) << ((int)(x))))) * ((int)((((int)(y)) >> ((int)(y))))) * ((long)((((double)(y)) + ((double)(y)))))) + 41 + ((long)((((int)(y + 41 + ((short)((((double)(y)) * ((double)(y))))) - ((long)((((int)(y)) << ((int)(x))))) * ((int)((((int)(y)) >> ((int)(y))))) * ((long)((((double)(y)) + ((double)(y))))))) % ((int)(((short)((((double)(y)) * ((double)(y)))))))))) * ((short)((((int)(((long)((((int)(y)) << ((int)(x))))) * ((int)((((int)(y)) >> ((int)(y))))) * ((long)((((double)(y)) + ((double)(y))))))) ^ ((int)((int)x))))) + ((short)((((int)(((long)((((int)(y)) << ((int)(x))))) * ((int)((((int)(y)) >> ((int)(y))))) * ((long)((((double)(y)) + ((double)(y))))))) | ((int)((int)x))))) - ((int)((((int)(y + 41 + ((short)((((double)(y)) * ((double)(y))))))) >> ((int)(y + 41)))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)((int)x != y + 41 + ((int)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(x)) + ((double)(x))))) - ((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) >> ((int)(x))))) + ((int)((((int)(y)) % ((int)(x)))))) + 41 * ((int)((((double)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))))) + ((double)(y))))) * ((long)((((int)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(x)) + ((double)(x))))) - ((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) >> ((int)(x))))) + ((int)((((int)(y)) % ((int)(x))))))) % ((int)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(x)) + ((double)(x))))) - ((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) >> ((int)(x)))))))))) * ((long)((((double)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))))) * ((double)(((long)((((double)(x)) + ((double)(x)))))))))) - ((int)((((int)(((int)((((int)(y)) ^ ((int)(x))))))) % ((int)(y + 41))))) - ((int)((((int)(((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) >> ((int)(x))))))) ^ ((int)((int)x))))) + ((int)((((double)(((long)((((double)(x)) + ((double)(x))))))) * ((double)(((int)((((int)(y)) % ((int)(x)))))))))) + ((long)((((double)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))))) + ((double)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(x)) + ((double)(x)))))))))) * ((short)((((int)(((int)((((int)(y)) ^ ((int)(x))))))) | ((int)(41))))) + ((long)((((int)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(x)) + ((double)(x))))) - ((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) >> ((int)(x))))))) | ((int)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))) + ((long)((((double)(x)) + ((double)(x))))) - ((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) >> ((int)(x))))) + ((int)((((int)(y)) % ((int)(x)))))))))) * ((int)((((double)(y + 41 + ((int)((((int)(y)) ^ ((int)(x))))))) * ((double)(((int)((((int)(y)) % ((int)(x))))))))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)((int)x < y + 41 - ((long)((((double)(y)) * ((double)(y))))) * ((int)((((int)(y)) % ((int)(y))))) + ((long)((((int)(x)) | ((int)(y)))))) + 41 + ((int)((((int)(y)) ^ ((int)((int)x)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)((int)x >= y + 41 - ((int)((((double)(x)) - ((double)(x))))) + ((long)((((int)(x)) & ((int)(x))))) - ((long)((((double)(x)) - ((double)(y))))) - ((long)((((double)(y)) + ((double)(x))))) + ((long)((((double)(y)) - ((double)(x)))))) + 41 * ((long)((((int)(((long)((((double)(y)) - ((double)(x))))))) >> ((int)(y + 41 - ((int)((((double)(x)) - ((double)(x)))))))))) - ((long)((((int)(((long)((((double)(y)) + ((double)(x))))))) ^ ((int)(((long)((((double)(y)) + ((double)(x)))))))))) + ((long)((((int)(y + 41 - ((int)((((double)(x)) - ((double)(x))))) + ((long)((((int)(x)) & ((int)(x))))) - ((long)((((double)(x)) - ((double)(y))))) - ((long)((((double)(y)) + ((double)(x))))) + ((long)((((double)(y)) - ((double)(x))))))) >> ((int)(((long)((((double)(x)) - ((double)(y)))))))))) + ((short)((((double)((int)x)) - ((double)(y + 41))))) * ((int)((((double)(y + 41)) + ((double)((int)x))))) * ((int)((((int)(y + 41 - ((int)((((double)(x)) - ((double)(x))))) + ((long)((((int)(x)) & ((int)(x))))) - ((long)((((double)(x)) - ((double)(y))))) - ((long)((((double)(y)) + ((double)(x))))) + ((long)((((double)(y)) - ((double)(x))))))) % ((int)(((long)((((double)(y)) - ((double)(x)))))))))) - ((int)((((double)(((int)((((double)(x)) - ((double)(x))))))) - ((double)(((long)((((double)(x)) - ((double)(y)))))))))) + ((short)((((double)(((int)((((double)(x)) - ((double)(x))))))) - ((double)(((long)((((double)(x)) - ((double)(y)))))))))) - ((short)((((double)(y + 41)) + ((double)(y + 41 - ((int)((((double)(x)) - ((double)(x))))))))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)((int)x > y + 41 * ((short)((((double)(y)) + ((double)(x))))) * ((long)((((int)(x)) >> ((int)(y))))) * ((int)((((int)(x)) ^ ((int)(y))))) * ((long)((((double)(y)) * ((double)(y))))) + ((int)((((int)(x)) | ((int)(y)))))) + 41 + ((long)((((int)(41 * ((short)((((double)(y)) + ((double)(x))))) * ((long)((((int)(x)) >> ((int)(y))))) * ((int)((((int)(x)) ^ ((int)(y))))) * ((long)((((double)(y)) * ((double)(y))))))) % ((int)(((int)((((int)(x)) | ((int)(y)))))))))) - ((int)((((int)(y + 41 * ((short)((((double)(y)) + ((double)(x))))) * ((long)((((int)(x)) >> ((int)(y))))) * ((int)((((int)(x)) ^ ((int)(y))))) * ((long)((((double)(y)) * ((double)(y))))) + ((int)((((int)(x)) | ((int)(y))))))) ^ ((int)(y))))) + ((long)((((int)(y + 41 * ((short)((((double)(y)) + ((double)(x))))) * ((long)((((int)(x)) >> ((int)(y))))) * ((int)((((int)(x)) ^ ((int)(y))))) * ((long)((((double)(y)) * ((double)(y))))) + ((int)((((int)(x)) | ((int)(y))))))) | ((int)(y + 41 * ((short)((((double)(y)) + ((double)(x))))) * ((long)((((int)(x)) >> ((int)(y))))) * ((int)((((int)(x)) ^ ((int)(y))))) * ((long)((((double)(y)) * ((double)(y))))))))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 41 - ((int)((((int)(y)) << ((int)(y))))) + ((int)((((int)(x)) | ((int)(x))))) - ((long)((((int)(x)) % ((int)(x))))) * ((long)((((int)(x)) % ((int)(y))))) * ((short)((((double)(x)) + ((double)(x))))) + ((short)((((int)(y)) >> ((int)(y))))) * ((long)((((double)(x)) * ((double)(y))))) - ((long)((((int)(y)) ^ ((int)(y))))) * ((int)((((int)(y)) << ((int)(x))))) * ((int)((((int)(x)) << ((int)(y)))))))
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

  
int loop_break_15436 = 8;

int loop_break_15502 = 0;
for (i = 0; i < 8; i++)
    {
      

loop_break_15502++;
if(loop_break_15502<=45){
break;
}

loop_break_15436++;
if(loop_break_15436<=21){
break;
}

float arg0 = args[i];
      for (j = 0 + 42 * ((long)((((int)(0)) % ((int)(j))))) * ((long)((((int)(j)) << ((int)(0))))) * ((long)((((int)(0)) | ((int)(j))))) + ((long)((((int)(j)) >> ((int)(j))))) - ((long)((((double)(0)) - ((double)(j))))) + 42 - ((int)((((int)(0 + 42 * ((long)((((int)(0)) % ((int)(j))))) * ((long)((((int)(j)) << ((int)(0))))) * ((long)((((int)(0)) | ((int)(j))))) + ((long)((((int)(j)) >> ((int)(j))))) - ((long)((((double)(0)) - ((double)(j))))))) << ((int)(0 + 42 * ((long)((((int)(0)) % ((int)(j))))) * ((long)((((int)(j)) << ((int)(0))))) * ((long)((((int)(0)) | ((int)(j))))) + ((long)((((int)(j)) >> ((int)(j))))) - ((long)((((double)(0)) - ((double)(j)))))))))) * ((int)((((int)(0 + 42 * ((long)((((int)(0)) % ((int)(j))))) * ((long)((((int)(j)) << ((int)(0))))) * ((long)((((int)(0)) | ((int)(j))))) + ((long)((((int)(j)) >> ((int)(j))))) - ((long)((((double)(0)) - ((double)(j))))))) << ((int)(0 + 42 * ((long)((((int)(0)) % ((int)(j))))) * ((long)((((int)(j)) << ((int)(0))))) * ((long)((((int)(0)) | ((int)(j))))) + ((long)((((int)(j)) >> ((int)(j))))) - ((long)((((double)(0)) - ((double)(j)))))))))) * ((long)((((int)(j)) ^ ((int)(0 + 42 * ((long)((((int)(0)) % ((int)(j))))) * ((long)((((int)(j)) << ((int)(0))))) * ((long)((((int)(0)) | ((int)(j))))) + ((long)((((int)(j)) >> ((int)(j))))) - ((long)((((double)(0)) - ((double)(j)))))))))); j < 8; j--)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 41 * ((int)((((int)(*res++)) | ((int)(*res++))))) - ((int)((((int)(*res++)) ^ ((int)(feq (arg0, arg1)))))) + ((short)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) + ((long)((((int)(*res++)) % ((int)(*res++))))) + ((int)((((int)(*res++)) >> ((int)(*res++))))) - ((short)((((int)(*res++)) >> ((int)(feq (arg0, arg1)))))) * ((long)((((int)(feq (arg0, arg1))) << ((int)(feq (arg0, arg1))))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 41 * ((long)((((int)(fne (arg0, arg1))) % ((int)(*res++))))) * ((int)((((int)(*res++)) & ((int)(*res--))))) * ((long)((((int)(*res++)) ^ ((int)(*res++))))) - ((short)((((int)(*res++)) % ((int)(fne (arg0, arg1))))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 41 * ((long)((((int)(*res++)) | ((int)(*res++))))) + ((long)((((int)(flt (arg0, arg1))) << ((int)(flt (arg0, arg1)))))) + ((short)((((int)(flt (arg0, arg1))) % ((int)(*res++))))) + ((int)((((int)(*res++)) | ((int)(*res++))))) - ((long)((((int)(*res++)) & ((int)(flt (arg0, arg1)))))) * ((int)((((int)(*res++)) & ((int)(flt (arg0, arg1)))))) * ((int)((((int)(*res++)) % ((int)(*res++))))) - ((long)((((int)(*res++)) & ((int)(flt (arg0, arg1)))))) + ((short)((((int)(*res++)) | ((int)(*res++)))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 41 - ((int)((((int)(*res--)) & ((int)(fge (arg0, arg1)))))) * ((short)((((int)(fge (arg0, arg1))) | ((int)(*res++))))) + ((short)((((int)(*res++)) >> ((int)(*res++))))) * ((long)((((int)(fge (arg0, arg1))) & ((int)(*res--))))) * ((long)((((int)(fge (arg0, arg1))) << ((int)(*res++)))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 41 * ((int)((((double)(fgt (arg0, arg1))) * ((double)(fgt (arg0, arg1)))))) + ((long)((((int)(fgt (arg0, arg1))) ^ ((int)(*res++))))) - ((short)((((int)(fgt (arg0, arg1))) >> ((int)(*res++))))) * ((short)((((int)(fgt (arg0, arg1))) % ((int)(fgt (arg0, arg1)))))) * ((int)((((int)(fgt (arg0, arg1))) >> ((int)(*res++))))) + ((int)((((int)(fgt (arg0, arg1))) << ((int)(*res++))))) + ((int)((((int)(fgt (arg0, arg1))) | ((int)(*res++))))) + ((short)((((double)(fgt (arg0, arg1))) - ((double)(fgt (arg0, arg1)))))) - ((long)((((int)(*res++)) | ((int)(fgt (arg0, arg1)))))) * ((long)((((double)(fgt (arg0, arg1))) + ((double)(fgt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 + ((short)((((int)(*res++)) ^ ((int)(fle (arg0, arg1)))))) - ((short)((((int)(fle (arg0, arg1))) >> ((int)(*res++))))) + ((short)((((int)(*res++)) | ((int)(*res++))))) + ((int)((((int)(*res++)) >> ((int)(fle (arg0, arg1)))))) + ((short)((((int)(fle (arg0, arg1))) << ((int)(*res++))))) + ((short)((((int)(fle (arg0, arg1))) % ((int)(*res--)))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
