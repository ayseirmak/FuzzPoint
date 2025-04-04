/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = (0xF);
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1204 = 0;
for (i = (17); i <= (19); i++, flag++)
    {
      
loop_break_1204++;
if(loop_break_1204<=4){
break;
}

if (flag & (-2))
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
	(17), (1.3),
	(3), (5.5),
	(-6), (6.1),
	(0x6), (2.6),
	(0x1), (10.3),
	(0x7011B), (5.10),
	(0xBA19), (10.1),
	(15), (6.5),
	(-18), (3.10) );
  exit((0));
  return (0x2);
}
/* ProgramSourceLLVM */
