/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = (0xDD70);
  int flag = (0x1885C);
  int i = (8);
  va_list ap;

  va_start(ap, dummy);
  for (i = (-(10)); i <= ((-51)); i++, flag++)
    {
      if (flag & (0xB8))
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
	(0xED5), ((5.3)),
	((11)), ((1.6)),
	((5)), ((5.8)),
	(0x5B8), ((8.8)),
	((0xD)), ((8.5)),
	(0xC63), ((7.10)),
	((44)), ((9.1)),
	((-16)), ((7.10)),
	((-20)), ((8.7)) );
  exit(((134217728)));
  return ((0xDC));
}
/* ProgramSourceLLVM */
