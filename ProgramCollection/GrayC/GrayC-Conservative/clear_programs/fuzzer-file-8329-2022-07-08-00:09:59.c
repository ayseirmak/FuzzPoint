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
  s.a.i = 0 + 42 - ((long)(((int)0) << ((int)(s.a.i)))) * ((int)(((int)0) << ((int)0))) - ((short)(((int)(s.a.i)) & ((int)0)));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  b->i = 3 + 42 * ((int)(((int)(b->i)) | ((int)3))) - ((int)(((int)3) << ((int)(b->i)))) * ((short)(((double)3) - ((double)3))) - ((long)(((int)3) ^ ((int)3)));
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
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((long)(((double)(offsetof (struct Q, a) != sizeof (int))) * ((double)(sizeof (float) != sizeof (int))))) * ((long)(((int)(sizeof (int))) & ((int)(sizeof (int))))) + ((short)(((double)(offsetof (struct R, a))) - ((double)(sizeof (float) != sizeof (int))))) * ((long)(((double)(sizeof (int))) + ((double)(offsetof (struct R, a) != sizeof (int))))) - ((long)(((double)(offsetof (struct Q, a) != sizeof (int))) + ((double)(offsetof (struct R, a))))) * ((short)(((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(offsetof (struct Q, a) != sizeof (int))))) * ((long)(((double)(sizeof (int))) * ((double)(sizeof (int))))) * ((short)(((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) & ((int)(sizeof (float) != sizeof (int))))) * ((int)(((int)(sizeof (int))) % ((int)(offsetof (struct Q, a)))))))
    { return 0; }
  s.a.i = 1 + 42 * ((long)(((double)1) - ((double)1)));
  s.a.j = 2 + 42 + ((short)(((double)2) - ((double)(s.a.j)))) - ((int)(((int)(s.a.j)) & ((int)2))) + ((short)(((double)2) - ((double)(s.a.j))));
  if (((int)test1 ((void *)&s) != 3 + 41 - ((long)(((int)test1 ((void *)&s)) << ((int)test1 ((void *)&s)))) + ((int)(((int)test1 ((void *)&s)) >> ((int)test1 ((void *)&s)))) + ((long)(((int)test1 ((void *)&s)) >> ((int)3))) * ((int)(((int)3) % ((int)test1 ((void *)&s)))) + ((short)(((int)test1 ((void *)&s)) >> ((int)3))) + ((int)(((int)3) & ((int)test1 ((void *)&s)))) - ((short)(((double)3) + ((double)3)))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 * ((long)(((int)test2 ((void *)&s)) >> ((int)test2 ((void *)&s))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((short)(((double)(s.a.j)) + ((double)(s.a.j)))) * ((int)(((double)2) + ((double)(s.a.j)))) + ((long)(((double)(s.a.j)) + ((double)(s.a.j)))) - ((short)(((double)2) + ((double)(s.a.j)))) - ((long)(((int)2) ^ ((int)(s.a.j))));
  if (((int)test3 ((void *)&s) != 3 + 41 * ((long)(((int)3) % ((int)3))) * ((long)(((int)3) % ((int)test3 ((void *)&s)))) * ((int)(((int)test3 ((void *)&s)) << ((int)3))) + ((short)(((int)3) >> ((int)3))) * ((int)(((int)test3 ((void *)&s)) % ((int)3))) + ((long)(((int)3) % ((int)test3 ((void *)&s))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
