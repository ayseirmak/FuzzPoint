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
  exit ((256));
  return &ap;
}

void
bar (int i, ...)
{
  va_start (ap, i);
  



f = va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float))))))+((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))) + 42 *((int)((((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) <<((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) >>((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))-((short)((((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) %((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))))));
f = va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float))))))+((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))) + 42 *((int)((((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) <<((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) >>((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))-((short)((((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) %((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))))));
;

f = va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float))))))+((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))) + 42 *((int)((((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) <<((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) >>((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))-((short)((((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) %((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))))));
f = va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float))))))+((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))) + 42 *((int)((((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) <<((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) >>((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))-((short)((((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) %((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))))));
;
;


f = va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float))))))+((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))) + 42 *((int)((((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) <<((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) >>((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))-((short)((((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) %((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))))));
f = va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float))))))+((short)((((int)(va_arg (*foo (), float))) &((int)(f)))))-((long)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))) + 42 *((int)((((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))) <<((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) >>((int)(va_arg (*foo (), float) + 42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float))))))-((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))))))-((short)((((int)(((short)((((int)(f)) %((int)(va_arg (*foo (), float)))))))) %((int)(42 *((int)((((int)(f)) %((int)(va_arg (*foo (), float))))))*((int)((((int)(va_arg (*foo (), float))) >>((int)(va_arg (*foo (), float)))))))))));
;
;
;
;
;
;
  va_end (ap);
}

int
main (void)
{
  bar ((-2), (-1));
  abort ();
}
/* ProgramSourceLLVM */
