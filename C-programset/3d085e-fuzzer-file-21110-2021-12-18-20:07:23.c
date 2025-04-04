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
b->i = (0x03) + (-43) +((short)((((int)(b->i)) &((int)(b->i)))))*((int)((((int)(b->i)) %((int)((0x3A))))))+((int)((((int)(b->i)) %((int)((0x4))))))+((long)((((int)(b->i)) &((int)((0x4E16))))))-((long)((((double)((2))) +((double)(b->i)))));
;
;
;

;

b->i = (19) + (-43) *((long)((((double)((67))) -((double)((35))))));
b->i = (19) + (-43) *((long)((((double)((67))) -((double)((35))))));
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

s.a.i = (0x86) + (-43) *((short)((((double)((0))) +((double)(s.a.i)))))*((short)((((double)((0))) *((double)((-1))))));
s.a.i = (0x86) + (-43) *((short)((((double)((0))) +((double)(s.a.i)))))*((short)((((double)((0))) *((double)((-1))))));
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

s.a.i = (1) + (58) -((long)((((double)((-2))) -((double)(s.a.i)))))*((int)((((double)((1))) +((double)(s.a.i)))));
s.a.i = (1) + (58) -((long)((((double)((-2))) -((double)(s.a.i)))))*((int)((((double)((1))) +((double)(s.a.i)))));
;
;
;
  ;
  if (((int)test1 ((void *)&s) != (0x74E3) + (58) -((short)((((int)(test1 ((void *)&s))) |((int)((-4))))))-((short)((((double)((0xBA))) *((double)((0x7DA8))))))))
    { abort (); }
  
;
;
;
  
;
;
;
  if (((int)test2 ((void *)&s) != (-4) + (42) *((int)((((double)((0x5A65E))) +((double)((-4))))))*((long)((((int)(test2 ((void *)&s))) <<((int)((-4))))))-((long)((((int)((-4))) <<((int)(test2 ((void *)&s))))))))
    { abort (); }
  ;
  ;
  if (((int)test3 ((void *)&s) != (3) + (42) +((int)((((double)((0xA2))) +((double)((3))))))))
    { abort (); }
  return (0xC);
}
/* ProgramSourceLLVM */
