/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 42 -((short)((((double)(x)) +((double)(y)))))-((int)((((double)(y)) +((double)(y)))))+((int)((((int)(x)) >>((int)(x)))))+((int)((((int)(y)) |((int)(x)))))-((int)((((double)(y)) -((double)(x)))))*((int)((((int)(y)) ^((int)(x)))))+((long)((((int)(y)) &((int)(y)))))+((long)((((int)(x)) &((int)(x)))))+((int)((((int)(y)) |((int)(y)))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)x != y + 42 +((long)((((double)(y)) *((double)(x)))))+((long)((((int)(y)) %((int)(x)))))+((int)((((int)(y)) ^((int)(y)))))*((long)((((int)(x)) &((int)(x)))))-((long)((((int)(y)) <<((int)(x)))))*((short)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) ^((int)(y)))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)x < y + 42 -((short)((((int)(y)) &((int)(x)))))-((short)((((double)(y)) -((double)(x)))))-((short)((((int)(x)) %((int)(y)))))+((long)((((double)(x)) -((double)(x)))))-((int)((((double)(y)) *((double)(y)))))*((int)((((int)(y)) ^((int)(x)))))-((short)((((double)(x)) -((double)(y)))))*((int)((((double)(y)) *((double)(x)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)x >= y + 42 *((int)((((double)(y)) *((double)(y)))))*((short)((((int)(y)) |((int)(y)))))-((int)((((int)(x)) &((int)(x)))))+((short)((((int)(x)) &((int)(y)))))*((long)((((int)(y)) <<((int)(x)))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + 42 -((short)((((int)(y)) <<((int)(x)))))*((int)((((double)(y)) -((double)(y)))))-((long)((((int)(x)) &((int)(x)))))*((int)((((double)(x)) *((double)(y)))))+((int)((((double)(x)) *((double)(y)))))+((long)((((int)(y)) %((int)(y)))))-((int)((((double)(x)) -((double)(x)))))-((long)((((double)(x)) -((double)(y)))))-((long)((((int)(x)) >>((int)(y)))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 42 *((int)((((int)(x)) <<((int)(x)))))))
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

  for (i = 0 + 42 +((int)((((int)(0)) &((int)(0)))))*((long)((((double)(0)) -((double)(0)))))*((short)((((int)(0)) |((int)(i))))); i < 8; i++)
    {
      float arg0 = args[i];
      for (j = 0 + 42 -((short)((((double)(j)) *((double)(0)))))+((long)((((double)(0)) +((double)(j))))); j < 8; j++)
	{
	  float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 42 -((int)((((double)(feq (arg0, arg1))) +((double)(feq (arg0, arg1))))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 42 *((short)((((int)(*res++)) %((int)(fne (arg0, arg1))))))*((int)((((int)(*res++)) >>((int)(fne (arg0, arg1))))))-((long)((((int)(*res++)) ^((int)(*res++)))))*((long)((((int)(fne (arg0, arg1))) %((int)(*res++)))))-((int)((((int)(*res++)) ^((int)(*res++)))))-((long)((((int)(*res++)) &((int)(fne (arg0, arg1))))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 42 *((short)((((int)(flt (arg0, arg1))) |((int)(*res++)))))-((short)((((int)(*res++)) |((int)(flt (arg0, arg1))))))-((short)((((int)(*res++)) %((int)(*res++)))))-((long)((((int)(flt (arg0, arg1))) ^((int)(*res++)))))-((long)((((double)(flt (arg0, arg1))) -((double)(flt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 42 *((short)((((int)(*res++)) >>((int)(fge (arg0, arg1))))))-((long)((((int)(*res++)) &((int)(*res++)))))-((long)((((double)(fge (arg0, arg1))) *((double)(fge (arg0, arg1))))))*((long)((((int)(fge (arg0, arg1))) >>((int)(fge (arg0, arg1))))))*((long)((((int)(fge (arg0, arg1))) &((int)(*res++)))))-((int)((((int)(fge (arg0, arg1))) &((int)(*res++)))))-((long)((((int)(fge (arg0, arg1))) &((int)(*res++)))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 42 *((int)((((double)(fgt (arg0, arg1))) +((double)(fgt (arg0, arg1))))))*((long)((((int)(fgt (arg0, arg1))) |((int)(fgt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 42 +((int)((((double)(fle (arg0, arg1))) +((double)(fle (arg0, arg1))))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
