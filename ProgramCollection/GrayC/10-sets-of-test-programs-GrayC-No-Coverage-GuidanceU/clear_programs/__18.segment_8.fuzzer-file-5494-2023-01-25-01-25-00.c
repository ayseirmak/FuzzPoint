/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (0)
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (0)
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
  if (((int)((int)x > y + 41 * ((int)((((double)(x)) - ((double)(y))))) + ((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y)))))) + 41 - ((short)((((int)(41 * ((int)((((double)(x)) - ((double)(y))))))) % ((int)(y))))) - ((int)((((int)((int)x)) ^ ((int)(41 * ((int)((((double)(x)) - ((double)(y)))))))))) - ((int)((((int)(((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y))))))) ^ ((int)(y))))) + ((int)((((int)((int)x)) >> ((int)((int)x))))) + ((short)((((int)(y + 41 * ((int)((((double)(x)) - ((double)(y))))) + ((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y))))))) >> ((int)(y + 41 * ((int)((((double)(x)) - ((double)(y))))) + ((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y)))))))))) * ((short)((((int)(((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y))))))) >> ((int)(y + 41 * ((int)((((double)(x)) - ((double)(y))))) + ((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y)))))))))) * ((int)((((int)(y)) >> ((int)(((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y)))))))))) + ((long)((((int)(y)) ^ ((int)(((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y)))))))))) + ((short)((((int)(y + 41 * ((int)((((double)(x)) - ((double)(y))))))) & ((int)(((int)((((int)(x)) >> ((int)(x))))) * ((short)((((int)(x)) % ((int)(x))))) * ((short)((((double)(y)) * ((double)(y)))))))))) - ((short)((((int)((int)x)) >> ((int)((int)x)))))))
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

  
int loop_break_9418 = 0;
for (i = 0; i < 8; i++)
    {
      
loop_break_9418++;
if(((int)loop_break_9418<=27 + 41 * ((long)((((double)(loop_break_9418)) - ((double)(loop_break_9418))))))){
continue;
}

float arg0 = args[i];
      for (j = 0; j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)((int)feq (arg0, arg1) != *res++ + 41 - ((short)((((int)(*res++)) % ((int)(feq (arg0, arg1)))))) - ((int)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) - ((int)((((int)(*res++)) | ((int)(feq (arg0, arg1)))))) * ((short)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) * ((long)((((int)(*res++)) % ((int)(*res++))))) * ((short)((((int)(*res++)) ^ ((int)(feq (arg0, arg1)))))) + ((int)((((int)(*res++)) ^ ((int)(*res++)))))) + 41 * ((int)((((int)(((int)((((int)(*res++)) | ((int)(feq (arg0, arg1)))))) * ((short)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))))) % ((int)((int)feq (arg0, arg1)))))) * ((short)((((int)(*res++ + 41 - ((short)((((int)(*res++)) % ((int)(feq (arg0, arg1)))))) - ((int)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))))) >> ((int)(((long)((((int)(*res++)) % ((int)(*res++)))))))))) * ((int)((((int)(((int)((((int)(*res++)) | ((int)(feq (arg0, arg1)))))) * ((short)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) * ((long)((((int)(*res++)) % ((int)(*res++))))) * ((short)((((int)(*res++)) ^ ((int)(feq (arg0, arg1)))))))) & ((int)(*res++ + 41 - ((short)((((int)(*res++)) % ((int)(feq (arg0, arg1)))))) - ((int)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) - ((int)((((int)(*res++)) | ((int)(feq (arg0, arg1)))))) * ((short)((((int)(*res++)) & ((int)(feq (arg0, arg1)))))) * ((long)((((int)(*res++)) % ((int)(*res++))))) * ((short)((((int)(*res++)) ^ ((int)(feq (arg0, arg1)))))))))))))
    { abort (); }
	  if (0)
    { abort (); }
	  if (0)
    { abort (); }
	  if (((int)((int)fge (arg0, arg1) != *res++ + 41 * ((int)((((int)(*res++)) % ((int)(*res++))))) + ((long)((((int)(*res++)) % ((int)(*res++))))) - ((long)((((int)(*res++)) | ((int)(fge (arg0, arg1))))))) + 41 + ((int)((((int)(*res++ + 41 * ((int)((((int)(*res++)) % ((int)(*res++))))) + ((long)((((int)(*res++)) % ((int)(*res++))))) - ((long)((((int)(*res++)) | ((int)(fge (arg0, arg1)))))))) % ((int)(((long)((((int)(*res++)) % ((int)(*res++)))))))))) + ((int)((((int)(*res++ + 41 * ((int)((((int)(*res++)) % ((int)(*res++))))) + ((long)((((int)(*res++)) % ((int)(*res++))))) - ((long)((((int)(*res++)) | ((int)(fge (arg0, arg1)))))))) << ((int)((int)fge (arg0, arg1)))))) - ((long)((((int)(*res++ + 41 * ((int)((((int)(*res++)) % ((int)(*res++))))) + ((long)((((int)(*res++)) % ((int)(*res++))))))) << ((int)(*res++ + 41 * ((int)((((int)(*res++)) % ((int)(*res++))))) + ((long)((((int)(*res++)) % ((int)(*res++))))) - ((long)((((int)(*res++)) | ((int)(fge (arg0, arg1)))))))))))))
    { abort (); }
	  if (((int)((int)fgt (arg0, arg1) != *res++ + 41 + ((short)((((int)(*res++)) | ((int)(fgt (arg0, arg1)))))) + ((int)((((int)(fgt (arg0, arg1))) ^ ((int)(*res++))))) - ((int)((((int)(fgt (arg0, arg1))) << ((int)(*res++))))) * ((short)((((int)(fgt (arg0, arg1))) ^ ((int)(fgt (arg0, arg1)))))) * ((int)((((int)(*res++)) << ((int)(*res++)))))) + 41 - ((int)((((int)(*res++ + 41 + ((short)((((int)(*res++)) | ((int)(fgt (arg0, arg1)))))))) & ((int)(*res++ + 41 + ((short)((((int)(*res++)) | ((int)(fgt (arg0, arg1)))))) + ((int)((((int)(fgt (arg0, arg1))) ^ ((int)(*res++)))))))))) + ((int)((((int)(((int)((((int)(fgt (arg0, arg1))) << ((int)(*res++))))) * ((short)((((int)(fgt (arg0, arg1))) ^ ((int)(fgt (arg0, arg1)))))) * ((int)((((int)(*res++)) << ((int)(*res++))))))) << ((int)(((int)((((int)(fgt (arg0, arg1))) << ((int)(*res++)))))))))) - ((int)((((int)(*res++ + 41 + ((short)((((int)(*res++)) | ((int)(fgt (arg0, arg1)))))))) << ((int)(41))))) - ((long)((((int)(((int)((((int)(fgt (arg0, arg1))) << ((int)(*res++))))) * ((short)((((int)(fgt (arg0, arg1))) ^ ((int)(fgt (arg0, arg1)))))) * ((int)((((int)(*res++)) << ((int)(*res++))))))) % ((int)(*res++ + 41)))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 41 + ((long)((((double)(fle (arg0, arg1))) * ((double)(fle (arg0, arg1)))))) + ((int)((((int)(fle (arg0, arg1))) & ((int)(fle (arg0, arg1)))))) + ((long)((((int)(fle (arg0, arg1))) >> ((int)(fle (arg0, arg1)))))) + ((int)((((int)(*res++)) >> ((int)(*res++))))) + ((long)((((int)(fle (arg0, arg1))) >> ((int)(*res++))))) * ((long)((((int)(*res++)) ^ ((int)(fle (arg0, arg1)))))) * ((long)((((int)(*res++)) | ((int)(fle (arg0, arg1)))))) * ((short)((((int)(*res++)) % ((int)(fle (arg0, arg1)))))) + ((int)((((int)(*res++)) << ((int)(*res++))))) - ((int)((((int)(fle (arg0, arg1))) & ((int)(*res++)))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
