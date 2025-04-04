/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 42 +((short)((((double)(x)) -((double)(y)))))-((long)((((int)(x)) &((int)(x)))))-((short)((((int)(x)) <<((int)(x)))))*((int)((((double)(x)) -((double)(y)))))*((int)((((double)(y)) *((double)(x)))))*((short)((((double)(y)) -((double)(y)))))*((short)((((double)(y)) -((double)(y)))))+((int)((((double)(x)) *((double)(x)))))-((long)((((double)(y)) *((double)(y)))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)x != y + 42 +((int)((((double)(y)) +((double)(x)))))*((long)((((double)(y)) *((double)(y)))))-((short)((((int)(x)) <<((int)(y)))))-((int)((((double)(y)) *((double)(x)))))+((long)((((double)(x)) -((double)(x)))))+((short)((((int)(y)) >>((int)(x)))))*((short)((((int)(y)) >>((int)(y)))))+((short)((((int)(x)) >>((int)(x)))))+((int)((((int)(x)) ^((int)(x)))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)x < y + 42 *((long)((((double)(y)) +((double)(x)))))+((long)((((int)(x)) |((int)(x)))))*((short)((((double)(x)) +((double)(x)))))+((int)((((double)(x)) +((double)(y)))))+((short)((((double)(y)) -((double)(y)))))-((short)((((double)(y)) +((double)(y)))))*((short)((((int)(y)) <<((int)(y)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)x >= y + 42 +((short)((((int)(y)) <<((int)(y)))))+((long)((((double)(x)) -((double)(x)))))+((long)((((int)(x)) |((int)(x)))))*((long)((((double)(x)) *((double)(x)))))+((int)((((double)(x)) *((double)(x)))))+((short)((((double)(x)) *((double)(y)))))-((int)((((int)(x)) %((int)(x)))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + 42 -((int)((((int)(y)) <<((int)(x)))))*((long)((((double)(x)) *((double)(x)))))-((short)((((int)(y)) <<((int)(y)))))+((long)((((double)(x)) +((double)(x)))))+((long)((((int)(x)) <<((int)(x)))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 42 *((short)((((double)(y)) -((double)(x)))))+((long)((((double)(y)) *((double)(y)))))-((short)((((double)(x)) -((double)(y)))))))
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
for (i = 0 + 42 *((short)((((double)(0)) +((double)(0))))); i < 8; i++)
    {
      
loop_break_5433++;
if(((int)loop_break_5433<=8 + 42 -((long)((((int)(8)) >>((int)(8)))))-((int)((((int)(8)) >>((int)(8)))))*((long)((((double)(8)) -((double)(8)))))*((int)((((double)(8)) *((double)(loop_break_5433)))))+((long)((((int)(8)) >>((int)(loop_break_5433)))))-((int)((((double)(loop_break_5433)) -((double)(loop_break_5433))))))){
continue;
}

float arg0 = args[i];
      
int loop_break_5420 = 0;
for (j = 0 + 42 *((long)((((int)(0)) &((int)(j)))))*((short)((((int)(0)) ^((int)(j)))))*((int)((((int)(0)) >>((int)(j))))); j < 8; j++)
	{
	  
loop_break_5420++;
if(((int)loop_break_5420<=34 + 42 -((long)((((double)(loop_break_5420)) *((double)(loop_break_5420)))))-((short)((((int)(34)) ^((int)(loop_break_5420)))))-((short)((((int)(loop_break_5420)) ^((int)(loop_break_5420)))))-((int)((((int)(34)) >>((int)(34)))))+((long)((((double)(34)) +((double)(34))))))){
break;
}

float arg1 = args[j];

	  if (((int)feq (arg0, arg1) != *res++ + 42 +((short)((((int)(*res++)) >>((int)(*res++)))))+((int)((((double)(feq (arg0, arg1))) *((double)(feq (arg0, arg1))))))+((int)((((int)(*res++)) >>((int)(feq (arg0, arg1))))))*((long)((((int)(feq (arg0, arg1))) %((int)(*res++)))))-((int)((((int)(feq (arg0, arg1))) ^((int)(*res++)))))*((long)((((int)(feq (arg0, arg1))) %((int)(*res++)))))+((long)((((int)(feq (arg0, arg1))) |((int)(*res++)))))*((long)((((int)(*res++)) &((int)(feq (arg0, arg1))))))*((int)((((int)(feq (arg0, arg1))) &((int)(*res++)))))))
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 42 +((long)((((int)(*res++)) ^((int)(fne (arg0, arg1))))))*((int)((((double)(fne (arg0, arg1))) +((double)(fne (arg0, arg1))))))+((int)((((int)(fne (arg0, arg1))) >>((int)(fne (arg0, arg1))))))*((long)((((int)(*res++)) |((int)(fne (arg0, arg1))))))-((long)((((int)(fne (arg0, arg1))) ^((int)(*res++)))))*((int)((((int)(fne (arg0, arg1))) |((int)(*res++)))))-((long)((((int)(fne (arg0, arg1))) <<((int)(*res++)))))-((long)((((int)(*res++)) >>((int)(fne (arg0, arg1))))))))
    { abort (); }
	  if (((int)flt (arg0, arg1) != *res++ + 42 +((int)((((double)(flt (arg0, arg1))) -((double)(flt (arg0, arg1))))))*((long)((((double)(flt (arg0, arg1))) *((double)(flt (arg0, arg1))))))-((int)((((double)(flt (arg0, arg1))) *((double)(flt (arg0, arg1))))))*((long)((((int)(flt (arg0, arg1))) %((int)(flt (arg0, arg1))))))+((long)((((int)(*res++)) &((int)(*res++)))))))
    { abort (); }
	  if (((int)fge (arg0, arg1) != *res++ + 42 +((long)((((int)(*res++)) ^((int)(*res++)))))+((int)((((int)(fge (arg0, arg1))) >>((int)(*res++)))))+((short)((((int)(fge (arg0, arg1))) >>((int)(fge (arg0, arg1))))))+((int)((((int)(fge (arg0, arg1))) ^((int)(*res++)))))+((long)((((int)(*res++)) ^((int)(fge (arg0, arg1))))))*((short)((((int)(*res++)) %((int)(fge (arg0, arg1))))))+((int)((((int)(*res++)) %((int)(fge (arg0, arg1))))))*((int)((((int)(fge (arg0, arg1))) |((int)(*res++)))))-((long)((((int)(*res++)) &((int)(fge (arg0, arg1))))))))
    { abort (); }
	  if (((int)fgt (arg0, arg1) != *res++ + 42 *((short)((((int)(*res++)) <<((int)(*res++)))))+((short)((((int)(*res++)) |((int)(fgt (arg0, arg1))))))*((int)((((int)(fgt (arg0, arg1))) %((int)(*res++)))))-((long)((((double)(fgt (arg0, arg1))) +((double)(fgt (arg0, arg1))))))))
    { abort (); }
	  if (((int)fle (arg0, arg1) != *res++ + 42 *((int)((((int)(fle (arg0, arg1))) %((int)(*res++)))))-((short)((((int)(*res++)) ^((int)(fle (arg0, arg1))))))))
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
