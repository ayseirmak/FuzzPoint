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
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  ;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = 0 + 42 *((long)((((int)(s.a.i)) %((int)(s.a.i)))))-((short)((((double)(s.a.i)) *((double)(0)))))-((long)((((int)(0)) ^((int)(0)))));
s.a.i = 0 + 42 *((short)((((double)(0)) *((double)(0)))))+((int)((((int)(s.a.i)) |((int)(0)))))-((short)((((double)(s.a.i)) +((double)(s.a.i)))));
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
      || offsetof (struct Q, a) != sizeof (int) + 42 +((int)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) -((double)(sizeof (int))))))+((long)((((double)(sizeof (float))) -((double)(offsetof (struct R, a) != sizeof (int))))))-((short)((((double)(offsetof (struct R, a) != sizeof (int))) -((double)(offsetof (struct Q, a))))))*((int)((((double)(offsetof (struct Q, a))) *((double)(offsetof (struct R, a))))))*((int)((((double)(offsetof (struct R, a))) *((double)(offsetof (struct Q, a))))))+((long)((((int)(offsetof (struct Q, a) != sizeof (int))) ^((int)(sizeof (int))))))-((short)((((double)(offsetof (struct R, a))) -((double)(sizeof (int))))))-((long)((((int)(sizeof (float) != sizeof (int))) ^((int)(sizeof (int))))))))
    { return 0; }
  
s.a.i = 1 + 42 +((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((int)((((int)(s.a.i)) <<((int)(1)))))-((short)((((int)(s.a.i)) <<((int)(s.a.i)))));
s.a.i = 1 + 42 *((int)((((int)(s.a.i)) >>((int)(s.a.i)))));
;
  ;
  if (((int)test1 ((void *)&s) != 3 + 42 *((long)((((int)(test1 ((void *)&s))) %((int)(3)))))+((int)((((int)(3)) &((int)(test1 ((void *)&s))))))*((long)((((int)(test1 ((void *)&s))) |((int)(test1 ((void *)&s))))))))
    { abort (); }
  
s.a.i = 1 + 42 *((short)((((int)(s.a.i)) &((int)(s.a.i)))));
s.a.i = 1 + 42 -((short)((((double)(1)) +((double)(s.a.i)))))*((short)((((double)(s.a.i)) -((double)(1)))))*((short)((((int)(1)) &((int)(1)))))+((short)((((double)(1)) *((double)(1)))));
;
  ;
  if (((int)test2 ((void *)&s) != 3 + 42 +((int)((((double)(3)) *((double)(3)))))+((short)((((double)(3)) -((double)(3)))))))
    { abort (); }
  ;
  
s.a.j = 2 + 42 +((long)((((int)(2)) %((int)(2)))));
s.a.j = 2 + 42 +((short)((((int)(2)) &((int)(2)))))+((long)((((double)(s.a.j)) +((double)(2)))))+((long)((((int)(2)) <<((int)(s.a.j)))))+((int)((((double)(s.a.j)) +((double)(s.a.j)))))*((int)((((double)(s.a.j)) -((double)(s.a.j)))));
;
  if (((int)test3 ((void *)&s) != 3 + 42 *((short)((((int)(test3 ((void *)&s))) |((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) ^((int)(test3 ((void *)&s))))))*((long)((((int)(3)) &((int)(test3 ((void *)&s))))))*((short)((((int)(test3 ((void *)&s))) >>((int)(test3 ((void *)&s))))))+((short)((((int)(3)) %((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
