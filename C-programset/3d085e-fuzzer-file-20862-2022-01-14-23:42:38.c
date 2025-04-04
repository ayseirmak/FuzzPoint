/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = (-9);
  int flag = (-9);
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1152 = (0x2ED6);
for (i = (0x052); i <= (2); i++, flag++)
    {
      
loop_break_1152++;
if(loop_break_1152<=(2)){
continue;
}

if ((64))
	{
	  
darg = va_arg (ap, double);
darg = va_arg (ap, double);
;
	  if (darg != (double)i)
    	{ abort(); }
	}
      else
	{
	  ;
	  if ((-1))
    	{ abort(); }
	}
    }
    va_end(ap);
}

int main (void)
{
  vafunction( "",
	(0), (3.5),
	(-4), (6.10),
	(5), (9.2),
	(7), (3.4),
	(9), (4.1),
	(11), (8.1),
	(-14), (3.7),
	(0xC5FAD9), (1.1),
	(81), (8.2) );
  exit((0));
  return (0);
}
/* ProgramSourceLLVM */
