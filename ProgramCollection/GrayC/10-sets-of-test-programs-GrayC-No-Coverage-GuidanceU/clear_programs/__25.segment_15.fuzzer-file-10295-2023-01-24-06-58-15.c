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
  s.a.i = 0 + 42 * ((long)((((int)(s.a.i)) | ((int)(0))))) - ((long)((((double)(s.a.i)) * ((double)(0))))) * ((short)((((double)(0)) + ((double)(s.a.i))))) * ((short)((((double)(s.a.i)) * ((double)(0)))));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 + ((short)((((int)(s.a.i)) | ((int)(0))))) - ((short)((((int)(s.a.i)) | ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) + ((double)(0)))));
  b->i = 3 + 42 - ((long)((((int)(b->i)) ^ ((int)(b->i))))) + ((short)((((int)(3)) % ((int)(b->i)))));
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
      || offsetof (struct Q, a) != sizeof (int) + 41 * ((short)((((int)(sizeof (int))) | ((int)(offsetof (struct Q, a) != sizeof (int)))))) + ((long)((((double)(offsetof (struct Q, a))) * ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((int)((((double)(offsetof (struct Q, a))) * ((double)(sizeof (int)))))) - ((int)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a)))))) + ((short)((((double)(offsetof (struct R, a) != sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) - ((long)((((int)(offsetof (struct Q, a) != sizeof (int))) & ((int)(offsetof (struct R, a)))))) - ((int)((((double)(sizeof (int))) * ((double)(offsetof (struct Q, a) != sizeof (int)))))) + ((long)((((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 + ((short)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((double)(1)) - ((double)(s.a.i))))) + ((long)((((double)(1)) + ((double)(s.a.i)))));
  s.a.j = 2 + 42 * ((long)((((int)(s.a.j)) ^ ((int)(s.a.j))))) * ((short)((((int)(2)) % ((int)(2))))) * ((int)((((double)(s.a.j)) + ((double)(2))))) * ((short)((((int)(2)) << ((int)(s.a.j)))));
  if (0)
    { abort (); }
  s.a.i = 1 + 42 * ((short)((((double)(1)) - ((double)(1))))) * ((long)((((double)(1)) + ((double)(s.a.i))))) - ((int)((((double)(1)) + ((double)(s.a.i))))) - ((int)((((double)(s.a.i)) + ((double)(s.a.i))))) * ((int)((((double)(1)) + ((double)(1)))));
  s.a.j = 2 + 42 - ((short)((((int)(s.a.j)) % ((int)(2))))) - ((long)((((double)(s.a.j)) + ((double)(s.a.j))))) + ((long)((((double)(2)) - ((double)(s.a.j))))) * ((int)((((int)(s.a.j)) & ((int)(2)))));
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
