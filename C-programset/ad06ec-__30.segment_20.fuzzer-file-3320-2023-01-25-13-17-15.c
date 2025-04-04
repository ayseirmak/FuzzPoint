/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)((int)x == y + 41 * ((short)((((int)(x)) | ((int)(y))))) + ((int)((((double)(y)) + ((double)(y))))) - ((short)((((double)(y)) * ((double)(y))))) - ((int)((((double)(x)) + ((double)(x))))) + ((int)((((int)(x)) ^ ((int)(y)))))) + 41 - ((short)((((int)(((int)((((int)(x)) ^ ((int)(y))))))) | ((int)(41 * ((short)((((int)(x)) | ((int)(y)))))))))) + ((long)((((double)(y)) + ((double)(((int)((((double)(x)) + ((double)(x)))))))))) - ((short)((((int)(((int)((((double)(y)) + ((double)(y))))))) ^ ((int)(((int)((((int)(x)) ^ ((int)(y)))))))))) + ((int)((((int)(y + 41 * ((short)((((int)(x)) | ((int)(y))))) + ((int)((((double)(y)) + ((double)(y))))) - ((short)((((double)(y)) * ((double)(y))))) - ((int)((((double)(x)) + ((double)(x))))))) % ((int)(((short)((((double)(y)) * ((double)(y))))))))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)((int)x != y + 41 * ((long)((((double)(x)) * ((double)(y))))) - ((short)((((double)(x)) * ((double)(y))))) * ((long)((((double)(y)) * ((double)(y))))) * ((int)((((int)(y)) & ((int)(y))))) + ((short)((((double)(x)) - ((double)(x))))) - ((short)((((int)(x)) % ((int)(y)))))) + 41 + ((long)((((int)(y)) ^ ((int)(((short)((((double)(x)) * ((double)(y))))) * ((long)((((double)(y)) * ((double)(y))))) * ((int)((((int)(y)) & ((int)(y)))))))))) - ((int)((((int)(((short)((((int)(x)) % ((int)(y))))))) ^ ((int)(y + 41 * ((long)((((double)(x)) * ((double)(y)))))))))) + ((short)((((int)(y + 41 * ((long)((((double)(x)) * ((double)(y))))))) >> ((int)(((short)((((int)(x)) % ((int)(y)))))))))) * ((short)((((int)(41 * ((long)((((double)(x)) * ((double)(y))))))) % ((int)(y + 41 * ((long)((((double)(x)) * ((double)(y))))) - ((short)((((double)(x)) * ((double)(y))))) * ((long)((((double)(y)) * ((double)(y))))) * ((int)((((int)(y)) & ((int)(y))))) + ((short)((((double)(x)) - ((double)(x))))) - ((short)((((int)(x)) % ((int)(y))))))))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)((int)x < y + 41 + ((long)((((double)(x)) - ((double)(x))))) * ((long)((((int)(x)) | ((int)(y))))) - ((short)((((double)(y)) - ((double)(y))))) - ((int)((((int)(x)) << ((int)(y)))))) + 41 * ((int)((((int)(((short)((((double)(y)) - ((double)(y))))))) & ((int)(y))))) + ((long)((((int)(41)) % ((int)(((short)((((double)(y)) - ((double)(y)))))))))) + ((short)((((int)(((long)((((double)(x)) - ((double)(x))))) * ((long)((((int)(x)) | ((int)(y))))))) & ((int)(y + 41))))) * ((long)((((int)(y + 41 + ((long)((((double)(x)) - ((double)(x))))) * ((long)((((int)(x)) | ((int)(y))))) - ((short)((((double)(y)) - ((double)(y))))))) | ((int)(((int)((((int)(x)) << ((int)(y))))))))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)((int)x >= y + 41 * ((long)((((int)(x)) >> ((int)(y))))) * ((short)((((double)(y)) - ((double)(y))))) + ((int)((((int)(y)) >> ((int)(x))))) + ((int)((((double)(x)) + ((double)(y))))) + ((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) % ((int)(x))))) + ((int)((((int)(x)) % ((int)(x))))) - ((long)((((int)(x)) ^ ((int)(y)))))) + 41 * ((long)((((int)(y + 41 * ((long)((((int)(x)) >> ((int)(y))))) * ((short)((((double)(y)) - ((double)(y))))) + ((int)((((int)(y)) >> ((int)(x))))))) & ((int)(y))))) - ((int)((((double)(((long)((((int)(x)) ^ ((int)(y))))))) * ((double)(((int)((((int)(x)) % ((int)(x)))))))))) + ((int)((((int)(((int)((((double)(x)) + ((double)(y))))))) | ((int)(y + 41 * ((long)((((int)(x)) >> ((int)(y))))) * ((short)((((double)(y)) - ((double)(y))))) + ((int)((((int)(y)) >> ((int)(x))))) + ((int)((((double)(x)) + ((double)(y))))) + ((long)((((int)(x)) | ((int)(y))))) * ((long)((((int)(y)) % ((int)(x))))) + ((int)((((int)(x)) % ((int)(x))))) - ((long)((((int)(x)) ^ ((int)(y))))))))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + 41 - ((int)((((int)(x)) | ((int)(x)))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 41 * ((int)((((double)(y)) - ((double)(x))))) - ((int)((((double)(x)) + ((double)(x))))) * ((long)((((int)(x)) | ((int)(y))))) + ((long)((((double)(x)) - ((double)(y))))) * ((int)((((int)(x)) ^ ((int)(y))))) - ((int)((((int)(x)) << ((int)(y)))))))
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

  for (i = 0 + 42 - ((int)((((double)(0)) + ((double)(0))))); i < 8; i++)
    {
      float arg0 = args[i];
      for (j = 0 + 42 + ((int)((((int)(j)) % ((int)(j))))) - ((long)((((int)(j)) >> ((int)(j))))) * ((long)((((double)(0)) - ((double)(0))))) - ((int)((((double)(j)) - ((double)(j))))) + ((short)((((double)(0)) - ((double)(j))))); j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 41 + ((short)((((int)(*res++)) >> ((int)(*res++))))) - ((long)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) * ((short)((((double)(feq (arg0, arg1))) * ((double)(feq (arg0, arg1)))))) * ((short)((((int)(*res++)) << ((int)(*res++))))) + ((long)((((int)(*res++)) & ((int)(*res++))))) + ((int)((((int)(feq (arg0, arg1))) % ((int)(*res++))))) - ((int)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) - ((short)((((int)(feq (arg0, arg1))) >> ((int)(*res++))))) - ((long)((((int)(feq (arg0, arg1))) << ((int)(*res++))))) - ((long)((((int)(feq (arg0, arg1))) << ((int)(*res++)))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 41 + ((long)((((int)(*res++)) | ((int)(*res++))))) * ((int)((((int)(*res++)) ^ ((int)(fne (arg0, arg1)))))) - ((int)((((double)(fne (arg0, arg1))) * ((double)(fne (arg0, arg1)))))) * ((int)((((int)(fne (arg0, arg1))) ^ ((int)(fne (arg0, arg1)))))) * ((long)((((int)(*res++)) & ((int)(fne (arg0, arg1)))))) + ((int)((((int)(*res++)) % ((int)(*res++))))) * ((int)((((int)(fne (arg0, arg1))) % ((int)(*res++))))) + ((long)((((int)(fne (arg0, arg1))) & ((int)(*res++))))) - ((short)((((double)(fne (arg0, arg1))) + ((double)(fne (arg0, arg1))))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 41 * ((long)((((int)(*res++)) ^ ((int)(flt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 41 - ((int)((((int)(*res++)) % ((int)(fge (arg0, arg1)))))) * ((short)((((int)(fge (arg0, arg1))) | ((int)(*res++))))) + ((long)((((int)(fge (arg0, arg1))) >> ((int)(fge (arg0, arg1)))))) - ((int)((((int)(*res++)) >> ((int)(*res++))))) * ((short)((((int)(fge (arg0, arg1))) & ((int)(*res++))))) + ((long)((((int)(fge (arg0, arg1))) | ((int)(fge (arg0, arg1)))))) - ((int)((((int)(fge (arg0, arg1))) | ((int)(*res++))))) - ((int)((((int)(*res++)) << ((int)(*res++)))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 41 + ((int)((((int)(*res++)) ^ ((int)(*res++))))) + ((short)((((int)(*res++)) & ((int)(*res++)))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 - ((int)((((int)(*res++)) ^ ((int)(fle (arg0, arg1)))))) * ((short)((((int)(*res++)) & ((int)(fle (arg0, arg1)))))) - ((short)((((double)(fle (arg0, arg1))) - ((double)(fle (arg0, arg1))))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
