/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 42 +((long)((((int)(x)) ^((int)(x)))))-((short)((((int)(y)) >>((int)(x)))))-((short)((((int)(x)) &((int)(y)))))+((int)((((double)(x)) +((double)(x)))))*((long)((((int)(x)) &((int)(y)))))*((int)((((double)(x)) -((double)(y)))))+((long)((((double)(x)) +((double)(x)))))*((int)((((int)(y)) >>((int)(y)))))))
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
  if (((int)x < y + 42 *((short)((((int)(y)) &((int)(y)))))*((short)((((double)(x)) -((double)(y)))))-((int)((((double)(x)) -((double)(y)))))-((short)((((double)(x)) +((double)(y)))))*((int)((((int)(y)) <<((int)(y)))))*((long)((((int)(y)) >>((int)(y)))))*((short)((((double)(x)) *((double)(y)))))+((long)((((double)(x)) -((double)(y)))))*((short)((((double)(y)) *((double)(y)))))-((int)((((double)(x)) *((double)(x)))))))
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

  for (i = 0 + 42 +((short)((((double)(0)) +((double)(0))))); i < 8; i++)
    {
      float arg0 = args[i];
      for (j = 0 + 42 -((int)((((int)(0)) ^((int)(j)))))*((long)((((double)(0)) +((double)(0)))))-((long)((((int)(j)) >>((int)(0)))))*((int)((((double)(0)) +((double)(0)))))-((int)((((int)(0)) %((int)(j))))); j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 42 -((long)((((int)(feq (arg0, arg1))) %((int)(feq (arg0, arg1))))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 42 *((int)((((double)(fne (arg0, arg1))) *((double)(fne (arg0, arg1))))))+((long)((((int)(*res++)) &((int)(*res++)))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 42 +((short)((((int)(flt (arg0, arg1))) &((int)(*res++)))))+((int)((((double)(flt (arg0, arg1))) -((double)(flt (arg0, arg1))))))+((int)((((int)(flt (arg0, arg1))) <<((int)(*res++)))))-((int)((((int)(*res++)) >>((int)(flt (arg0, arg1))))))-((int)((((int)(*res++)) ^((int)(flt (arg0, arg1))))))*((long)((((int)(flt (arg0, arg1))) >>((int)(*res++)))))+((short)((((int)(flt (arg0, arg1))) <<((int)(*res++)))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 42 -((short)((((int)(*res++)) |((int)(fge (arg0, arg1))))))*((long)((((int)(*res++)) >>((int)(fge (arg0, arg1))))))-((long)((((int)(fge (arg0, arg1))) ^((int)(*res++)))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 42 -((int)((((int)(*res++)) &((int)(*res++)))))+((long)((((int)(fgt (arg0, arg1))) >>((int)(*res++)))))-((long)((((int)(*res++)) <<((int)(fgt (arg0, arg1))))))*((short)((((int)(*res++)) %((int)(*res++)))))*((long)((((int)(fgt (arg0, arg1))) <<((int)(*res++)))))*((short)((((int)(*res++)) %((int)(fgt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 42 *((long)((((int)(fle (arg0, arg1))) <<((int)(fle (arg0, arg1))))))*((short)((((int)(fle (arg0, arg1))) %((int)(fle (arg0, arg1))))))*((int)((((int)(*res++)) ^((int)(fle (arg0, arg1))))))*((long)((((int)(*res++)) |((int)(fle (arg0, arg1))))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
