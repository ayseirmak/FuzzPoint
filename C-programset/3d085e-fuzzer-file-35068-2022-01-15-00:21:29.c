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
  s.a.i = (0);
  b->i = (-4);
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (0);
  b->i = (1);
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (-1);
  ((struct S *)((char *)q + sizeof (int)))->i = (0x1640);
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int))
    { return (0); }
  s.a.i = (0xA2F2);
  s.a.j = (2);
  if ((0))
    { abort (); }
  s.a.i = (1);
  s.a.j = (-3);
  if ((0))
    { abort (); }
  s.a.i = (65);
  s.a.j = (0x2);
  if ((0))
    { abort (); }
  return (256);
}
/* ProgramSourceLLVM */
