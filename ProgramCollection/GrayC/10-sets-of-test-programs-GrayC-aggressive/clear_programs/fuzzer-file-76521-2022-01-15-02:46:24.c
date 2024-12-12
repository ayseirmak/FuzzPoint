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
  exit (((0)));
  return &ap;
}

void
bar (int i, ...)
{
  va_start (ap, i);
  f = va_arg (*foo (), float) + ((42)) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))-((long)((((int)(va_arg (*foo (), float))) ^((int)(f)))))-((long)((((int)(f)) %((int)(f))))) + (0xF3) -((int)((((int)(((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))) <<((int)(f)))))-((long)((((int)(((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))) &((int)((-(43)) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))))))-((long)((((int)(va_arg (*foo (), float) + (0x785) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))-((long)((((int)(va_arg (*foo (), float))) ^((int)(f)))))-((long)((((int)(f)) %((int)(f))))))) >>((int)(va_arg (*foo (), float)))))) + (0x252915) *((short)((((int)(((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))) |((int)(((long)((((int)(f)) %((int)(f))))))))))*((int)((((int)(va_arg (*foo (), float) + ((58)) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))-((long)((((int)(va_arg (*foo (), float))) ^((int)(f)))))-((long)((((int)(f)) %((int)(f))))))) ^((int)(va_arg (*foo (), float) + ((58)) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))-((long)((((int)(va_arg (*foo (), float))) ^((int)(f)))))-((long)((((int)(f)) %((int)(f))))) + (0xAEA) -((int)((((int)(((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))) <<((int)(f)))))-((long)((((int)(((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))) &((int)((-(43)) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))))))))))))+((long)((((int)(f)) >>((int)(((int)((((int)(((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))) <<((int)(f))))))))))*((long)((((int)(va_arg (*foo (), float) + ((-13)) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))-((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))) %((int)(f)))))+((short)((((int)(va_arg (*foo (), float) + (0xBA) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))-((long)((((int)(va_arg (*foo (), float))) ^((int)(f)))))-((long)((((int)(f)) %((int)(f))))))) |((int)(va_arg (*foo (), float) + (0x05FA3) *((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))-((long)((((int)(va_arg (*foo (), float))) ^((int)(f))))))))));
  va_end (ap);
}

int
main (void)
{
  bar ((0x58D6), (0xB9));
  abort ();
}
/* ProgramSourceLLVM */
