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
  

f = va_arg (*foo (), float) + (40) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (0xF4) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (106))) %((int)(va_arg (*foo (), float) + (42))))))+((long)((((int)((-43))) <<((int)(va_arg (*foo (), float))))));
f = va_arg (*foo (), float) + (42) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (0xBA63) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (46))) %((int)(va_arg (*foo (), float) + (170))))))+((long)((((int)((10))) <<((int)(va_arg (*foo (), float))))));
;

f = va_arg (*foo (), float) + (42) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (0x9D02CE) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (58))) %((int)(va_arg (*foo (), float) + (42))))))+((long)((((int)((42))) <<((int)(va_arg (*foo (), float))))));
f = va_arg (*foo (), float) + (42) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (106) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (-43))) %((int)(va_arg (*foo (), float) + (58))))))+((long)((((int)((42))) <<((int)(va_arg (*foo (), float))))));
;
;
  va_end (ap);
}

int
main (void)
{
  bar ((-2), (0));
  abort ();
}
/* ProgramSourceLLVM */
