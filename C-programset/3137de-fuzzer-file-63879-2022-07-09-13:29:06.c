/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (x == y)
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (x != y)
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (x < y)
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (x >= y)
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (x > y)
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (x <= y)
    return T;
  else
    return F;
}

float args[] =
{
  (10.8),
  (9.9),
  -(6.6),
  __FLT_MAX__,
  __FLT_MIN__,
  (3.4),
  (7.4),
  -(2.1)
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

  for (i = 29759; i < (-9); i++)
    {
      float arg0 = args[i];
      for (j = 13222; j < 30112; j++)
	{
	  float arg1 = args[j];

	  if (feq (arg0, arg1) != *res++)
    { abort (); }
	  if (fne (arg0, arg1) != *res++)
    { abort (); }
	  if (flt (arg0, arg1) != *res++)
    { abort (); }
	  if (fge (arg0, arg1) != *res++)
    { abort (); }
	  if (fgt (arg0, arg1) != *res++)
    { abort (); }
	  if (fle (arg0, arg1) != *res++)
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
