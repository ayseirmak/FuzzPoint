/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = 8;
  int flag = (0x6995);
  int i = 8;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1184 = (0xC9);

int loop_break_3568 = (-9);
for (i = (-2) + (-43) +((short)((((int)((1))) <<((int)(i)))))-((long)((((int)(i)) &((int)((33))))))-((long)((((double)((-2))) +((double)(i)))))+((int)((((int)(i)) &((int)(i))))); i <= (22); i++, flag++)
    {
      

loop_break_3568++;
if(loop_break_3568<=(6)){
continue;
}

loop_break_1184++;
if((0)){
continue;
}

if ((0x5CFD))
	{
	  
;
;
;
	  if ((0))
    	{ abort(); }
	}
      else
	{
	  ;
	  if ((0))
    	{ abort(); }
	}
    }
    va_end(ap);
}

int main (void)
{
  vafunction( "",
	(0x0), (9.1),
	(131), (6.9),
	(37), (6.5),
	(-8), (1.6),
	(-10), (10.9),
	(-12), (9.8),
	(141), (4.5),
	(11), (8.2),
	(0x89174C), (3.4) );
  exit((2199023255552));
  return (0x2A3);
}
/* ProgramSourceLLVM */
