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
  
b->i = 3 + 42 +((short)((((int)(b->i)) &((int)(b->i)))))*((int)((((int)(b->i)) %((int)(3)))))+((int)((((int)(b->i)) %((int)(3)))))+((long)((((int)(b->i)) &((int)(3)))))-((long)((((double)(3)) +((double)(b->i)))));
b->i = 3 + 42 *((long)((((double)(3)) -((double)(3)))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
s.a.i = 0 + 42 +((long)((((double)(s.a.i)) -((double)(s.a.i)))))+((short)((((int)(0)) |((int)(0)))));
s.a.i = 0 + 42 +((long)((((int)(0)) <<((int)(s.a.i)))))+((int)((((double)(0)) -((double)(0)))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))-((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
  
b->i = 3 + 42 *((short)((((double)(b->i)) -((double)(3)))))+((long)((((double)(b->i)) *((double)(b->i)))));
b->i = 3 + 42 -((int)((((int)(b->i)) &((int)(b->i)))))-((int)((((double)(3)) *((double)(3)))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = 0 + 42 -((long)((((int)(0)) &((int)(s.a.i)))))-((int)((((double)(s.a.i)) +((double)(0)))));
s.a.i = 0 + 42 *((short)((((double)(0)) +((double)(s.a.i)))))*((short)((((double)(0)) *((double)(0)))));
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
      || offsetof (struct Q, a) != sizeof (int) + 42 +((int)((((double)(sizeof (int))) *((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((short)((((int)(offsetof (struct Q, a))) %((int)(offsetof (struct R, a))))))+((short)((((double)(sizeof (float))) *((double)(sizeof (float) != sizeof (int))))))*((long)((((int)(offsetof (struct Q, a) != sizeof (int))) |((int)(sizeof (int))))))-((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) *((double)(offsetof (struct Q, a))))))+((short)((((int)(offsetof (struct R, a))) &((int)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  
s.a.i = 1 + 42 *((long)((((int)(1)) &((int)(1)))))+((int)((((int)(1)) |((int)(1)))))+((long)((((int)(s.a.i)) <<((int)(s.a.i)))))*((short)((((int)(s.a.i)) >>((int)(1)))));
s.a.i = 1 + 42 -((long)((((double)(1)) -((double)(s.a.i)))))*((int)((((double)(1)) +((double)(s.a.i)))));
;
  ;
  if (0)
    { abort (); }
  
s.a.i = 1 + 42 *((short)((((double)(s.a.i)) -((double)(1)))));
s.a.i = 1 + 42 *((int)((((int)(1)) %((int)(1)))))-((long)((((int)(s.a.i)) >>((int)(1)))));
;
  
s.a.j = 2 + 42 *((long)((((int)(2)) &((int)(s.a.j)))))*((int)((((double)(s.a.j)) *((double)(s.a.j)))))*((int)((((int)(s.a.j)) &((int)(2)))));
s.a.j = 2 + 42 -((short)((((int)(s.a.j)) >>((int)(2)))))-((long)((((double)(s.a.j)) *((double)(2)))));
;
  if (0)
    { abort (); }
  ;
  ;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
