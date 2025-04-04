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
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((long)((((int)(3)) % ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) - ((long)((((double)(3)) * ((double)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((int)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) | ((int)(sizeof (float) != sizeof (int)))))) * ((short)((((int)(sizeof (int))) ^ ((int)(offsetof (struct Q, a) != sizeof (int)))))) + ((int)((((int)(sizeof (float))) | ((int)(offsetof (struct Q, a)))))) + ((long)((((int)(sizeof (float) != sizeof (int))) >> ((int)(sizeof (float) != sizeof (int)))))) * ((int)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) * ((double)(sizeof (float)))))) - ((int)((((int)(offsetof (struct Q, a))) << ((int)(sizeof (float) != sizeof (int)))))) + ((long)((((int)(offsetof (struct R, a))) << ((int)(sizeof (float) != sizeof (int)))))) - ((int)((((int)(offsetof (struct R, a))) ^ ((int)(offsetof (struct R, a))))))))
    { return 0; }
  s.a.i = 1 + 42 * ((long)((((double)(s.a.i)) * ((double)(1))))) - ((short)((((int)(1)) & ((int)(1))))) - ((long)((((double)(1)) - ((double)(s.a.i)))));
  s.a.j = 2;
  if (((int)test1 ((void *)&s) != 3 + 41 * ((short)((((int)(test1 ((void *)&s))) & ((int)(3))))) - ((long)((((int)(test1 ((void *)&s))) >> ((int)(test1 ((void *)&s)))))) * ((long)((((double)(3)) * ((double)(3))))) * ((int)((((int)(3)) | ((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((short)((((double)(s.a.j)) * ((double)(s.a.j))))) + ((int)((((double)(2)) + ((double)(s.a.j))))) - ((long)((((int)(s.a.j)) ^ ((int)(2))))) * ((int)((((double)(2)) + ((double)(2))))) + ((int)((((double)(2)) - ((double)(s.a.j)))));
  if (((int)test2 ((void *)&s) != 3 + 41 + ((short)((((int)(3)) | ((int)(3))))) + ((int)((((double)(3)) - ((double)(3))))) * ((long)((((int)(test2 ((void *)&s))) ^ ((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 * ((int)((((int)(s.a.j)) & ((int)(s.a.j))))) * ((int)((((double)(s.a.j)) * ((double)(s.a.j)))));
  if (((int)test3 ((void *)&s) != 3 + 41 - ((long)((((int)(test3 ((void *)&s))) % ((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
