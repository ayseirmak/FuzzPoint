/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = (-1);
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1182 = (0x4);

int loop_break_1242 = (0);

int loop_break_1310 = (0x75EF0);
for (i = (0x84); i <= (82); i++, flag++)
    {
      


loop_break_1310++;
if(loop_break_1310<=(2)){
break;
}

loop_break_1242++;
if(loop_break_1242<=(-6)){
break;
}

loop_break_1182++;
if(loop_break_1182<=(-8)){
continue;
}

if (flag & (33))
	{
	  darg = va_arg (ap, double);
	  if (darg != (double)i)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
	  if (iarg != i)
    	{ abort(); }
	}
    }
    va_end(ap);
}

int main (void)
{
  vafunction( "",
	(-2), (10.2),
	(35), (10.9),
	(37), (8.9),
	(-8), (8.8),
	(0x0), (7.3),
	(11), (2.7),
	(29), (5.8),
	(0x83CFAD), (6.8),
	(-18), (6.6) );
  exit((0));
  return (0);
}
/* ProgramSourceLLVM */
