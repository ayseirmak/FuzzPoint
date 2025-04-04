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
  s.a.i = 0 + 42 * ((long)(((double)0) - ((double)0)));
  b->i = 3 + 42 * ((short)(((double)3) - ((double)(b->i)))) * ((short)(((int)3) | ((int)(b->i)))) + ((long)(((double)3) * ((double)3))) - ((int)(((double)3) - ((double)(b->i))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  b->i = 3 + 42 + ((int)(((double)3) - ((double)3))) * ((short)(((int)3) << ((int)(b->i))));
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
      || offsetof (struct Q, a) != sizeof (int) + 41 * ((long)(((double)(offsetof (struct Q, a) != sizeof (int))) * ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))) + ((int)(((int)(sizeof (int))) & ((int)(offsetof (struct R, a))))) * ((long)(((double)(offsetof (struct Q, a) != sizeof (int))) + ((double)(offsetof (struct R, a))))) - ((int)(((double)(offsetof (struct Q, a) != sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))) * ((long)(((double)(sizeof (float))) * ((double)(sizeof (float))))) + ((short)(((int)(offsetof (struct R, a))) | ((int)(sizeof (int))))) * ((int)(((double)(sizeof (float) != sizeof (int))) * ((double)(offsetof (struct Q, a) != sizeof (int)))))))
    { return 0; }
  s.a.i = 1 + 42 - ((int)(((double)(s.a.i)) - ((double)1))) + ((long)(((double)(s.a.i)) - ((double)(s.a.i)))) * ((short)(((int)1) >> ((int)1))) + ((long)(((double)(s.a.i)) + ((double)1)));
  s.a.j = 2;
  if (((int)test1 ((void *)&s) != 3 + 41 + ((long)(((int)3) & ((int)test1 ((void *)&s)))) + ((short)(((int)3) << ((int)3))) + ((long)(((int)test1 ((void *)&s)) & ((int)3))) - ((int)(((int)3) & ((int)3))) * ((long)(((double)3) - ((double)3))) - ((short)(((int)3) << ((int)test1 ((void *)&s))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((long)(((double)(s.a.j)) + ((double)2))) * ((int)(((int)(s.a.j)) % ((int)2))) - ((long)(((int)(s.a.j)) << ((int)(s.a.j)))) * ((long)(((int)(s.a.j)) << ((int)(s.a.j)))) + ((long)(((double)(s.a.j)) + ((double)2)));
  if (((int)test2 ((void *)&s) != 3 + 41 * ((int)(((int)3) ^ ((int)test2 ((void *)&s)))) + ((long)(((int)3) >> ((int)test2 ((void *)&s)))) * ((short)(((int)test2 ((void *)&s)) | ((int)3))) + ((short)(((int)test2 ((void *)&s)) % ((int)3))) - ((int)(((int)3) % ((int)3))) - ((long)(((int)3) % ((int)3))) - ((short)(((int)3) ^ ((int)test2 ((void *)&s))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((int)(((int)(s.a.j)) ^ ((int)2))) - ((short)(((double)2) - ((double)(s.a.j))));
  if (((int)test3 ((void *)&s) != 3 + 41 + ((short)(((double)3) + ((double)3))) * ((int)(((int)3) & ((int)3))) + ((int)(((int)3) | ((int)test3 ((void *)&s))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
