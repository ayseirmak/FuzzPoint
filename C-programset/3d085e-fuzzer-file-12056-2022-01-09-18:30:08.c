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
  
f = va_arg (*foo (), float) + (0xD7A9) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (42) +((int)((((int)((43))) %((int)(va_arg (*foo (), float) + (-43))))))-((short)((((int)((42))) ^((int)(f)))))-((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))) + (43) -((short)((((int)(va_arg (*foo (), float) + (42))) %((int)((-43))))))-((short)((((int)((45))) &((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))))))+((long)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((short)((((int)(va_arg (*foo (), float) + (-43) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (42) +((int)((((int)((-43))) %((int)(va_arg (*foo (), float) + (42)))))))) %((int)(va_arg (*foo (), float) + (-43)))))) + (42) -((long)((((int)((0xFC2C8))) >>((int)(((short)((((int)(va_arg (*foo (), float) + (-43) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (42) +((int)((((int)((106))) %((int)(va_arg (*foo (), float) + (-43)))))))) %((int)(va_arg (*foo (), float) + (-43)))))))))))*((int)((((int)(((long)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) %((int)(f))))))) <<((int)(f)))))-((short)((((int)((170))) ^((int)(((long)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) %((int)(f))))))))))+((int)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) ^((int)(va_arg (*foo (), float) + (0x8835) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (42) +((int)((((int)((-43))) %((int)(va_arg (*foo (), float) + (-43))))))-((short)((((int)((47))) ^((int)(f)))))-((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))) + (34))))));
f = va_arg (*foo (), float) + (42) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (-43) +((int)((((int)((42))) %((int)(va_arg (*foo (), float) + (42))))))-((short)((((int)((0x32))) ^((int)(f)))))-((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))) + (42) -((short)((((int)(va_arg (*foo (), float) + (-43))) %((int)((-43))))))-((short)((((int)((42))) &((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))))))+((long)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((short)((((int)(va_arg (*foo (), float) + (0x9C9) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (42) +((int)((((int)((10))) %((int)(va_arg (*foo (), float) + (43)))))))) %((int)(va_arg (*foo (), float) + (0xB52B3)))))) + (0x0257) +((long)((((int)(((short)((((int)((42))) &((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float))))))))))))) ^((int)(va_arg (*foo (), float) + (42) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (0x0F5967) +((int)((((int)((02))) %((int)(va_arg (*foo (), float) + (42)))))))))))+((long)((((int)(((long)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) %((int)(f))))))) ^((int)(((long)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) %((int)(f))))))))))+((short)((((int)(((short)((((int)(va_arg (*foo (), float) + (42) -((int)((((int)(va_arg (*foo (), float))) %((int)(f)))))*((short)((((double)(f)) *((double)(f)))))*((int)((((int)(f)) ^((int)(f)))))*((int)((((int)(f)) %((int)(f))))) + (-43) +((int)((((int)((-43))) %((int)(va_arg (*foo (), float) + (46)))))))) %((int)(va_arg (*foo (), float) + (170)))))))) &((int)((-43))))))-((long)((((int)((0x6784))) <<((int)(((long)((((int)(((int)((((int)(va_arg (*foo (), float))) &((int)(va_arg (*foo (), float)))))))) %((int)(f))))))))));
;
  va_end (ap);
}

int
main (void)
{
  bar ((-(0x185B2)), ((0x0)));
  abort ();
}
/* ProgramSourceLLVM */
