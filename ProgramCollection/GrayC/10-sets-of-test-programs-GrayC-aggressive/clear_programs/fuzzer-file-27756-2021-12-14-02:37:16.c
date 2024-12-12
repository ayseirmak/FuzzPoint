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
  

f = va_arg (*foo (), float) + (42) +((short)((((int)(f)) <<((int)(va_arg (*foo (), float))))))+((short)((((int)(f)) <<((int)(va_arg (*foo (), float))))))-((long)((((int)(f)) %((int)(va_arg (*foo (), float))))))+((int)((((int)(va_arg (*foo (), float))) ^((int)(f)))))-((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))) + 42 +((int)((((int)(((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) &((int)(va_arg (*foo (), float) + (42) +((short)((((int)(f)) <<((int)(va_arg (*foo (), float))))))+((short)((((int)(f)) <<((int)(va_arg (*foo (), float))))))-((long)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))+((long)((((int)(((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) %((int)(f)))))*((short)((((int)(va_arg (*foo (), float) + (42) +((short)((((int)(f)) <<((int)(va_arg (*foo (), float))))))+((short)((((int)(f)) <<((int)(va_arg (*foo (), float)))))))) ^((int)(va_arg (*foo (), float) + (42) +((short)((((int)(f)) <<((int)(va_arg (*foo (), float)))))))))))+((short)((((int)(((short)((((int)(f)) <<((int)(va_arg (*foo (), float)))))))) >>((int)(((short)((((int)(f)) <<((int)(va_arg (*foo (), float)))))))))))-((int)((((int)(f)) <<((int)(f)))));
f = va_arg (*foo (), float) + (34) -((long)((((int)(va_arg (*foo (), float))) |((int)(f)))))*((int)((((double)(f)) -((double)(f)))))+((short)((((int)(f)) ^((int)(va_arg (*foo (), float))))))-((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))) + 42 -((int)((((int)(((long)((((int)(f)) >>((int)(va_arg (*foo (), float)))))))) ^((int)(va_arg (*foo (), float) + (34))))));
;

f = va_arg (*foo (), float) + (34) +((int)((((int)(f)) &((int)(va_arg (*foo (), float))))))+((int)((((int)(f)) ^((int)(f)))))-((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float)))))) + 42 +((short)((((int)(va_arg (*foo (), float) + (34) +((int)((((int)(f)) &((int)(va_arg (*foo (), float))))))+((int)((((int)(f)) ^((int)(f))))))) ^((int)(va_arg (*foo (), float) + (34) +((int)((((int)(f)) &((int)(va_arg (*foo (), float))))))+((int)((((int)(f)) ^((int)(f)))))-((int)((((int)(f)) <<((int)(va_arg (*foo (), float))))))+((long)((((int)(va_arg (*foo (), float))) <<((int)(va_arg (*foo (), float)))))))))));
f = va_arg (*foo (), float) + (42) +((short)((((double)(f)) +((double)(f)))))*((long)((((int)(va_arg (*foo (), float))) |((int)(va_arg (*foo (), float))))))+((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))-((short)((((int)(va_arg (*foo (), float))) <<((int)(f)))))+((short)((((int)(f)) |((int)(va_arg (*foo (), float)))))) + 42 *((int)((((int)(va_arg (*foo (), float) + (42) +((short)((((double)(f)) +((double)(f)))))*((long)((((int)(va_arg (*foo (), float))) |((int)(va_arg (*foo (), float)))))))) >>((int)(va_arg (*foo (), float) + (42) +((short)((((double)(f)) +((double)(f)))))*((long)((((int)(va_arg (*foo (), float))) |((int)(va_arg (*foo (), float))))))+((int)((((int)(va_arg (*foo (), float))) |((int)(f)))))-((short)((((int)(va_arg (*foo (), float))) <<((int)(f))))))))));
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
