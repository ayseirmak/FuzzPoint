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
  s.a.i = 0 + 42 - ((long)((((double)(0)) - ((double)(0))))) - ((int)((((double)(0)) - ((double)(s.a.i))))) - ((long)((((int)(s.a.i)) ^ ((int)(s.a.i)))));
  b->i = 3 + 42 - ((long)((((double)(3)) * ((double)(b->i))))) - ((int)((((int)(3)) % ((int)(b->i))))) - ((short)((((double)(3)) + ((double)(b->i))))) - ((int)((((double)(3)) - ((double)(3))))) - ((long)((((double)(3)) + ((double)(3)))));
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
  ((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((double)(sizeof (float))) + ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((int)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) % ((int)(sizeof (float)))))) + ((short)((((double)(sizeof (float) != sizeof (int))) * ((double)(offsetof (struct Q, a) != sizeof (int)))))) + ((int)((((double)(sizeof (int))) + ((double)(sizeof (float)))))) - ((int)((((int)(sizeof (int))) & ((int)(sizeof (float)))))) - ((long)((((double)(sizeof (int))) * ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) - ((long)((((int)(offsetof (struct R, a))) | ((int)(sizeof (int)))))) + ((short)((((int)(offsetof (struct R, a))) >> ((int)(sizeof (float) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 * ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) * ((long)((((double)(s.a.i)) + ((double)(s.a.i))))) - ((short)((((double)(1)) * ((double)(1))))) - ((int)((((double)(1)) - ((double)(1))))) * ((long)((((int)(s.a.i)) | ((int)(s.a.i)))));
  s.a.j = 2 + 42 + ((long)((((double)(2)) - ((double)(2))))) * ((long)((((double)(s.a.j)) - ((double)(s.a.j)))));
  if (((int)test1 ((void *)&s) != 3 + 41 + ((int)((((double)(3)) + ((double)(3))))) + ((short)((((double)(3)) * ((double)(3))))) * ((int)((((int)(test1 ((void *)&s))) ^ ((int)(3))))) - ((short)((((int)(test1 ((void *)&s))) << ((int)(test1 ((void *)&s)))))) + ((long)((((double)(3)) * ((double)(3))))) * ((long)((((int)(test1 ((void *)&s))) & ((int)(test1 ((void *)&s)))))) - ((long)((((int)(test1 ((void *)&s))) << ((int)(3))))) * ((long)((((int)(test1 ((void *)&s))) ^ ((int)(3))))) * ((int)((((int)(3)) >> ((int)(3)))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 - ((short)((((int)(3)) << ((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 + ((int)((((int)(test3 ((void *)&s))) % ((int)(test3 ((void *)&s)))))) - ((short)((((int)(test3 ((void *)&s))) | ((int)(3))))) + ((short)((((int)(3)) | ((int)(test3 ((void *)&s)))))) - ((int)((((int)(3)) | ((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
