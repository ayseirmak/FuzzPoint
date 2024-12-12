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
  
b->i = 3 + 42 +((long)((((double)(3)) *((double)(3)))))*((long)((((double)(3)) *((double)(3)))))*((long)((((int)(b->i)) |((int)(b->i)))));
b->i = 3 + 42 +((int)((((int)(b->i)) |((int)(3)))))*((short)((((double)(b->i)) *((double)(3)))))+((int)((((int)(b->i)) %((int)(b->i)))))*((long)((((int)(b->i)) %((int)(b->i)))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
s.a.i = 0 + 42 -((long)((((int)(s.a.i)) >>((int)(0)))))*((long)((((int)(s.a.i)) |((int)(0)))))-((long)((((double)(s.a.i)) *((double)(s.a.i)))))*((short)((((int)(s.a.i)) >>((int)(0)))));
s.a.i = 0 + 42 *((long)((((int)(s.a.i)) ^((int)(0)))))+((short)((((double)(0)) +((double)(0)))))+((short)((((double)(0)) -((double)(s.a.i)))));
;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  ;
  
((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 *((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) >>((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 *((short)((((double)(3)) -((double)(3)))))+((short)((((int)(3)) |((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 42 -((short)((((int)(sizeof (float))) <<((int)(sizeof (int))))))+((short)((((double)(sizeof (int))) +((double)(sizeof (int))))))*((short)((((int)(sizeof (int))) >>((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((long)((((double)(offsetof (struct R, a) != sizeof (int))) -((double)(sizeof (int))))))+((long)((((int)(sizeof (float))) <<((int)(sizeof (int))))))-((int)((((double)(offsetof (struct R, a) != sizeof (int))) +((double)(sizeof (float))))))+((long)((((double)(offsetof (struct Q, a))) +((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((long)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) -((double)(sizeof (int))))))*((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^((int)(sizeof (float))))))+((int)((((double)(sizeof (int))) +((double)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  ;
  
s.a.j = 2 + 42 -((long)((((int)(2)) >>((int)(2)))))*((long)((((double)(2)) -((double)(s.a.j)))))+((short)((((double)(2)) -((double)(2)))))+((long)((((double)(2)) +((double)(s.a.j)))))+((long)((((int)(2)) ^((int)(s.a.j)))));
s.a.j = 2 + 42 *((long)((((double)(2)) *((double)(s.a.j)))))+((int)((((int)(s.a.j)) &((int)(s.a.j)))))-((int)((((double)(2)) *((double)(s.a.j)))))-((short)((((double)(s.a.j)) *((double)(2)))));
;
  if (((int)test1 ((void *)&s) != 3 + 42 +((long)((((int)(3)) &((int)(test1 ((void *)&s))))))-((short)((((int)(test1 ((void *)&s))) &((int)(3)))))))
    { abort (); }
  
s.a.i = 1 + 42 +((short)((((int)(1)) |((int)(1)))))*((long)((((double)(1)) *((double)(s.a.i)))));
s.a.i = 1 + 42 *((short)((((int)(1)) >>((int)(1)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))*((int)((((double)(s.a.i)) -((double)(1)))));
;
  ;
  if (((int)test2 ((void *)&s) != 3 + 42 +((short)((((double)(3)) +((double)(3)))))+((int)((((int)(test2 ((void *)&s))) |((int)(3)))))+((int)((((int)(3)) |((int)(3)))))+((int)((((double)(3)) *((double)(3)))))))
    { abort (); }
  
s.a.i = 1 + 42 +((short)((((double)(s.a.i)) +((double)(1)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) %((int)(s.a.i)))));
s.a.i = 1 + 42 -((int)((((int)(s.a.i)) ^((int)(1)))));
;
  
s.a.j = 2 + 42 +((short)((((double)(2)) *((double)(2)))))+((int)((((int)(2)) |((int)(2)))))*((short)((((int)(s.a.j)) &((int)(2)))))-((short)((((double)(2)) +((double)(s.a.j)))));
s.a.j = 2 + 42 -((short)((((int)(s.a.j)) >>((int)(s.a.j)))))-((long)((((double)(2)) +((double)(s.a.j)))))*((long)((((double)(s.a.j)) *((double)(2)))));
;
  if (((int)test3 ((void *)&s) != 3 + 42 *((long)((((int)(3)) >>((int)(test3 ((void *)&s))))))*((long)((((int)(3)) ^((int)(test3 ((void *)&s))))))+((short)((((int)(test3 ((void *)&s))) ^((int)(3)))))-((long)((((int)(3)) %((int)(3)))))+((long)((((int)(test3 ((void *)&s))) ^((int)(test3 ((void *)&s))))))*((short)((((int)(3)) >>((int)(test3 ((void *)&s))))))-((short)((((int)(test3 ((void *)&s))) <<((int)(3)))))+((long)((((int)(test3 ((void *)&s))) ^((int)(3)))))*((long)((((double)(3)) -((double)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
