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
  s.a.i = 0 + 42 + ((long)((((double)(s.a.i)) * ((double)(0))))) + ((short)((((int)(s.a.i)) & ((int)(0)))));
  b->i = 3 + 42 + ((int)((((int)(3)) ^ ((int)(b->i))))) * ((short)((((int)(b->i)) | ((int)(3))))) + ((long)((((int)(3)) << ((int)(3))))) * ((short)((((int)(b->i)) << ((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 + ((short)((((int)(s.a.i)) << ((int)(s.a.i))))) * ((long)((((int)(0)) | ((int)(s.a.i))))) * ((int)((((int)(s.a.i)) << ((int)(0)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 + ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) >> ((int)(3))))) + ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) >> ((int)(3))))) * ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) % ((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((long)((((int)(sizeof (int))) << ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((long)((((int)(offsetof (struct R, a))) | ((int)(offsetof (struct Q, a) != sizeof (int)))))) * ((long)((((int)(offsetof (struct Q, a))) | ((int)(offsetof (struct Q, a) != sizeof (int)))))) * ((short)((((double)(sizeof (int))) * ((double)(sizeof (float) != sizeof (int)))))) + ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) - ((double)(sizeof (int)))))) * ((int)((((double)(sizeof (int))) - ((double)(offsetof (struct R, a)))))) * ((int)((((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int)))))) + ((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) - ((int)((((double)(offsetof (struct R, a))) - ((double)(offsetof (struct Q, a)))))) * ((short)((((int)(sizeof (float) != sizeof (int))) << ((int)(sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 - ((long)((((double)(s.a.i)) - ((double)(1)))));
  s.a.j = 2 + 42 + ((short)((((double)(s.a.j)) * ((double)(2))))) + ((long)((((int)(s.a.j)) % ((int)(2))))) - ((short)((((double)(2)) + ((double)(s.a.j))))) * ((int)((((int)(s.a.j)) << ((int)(2)))));
  if (0)
    { abort (); }
  s.a.i = 1 + 42 - ((int)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) ^ ((int)(s.a.i))))) * ((int)((((int)(s.a.i)) >> ((int)(1))))) * ((long)((((double)(s.a.i)) + ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(1)))));
  s.a.j = 2 + 42 - ((long)((((double)(2)) * ((double)(s.a.j))))) * ((short)((((int)(2)) | ((int)(2))))) * ((int)((((double)(2)) - ((double)(2))))) - ((long)((((double)(2)) * ((double)(s.a.j)))));
  if (((int)test2 ((void *)&s) != 3 + 41 * ((int)((((int)(3)) | ((int)(test2 ((void *)&s)))))) + ((short)((((int)(test2 ((void *)&s))) & ((int)(test2 ((void *)&s)))))) + ((short)((((int)(3)) | ((int)(test2 ((void *)&s)))))) * ((int)((((int)(3)) ^ ((int)(test2 ((void *)&s)))))) - ((long)((((int)(test2 ((void *)&s))) % ((int)(3))))) - ((short)((((double)(3)) * ((double)(3))))) * ((int)((((int)(test2 ((void *)&s))) >> ((int)(test2 ((void *)&s)))))) - ((short)((((int)(3)) | ((int)(3)))))))
    { abort (); }
  s.a.i = 1 + 42 - ((short)((((int)(1)) % ((int)(s.a.i)))));
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 - ((short)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) + ((int)((((int)(test3 ((void *)&s))) | ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
