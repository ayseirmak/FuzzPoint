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
  s.a.i = 0 + 42 +((short)((((int)(s.a.i)) >>((int)(s.a.i)))))*((short)((((double)(s.a.i)) +((double)(0)))))*((int)((((double)(0)) *((double)(0)))));
  b->i = 3 + 42 *((int)((((int)(b->i)) >>((int)(3)))))+((short)((((double)(3)) +((double)(b->i)))))-((short)((((double)(b->i)) -((double)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 +((int)((((double)(s.a.i)) *((double)(0)))));
  b->i = 3 + 42 -((long)((((double)(3)) *((double)(b->i)))))+((long)((((double)(b->i)) -((double)(b->i)))))*((short)((((int)(3)) >>((int)(3)))))+((long)((((int)(b->i)) >>((int)(b->i)))))+((long)((((int)(3)) &((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 -((int)((((double)(s.a.i)) +((double)(0)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 +((short)((((int)(3)) &((int)(3)))))-((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(3)))))*((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))))*((short)((((double)(3)) *((double)(3)))))*((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 42 +((int)((((int)(sizeof (int))) <<((int)(offsetof (struct R, a) != sizeof (int))))))*((short)((((int)(sizeof (int))) >>((int)(sizeof (float) != sizeof (int))))))*((int)((((double)(offsetof (struct Q, a))) -((double)(sizeof (int))))))-((int)((((int)(offsetof (struct R, a))) ^((int)(offsetof (struct R, a))))))))
    { return 0; }
  s.a.i = 1 + 42 -((short)((((double)(s.a.i)) *((double)(s.a.i)))))+((short)((((int)(s.a.i)) ^((int)(s.a.i)))));
  s.a.j = 2 + 42 +((int)((((int)(s.a.j)) %((int)(s.a.j)))));
  if (((int)test1 ((void *)&s) != 3 + 42 *((short)((((int)(test1 ((void *)&s))) %((int)(test1 ((void *)&s))))))-((long)((((int)(3)) &((int)(test1 ((void *)&s))))))+((long)((((int)(3)) ^((int)(test1 ((void *)&s))))))-((int)((((int)(3)) &((int)(3)))))))
    { abort (); }
  s.a.i = 1 + 42 *((short)((((int)(s.a.i)) |((int)(s.a.i)))));
  s.a.j = 2 + 42 -((long)((((double)(s.a.j)) *((double)(2)))))-((short)((((int)(s.a.j)) |((int)(s.a.j)))))*((int)((((double)(2)) -((double)(2)))))+((int)((((int)(2)) <<((int)(s.a.j)))))*((short)((((int)(2)) |((int)(s.a.j)))));
  if (((int)test2 ((void *)&s) != 3 + 42 *((short)((((int)(test2 ((void *)&s))) &((int)(test2 ((void *)&s))))))-((short)((((int)(test2 ((void *)&s))) <<((int)(3)))))+((int)((((int)(test2 ((void *)&s))) >>((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1 + 42 *((short)((((int)(1)) ^((int)(s.a.i)))))+((short)((((double)(1)) *((double)(1)))))+((int)((((int)(1)) |((int)(1)))));
  s.a.j = 2 + 42 *((int)((((int)(s.a.j)) >>((int)(2)))));
  if (((int)test3 ((void *)&s) != 3 + 42 -((int)((((int)(3)) &((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
