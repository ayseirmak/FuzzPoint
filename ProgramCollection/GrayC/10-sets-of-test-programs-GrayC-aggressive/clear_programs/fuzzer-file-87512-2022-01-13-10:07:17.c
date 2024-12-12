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
  s.a.i = 0 + 42 *((short)((((int)(0)) ^((int)(0)))))-((short)((((int)(0)) |((int)(s.a.i)))))-((short)((((double)(s.a.i)) +((double)(0)))))+((int)((((int)(0)) &((int)(0)))))+((long)((((double)(0)) +((double)(s.a.i)))));
  b->i = 3 + 42 *((long)((((int)(3)) <<((int)(3)))))+((short)((((int)(b->i)) %((int)(3)))))*((short)((((double)(b->i)) *((double)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 -((int)((((double)(s.a.i)) *((double)(s.a.i)))))*((long)((((int)(0)) %((int)(s.a.i)))))+((int)((((double)(0)) +((double)(s.a.i)))));
  b->i = 3 + 42 +((int)((((int)(b->i)) %((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 *((int)((((int)(0)) &((int)(s.a.i)))))-((short)((((double)(0)) +((double)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 +((short)((((double)(3)) *((double)(3)))))*((long)((((double)(3)) -((double)(3)))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 42 +((long)((((double)(sizeof (int))) *((double)(offsetof (struct R, a))))))-((short)((((double)(offsetof (struct Q, a) != sizeof (int))) -((double)(offsetof (struct Q, a) != sizeof (int))))))-((long)((((int)(offsetof (struct R, a))) &((int)(sizeof (float))))))+((long)((((double)(sizeof (int))) +((double)(sizeof (int))))))*((long)((((int)(sizeof (float) != sizeof (int))) <<((int)(sizeof (float))))))))
    { return 0; }
  s.a.i = 1 + 42 -((long)((((double)(s.a.i)) *((double)(s.a.i)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))-((long)((((double)(1)) +((double)(s.a.i)))))+((long)((((double)(s.a.i)) +((double)(s.a.i)))));
  s.a.j = 2 + 42 +((int)((((int)(s.a.j)) >>((int)(s.a.j)))))+((short)((((int)(2)) ^((int)(s.a.j)))))*((long)((((int)(s.a.j)) >>((int)(2)))))*((long)((((double)(s.a.j)) *((double)(s.a.j)))))*((short)((((double)(2)) *((double)(s.a.j)))));
  if (((int)test1 ((void *)&s) != 3 + 42 +((short)((((int)(test1 ((void *)&s))) &((int)(3)))))))
    { abort (); }
  s.a.i = 1 + 42 -((long)((((double)(1)) *((double)(s.a.i)))))*((short)((((double)(1)) -((double)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)(1)))));
  s.a.j = 2 + 42 +((int)((((double)(2)) +((double)(s.a.j)))))+((short)((((int)(s.a.j)) >>((int)(s.a.j)))))+((long)((((double)(s.a.j)) *((double)(s.a.j)))))-((long)((((int)(2)) |((int)(s.a.j)))));
  if (((int)test2 ((void *)&s) != 3 + 42 *((long)((((int)(test2 ((void *)&s))) ^((int)(3)))))-((int)((((int)(test2 ((void *)&s))) |((int)(test2 ((void *)&s))))))*((short)((((int)(3)) <<((int)(test2 ((void *)&s))))))*((short)((((int)(3)) %((int)(3)))))+((long)((((int)(test2 ((void *)&s))) >>((int)(test2 ((void *)&s))))))*((short)((((int)(test2 ((void *)&s))) ^((int)(3)))))-((long)((((double)(3)) *((double)(3)))))*((int)((((int)(test2 ((void *)&s))) <<((int)(3)))))*((int)((((int)(test2 ((void *)&s))) |((int)(3)))))-((short)((((int)(test2 ((void *)&s))) &((int)(3)))))))
    { abort (); }
  s.a.i = 1 + 42 *((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((int)(s.a.i)) &((int)(1)))))*((long)((((int)(1)) <<((int)(1)))))-((int)((((int)(s.a.i)) &((int)(s.a.i)))));
  s.a.j = 2 + 42 -((short)((((int)(s.a.j)) &((int)(s.a.j)))))+((int)((((int)(s.a.j)) ^((int)(2)))))-((short)((((double)(s.a.j)) *((double)(2)))))*((int)((((int)(s.a.j)) &((int)(s.a.j)))))*((long)((((double)(2)) -((double)(2)))));
  if (((int)test3 ((void *)&s) != 3 + 42 -((int)((((int)(3)) &((int)(3)))))+((long)((((int)(test3 ((void *)&s))) &((int)(3)))))-((int)((((int)(test3 ((void *)&s))) >>((int)(test3 ((void *)&s))))))*((short)((((int)(3)) >>((int)(test3 ((void *)&s))))))+((long)((((int)(3)) ^((int)(3)))))-((int)((((double)(3)) *((double)(3)))))*((long)((((int)(test3 ((void *)&s))) |((int)(test3 ((void *)&s))))))*((short)((((int)(3)) |((int)(3)))))+((long)((((int)(test3 ((void *)&s))) >>((int)(3)))))*((int)((((int)(3)) &((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
