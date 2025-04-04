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
  s.a.i = 0 + 42 * ((long)((((double)(s.a.i)) - ((double)(s.a.i))))) * ((long)((((int)(s.a.i)) & ((int)(s.a.i)))));
  b->i = 3 + 42 * ((int)((((int)(3)) ^ ((int)(b->i))))) * ((long)((((double)(b->i)) - ((double)(3))))) + ((int)((((double)(b->i)) + ((double)(b->i))))) - ((short)((((int)(b->i)) & ((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  b->i = 3 + 42 * ((int)((((int)(b->i)) & ((int)(3))))) + ((int)((((int)(b->i)) ^ ((int)(3))))) - ((long)((((int)(3)) ^ ((int)(b->i))))) * ((long)((((double)(b->i)) * ((double)(b->i))))) - ((short)((((double)(3)) + ((double)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 - ((long)((((double)(0)) + ((double)(0))))) - ((int)((((int)(0)) & ((int)(0))))) * ((long)((((double)(0)) * ((double)(s.a.i))))) - ((int)((((double)(0)) - ((double)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((int)(sizeof (float) != sizeof (int))) >> ((int)(offsetof (struct R, a) != sizeof (int)))))) + ((long)((((double)(sizeof (int))) + ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) >> ((int)(offsetof (struct R, a) != sizeof (int)))))) - ((long)((((int)(offsetof (struct R, a) != sizeof (int))) << ((int)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 * ((short)((((int)(s.a.i)) & ((int)(1))))) + ((short)((((int)(1)) % ((int)(1))))) * ((short)((((int)(1)) & ((int)(1))))) + ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(1)))));
  s.a.j = 2;
  if (((int)test1 ((void *)&s) != 3 + 41 + ((long)((((int)(3)) % ((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = 1 + 42 * ((int)((((double)(s.a.i)) * ((double)(s.a.i))))) * ((short)((((double)(s.a.i)) * ((double)(1)))));
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 * ((long)((((int)(test2 ((void *)&s))) & ((int)(3))))) - ((int)((((int)(3)) | ((int)(3))))) - ((short)((((int)(3)) % ((int)(test2 ((void *)&s)))))) * ((short)((((int)(3)) % ((int)(test2 ((void *)&s)))))) + ((long)((((int)(3)) & ((int)(3))))) + ((long)((((int)(test2 ((void *)&s))) & ((int)(test2 ((void *)&s)))))) - ((long)((((int)(test2 ((void *)&s))) | ((int)(3)))))))
    { abort (); }
  s.a.i = 1 + 42 * ((long)((((double)(1)) + ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(1))))) * ((short)((((int)(1)) >> ((int)(1)))));
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 + ((long)((((int)(test3 ((void *)&s))) << ((int)(3))))) + ((long)((((int)(test3 ((void *)&s))) & ((int)(3))))) - ((short)((((int)(test3 ((void *)&s))) % ((int)(3))))) + ((int)((((int)(test3 ((void *)&s))) ^ ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
