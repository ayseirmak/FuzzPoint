/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = (8);
  int i;
  va_list ap;

  va_start(ap, dummy);
  for (i = (0xC4); i <= (-19); i++, flag++)
    {
      if ((0))
	{
	  darg = va_arg (ap, double);
	  if ((262144))
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
	(-2), (4.7),
	(35), (4.5),
	(-6), (1.6),
	(15), (10.2),
	(-10), (10.7),
	(3), (3.9),
	(0x28), (4.1),
	(0x205), (10.8),
	(81), (1.9) );
  exit((0));
  return (-1);
}
/* ProgramSourceLLVM */
