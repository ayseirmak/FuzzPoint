/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if ((0x58))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if ((-1))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)x < y + (0x125266) -((short)((((int)(y)) &((int)(x)))))-((short)((((double)(y)) -((double)(x)))))-((short)((((int)(x)) %((int)(y)))))+((long)((((double)(x)) -((double)(x)))))-((int)((((double)(y)) *((double)(y)))))*((int)((((int)(y)) ^((int)(x)))))-((short)((((double)(x)) -((double)(y)))))*((int)((((double)(y)) *((double)(x)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if ((562949953421312))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + (0x90A) -((short)((((int)(y)) <<((int)(x)))))*((int)((((double)(y)) -((double)(y)))))-((long)((((int)(x)) &((int)(x)))))*((int)((((double)(x)) *((double)(y)))))+((int)((((double)(x)) *((double)(y)))))+((long)((((int)(y)) %((int)(y)))))-((int)((((double)(x)) -((double)(x)))))-((long)((((double)(x)) -((double)(y)))))-((long)((((int)(x)) >>((int)(y)))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + (170) *((int)((((int)(x)) <<((int)(x)))))))
    return T;
  else
    return F;
}

float args[] =
{
  (5.7),
  (3.5),
  -(4.2),
  __FLT_MAX__,
  __FLT_MIN__,
  (3.6),
  (6.6),
  -(10.4)
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

  for (i = (0) + (0xEB5) +((int)((((int)((-1))) &((int)((0))))))*((long)((((double)((0))) -((double)((0))))))*((short)((((int)((1125899906842624))) |((int)(i))))); i < (0x6D0); i++)
    {
      float arg0 = args[i];
      for (j = (0) + (34) -((short)((((double)(j)) *((double)((4096))))))+((long)((((double)((1048576))) +((double)(j))))); j < (0x593BB); j++)
	{
	  float arg1 = args[j];

	  if ((0))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + (0x71B80F) *((short)((((int)(*res++)) %((int)(fne (arg0, arg1))))))*((int)((((int)(*res++)) >>((int)(fne (arg0, arg1))))))-((long)((((int)(*res--)) ^((int)(*res++)))))*((long)((((int)(fne (arg0, arg1))) %((int)(*res++)))))-((int)((((int)(*res--)) ^((int)(*res++)))))-((long)((((int)(*res++)) &((int)(fne (arg0, arg1))))))))
    { abort (); }
	  if ((-1))
    { abort (); }
	  if ((0))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res-- + (42) *((int)((((double)(fgt (arg0, arg1))) +((double)(fgt (arg0, arg1))))))*((long)((((int)(fgt (arg0, arg1))) |((int)(fgt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + (170) +((int)((((double)(fle (arg0, arg1))) +((double)(fle (arg0, arg1))))))))
    { abort (); }
	}
    }
  exit ((0));
}
/* ProgramSourceLLVM */
