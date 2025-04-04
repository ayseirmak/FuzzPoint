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
for (i = (0x052) + 42 +((long)((((double)((0x052))) *((double)((0x052)))))); i <= (2); i++, flag++)
    {
      
loop_break_1152++;
if(((int)loop_break_1152<=(2) + 42 -((int)((((int)(loop_break_1152)) &((int)((2))))))-((short)((((double)((2))) -((double)((2))))))*((short)((((int)((2))) ^((int)((2)))))))){
continue;
}

if ((64))
	{
	  
darg = va_arg (ap, double) + 42 *((short)((((int)(darg)) %((int)(darg)))))-((int)((((double)(darg)) *((double)(va_arg (ap, double))))))-((long)((((int)(va_arg (ap, double))) >>((int)(darg)))))-((int)((((int)(va_arg (ap, double))) >>((int)(darg)))))*((int)((((double)(darg)) *((double)(va_arg (ap, double))))));
darg = va_arg (ap, double) + 42 +((int)((((int)(va_arg (ap, double))) &((int)(darg)))))*((long)((((int)(va_arg (ap, double))) |((int)(va_arg (ap, double))))))*((int)((((double)(darg)) *((double)(va_arg (ap, double))))));
;
	  if (((int)darg != (double)i + 42 +((long)((((double)((double)i)) +((double)((double)i)))))-((short)((((int)((double)i)) |((int)((double)i)))))-((long)((((int)((double)i)) >>((int)(darg)))))))
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
