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
  
s.a.i = 0 + 42 +((int)((((double)(s.a.i)) *((double)(s.a.i)))));
s.a.i = 0 + 42 *((long)((((double)(s.a.i)) *((double)(0)))));
;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
s.a.i = 0 + 42 +((int)((((int)(s.a.i)) %((int)(s.a.i)))));
s.a.i = 0 + 42 +((short)((((int)(s.a.i)) >>((int)(0)))))*((int)((((double)(0)) -((double)(0)))));
;
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
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 42 -((int)((((int)(offsetof (struct Q, a) != sizeof (int))) |((int)(sizeof (int))))))+((int)((((int)(offsetof (struct R, a))) |((int)(sizeof (float) != sizeof (int))))))-((long)((((double)(offsetof (struct Q, a) != sizeof (int))) -((double)(sizeof (float) != sizeof (int))))))*((short)((((double)(sizeof (int))) +((double)(sizeof (int))))))))
    { return 0; }
  
s.a.i = 1 + 42 -((long)((((int)(1)) &((int)(1)))));
s.a.i = 1 + 42 -((short)((((int)(s.a.i)) %((int)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)(s.a.i)))));
;
  
s.a.j = 2 + 42 -((long)((((double)(2)) +((double)(s.a.j)))));
s.a.j = 2 + 42 *((int)((((double)(s.a.j)) +((double)(s.a.j)))))-((int)((((double)(2)) +((double)(s.a.j)))))+((short)((((int)(s.a.j)) ^((int)(s.a.j)))));
;
  if (((int)test1 ((void *)&s) != 3 + 42 +((long)((((int)(test1 ((void *)&s))) <<((int)(test1 ((void *)&s))))))-((short)((((int)(test1 ((void *)&s))) >>((int)(test1 ((void *)&s))))))*((long)((((int)(3)) |((int)(test1 ((void *)&s))))))+((long)((((double)(3)) -((double)(3)))))-((short)((((int)(test1 ((void *)&s))) >>((int)(test1 ((void *)&s))))))*((int)((((int)(3)) &((int)(test1 ((void *)&s))))))+((int)((((int)(test1 ((void *)&s))) ^((int)(3)))))*((long)((((int)(test1 ((void *)&s))) %((int)(3)))))*((short)((((int)(test1 ((void *)&s))) %((int)(test1 ((void *)&s))))))-((long)((((int)(test1 ((void *)&s))) &((int)(test1 ((void *)&s))))))))
    { abort (); }
  ;
  
s.a.j = 2 + 42 -((int)((((double)(2)) +((double)(2)))))-((int)((((double)(s.a.j)) -((double)(s.a.j)))))*((long)((((double)(s.a.j)) *((double)(s.a.j)))));
s.a.j = 2 + 42 -((short)((((double)(s.a.j)) +((double)(2)))))-((short)((((double)(2)) +((double)(2)))))+((short)((((double)(s.a.j)) *((double)(2)))))+((short)((((double)(2)) *((double)(2)))));
;
  if (((int)test2 ((void *)&s) != 3 + 42 -((short)((((int)(test2 ((void *)&s))) <<((int)(test2 ((void *)&s))))))+((long)((((int)(3)) &((int)(test2 ((void *)&s))))))*((long)((((double)(3)) +((double)(3)))))+((long)((((int)(3)) |((int)(test2 ((void *)&s))))))-((int)((((int)(3)) &((int)(test2 ((void *)&s))))))))
    { abort (); }
  ;
  ;
  if (((int)test3 ((void *)&s) != 3 + 42 *((short)((((int)(3)) ^((int)(test3 ((void *)&s))))))*((long)((((int)(test3 ((void *)&s))) |((int)(3)))))*((int)((((int)(3)) ^((int)(test3 ((void *)&s))))))-((long)((((int)(3)) ^((int)(3)))))*((int)((((double)(3)) +((double)(3)))))-((short)((((int)(test3 ((void *)&s))) <<((int)(3)))))*((int)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))+((short)((((double)(3)) -((double)(3)))))-((long)((((double)(3)) *((double)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
