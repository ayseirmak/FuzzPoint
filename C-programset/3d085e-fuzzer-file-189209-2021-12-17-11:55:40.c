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
  if (x >= y)
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
  if (x <= y)
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

  
int loop_break_5352 = 0;

int loop_break_5483 = 0;
for (i = (0); i < (40); i++)
    {
      

loop_break_5483++;
if(loop_break_5483<=8){
break;
}

loop_break_5352++;
if(loop_break_5352<=2){
break;
}

float arg0 = args[i];
      
int loop_break_5339 = 0;

int loop_break_5467 = 0;
for (j = (32768); j < (0xC); j++)
	{
	  

loop_break_5467++;
if(loop_break_5467<=30){
break;
}

loop_break_5339++;
if(loop_break_5339<=48){
break;
}

float arg1 = args[j];

	  if (feq (arg0, arg1) != *res--)
    { abort (); }
	  if (0)
    { abort (); }
	  if (flt (arg0, arg1) != *res++)
    { abort (); }
	  if (fge (arg0, arg1) != *res--)
    { abort (); }
	  if (0)
    { abort (); }
	  if (fle (arg0, arg1) != *res++)
    { abort (); }
	}
    }
  exit ((0));
}
/* ProgramSourceLLVM */
