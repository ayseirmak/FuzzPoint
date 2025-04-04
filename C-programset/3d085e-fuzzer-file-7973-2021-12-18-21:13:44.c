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
  
b->i = (0x03) + (-43) +((short)((((int)(b->i)) &((int)(b->i)))))*((int)((((int)(b->i)) %((int)((0x3A))))))+((int)((((int)(b->i)) %((int)((0x4))))))+((long)((((int)(b->i)) &((int)((0x4E16))))))-((long)((((double)((2))) +((double)(b->i)))));
b->i = (19) + (-43) *((long)((((double)((67))) -((double)((35))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
s.a.i = (4096) + (42) +((long)((((double)(s.a.i)) -((double)(s.a.i)))))+((short)((((int)((-1))) |((int)((0))))));
s.a.i = (8192) + (42) +((long)((((int)((0xE))) <<((int)(s.a.i)))))+((int)((((double)((2))) -((double)((-1))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))-((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
  
b->i = (-4) + (42) *((short)((((double)(b->i)) -((double)((4))))))+((long)((((double)(b->i)) *((double)(b->i)))));
b->i = (131) + (42) -((int)((((int)(b->i)) &((int)(b->i)))))-((int)((((double)((3))) *((double)((7))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = (0xB1) + (0x8F01B) -((long)((((int)((0))) &((int)(s.a.i)))))-((int)((((double)(s.a.i)) +((double)((0xE41D4))))));
s.a.i = (0x86) + (-43) *((short)((((double)((0))) +((double)(s.a.i)))))*((short)((((double)((0))) *((double)((-1))))));
;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (-43) +((int)((((double)(sizeof (int))) *((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((short)((((int)(offsetof (struct Q, a))) %((int)(offsetof (struct R, a))))))+((short)((((double)(sizeof (float))) *((double)(sizeof (float) != sizeof (int))))))*((long)((((int)(offsetof (struct Q, a) != sizeof (int))) |((int)(sizeof (int))))))-((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) *((double)(offsetof (struct Q, a))))))+((short)((((int)(offsetof (struct R, a))) &((int)(offsetof (struct R, a) != sizeof (int))))))))
    { return (0); }
  
s.a.i = (1) + (0x0A) *((long)((((int)((1))) &((int)((0xB4))))))+((int)((((int)((-2))) |((int)((1))))))+((long)((((int)(s.a.i)) <<((int)(s.a.i)))))*((short)((((int)(s.a.i)) >>((int)((-2))))));
s.a.i = (1) + (58) -((long)((((double)((-2))) -((double)(s.a.i)))))*((int)((((double)((1))) +((double)(s.a.i)))));
;
  ;
  if (0)
    { abort (); }
  
s.a.i = (0) + (42) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
s.a.i = (7) + (46) *((int)((((int)((33))) %((int)((33))))))-((long)((((int)(s.a.i)) >>((int)((9))))));
;
  
s.a.j = (0x39AC) + (-43) *((long)((((int)((6))) &((int)(s.a.j)))))*((int)((((double)(s.a.j)) *((double)(s.a.j)))))*((int)((((int)(s.a.j)) &((int)((10))))));
s.a.j = (0x50F) + (0xD64C) -((short)((((int)(s.a.j)) >>((int)((-3))))))-((long)((((double)(s.a.j)) *((double)((2))))));
;
  if (0)
    { abort (); }
  ;
  ;
  if (0)
    { abort (); }
  return (0xC);
}
/* ProgramSourceLLVM */
