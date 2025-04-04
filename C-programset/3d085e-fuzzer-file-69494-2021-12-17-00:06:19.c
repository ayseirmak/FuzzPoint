/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 42 *((short)((((double)(x)) *((double)(y)))))+((int)((((int)(y)) ^((int)(x)))))*((long)((((int)(x)) &((int)(x)))))-((int)((((double)(y)) *((double)(y)))))))
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
  if (((int)x < y + 42 *((short)((((double)(x)) *((double)(y)))))*((long)((((int)(y)) >>((int)(x)))))*((short)((((int)(y)) >>((int)(x)))))-((int)((((int)(x)) &((int)(x)))))-((long)((((double)(y)) *((double)(y)))))-((short)((((double)(x)) *((double)(y)))))+((int)((((double)(y)) *((double)(x)))))+((int)((((double)(y)) -((double)(x)))))+((int)((((int)(y)) <<((int)(x)))))+((int)((((int)(y)) <<((int)(x)))))))
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
  (10.4),
  (1.7),
  -(6.5),
  __FLT_MAX__,
  __FLT_MIN__,
  (2.9),
  (7.6),
  -(6.5)
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

  for (i = (0) + 42 +((short)((((int)(i)) &((int)((0)))))); i < (40); i++)
    {
      float arg0 = args[i];
      for (j = (32768) + 42 *((long)((((double)((32768))) -((double)((32768))))))-((long)((((double)(j)) +((double)(j)))))+((long)((((int)((32768))) >>((int)((32768))))))*((long)((((int)(j)) <<((int)(j))))); j < (0xC); j++)
	{
	  float arg1 = args[j];

	  if (0)
    { abort (); }
	  if (0)
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 42 *((int)((((int)(flt (arg0, arg1))) >>((int)(flt (arg0, arg1))))))-((int)((((int)(flt (arg0, arg1))) <<((int)(flt (arg0, arg1))))))*((long)((((double)(flt (arg0, arg1))) +((double)(flt (arg0, arg1))))))+((short)((((int)(*res++)) <<((int)(*res++)))))*((short)((((int)(flt (arg0, arg1))) >>((int)(flt (arg0, arg1))))))-((int)((((int)(*res++)) &((int)(*res++)))))-((short)((((int)(flt (arg0, arg1))) |((int)(*res++)))))+((int)((((int)(*res++)) <<((int)(*res++)))))*((long)((((int)(*res++)) |((int)(flt (arg0, arg1))))))))
    { abort (); }
	  if (0)
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 42 -((long)((((int)(fgt (arg0, arg1))) ^((int)(fgt (arg0, arg1))))))-((long)((((int)(*res++)) ^((int)(fgt (arg0, arg1))))))))
    { abort (); }
	  if (0)
    { abort (); }
	}
    }
  exit ((0));
}
/* ProgramSourceLLVM */
