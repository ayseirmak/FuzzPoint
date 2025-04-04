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
  s.a.i = 0;
  b->i = 3;
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
  s.a.i = 0;
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) << ((int)(3))))) + ((int)((((int)(3)) & ((int)(3))))) + ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) - ((long)((((int)(3)) & ((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((int)((((int)(offsetof (struct R, a))) ^ ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((int)((((double)(offsetof (struct R, a))) + ((double)(offsetof (struct Q, a))))))))
    { return 0; }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test1 ((void *)&s) != 3 + 41 * ((short)((((int)(test1 ((void *)&s))) % ((int)(test1 ((void *)&s)))))) - ((short)((((int)(test1 ((void *)&s))) >> ((int)(3))))) * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))) * ((long)((((int)(test1 ((void *)&s))) & ((int)(3))))) - ((long)((((int)(test1 ((void *)&s))) >> ((int)(test1 ((void *)&s)))))) * ((int)((((int)(3)) & ((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 - ((long)((((double)(s.a.j)) * ((double)(2))))) - ((short)((((int)(2)) >> ((int)(2))))) + ((long)((((double)(s.a.j)) + ((double)(2)))));
  if (((int)test2 ((void *)&s) != 3 + 41 + ((long)((((int)(test2 ((void *)&s))) & ((int)(3))))) + ((short)((((int)(3)) % ((int)(test2 ((void *)&s)))))) * ((long)((((int)(test2 ((void *)&s))) & ((int)(3))))) - ((long)((((int)(test2 ((void *)&s))) << ((int)(3))))) * ((long)((((int)(3)) << ((int)(test2 ((void *)&s)))))) + ((int)((((int)(test2 ((void *)&s))) >> ((int)(test2 ((void *)&s)))))) * ((long)((((int)(3)) ^ ((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1 + 42 + ((short)((((double)(1)) + ((double)(1))))) - ((long)((((double)(1)) + ((double)(1))))) + ((int)((((int)(1)) & ((int)(1))))) - ((long)((((double)(s.a.i)) * ((double)(s.a.i)))));
  s.a.j = 2 + 42 * ((long)((((double)(2)) - ((double)(s.a.j))))) - ((short)((((double)(2)) - ((double)(s.a.j))))) * ((int)((((int)(2)) | ((int)(s.a.j))))) * ((long)((((double)(s.a.j)) + ((double)(s.a.j)))));
  if (((int)test3 ((void *)&s) != 3 + 41 + ((short)((((int)(3)) >> ((int)(test3 ((void *)&s)))))) + ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) & ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
