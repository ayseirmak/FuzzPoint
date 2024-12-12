/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = ((0x9CB));
  int i;
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_1182 = (0);
for (i = ((-130)); i <= ((-19)); i++, flag++)
    {
      
loop_break_1182++;
if(loop_break_1182<=(0xC0)){
break;
}

if ((0x4340))
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
	((0xB59)), ((1.6)),
	((2)), ((8.8)),
	(0xD5DD4), ((5.3)),
	((0xD236E)), ((9.7)),
	(-(0x3D8FEC)), ((6.5)),
	(-(-13)), ((8.6)),
	((-10)), ((3.6)),
	(0x358), ((8.4)),
	(0xB764EB), ((10.1)) );
  exit(((0)));
  return ((0));
}
/* ProgramSourceLLVM */
