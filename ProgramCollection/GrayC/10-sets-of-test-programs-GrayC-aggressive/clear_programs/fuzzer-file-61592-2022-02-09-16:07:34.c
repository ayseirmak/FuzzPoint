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
  

f = va_arg (*foo (), float) + (42) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (-43) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (-43))) %((int)(va_arg (*foo (), float) + (0x4B1))))))+((long)((((int)((0x12F544))) <<((int)(va_arg (*foo (), float)))))) + (42) -((int)((((int)(((long)((((int)(va_arg (*foo (), float) + (0xF6CEA9))) %((int)(va_arg (*foo (), float) + (-43)))))))) >>((int)(va_arg (*foo (), float) + (106))))))*((long)((((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (-43) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (-43))) %((int)(va_arg (*foo (), float) + (42)))))))) |((int)(va_arg (*foo (), float) + (40) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (-43))))))-((long)((((int)(f)) >>((int)(((long)((((int)(va_arg (*foo (), float) + (-43))) %((int)(va_arg (*foo (), float) + (-43)))))))))));
f = va_arg (*foo (), float) + (43) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (-43) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (0xC2F270))) %((int)(va_arg (*foo (), float) + (-43))))))+((long)((((int)((0x5C19F))) <<((int)(va_arg (*foo (), float)))))) + (-43) *((short)((((int)(va_arg (*foo (), float) + (10) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (0x7BB963) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (-43))) %((int)(va_arg (*foo (), float) + (42))))))+((long)((((int)((0xFB1))) <<((int)(va_arg (*foo (), float)))))))) &((int)((0xEF42D4))))))+((short)((((int)(va_arg (*foo (), float))) %((int)((43))))))*((short)((((int)(((long)((((int)((-43))) <<((int)(va_arg (*foo (), float)))))))) %((int)(f)))));
;

f = va_arg (*foo (), float) + (0x5DC9) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (58) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (42))) %((int)(va_arg (*foo (), float) + (106))))))+((long)((((int)((22))) <<((int)(va_arg (*foo (), float)))))) + (42) *((short)((((int)(((long)((((int)((0x6B768F))) <<((int)(va_arg (*foo (), float)))))))) ^((int)(((long)((((int)((41))) <<((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(va_arg (*foo (), float) + (0x233621))) &((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (-43) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (10))) %((int)(va_arg (*foo (), float) + (42)))))))))))-((int)((((int)(va_arg (*foo (), float) + (0x177) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (42) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f))))))) >>((int)((-43))))))-((short)((((int)(((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f))))))) &((int)(f)))))*((long)((((int)(va_arg (*foo (), float) + (58) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (-43) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (0x1437))) %((int)(va_arg (*foo (), float) + (-43)))))))) &((int)(va_arg (*foo (), float) + (-43) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))))));
f = va_arg (*foo (), float) + (0x91BF5) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (34) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (0x7B))) %((int)(va_arg (*foo (), float) + (106))))))+((long)((((int)((106))) <<((int)(va_arg (*foo (), float)))))) + (0xE595) +((long)((((int)(va_arg (*foo (), float) + (42) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (10) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (106))) %((int)(va_arg (*foo (), float) + (42)))))))) |((int)(va_arg (*foo (), float) + (10) +((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))) + (34) +((int)((((int)(((int)((((int)(va_arg (*foo (), float))) %((int)(va_arg (*foo (), float)))))))) %((int)(f)))))-((long)((((int)(va_arg (*foo (), float) + (42))) %((int)(va_arg (*foo (), float) + (43))))))+((long)((((int)((42))) <<((int)(va_arg (*foo (), float)))))))))))*((long)((((int)(f)) >>((int)(((long)((((int)((42))) <<((int)(va_arg (*foo (), float)))))))))));
;
;
  va_end (ap);
}

int
main (void)
{
  bar ((0x65CFA), (0));
  abort ();
}
/* ProgramSourceLLVM */
