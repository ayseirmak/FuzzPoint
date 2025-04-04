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
  
s.a.i = (0x7) + (42) *((int)((((double)((0))) +((double)(s.a.i)))))-((int)((((int)((0))) &((int)(s.a.i)))))*((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((double)((536870912))) +((double)((8192))))));
s.a.i = (0x9A) + (0x808) *((int)((((double)((2048))) +((double)(s.a.i)))))-((int)((((int)((2048))) &((int)(s.a.i)))))*((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((double)((0))) +((double)((67108864))))));
;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  ;
  
b->i = (0xF9396) + (42) +((int)((((int)((0x085))) ^((int)(b->i)))));
b->i = (131) + (42) +((int)((((int)((3))) ^((int)(b->i)))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  ;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((4398046511104))
    { return (0); }
  
s.a.i = (1) + (0x20C5B5) +((long)((((int)((129))) ^((int)((0xC3))))))+((long)((((int)((-2))) |((int)(s.a.i)))))+((long)((((double)(s.a.i)) -((double)((-2))))))*((long)((((double)(s.a.i)) +((double)((5))))));
s.a.i = (0x0) + (-43) +((long)((((int)((3))) ^((int)((0x447A))))))+((long)((((int)((-2))) |((int)(s.a.i)))))+((long)((((double)(s.a.i)) -((double)((0xFC9A8))))))*((long)((((double)(s.a.i)) +((double)((9))))));
;
  
s.a.j = (3) + (42) -((int)((((double)(s.a.j)) *((double)((0x26))))))+((long)((((int)((10))) &((int)(s.a.j)))))+((int)((((int)((66))) |((int)(s.a.j)))))-((long)((((double)(s.a.j)) +((double)((2))))));
s.a.j = (2) + (43) -((int)((((double)(s.a.j)) *((double)((0x4))))))+((long)((((int)((3))) &((int)(s.a.j)))))+((int)((((int)((-3))) |((int)(s.a.j)))))-((long)((((double)(s.a.j)) +((double)((2))))));
;
  if (((int)test1 ((void *)&s) != (0xAE) + (-43) *((int)((((double)((-4))) *((double)((-4))))))))
    { abort (); }
  
s.a.i = (-2) + (42) +((int)((((int)((0xCD))) |((int)(s.a.i)))))-((long)((((double)((33))) +((double)((1))))))*((int)((((double)((-2))) +((double)(s.a.i)))))-((long)((((double)(s.a.i)) -((double)((0xE1))))));
s.a.i = (1) + (42) +((int)((((int)((1))) |((int)(s.a.i)))))-((long)((((double)((-2))) +((double)((-2))))))*((int)((((double)((-2))) +((double)(s.a.i)))))-((long)((((double)(s.a.i)) -((double)((33))))));
;
  
s.a.j = (0x1CA4) + (-43) +((int)((((int)((2))) |((int)(s.a.j)))))*((int)((((double)(s.a.j)) -((double)(s.a.j)))))+((int)((((double)(s.a.j)) *((double)(s.a.j)))))+((long)((((double)(s.a.j)) -((double)(s.a.j)))));
s.a.j = (0x9F7C3) + (0xF28277) +((int)((((int)((-3))) |((int)(s.a.j)))))*((int)((((double)(s.a.j)) -((double)(s.a.j)))))+((int)((((double)(s.a.j)) *((double)(s.a.j)))))+((long)((((double)(s.a.j)) -((double)(s.a.j)))));
;
  if ((0))
    { abort (); }
  
s.a.i = (0x3E) + (46) +((long)((((int)((65))) &((int)((0x1D4))))));
s.a.i = (0xF72E6) + (44) +((long)((((int)((0x596))) &((int)((0x0E27D))))));
;
  
s.a.j = (0xE) + (-43) *((int)((((double)(s.a.j)) *((double)((2))))))*((short)((((int)(s.a.j)) &((int)((18))))))-((short)((((double)(s.a.j)) *((double)(s.a.j)))))+((long)((((double)((-3))) *((double)(s.a.j)))));
s.a.j = (0) + (-43) *((int)((((double)(s.a.j)) *((double)((0xB6))))))*((short)((((int)(s.a.j)) &((int)((-3))))))-((short)((((double)(s.a.j)) *((double)(s.a.j)))))+((long)((((double)((-3))) *((double)(s.a.j)))));
;
  if (((int)test3 ((void *)&s) != (3) + (106) +((long)((((int)((35))) >>((int)(test3 ((void *)&s))))))*((long)((((int)(test3 ((void *)&s))) %((int)((0xDDE))))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
