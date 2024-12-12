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
  s.a.i = 0 + 42 -((long)((((double)(s.a.i)) *((double)(0)))))*((short)((((int)(s.a.i)) >>((int)(s.a.i)))))-((long)((((int)(s.a.i)) %((int)(0)))))-((int)((((int)(s.a.i)) >>((int)(s.a.i)))));
  b->i = 3 + 42 +((int)((((double)(3)) -((double)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 -((short)((((double)(0)) +((double)(0)))))-((short)((((int)(0)) <<((int)(s.a.i)))))*((int)((((int)(0)) ^((int)(s.a.i)))))+((long)((((int)(0)) |((int)(s.a.i)))));
  b->i = 3 + 42 -((short)((((int)(3)) >>((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 -((int)((((double)(s.a.i)) *((double)(0)))))+((long)((((double)(0)) *((double)(0)))))*((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) |((int)(0)))))*((int)((((int)(s.a.i)) ^((int)(0)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 -((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) >>((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 42 +((long)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) -((double)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 *((short)((((int)(1)) ^((int)(1)))))-((int)((((double)(s.a.i)) *((double)(1)))))*((long)((((int)(s.a.i)) ^((int)(s.a.i)))));
  s.a.j = 2 + 42 -((int)((((double)(s.a.j)) +((double)(s.a.j)))))-((short)((((double)(s.a.j)) -((double)(2)))));
  if (((int)test1 ((void *)&s) != 3 + 42 -((int)((((int)(test1 ((void *)&s))) >>((int)(test1 ((void *)&s))))))*((long)((((int)(3)) |((int)(test1 ((void *)&s))))))-((long)((((int)(3)) &((int)(3)))))))
    { abort (); }
  s.a.i = 1 + 42 *((short)((((double)(1)) -((double)(1)))))+((long)((((double)(1)) *((double)(s.a.i)))));
  s.a.j = 2 + 42 *((long)((((double)(2)) *((double)(s.a.j)))))-((long)((((double)(2)) +((double)(s.a.j)))))-((int)((((double)(s.a.j)) -((double)(s.a.j)))));
  if (((int)test2 ((void *)&s) != 3 + 42 +((int)((((int)(3)) &((int)(test2 ((void *)&s))))))-((long)((((int)(3)) >>((int)(test2 ((void *)&s))))))+((short)((((int)(test2 ((void *)&s))) <<((int)(3)))))-((short)((((int)(3)) %((int)(test2 ((void *)&s))))))-((short)((((int)(3)) ^((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1 + 42 -((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(s.a.i)))))-((int)((((int)(1)) <<((int)(s.a.i)))))+((int)((((double)(1)) *((double)(s.a.i)))))*((long)((((int)(1)) %((int)(s.a.i)))));
  s.a.j = 2 + 42 +((short)((((double)(2)) +((double)(s.a.j)))));
  if (((int)test3 ((void *)&s) != 3 + 42 *((long)((((int)(test3 ((void *)&s))) >>((int)(3)))))+((long)((((int)(test3 ((void *)&s))) >>((int)(3)))))-((short)((((int)(3)) >>((int)(test3 ((void *)&s))))))-((long)((((int)(3)) %((int)(test3 ((void *)&s))))))-((long)((((double)(3)) -((double)(3)))))*((short)((((int)(3)) |((int)(test3 ((void *)&s))))))+((int)((((int)(test3 ((void *)&s))) %((int)(3)))))-((int)((((int)(test3 ((void *)&s))) >>((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
