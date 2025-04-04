/* corpus/va-arg-15.c */
#include <stdarg.h>

void vafunction (char *dummy, ...)
{
  double darg;
  int iarg = (-9);
  int flag = (12);
  int i = (-9);
  va_list ap;

  va_start(ap, dummy);
  
int loop_break_3750 = (24);

int loop_break_3809 = (4096);
for (i = (-2) + (46) +((long)((((int)(i)) %((int)(i)))))+((int)((((double)(i)) -((double)(i)))))-((short)((((double)(i)) -((double)((-2))))))+((short)((((int)(i)) %((int)((-2)))))) + (-43) -((long)((((double)(i)) *((double)(i)))))*((long)((((int)(i)) %((int)(i)))))-((short)((((int)(i)) %((int)((1) + (0xAF) +((long)((((int)(i)) %((int)(i)))))+((int)((((double)(i)) -((double)(i)))))-((short)((((double)(i)) -((double)((1))))))+((short)((((int)(i)) %((int)((17))))))))))); i <= (22); i++, flag++)
    {
      

loop_break_3809++;
if(((int)loop_break_3809<=(18) + (0x192F) +((int)((((double)((130))) *((double)(loop_break_3809)))))*((long)((((int)(loop_break_3809)) ^((int)(loop_break_3809)))))-((long)((((double)((6))) +((double)((2)))))))){
break;
}

loop_break_3750++;
if((-1)){
continue;
}

if ((-1))
	{
	  darg = va_arg (ap, double) + (34) *((short)((((double)(darg)) *((double)(va_arg (ap, double))))))+((long)((((int)(darg)) >>((int)(va_arg (ap, double)))))) + (42) +((short)((((int)(((long)((((int)(darg)) >>((int)(va_arg (ap, double)))))))) >>((int)(va_arg (ap, double) + (42) *((short)((((double)(darg)) *((double)(va_arg (ap, double))))))+((long)((((int)(darg)) >>((int)(va_arg (ap, double)))))))))))*((long)((((int)((0x54) *((short)((((double)(darg)) *((double)(va_arg (ap, double)))))))) <<((int)(va_arg (ap, double) + (0xA55364) *((short)((((double)(darg)) *((double)(va_arg (ap, double))))))+((long)((((int)(darg)) >>((int)(va_arg (ap, double)))))))))));
	  if (((int)((int)darg != (double)i + (22) -((long)((((double)((double)i)) -((double)(darg)))))+((long)((((double)(darg)) *((double)(darg)))))-((short)((((int)((double)i)) >>((int)((double)i)))))-((int)((((double)(darg)) *((double)((double)i)))))) + (46) +((int)((((int)(((long)((((double)(darg)) *((double)(darg))))))) |((int)((double)i + (10) -((long)((((double)((double)i)) -((double)(darg))))))))))+((int)((((double)((double)i + (40))) -((double)((int)darg)))))+((long)((((int)((double)i + (43) -((long)((((double)((double)i)) -((double)(darg)))))+((long)((((double)(darg)) *((double)(darg)))))-((short)((((int)((double)i)) >>((int)((double)i)))))-((int)((((double)(darg)) *((double)((double)i))))))) ^((int)(((int)((((double)(darg)) *((double)((double)i))))))))))))
    	{ abort(); }
	}
      else
	{
	  iarg = va_arg (ap, int) + (-43) +((long)((((double)(va_arg (ap, int))) +((double)(va_arg (ap, int)))))) + (0x9E2) +((short)((((double)(va_arg (ap, int) + (42) +((long)((((double)(va_arg (ap, int))) +((double)(va_arg (ap, int)))))))) -((double)(iarg)))))*((long)((((double)(iarg)) +((double)(iarg)))))+((int)((((int)(iarg)) <<((int)(va_arg (ap, int) + (-43) +((long)((((double)(va_arg (ap, int))) +((double)(va_arg (ap, int)))))))))));
	  if ((4))
    	{ abort(); }
	}
    }
    va_end(ap);
}

int main (void)
{
  vafunction( "",
	(-2), (10.6),
	(0x971D7), (10.7),
	(5), (3.9),
	(6), (8.6),
	(-10), (10.2),
	(3), (7.3),
	(13), (4.2),
	(05), (4.10),
	(19), (10.5) );
  exit((8388608));
  return (0xC);
}
/* ProgramSourceLLVM */
