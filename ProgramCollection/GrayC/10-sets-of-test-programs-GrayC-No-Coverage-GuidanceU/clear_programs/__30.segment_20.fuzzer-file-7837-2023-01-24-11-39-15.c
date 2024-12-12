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
  s.a.i = 0 + 42 * ((short)((((double)(0)) * ((double)(0))))) + ((short)((((double)(0)) * ((double)(0)))));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  b->i = 3 + 42 - ((short)((((double)(3)) * ((double)(b->i))))) + ((int)((((double)(3)) + ((double)(3))))) * ((int)((((int)(3)) << ((int)(3))))) * ((int)((((int)(b->i)) >> ((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 - ((long)((((double)(0)) - ((double)(0))))) * ((int)((((double)(0)) * ((double)(0))))) * ((short)((((int)(s.a.i)) ^ ((int)(s.a.i))))) * ((short)((((int)(0)) | ((int)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((int)((((int)(sizeof (float))) >> ((int)(sizeof (int)))))) - ((int)((((double)(offsetof (struct Q, a))) - ((double)(sizeof (float) != sizeof (int)))))) * ((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct Q, a)))))) - ((short)((((int)(sizeof (int))) >> ((int)(sizeof (float)))))) - ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) - ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) | ((int)(sizeof (int)))))) * ((long)((((double)(offsetof (struct Q, a))) + ((double)(offsetof (struct R, a)))))) - ((int)((((double)(offsetof (struct R, a) != sizeof (int))) * ((double)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((long)((((double)(2)) * ((double)(2))))) - ((int)((((int)(s.a.j)) << ((int)(2))))) + ((long)((((double)(s.a.j)) - ((double)(s.a.j))))) - ((long)((((double)(2)) * ((double)(2)))));
  if (0)
    { abort (); }
  s.a.i = 1 + 42 - ((int)((((double)(s.a.i)) + ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((short)((((double)(1)) - ((double)(s.a.i))))) * ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((int)((((int)(1)) & ((int)(1)))));
  s.a.j = 2 + 42 - ((int)((((int)(s.a.j)) ^ ((int)(2))))) - ((int)((((double)(2)) + ((double)(s.a.j))))) + ((short)((((int)(2)) ^ ((int)(s.a.j)))));
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
