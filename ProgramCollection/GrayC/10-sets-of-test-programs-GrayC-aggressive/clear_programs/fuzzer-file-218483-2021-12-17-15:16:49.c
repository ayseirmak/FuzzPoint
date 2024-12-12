/* corpus/va-arg-trap-1.c */
/* Undefined behavior from a call to va_arg with a type other than
   that of the argument passed (in particular, with a type such as
   "float" that can never be the type of an argument passed through
   "...") does not appear until after the va_list expression is
   evaluated.  PR 38483.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

#include <stdarg.h>

extern void exit (int);
extern void abort (void);

va_list ap;
float f;

va_list *
foo (void)
{
  exit ((8192));
  return &ap;
}

void
bar (int i, ...)
{
  va_start (ap, i);
  f = va_arg (*foo (), float) + (-43) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))) + (106) -((short)((((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))) &((int)(((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))))))+((short)((((int)(((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))) ^((int)((-43))))))+((int)((((int)(va_arg (*foo (), float) + (42) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))) %((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))))))+((short)((((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))) ^((int)(va_arg (*foo (), float) + (0x8171EE) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))))))*((int)((((int)(va_arg (*foo (), float) + (0x13EC))) <<((int)(f))))) + (0x42) -((short)((((int)(va_arg (*foo (), float) + (0xF60D7C) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))) + (106) -((short)((((int)(va_arg (*foo (), float) + (0x05A2F) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))) &((int)(((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))))))))) |((int)(va_arg (*foo (), float))))))-((short)((((int)(((short)((((int)(va_arg (*foo (), float) + (34) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))) &((int)(((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))))))))) ^((int)(va_arg (*foo (), float) + (0xE6) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))) + (42) -((short)((((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))) &((int)(((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))))))+((short)((((int)(((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))) ^((int)((0xA5A3))))))+((int)((((int)(va_arg (*foo (), float) + (170) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))) %((int)(va_arg (*foo (), float) + (0x12) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))))))+((short)((((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))) ^((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(va_arg (*foo (), float))) >>((int)(f))))))))))*((int)((((int)(va_arg (*foo (), float) + (-43))) <<((int)(f))))))))));
  va_end (ap);
}

int
main (void)
{
  bar ((0x77DED), (0));
  abort ();
}
/* ProgramSourceLLVM */
