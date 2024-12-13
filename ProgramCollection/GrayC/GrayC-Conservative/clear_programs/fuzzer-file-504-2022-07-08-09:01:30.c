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
  s.a.i = 0 + 42 + ((long)(((double)0) - ((double)0))) * ((short)(((int)0) >> ((int)(s.a.i)))) * ((int)(((double)0) * ((double)(s.a.i)))) + ((long)(((double)(s.a.i)) * ((double)(s.a.i))));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 - ((long)(((double)(s.a.i)) * ((double)0)));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 + ((short)(((int)(s.a.i)) & ((int)0))) * ((int)(((double)0) + ((double)(s.a.i)))) - ((short)(((int)(s.a.i)) % ((int)(s.a.i)))) + ((long)(((double)0) - ((double)0))) + ((short)(((double)(s.a.i)) * ((double)(s.a.i))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 * ((long)(((double)(offsetof (struct Q, a))) * ((double)(offsetof (struct R, a) != sizeof (int))))) - ((int)(((double)(offsetof (struct R, a))) + ((double)(sizeof (float))))) * ((short)(((int)(sizeof (float))) % ((int)(sizeof (int))))) * ((short)(((int)(offsetof (struct R, a) != sizeof (int))) % ((int)(sizeof (int))))) * ((long)(((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (int))))) + ((long)(((double)(sizeof (float))) + ((double)(sizeof (float)))))))
    { return 0; }
  s.a.i = 1 + 42 + ((short)(((double)(s.a.i)) + ((double)(s.a.i)))) + ((int)(((double)(s.a.i)) + ((double)1)));
  s.a.j = 2 + 42 * ((long)(((double)(s.a.j)) + ((double)2))) * ((short)(((int)2) & ((int)(s.a.j))));
  if (((int)test1 ((void *)&s) != 3 + 41 * ((short)(((int)3) ^ ((int)test1 ((void *)&s)))) * ((int)(((int)test1 ((void *)&s)) & ((int)test1 ((void *)&s))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 - ((int)(((int)test2 ((void *)&s)) >> ((int)test2 ((void *)&s)))) - ((long)(((double)3) - ((double)3))) * ((int)(((int)test2 ((void *)&s)) >> ((int)test2 ((void *)&s)))) - ((int)(((int)test2 ((void *)&s)) << ((int)3))) - ((long)(((int)test2 ((void *)&s)) << ((int)test2 ((void *)&s)))) - ((int)(((double)3) - ((double)3))) * ((int)(((int)test2 ((void *)&s)) & ((int)test2 ((void *)&s))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 - ((short)(((double)3) - ((double)3))) - ((short)(((int)3) ^ ((int)test3 ((void *)&s)))) - ((long)(((int)test3 ((void *)&s)) ^ ((int)test3 ((void *)&s)))) * ((long)(((int)test3 ((void *)&s)) << ((int)test3 ((void *)&s))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
