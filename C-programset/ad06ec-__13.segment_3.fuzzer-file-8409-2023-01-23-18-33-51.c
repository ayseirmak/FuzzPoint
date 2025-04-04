/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if (((int)x == y + 41 + ((int)((((int)(y)) >> ((int)(x))))) * ((int)((((double)(x)) + ((double)(y)))))))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if (((int)x != y + 41 * ((long)((((double)(x)) + ((double)(x))))) - ((short)((((double)(x)) - ((double)(y)))))))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if (((int)x < y + 41 * ((short)((((int)(y)) & ((int)(x))))) * ((long)((((double)(x)) + ((double)(y))))) + ((int)((((int)(x)) % ((int)(y))))) * ((int)((((int)(y)) >> ((int)(x))))) * ((int)((((double)(y)) - ((double)(y))))) * ((long)((((int)(y)) << ((int)(y))))) + ((long)((((double)(x)) + ((double)(y))))) - ((short)((((double)(y)) - ((double)(y))))) + ((long)((((int)(y)) << ((int)(y))))) + ((long)((((double)(x)) + ((double)(y)))))))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if (((int)x >= y + 41 - ((int)((((double)(y)) * ((double)(y))))) * ((int)((((double)(y)) - ((double)(x))))) + ((long)((((int)(x)) % ((int)(y)))))))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if (((int)x > y + 41 + ((short)((((double)(x)) - ((double)(y))))) * ((long)((((int)(x)) << ((int)(x))))) + ((short)((((double)(x)) - ((double)(x))))) * ((long)((((double)(x)) + ((double)(y))))) - ((long)((((double)(y)) - ((double)(y))))) * ((long)((((int)(y)) & ((int)(x))))) * ((long)((((int)(x)) & ((int)(y))))) - ((long)((((int)(y)) % ((int)(x)))))))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if (((int)x <= y + 41 + ((int)((((int)(x)) | ((int)(x))))) - ((long)((((double)(y)) + ((double)(x))))) - ((long)((((int)(x)) >> ((int)(x))))) * ((long)((((double)(y)) * ((double)(y))))) + ((int)((((int)(x)) << ((int)(y)))))))
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

  
int loop_break_9597 = 0;

int loop_break_9665 = 0;
for (i = 0; i < 8; i++)
    {
      

loop_break_9665++;
if(loop_break_9665<=46){
continue;
}

loop_break_9597++;
if(loop_break_9597<=2){
break;
}

float arg0 = args[i];
      for (j = 0 + 42 - ((long)((((int)(j)) | ((int)(j))))); j < 8; j++)
	{
	  float arg1 = args[j];

	  if (0)
    { abort (); }
	  if (((int)fne (arg0, arg1) != *res++ + 41 + ((int)((((int)(*res++)) & ((int)(fne (arg0, arg1)))))) + ((short)((((int)(fne (arg0, arg1))) >> ((int)(*res++))))) - ((int)((((int)(*res++)) << ((int)(*res++))))) + ((short)((((int)(*res++)) | ((int)(fne (arg0, arg1)))))) * ((long)((((int)(*res++)) << ((int)(fne (arg0, arg1))))))))
    { abort (); }
	  if (0)
    { abort (); }
	  if (0)
    { abort (); }
	  if (0)
    { abort (); }
	  if (0)
    { abort (); }
	}
    }
  exit (0);
}
/* ProgramSourceLLVM */
