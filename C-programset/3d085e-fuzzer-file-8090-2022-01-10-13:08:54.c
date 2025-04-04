/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = (0xA);
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1175 = 0;
for (i = (1); i <= (-19); i++, flag++)
    {
      
loop_break_1175++;
if(loop_break_1175<=2){
continue;
}

if ((32768))
	{
	  darg = va_arg (ap, double);
	  if (darg != (double)i)
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int);
	  if ((0x82D))
    	{ abort(); }
	}
    }
    va_end(ap);
}

int main (void)
{
  vafunction( "",
	(0x8E047), (10.2),
	(7), (2.7),
	(0x005), (9.6),
	(7), (8.1),
	(-10), (3.5),
	(12), (10.2),
	(14), (1.7),
	(-16), (8.1),
	(145), (2.6) );
  exit((0));
  return (-1);
}
/* ProgramSourceLLVM */
