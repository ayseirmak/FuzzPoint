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
  if (((int)x < y + 42 -((short)((((int)(y)) &((int)(x)))))-((short)((((double)(y)) -((double)(x)))))-((short)((((int)(x)) %((int)(y)))))+((long)((((double)(x)) -((double)(x)))))-((int)((((double)(y)) *((double)(y)))))*((int)((((int)(y)) ^((int)(x)))))-((short)((((double)(x)) -((double)(y)))))*((int)((((double)(y)) *((double)(x)))))))
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

	  if (0)
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 42 *((short)((((int)(*res++)) %((int)(fne (arg0, arg1))))))*((int)((((int)(*res++)) >>((int)(fne (arg0, arg1))))))-((long)((((int)(*res++)) ^((int)(*res++)))))*((long)((((int)(fne (arg0, arg1))) %((int)(*res++)))))-((int)((((int)(*res++)) ^((int)(*res++)))))-((long)((((int)(*res++)) &((int)(fne (arg0, arg1))))))))
    { abort (); }
	  if (0)
    { abort (); }
	  if (0)
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
