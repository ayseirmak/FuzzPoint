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
  s.a.i = 0 + 42 * ((int)((((int)(s.a.i)) % ((int)(s.a.i)))));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0;
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) & ((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 * ((int)((((double)(sizeof (int))) + ((double)(sizeof (float) != sizeof (int)))))) * ((long)((((int)(offsetof (struct Q, a) != sizeof (int))) ^ ((int)(sizeof (int)))))) - ((long)((((int)(sizeof (float))) >> ((int)(offsetof (struct Q, a) != sizeof (int)))))) - ((long)((((double)(sizeof (float))) * ((double)(offsetof (struct R, a)))))) + ((long)((((int)(sizeof (int))) ^ ((int)(offsetof (struct R, a) != sizeof (int)))))) + ((short)((((double)(sizeof (float) != sizeof (int))) - ((double)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (int))) | ((int)(offsetof (struct Q, a) != sizeof (int)))))) + ((long)((((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) - ((long)((((double)(offsetof (struct Q, a) != sizeof (int))) * ((double)(sizeof (float) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 - ((long)((((int)(1)) ^ ((int)(s.a.i))))) + ((short)((((int)(1)) ^ ((int)(s.a.i))))) - ((long)((((double)(s.a.i)) - ((double)(1)))));
  s.a.j = 2 + 42 * ((int)((((double)(s.a.j)) - ((double)(s.a.j))))) - ((int)((((int)(2)) % ((int)(2))))) * ((long)((((double)(s.a.j)) + ((double)(2)))));
  if (((int)test1 ((void *)&s) != 3 + 41 + ((int)((((int)(test1 ((void *)&s))) >> ((int)(test1 ((void *)&s)))))) + ((short)((((int)(3)) % ((int)(test1 ((void *)&s)))))) - ((long)((((int)(3)) % ((int)(test1 ((void *)&s)))))) * ((int)((((int)(test1 ((void *)&s))) | ((int)(test1 ((void *)&s)))))) + ((int)((((int)(3)) & ((int)(3))))) * ((int)((((double)(3)) - ((double)(3)))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 - ((long)((((int)(3)) | ((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 + ((short)((((int)(3)) % ((int)(3))))) * ((long)((((double)(3)) * ((double)(3))))) - ((long)((((int)(test3 ((void *)&s))) | ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
