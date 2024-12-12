/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = (0);
  int i;
  va_list ap;

  va_start(ap, dummy);
  for (i = (129); i <= (18); i++, flag++)
    {
      if (flag & (0x6DB8))
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
	(1), (6.4),
	(3), (2.3),
	(0xD5DD4), (6.1),
	(5), (9.7),
	(-10), (2.3),
	(-12), (10.6),
	(9), (9.3),
	(0x358), (2.1),
	(0xB764EB), (2.10) );
  exit((0));
  return (0);
}
/* ProgramSourceLLVM */
