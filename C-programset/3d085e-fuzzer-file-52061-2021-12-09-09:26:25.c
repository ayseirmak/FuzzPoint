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
  exit ((0));
  return &ap;
}

void
bar (int i, ...)
{
  va_start (ap, i);
  

;

f = va_arg (*foo (), float) + (0xA9) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float))))));
f = va_arg (*foo (), float) + (43) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float))))));
;
;


f = va_arg (*foo (), float) + (42) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float))))));
f = va_arg (*foo (), float) + (0x649919) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float))))));
;

f = va_arg (*foo (), float) + (0xE96971) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float))))));
f = va_arg (*foo (), float) + (-43) +((int)((((int)(va_arg (*foo (), float))) >>((int)(f)))))+((long)((((double)(f)) -((double)(f)))))+((long)((((int)(va_arg (*foo (), float))) &((int)(f)))))*((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(f)) ^((int)(va_arg (*foo (), float))))));
;
;
;
  va_end (ap);
}

int
main (void)
{
  bar ((65), (0));
  abort ();
}
/* ProgramSourceLLVM */
