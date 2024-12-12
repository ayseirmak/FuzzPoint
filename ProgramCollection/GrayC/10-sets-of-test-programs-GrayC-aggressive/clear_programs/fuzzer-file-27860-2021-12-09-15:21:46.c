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
  

f = va_arg (*foo (), float) + ((0x9180)) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float)))))) + ((40)) +((int)((((int)(((long)((((double)(f)) -((double)(f))))))) >>((int)((-(-44)))))))+((int)((((int)((-(-44)))) >>((int)(va_arg (*foo (), float) + (-(-44)) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f))))))))))-((short)((((int)(va_arg (*foo (), float) + (0xADD8) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f))))))) &((int)(va_arg (*foo (), float) + (0xF8))))))+((short)((((int)(va_arg (*foo (), float))) ^((int)(((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f))))))))))*((short)((((int)(((long)((((double)(f)) -((double)(f))))))) |((int)(((long)((((int)(f)) ^((int)(va_arg (*foo (), float)))))))))));
f = va_arg (*foo (), float) + (0xE6) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float)))))) + (0xB340) +((int)((((int)(((long)((((double)(f)) -((double)(f))))))) >>((int)((-(43)))))))+((int)((((int)((-(43)))) >>((int)(va_arg (*foo (), float) + ((-171)) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f))))))))))-((short)((((int)(va_arg (*foo (), float) + ((32)) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f))))))) &((int)(va_arg (*foo (), float) + ((50)))))))+((short)((((int)(va_arg (*foo (), float))) ^((int)(((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f))))))))))*((short)((((int)(((long)((((double)(f)) -((double)(f))))))) |((int)(((long)((((int)(f)) ^((int)(va_arg (*foo (), float)))))))))));
;
;
;
  va_end (ap);
}

int
main (void)
{
  bar ((0x3D9), (0x6B));
  abort ();
}
/* ProgramSourceLLVM */
