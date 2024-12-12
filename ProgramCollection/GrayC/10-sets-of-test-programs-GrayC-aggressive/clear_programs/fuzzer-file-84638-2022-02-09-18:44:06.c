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
  


s.a.i = 0 + 42 +((int)((((int)(s.a.i)) ^((int)(s.a.i)))))*((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((double)(s.a.i)) +((double)(0)))))-((int)((((double)(0)) -((double)(s.a.i)))));
s.a.i = 0 + 42 -((long)((((double)(0)) +((double)(s.a.i)))))+((int)((((double)(s.a.i)) -((double)(0)))))-((short)((((int)(s.a.i)) <<((int)(0)))));
;

s.a.i = 0 + 42 +((long)((((int)(0)) %((int)(0)))))-((short)((((int)(0)) %((int)(0)))))*((long)((((int)(0)) |((int)(0)))))*((int)((((int)(s.a.i)) |((int)(0)))));
s.a.i = 0 + 42 -((long)((((double)(0)) -((double)(0)))))-((long)((((int)(s.a.i)) %((int)(s.a.i)))))-((int)((((double)(s.a.i)) +((double)(s.a.i)))));
;
;
;
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
;
;
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  

;

s.a.i = 0 + 42 -((long)((((double)(s.a.i)) -((double)(s.a.i)))))-((int)((((double)(s.a.i)) +((double)(0)))))-((int)((((double)(s.a.i)) -((double)(s.a.i)))));
s.a.i = 0 + 42 -((short)((((double)(0)) *((double)(s.a.i)))))+((int)((((double)(0)) -((double)(s.a.i)))))+((long)((((double)(s.a.i)) +((double)(s.a.i)))));
;
;
;
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
      || offsetof (struct Q, a) != sizeof (int) + 42 +((int)((((int)(sizeof (int))) &((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((long)((((double)(sizeof (int))) -((double)(offsetof (struct Q, a) != sizeof (int))))))-((int)((((double)(offsetof (struct R, a))) *((double)(sizeof (int))))))+((int)((((int)(offsetof (struct R, a) != sizeof (int))) ^((int)(offsetof (struct Q, a))))))))
    { return 0; }
  


s.a.i = 1 + 42 +((short)((((int)(s.a.i)) <<((int)(s.a.i)))))+((int)((((double)(1)) *((double)(1)))))*((long)((((double)(s.a.i)) *((double)(1)))))-((int)((((int)(s.a.i)) %((int)(s.a.i)))))*((short)((((int)(1)) &((int)(1)))));
s.a.i = 1 + 42 *((short)((((int)(s.a.i)) ^((int)(1)))))+((int)((((double)(1)) +((double)(1)))));
;
;
;
;
;
  

;

s.a.j = 2 + 42 -((short)((((int)(2)) |((int)(2)))))*((int)((((int)(s.a.j)) >>((int)(2)))))+((long)((((int)(2)) %((int)(2)))))*((long)((((int)(2)) %((int)(s.a.j)))));
s.a.j = 2 + 42 *((long)((((int)(2)) |((int)(s.a.j)))))+((long)((((int)(s.a.j)) <<((int)(2)))));
;
;

;
;
;
;
  if (((int)test1 ((void *)&s) != 3 + 42 *((short)((((int)(test1 ((void *)&s))) %((int)(test1 ((void *)&s))))))))
    { abort (); }
  ;
  


s.a.j = 2 + 42 *((long)((((double)(2)) -((double)(s.a.j)))))*((short)((((int)(2)) &((int)(s.a.j)))))+((int)((((double)(s.a.j)) *((double)(s.a.j)))));
s.a.j = 2 + 42 -((short)((((double)(2)) *((double)(2)))))*((int)((((double)(2)) -((double)(2)))));
;
;
;

;

s.a.j = 2 + 42 -((long)((((int)(s.a.j)) >>((int)(2)))));
s.a.j = 2 + 42 +((long)((((int)(s.a.j)) >>((int)(2)))))*((int)((((int)(2)) &((int)(2)))))-((short)((((double)(s.a.j)) -((double)(s.a.j)))));
;
;
;
  if (0)
    { abort (); }
  
;


s.a.i = 1 + 42 *((long)((((int)(s.a.i)) >>((int)(s.a.i)))))+((long)((((int)(s.a.i)) %((int)(s.a.i)))))-((int)((((double)(s.a.i)) *((double)(1)))));
s.a.i = 1 + 42 *((short)((((double)(1)) *((double)(s.a.i)))))-((int)((((double)(1)) -((double)(s.a.i)))))+((short)((((double)(1)) +((double)(s.a.i)))));
;
;
;
;
  ;
  if (((int)test3 ((void *)&s) != 3 + 42 +((long)((((int)(3)) <<((int)(test3 ((void *)&s))))))*((short)((((int)(test3 ((void *)&s))) &((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
