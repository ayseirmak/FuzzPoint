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
  

s.a.i = 0 + 42 -((int)((((double)(s.a.i)) +((double)(0)))))*((int)((((int)(s.a.i)) <<((int)(0)))))+((int)((((int)(0)) |((int)(0)))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))));
s.a.i = 0 + 42 -((int)((((double)(s.a.i)) *((double)(s.a.i)))))-((int)((((int)(s.a.i)) ^((int)(0)))))-((long)((((double)(0)) *((double)(0)))))+((long)((((double)(0)) -((double)(0)))));
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
  

b->i = 3 + 42 -((short)((((double)(3)) -((double)(b->i)))));
b->i = 3 + 42 *((short)((((double)(3)) +((double)(3)))))-((short)((((double)(b->i)) -((double)(3)))));
;
;
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  

s.a.i = 0 + 42 -((int)((((int)(0)) >>((int)(s.a.i)))))*((int)((((int)(0)) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) %((int)(0)))))*((long)((((double)(s.a.i)) +((double)(0)))))+((short)((((double)(0)) *((double)(0)))));
s.a.i = 0 + 42 *((int)((((double)(0)) *((double)(s.a.i)))))*((int)((((double)(0)) +((double)(0)))));
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
      || offsetof (struct Q, a) != sizeof (int) + 42 +((long)((((double)(sizeof (int))) +((double)(sizeof (float))))))-((int)((((double)(offsetof (struct Q, a))) -((double)(sizeof (int))))))+((long)((((double)(sizeof (int))) +((double)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  

s.a.i = 1 + 42 -((int)((((int)(s.a.i)) &((int)(1)))));
s.a.i = 1 + 42 +((int)((((double)(1)) *((double)(s.a.i)))))-((long)((((int)(1)) &((int)(1)))))-((short)((((double)(s.a.i)) *((double)(s.a.i)))))*((int)((((int)(s.a.i)) |((int)(1)))));
;
;
;
  

s.a.j = 2 + 42 *((int)((((int)(2)) |((int)(s.a.j)))));
s.a.j = 2 + 42 -((long)((((double)(s.a.j)) *((double)(2)))))-((long)((((double)(2)) *((double)(2)))))-((long)((((int)(s.a.j)) ^((int)(s.a.j)))));
;

s.a.j = 2 + 42 -((int)((((int)(s.a.j)) ^((int)(2)))))-((short)((((int)(2)) &((int)(s.a.j)))))+((short)((((double)(s.a.j)) +((double)(s.a.j)))));
s.a.j = 2 + 42 *((long)((((int)(s.a.j)) >>((int)(2)))));
;
;
  if (((int)test1 ((void *)&s) != 3 + 42 *((long)((((int)(3)) ^((int)(test1 ((void *)&s))))))-((long)((((int)(test1 ((void *)&s))) <<((int)(3)))))-((int)((((int)(3)) <<((int)(test1 ((void *)&s))))))-((long)((((int)(3)) &((int)(3)))))-((short)((((int)(test1 ((void *)&s))) <<((int)(3)))))-((short)((((double)(3)) -((double)(3)))))*((long)((((int)(test1 ((void *)&s))) %((int)(3)))))+((long)((((int)(3)) >>((int)(test1 ((void *)&s))))))*((long)((((int)(test1 ((void *)&s))) ^((int)(test1 ((void *)&s))))))))
    { abort (); }
  ;
  

s.a.j = 2 + 42 +((int)((((int)(s.a.j)) %((int)(2)))));
s.a.j = 2 + 42 -((int)((((double)(2)) -((double)(s.a.j)))))*((int)((((int)(s.a.j)) |((int)(s.a.j)))))*((int)((((int)(2)) &((int)(s.a.j)))))+((short)((((int)(s.a.j)) %((int)(2)))));
;

s.a.j = 2 + 42 -((int)((((double)(2)) +((double)(s.a.j)))))*((long)((((double)(s.a.j)) *((double)(2)))))*((int)((((double)(s.a.j)) *((double)(2)))))+((short)((((int)(s.a.j)) %((int)(2)))))+((int)((((int)(s.a.j)) &((int)(2)))));
s.a.j = 2 + 42 -((long)((((double)(2)) -((double)(2)))))+((long)((((int)(2)) &((int)(2)))))+((long)((((int)(s.a.j)) <<((int)(2)))))+((short)((((int)(2)) <<((int)(2)))))-((short)((((double)(s.a.j)) -((double)(2)))));
;
;
  if (0)
    { abort (); }
  
;

s.a.i = 1 + 42 +((int)((((double)(1)) *((double)(1)))))+((int)((((int)(s.a.i)) |((int)(s.a.i)))))*((long)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)(1)) %((int)(s.a.i)))))+((short)((((int)(1)) >>((int)(1)))));
s.a.i = 1 + 42 +((short)((((double)(s.a.i)) +((double)(s.a.i)))))-((int)((((double)(1)) -((double)(1)))))*((short)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)(1)))))-((short)((((double)(1)) *((double)(1)))));
;
;
  ;
  if (((int)test3 ((void *)&s) != 3 + 42 -((int)((((int)(test3 ((void *)&s))) |((int)(test3 ((void *)&s))))))-((short)((((int)(test3 ((void *)&s))) |((int)(3)))))-((short)((((int)(test3 ((void *)&s))) |((int)(3)))))-((long)((((int)(3)) <<((int)(3)))))-((long)((((int)(3)) |((int)(3)))))+((short)((((int)(test3 ((void *)&s))) ^((int)(test3 ((void *)&s))))))*((int)((((int)(test3 ((void *)&s))) |((int)(3)))))-((long)((((int)(test3 ((void *)&s))) >>((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
