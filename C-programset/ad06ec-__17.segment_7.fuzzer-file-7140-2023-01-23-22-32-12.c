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
  s.a.i = 0 + 42 + ((short)((((double)(0)) + ((double)(s.a.i)))));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 * ((int)((((int)(s.a.i)) >> ((int)(s.a.i))))) + ((short)((((int)(s.a.i)) % ((int)(s.a.i)))));
  b->i = 3 + 42 * ((int)((((double)(3)) - ((double)(b->i))))) - ((short)((((int)(b->i)) % ((int)(b->i))))) * ((int)((((double)(b->i)) * ((double)(b->i))))) - ((int)((((int)(b->i)) | ((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 * ((int)((((int)(s.a.i)) % ((int)(0))))) + ((short)((((int)(0)) % ((int)(s.a.i))))) * ((long)((((double)(0)) + ((double)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((short)((((int)(offsetof (struct R, a) != sizeof (int))) << ((int)(sizeof (int)))))) - ((short)((((double)(sizeof (int))) + ((double)(sizeof (float) != sizeof (int)))))) + ((long)((((double)(sizeof (int))) * ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((long)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a)))))) - ((long)((((double)(sizeof (float))) + ((double)(sizeof (int)))))) - ((long)((((double)(offsetof (struct R, a))) * ((double)(offsetof (struct Q, a)))))) - ((short)((((double)(sizeof (int))) + ((double)(offsetof (struct Q, a) != sizeof (int)))))) - ((int)((((int)(sizeof (float) != sizeof (int))) ^ ((int)(sizeof (float) != sizeof (int)))))) * ((long)((((int)(sizeof (int))) | ((int)(offsetof (struct Q, a) != sizeof (int)))))) - ((short)((((double)(sizeof (int))) + ((double)(offsetof (struct R, a))))))))
    { return 0; }
  s.a.i = 1;
  s.a.j = 2 + 42 - ((short)((((int)(2)) | ((int)(s.a.j))))) + ((short)((((int)(s.a.j)) % ((int)(s.a.j)))));
  if (((int)test1 ((void *)&s) != 3 + 41 + ((long)((((int)(test1 ((void *)&s))) & ((int)(test1 ((void *)&s)))))) - ((short)((((int)(test1 ((void *)&s))) % ((int)(3))))) + ((long)((((int)(3)) & ((int)(test1 ((void *)&s)))))) - ((short)((((int)(test1 ((void *)&s))) << ((int)(3))))) - ((int)((((int)(3)) % ((int)(3))))) + ((long)((((double)(3)) + ((double)(3)))))))
    { abort (); }
  s.a.i = 1 + 42 * ((int)((((int)(1)) << ((int)(1))))) + ((short)((((double)(1)) + ((double)(1)))));
  s.a.j = 2 + 42 + ((short)((((double)(s.a.j)) * ((double)(s.a.j))))) + ((long)((((int)(2)) & ((int)(s.a.j))))) + ((long)((((double)(s.a.j)) - ((double)(s.a.j))))) * ((short)((((int)(s.a.j)) % ((int)(2))))) - ((short)((((int)(2)) & ((int)(2)))));
  if (((int)test2 ((void *)&s) != 3 + 41 * ((long)((((double)(3)) - ((double)(3)))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 - ((short)((((double)(s.a.j)) - ((double)(s.a.j))))) * ((int)((((double)(2)) + ((double)(s.a.j)))));
  if (((int)test3 ((void *)&s) != 3 + 41 * ((short)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) - ((int)((((int)(3)) >> ((int)(test3 ((void *)&s)))))) + ((short)((((int)(test3 ((void *)&s))) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(3)) | ((int)(3))))) + ((short)((((double)(3)) + ((double)(3))))) - ((short)((((int)(3)) << ((int)(test3 ((void *)&s)))))) * ((long)((((int)(3)) << ((int)(test3 ((void *)&s)))))) - ((long)((((int)(test3 ((void *)&s))) >> ((int)(3))))) * ((int)((((int)(test3 ((void *)&s))) ^ ((int)(3))))) - ((short)((((int)(test3 ((void *)&s))) % ((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
