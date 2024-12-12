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
  s.a.i = 0 + 42 - ((short)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((long)((((double)(s.a.i)) - ((double)(s.a.i)))));
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
  s.a.i = 0 + 42 + ((short)((((double)(0)) * ((double)(s.a.i))))) * ((short)((((int)(s.a.i)) & ((int)(0)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) * ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) & ((int)(3))))) + ((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) & ((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((long)((((double)(offsetof (struct R, a))) * ((double)(offsetof (struct Q, a))))))))
    { return 0; }
  s.a.i = 1;
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1 + 42 - ((long)((((double)(1)) + ((double)(1))))) + ((long)((((int)(1)) | ((int)(1))))) + ((short)((((double)(1)) + ((double)(s.a.i))))) + ((short)((((double)(s.a.i)) * ((double)(1))))) - ((short)((((int)(1)) ^ ((int)(1)))));
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1 + 42 + ((int)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((long)((((double)(s.a.i)) + ((double)(1)))));
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 * ((long)((((double)(3)) + ((double)(3))))) * ((int)((((int)(test3 ((void *)&s))) % ((int)(test3 ((void *)&s)))))) + ((long)((((int)(test3 ((void *)&s))) | ((int)(test3 ((void *)&s)))))) + ((long)((((int)(3)) | ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
