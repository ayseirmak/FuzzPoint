/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = ((-1));
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1182 = ((538968064));
for (i = ((-6)); i <= (-(19)); i++, flag++)
    {
      
loop_break_1182++;
if(loop_break_1182<=(0xD)){
break;
}

if (flag & (0xC2A))
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
	((11)), ((3.7)),
	((27)), ((3.4)),
	(0x603), ((1.7)),
	(0x05BFE), ((6.3)),
	((0x51DE)), ((7.2)),
	((75)), ((4.8)),
	((5)), ((10.3)),
	((14)), ((2.4)),
	((-82)), ((5.10)) );
  exit((-(0)));
  return ((-1));
}
/* ProgramSourceLLVM */
