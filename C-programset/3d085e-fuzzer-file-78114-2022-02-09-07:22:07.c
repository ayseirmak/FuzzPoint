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
  s.a.i = 0 + 42 -((int)((((int)(s.a.i)) <<((int)(s.a.i)))))-((long)((((int)(s.a.i)) |((int)(0)))));
  b->i = 3 + 42 +((short)((((double)(3)) *((double)(3)))))+((long)((((int)(b->i)) |((int)(3)))))*((long)((((double)(b->i)) +((double)(3)))))+((short)((((double)(3)) +((double)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 -((long)((((double)(0)) -((double)(s.a.i)))))-((long)((((double)(0)) -((double)(0)))));
  b->i = 3 + 42 -((long)((((int)(b->i)) ^((int)(b->i)))))+((long)((((int)(3)) >>((int)(3)))))*((short)((((int)(3)) %((int)(3)))))-((long)((((double)(3)) +((double)(3)))))+((long)((((double)(3)) +((double)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 +((long)((((double)(s.a.i)) +((double)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 -((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(((struct S *)((char *)q + sizeof (int)))->i)))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))))-((short)((((int)(3)) %((int)(3)))))*((short)((((int)(3)) ^((int)(3)))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 42 *((long)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) +((double)(offsetof (struct R, a))))))-((short)((((double)(sizeof (int))) +((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) -((double)(offsetof (struct R, a))))))))
    { return 0; }
  s.a.i = 1 + 42 -((long)((((double)(s.a.i)) +((double)(1)))))+((int)((((double)(1)) *((double)(1)))))-((int)((((int)(s.a.i)) |((int)(1)))))+((int)((((double)(s.a.i)) *((double)(s.a.i)))));
  s.a.j = 2 + 42 +((long)((((double)(s.a.j)) +((double)(s.a.j)))))+((long)((((int)(2)) %((int)(s.a.j)))))*((short)((((int)(s.a.j)) >>((int)(s.a.j)))))*((int)((((int)(2)) >>((int)(s.a.j)))));
  if (((int)test1 ((void *)&s) != 3 + 42 -((int)((((int)(test1 ((void *)&s))) ^((int)(test1 ((void *)&s))))))*((long)((((int)(test1 ((void *)&s))) <<((int)(test1 ((void *)&s))))))-((long)((((int)(3)) ^((int)(test1 ((void *)&s))))))+((int)((((int)(test1 ((void *)&s))) ^((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1 + 42 -((short)((((int)(s.a.i)) <<((int)(1)))))-((short)((((double)(s.a.i)) -((double)(s.a.i)))));
  s.a.j = 2 + 42 -((short)((((int)(s.a.j)) >>((int)(2)))))+((long)((((double)(s.a.j)) *((double)(2)))));
  if (((int)test2 ((void *)&s) != 3 + 42 *((int)((((int)(test2 ((void *)&s))) <<((int)(3)))))+((int)((((int)(test2 ((void *)&s))) ^((int)(test2 ((void *)&s))))))*((short)((((int)(3)) |((int)(3)))))+((long)((((int)(test2 ((void *)&s))) %((int)(3)))))*((long)((((int)(test2 ((void *)&s))) >>((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1 + 42 *((long)((((int)(1)) <<((int)(s.a.i)))))-((long)((((int)(1)) |((int)(1)))));
  s.a.j = 2 + 42 -((int)((((double)(2)) +((double)(2)))))-((long)((((double)(2)) -((double)(2)))))*((int)((((int)(2)) |((int)(s.a.j)))))*((long)((((double)(2)) +((double)(2)))))*((short)((((double)(2)) -((double)(2)))));
  if (((int)test3 ((void *)&s) != 3 + 42 -((short)((((int)(3)) <<((int)(3)))))+((short)((((int)(3)) |((int)(test3 ((void *)&s))))))*((short)((((int)(3)) >>((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
