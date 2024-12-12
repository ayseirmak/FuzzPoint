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
  s.a.i = 0 + 42 - ((int)((((int)(0)) ^ ((int)(s.a.i))))) * ((short)((((double)(0)) * ((double)(0)))));
  b->i = 3 + 42 * ((int)((((double)(3)) * ((double)(b->i))))) + ((int)((((int)(b->i)) << ((int)(b->i))))) + ((long)((((int)(b->i)) >> ((int)(b->i))))) + ((long)((((double)(3)) * ((double)(b->i))))) - ((int)((((double)(3)) - ((double)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 * ((long)((((int)(0)) & ((int)(s.a.i)))));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0;
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((short)((((int)(3)) | ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) - ((short)((((int)(3)) << ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 * ((int)((((int)(sizeof (int))) % ((int)(offsetof (struct R, a)))))) - ((int)((((int)(sizeof (int))) ^ ((int)(sizeof (float) != sizeof (int)))))) + ((int)((((double)(offsetof (struct R, a) != sizeof (int))) + ((double)(sizeof (int)))))) * ((int)((((double)(offsetof (struct Q, a) != sizeof (int))) + ((double)(sizeof (float)))))) * ((int)((((double)(offsetof (struct Q, a) != sizeof (int))) - ((double)(sizeof (int)))))) - ((int)((((int)(sizeof (float))) & ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) - ((long)((((double)(sizeof (int))) * ((double)(offsetof (struct R, a))))))))
    { return 0; }
  s.a.i = 1 + 42 * ((int)((((double)(1)) * ((double)(s.a.i))))) + ((short)((((int)(1)) << ((int)(1)))));
  s.a.j = 2;
  if (((int)test1 ((void *)&s) != 3 + 41 - ((short)((((int)(3)) ^ ((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1 + 42 + ((short)((((int)(s.a.i)) & ((int)(s.a.i)))));
  s.a.j = 2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
