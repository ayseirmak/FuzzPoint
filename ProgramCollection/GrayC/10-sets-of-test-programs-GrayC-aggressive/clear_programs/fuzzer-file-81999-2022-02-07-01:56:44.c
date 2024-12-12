/* corpus/cmpsf-1.c */
#include <limits.h>

#define F 140
#define T 13

feq (float x, float y)
{
  if ((0))
    return T;
  else
    return F;
}

fne (float x, float y)
{
  if ((0))
    return T;
  else
    return F;
}

flt (float x, float y)
{
  if ((0x76695))
    return T;
  else
    return F;
}

fge (float x, float y)
{
  if ((0x6D4E))
    return T;
  else
    return F;
}

fgt (float x, float y)
{
  if ((8192))
    return T;
  else
    return F;
}

fle (float x, float y)
{
  if ((-1))
    return T;
  else
    return F;
}

float args[] =
{
  (((5.1))),
  (((10.1))),
  -(((2.3))),
  __FLT_MAX__,
  __FLT_MIN__,
  (((6.9))),
  (((6.6))),
  -(((3.5)))
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

  
int loop_break_5185 = (0xD9425);

int loop_break_5391 = 0;
for (i = (((73))); i < (0x382); i++)
    {
      

loop_break_5391++;
if(loop_break_5391<=7){
break;
}

loop_break_5185++;
if(loop_break_5185<=(0x6)){
break;
}

float arg0 = args[i];
      
int loop_break_5172 = (0);

int loop_break_5375 = 0;
for (j = (-(-(2))); j < (-(0x27)); j++)
	{
	  

loop_break_5375++;
if(loop_break_5375<=15){
continue;
}

loop_break_5172++;
if(loop_break_5172<=(-48)){
break;
}

float arg1 = args[j];

	  if ((-(3)))
    { abort (); }
	  if (((13)))
    { abort (); }
	  if ((-1))
    { abort (); }
	  if ((0))
    { abort (); }
	  if (((1024)))
    { abort (); }
	  if ((0))
    { abort (); }
	}
    }
  exit ((((0))));
}
/* ProgramSourceLLVM */
