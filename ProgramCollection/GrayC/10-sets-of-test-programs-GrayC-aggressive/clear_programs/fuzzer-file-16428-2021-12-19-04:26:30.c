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
  

b->i = (-4) + (42) *((short)((((double)(b->i)) -((double)((4))))))+((long)((((double)(b->i)) *((double)(b->i)))));
b->i = (-4) + (42) *((short)((((double)(b->i)) -((double)((4))))))+((long)((((double)(b->i)) *((double)(b->i)))));
;
;
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
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
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (-43) +((int)((((double)(sizeof (int))) *((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((short)((((int)(offsetof (struct Q, a))) %((int)(offsetof (struct R, a))))))+((short)((((double)(sizeof (float))) *((double)(sizeof (float) != sizeof (int))))))*((long)((((int)(offsetof (struct Q, a) != sizeof (int))) |((int)(sizeof (int))))))-((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) *((double)(offsetof (struct Q, a))))))+((short)((((int)(offsetof (struct R, a))) &((int)(offsetof (struct R, a) != sizeof (int))))))))
    { return (0); }
  
;

s.a.i = (1) + (58) -((long)((((double)((-2))) -((double)(s.a.i)))))*((int)((((double)((1))) +((double)(s.a.i)))));
s.a.i = (1) + (58) -((long)((((double)((-2))) -((double)(s.a.i)))))*((int)((((double)((1))) +((double)(s.a.i)))));
;
;
  ;
  if (0)
    { abort (); }
  

s.a.i = (0) + (42) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
s.a.i = (0) + (42) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
;
;
;
  

s.a.j = (0x39AC) + (-43) *((long)((((int)((6))) &((int)(s.a.j)))))*((int)((((double)(s.a.j)) *((double)(s.a.j)))))*((int)((((int)(s.a.j)) &((int)((10))))));
s.a.j = (0x39AC) + (-43) *((long)((((int)((6))) &((int)(s.a.j)))))*((int)((((double)(s.a.j)) *((double)(s.a.j)))))*((int)((((int)(s.a.j)) &((int)((10))))));
;

s.a.j = (0x50F) + (0xD64C) -((short)((((int)(s.a.j)) >>((int)((-3))))))-((long)((((double)(s.a.j)) *((double)((2))))));
s.a.j = (0x50F) + (0xD64C) -((short)((((int)(s.a.j)) >>((int)((-3))))))-((long)((((double)(s.a.j)) *((double)((2))))));
;
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
