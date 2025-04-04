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
  exit ((0x64800));
  return &ap;
}

void
bar (int i, ...)
{
  va_start (ap, i);
  
f = va_arg (*foo (), float) + (42) -((long)((((int)(f)) >>((int)(va_arg (*foo (), float))))))*((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))*((short)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))*((long)((((int)(f)) &((int)(f))))) + (0x6A) -((long)((((double)((46))) -((double)((-43))))))-((int)((((int)((-43))) &((int)((-43))))));
f = va_arg (*foo (), float) + (42) +((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))*((int)((((int)(va_arg (*foo (), float))) <<((int)(f))))) + (0x96CFF) -((long)((((int)(va_arg (*foo (), float) + (42))) |((int)((170))))))-((long)((((int)(va_arg (*foo (), float) + (10) +((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))*((int)((((int)(va_arg (*foo (), float))) <<((int)(f))))))) ^((int)(va_arg (*foo (), float) + (0xD981) +((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))*((int)((((int)(va_arg (*foo (), float))) <<((int)(f))))))))))-((long)((((int)(((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))*((int)((((int)(va_arg (*foo (), float))) <<((int)(f))))))) <<((int)(((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))*((int)((((int)(va_arg (*foo (), float))) <<((int)(f))))))))))+((long)((((int)(f)) >>((int)(va_arg (*foo (), float) + (46) +((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))*((int)((((int)(va_arg (*foo (), float))) <<((int)(f))))))))));
;
  va_end (ap);
}

int
main (void)
{
  bar ((1), (16));
  abort ();
}
/* ProgramSourceLLVM */
