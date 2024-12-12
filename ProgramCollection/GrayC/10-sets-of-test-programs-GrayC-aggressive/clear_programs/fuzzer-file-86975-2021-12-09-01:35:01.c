/* corpus/pr44468.c */
#include <stddef.h>

struct S {
  int i;
  int j;
};
struct R {
  int k;
  struct S a;
};
struct Q {
  float k;
  struct S a;
};
struct Q s;
int __attribute__((noinline,noclone))
test1 (void *q)
{
  struct S *b = (struct S *)((char *)q + sizeof (int));
  ;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;
;
;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  

s.a.i = ((0xEB1874B8C)) + (0x546) -((short)((((int)(s.a.i)) %((int)(((256)))))))+((int)((((double)(((-129)))) -((double)(s.a.i)))))+((long)((((double)((0x4))) +((double)(((0x23715)))))))-((short)((((int)(s.a.i)) ^((int)((-(1)))))));
s.a.i = ((0x29E015DC17)) + ((174)) -((short)((((int)(s.a.i)) %((int)(((0)))))))+((int)((((double)((-(0xF8F9C)))) -((double)(s.a.i)))))+((long)((((double)((0x44))) +((double)(((16)))))))-((short)((((int)(s.a.i)) ^((int)(((32)))))));
;
;
;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((16384)))
    { return ((0)); }
  
;

s.a.i = ((-130)) + ((49)) *((int)((((int)(s.a.i)) |((int)(((0x8447)))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
s.a.i = (-(2)) + ((46)) *((int)((((int)(s.a.i)) |((int)((0xA2405))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
;
  ;
  if (0)
    { abort (); }
  ;
  
;
;
;
  if (((int)test2 ((void *)&s) != (-(4)) + ((-35)) *((long)((((int)(test2 ((void *)&s))) <<((int)(test2 ((void *)&s))))))+((short)((((int)(((0x31AC)))) %((int)(test2 ((void *)&s))))))-((int)((((int)(test2 ((void *)&s))) <<((int)(test2 ((void *)&s))))))*((int)((((int)(test2 ((void *)&s))) <<((int)(test2 ((void *)&s))))))+((short)((((int)((-(12)))) %((int)(test2 ((void *)&s))))))-((short)((((int)((0x8))) %((int)(test2 ((void *)&s))))))+((int)((((int)(test2 ((void *)&s))) |((int)(test2 ((void *)&s))))))))
    { abort (); }
  

s.a.i = ((0x29998)) + ((0xF5E6)) -((int)((((int)(s.a.i)) &((int)(((0xE39)))))));
s.a.i = (0x94) + (0xA1B6B) -((int)((((int)(s.a.i)) &((int)(((-2)))))));
;
;
;
  

s.a.j = (0xDD8) + ((-171)) *((int)((((double)(s.a.j)) +((double)((0xCB020))))));
s.a.j = ((18)) + ((110)) *((int)((((double)(s.a.j)) +((double)((-(0xA48A)))))));
;
;
;
  if (0)
    { abort (); }
  return (0x8309E);
}
/* ProgramSourceLLVM */
