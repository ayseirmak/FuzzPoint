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
  s.a.i = 0 + 42 * ((short)((((double)(0)) - ((double)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((double)(offsetof (struct Q, a))) * ((double)(sizeof (int)))))) + ((int)((((double)(offsetof (struct R, a) != sizeof (int))) + ((double)(sizeof (float)))))) * ((long)((((int)(sizeof (float))) | ((int)(sizeof (float)))))) - ((int)((((int)(sizeof (float))) ^ ((int)(offsetof (struct R, a)))))) * ((short)((((double)(sizeof (float) != sizeof (int))) - ((double)(offsetof (struct Q, a) != sizeof (int)))))) + ((int)((((double)(offsetof (struct R, a))) + ((double)(sizeof (float) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1;
  s.a.j = 2 + 42 * ((long)((((int)(s.a.j)) | ((int)(s.a.j))))) + ((int)((((int)(2)) | ((int)(2)))));
  if (((int)test1 ((void *)&s) != 3 + 41 + ((short)((((int)(3)) % ((int)(3))))) + ((int)((((int)(3)) & ((int)(test1 ((void *)&s)))))) * ((long)((((int)(test1 ((void *)&s))) & ((int)(test1 ((void *)&s)))))) * ((int)((((double)(3)) + ((double)(3))))) * ((long)((((int)(test1 ((void *)&s))) | ((int)(test1 ((void *)&s)))))) - ((long)((((double)(3)) - ((double)(3))))) - ((long)((((int)(3)) % ((int)(3))))) * ((short)((((int)(3)) & ((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 * ((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) * ((long)((((double)(3)) + ((double)(3))))) + ((long)((((int)(test2 ((void *)&s))) << ((int)(3))))) - ((int)((((int)(test2 ((void *)&s))) << ((int)(3))))) - ((short)((((int)(3)) % ((int)(test2 ((void *)&s)))))) + ((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s)))))) - ((short)((((double)(3)) + ((double)(3)))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 - ((int)((((int)(3)) ^ ((int)(3))))) + ((short)((((int)(test3 ((void *)&s))) & ((int)(3))))) - ((short)((((int)(test3 ((void *)&s))) & ((int)(3))))) - ((short)((((int)(3)) % ((int)(3))))) - ((short)((((int)(test3 ((void *)&s))) ^ ((int)(3))))) - ((short)((((int)(3)) % ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
