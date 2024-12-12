/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = 8;
  int flag = 8;
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1182 = 8;
for (i = (-2); i <= (0x609815); i++, flag++)
    {
      
loop_break_1182++;
if(loop_break_1182<=(0x2B3E5)){
break;
}

if (flag & (1))
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
	(0xA103), (9.6),
	(131), (6.9),
	(0x4263), (3.2),
	(-8), (3.3),
	(9), (10.2),
	(11), (9.3),
	(-14), (7.10),
	(0x3AEBC), (4.2),
	(-18), (4.8) );
  exit((0));
  return (64);
}
/* ProgramSourceLLVM */
