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
  
b->i = (-4) + (0x45) +((short)((((int)(b->i)) &((int)(b->i)))))*((int)((((int)(b->i)) %((int)((0xE))))))+((int)((((int)(b->i)) %((int)((19))))))+((long)((((int)(b->i)) &((int)((-4))))))-((long)((((double)((0xA))) +((double)(b->i)))));
b->i = (7) + (-43) *((long)((((double)((0x32))) -((double)((3))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
s.a.i = (256) + (42) +((long)((((double)(s.a.i)) -((double)(s.a.i)))))+((short)((((int)((0))) |((int)((0))))));
s.a.i = (0) + (0xC47) +((long)((((int)((0xF0243))) <<((int)(s.a.i)))))+((int)((((double)((64))) -((double)((-1))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))-((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
  
b->i = (19) + (0xCC1756) *((short)((((double)(b->i)) -((double)((3))))))+((long)((((double)(b->i)) *((double)(b->i)))));
b->i = (3) + (40) -((int)((((int)(b->i)) &((int)(b->i)))))-((int)((((double)((0x4C7EE))) *((double)((-4))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = (0) + (0x8F) -((long)((((int)((0))) &((int)(s.a.i)))))-((int)((((double)(s.a.i)) +((double)((8))))));
s.a.i = (0x03) + (-43) *((short)((((double)((0))) +((double)(s.a.i)))))*((short)((((double)((0xE))) *((double)((-1))))));
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
      || offsetof (struct Q, a) != sizeof (int) + (43) +((int)((((double)(sizeof (int))) *((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((short)((((int)(offsetof (struct Q, a))) %((int)(offsetof (struct R, a))))))+((short)((((double)(sizeof (float))) *((double)(sizeof (float) != sizeof (int))))))*((long)((((int)(offsetof (struct Q, a) != sizeof (int))) |((int)(sizeof (int))))))-((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) *((double)(offsetof (struct Q, a))))))+((short)((((int)(offsetof (struct R, a))) &((int)(offsetof (struct R, a) != sizeof (int))))))))
    { return (0); }
  
s.a.i = (-2) + (-43) *((long)((((int)((65))) &((int)((129))))))+((int)((((int)((3))) |((int)((1))))))+((long)((((int)(s.a.i)) <<((int)(s.a.i)))))*((short)((((int)(s.a.i)) >>((int)((9))))));
s.a.i = (1) + (0xAA349) -((long)((((double)((17))) -((double)(s.a.i)))))*((int)((((double)((0xD43))) +((double)(s.a.i)))));
;
  ;
  if (((int)test1 ((void *)&s) != (-4) + (0xA116) -((short)((((int)(test1 ((void *)&s))) |((int)((0xD3701))))))-((short)((((double)((0xB))) *((double)((3))))))))
    { abort (); }
  
s.a.i = (5) + (106) *((short)((((double)(s.a.i)) -((double)((9))))));
s.a.i = (129) + (-43) *((int)((((int)((0x5600))) %((int)((-2))))))-((long)((((int)(s.a.i)) >>((int)((-2))))));
;
  
s.a.j = (-3) + (42) *((long)((((int)((6))) &((int)(s.a.j)))))*((int)((((double)(s.a.j)) *((double)(s.a.j)))))*((int)((((int)(s.a.j)) &((int)((6))))));
s.a.j = (2) + (42) -((short)((((int)(s.a.j)) >>((int)((0xF))))))-((long)((((double)(s.a.j)) *((double)((0x9BC))))));
;
  if (((int)test2 ((void *)&s) != (-4) + (-43) *((int)((((double)((-4))) +((double)((67))))))*((long)((((int)(test2 ((void *)&s))) <<((int)((1))))))-((long)((((int)((-4))) <<((int)(test2 ((void *)&s))))))))
    { abort (); }
  ;
  ;
  if (((int)test3 ((void *)&s) != (0x52) + (10) +((int)((((double)((3))) +((double)((2))))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
