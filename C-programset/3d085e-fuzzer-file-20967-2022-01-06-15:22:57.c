/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = (64);
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1164 = (-1);
for (i = (0x787); i <= (18); i++, flag++)
    {
      
loop_break_1164++;
if(loop_break_1164<=(0x156)){
continue;
}

if (flag & (5))
	{
	  darg = va_arg (ap, double);
	  if (darg != (double)i)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
	  if ((0))
    	{ abort(); }
	}
    }
    va_end(ap);
}

int main (void)
{
  vafunction( "",
	(0xC077), (10.5),
	(-4), (5.5),
	(-6), (6.7),
	(-8), (9.4),
	(9), (2.6),
	(27), (10.6),
	(-14), (9.8),
	(15), (4.10),
	(0x38A9), (6.1) );
  exit((1073741824));
  return (1073741824);
}
/* ProgramSourceLLVM */
