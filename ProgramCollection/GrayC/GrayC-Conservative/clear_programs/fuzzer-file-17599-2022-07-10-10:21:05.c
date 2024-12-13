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
  s.a.i = 0 + 42 + ((short)(((double)0) - ((double)0)));
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
  s.a.i = 0 + 42 + ((long)(((double)0) - ((double)(s.a.i)))) - ((int)(((int)0) % ((int)(s.a.i)))) + ((long)(((double)0) + ((double)0))) * ((int)(((int)(s.a.i)) >> ((int)(s.a.i))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 - ((int)(((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)3))) + ((long)(((int)3) << ((int)(((struct S *)((char *)q + sizeof (int)))->i))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((long)(((double)(offsetof (struct R, a))) - ((double)(sizeof (int))))) - ((int)(((double)(offsetof (struct R, a) != sizeof (int))) * ((double)(sizeof (int)))))) + 41 * ((short)(((int)(sizeof (int) + 41 + ((long)(((double)(offsetof (struct R, a))) - ((double)(sizeof (int))))) - ((int)(((double)(offsetof (struct R, a) != sizeof (int))) * ((double)(sizeof (int))))))) & ((int)(sizeof (int) + 41 + ((long)(((double)(offsetof (struct R, a))) - ((double)(sizeof (int)))))))))))
    { return 0; }
  s.a.i = 1 + 42 + ((short)(((int)1) & ((int)(s.a.i)))) - ((int)(((int)1) | ((int)(s.a.i))));
  s.a.j = 2 + 42 * ((long)(((double)(s.a.j)) + ((double)2))) - ((int)(((double)2) * ((double)(s.a.j)))) - ((short)(((double)(s.a.j)) - ((double)2)));
  if (((int)((int)test1 ((void *)&s) != 3 + 41 * ((int)(((int)3) % ((int)3))) + ((int)(((int)3) | ((int)3))) * ((long)(((int)test1 ((void *)&s)) ^ ((int)3))) + ((long)(((int)3) | ((int)test1 ((void *)&s)))) + ((short)(((int)test1 ((void *)&s)) % ((int)3)))) + 41 - ((long)(((int)(((int)(((int)3) | ((int)3))) * ((long)(((int)test1 ((void *)&s)) ^ ((int)3))))) % ((int)((long)(((int)test1 ((void *)&s)) ^ ((int)3)))))) + ((int)(((int)((long)(((int)3) | ((int)test1 ((void *)&s))))) << ((int)((int)test1 ((void *)&s))))) - ((long)(((int)((int)test1 ((void *)&s))) & ((int)((int)test1 ((void *)&s))))) - ((int)(((int)((long)(((int)3) | ((int)test1 ((void *)&s))))) | ((int)((long)(((int)test1 ((void *)&s)) ^ ((int)3)))))) * ((int)(((int)((long)(((int)3) | ((int)test1 ((void *)&s))))) % ((int)((int)test1 ((void *)&s))))) - ((int)(((int)(3 + 41 * ((int)(((int)3) % ((int)3))) + ((int)(((int)3) | ((int)3))) * ((long)(((int)test1 ((void *)&s)) ^ ((int)3))) + ((long)(((int)3) | ((int)test1 ((void *)&s)))) + ((short)(((int)test1 ((void *)&s)) % ((int)3))))) & ((int)((long)(((int)test1 ((void *)&s)) ^ ((int)3)))))) * ((long)(((int)((long)(((int)3) | ((int)test1 ((void *)&s))))) % ((int)((short)(((int)test1 ((void *)&s)) % ((int)3)))))) - ((short)(((int)((int)(((int)3) | ((int)3)))) | ((int)(((int)(((int)3) | ((int)3))) * ((long)(((int)test1 ((void *)&s)) ^ ((int)3))))))) + ((int)(((int)(3 + 41 * ((int)(((int)3) % ((int)3))) + ((int)(((int)3) | ((int)3))) * ((long)(((int)test1 ((void *)&s)) ^ ((int)3))) + ((long)(((int)3) | ((int)test1 ((void *)&s)))) + ((short)(((int)test1 ((void *)&s)) % ((int)3))))) % ((int)(3 + 41 * ((int)(((int)3) % ((int)3))) + ((int)(((int)3) | ((int)3))) * ((long)(((int)test1 ((void *)&s)) ^ ((int)3))) + ((long)(((int)3) | ((int)test1 ((void *)&s)))) + ((short)(((int)test1 ((void *)&s)) % ((int)3)))))))))
    { abort (); }
  s.a.i = 1 + 42 - ((int)(((int)(s.a.i)) % ((int)(s.a.i)))) + ((short)(((double)(s.a.i)) + ((double)1))) + ((int)(((double)(s.a.i)) - ((double)1))) + ((short)(((double)(s.a.i)) + ((double)(s.a.i)))) + ((short)(((int)(s.a.i)) >> ((int)1))) + 42 + ((int)(((double)(1 + 42 - ((int)(((int)(s.a.i)) % ((int)(s.a.i)))) + ((short)(((double)(s.a.i)) + ((double)1))) + ((int)(((double)(s.a.i)) - ((double)1))) + ((short)(((double)(s.a.i)) + ((double)(s.a.i)))))) - ((double)((short)(((double)(s.a.i)) + ((double)(s.a.i))))))) * ((long)(((int)((int)(((int)(s.a.i)) % ((int)(s.a.i))))) & ((int)(1 + 42 - ((int)(((int)(s.a.i)) % ((int)(s.a.i)))) + ((short)(((double)(s.a.i)) + ((double)1))))))) + ((int)(((double)42) - ((double)(1 + 42 - ((int)(((int)(s.a.i)) % ((int)(s.a.i)))) + ((short)(((double)(s.a.i)) + ((double)1))))))) - ((short)(((double)(s.a.i)) - ((double)((short)(((double)(s.a.i)) + ((double)(s.a.i)))))));
  s.a.j = 2 + 42 - ((short)(((double)2) + ((double)(s.a.j)))) - ((int)(((double)(s.a.j)) + ((double)2)));
  if (((int)((int)test2 ((void *)&s) != 3 + 41 + ((int)(((int)3) >> ((int)test2 ((void *)&s)))) + ((long)(((int)test2 ((void *)&s)) | ((int)3))) * ((long)(((int)3) >> ((int)3))) - ((short)(((int)test2 ((void *)&s)) >> ((int)test2 ((void *)&s)))) * ((int)(((double)3) * ((double)3))) + ((long)(((int)test2 ((void *)&s)) << ((int)3)))) + 41 + ((short)(((int)(((long)(((int)test2 ((void *)&s)) | ((int)3))) * ((long)(((int)3) >> ((int)3))))) | ((int)(((short)(((int)test2 ((void *)&s)) >> ((int)test2 ((void *)&s)))) * ((int)(((double)3) * ((double)3))))))) - ((short)(((int)(3 + 41 + ((int)(((int)3) >> ((int)test2 ((void *)&s)))) + ((long)(((int)test2 ((void *)&s)) | ((int)3))) * ((long)(((int)3) >> ((int)3))))) >> ((int)(((long)(((int)test2 ((void *)&s)) | ((int)3))) * ((long)(((int)3) >> ((int)3))))))) - ((short)(((int)((int)test2 ((void *)&s))) % ((int)(((long)(((int)test2 ((void *)&s)) | ((int)3))) * ((long)(((int)3) >> ((int)3))))))) * ((int)(((int)(3 + 41 + ((int)(((int)3) >> ((int)test2 ((void *)&s)))))) ^ ((int)((long)(((int)test2 ((void *)&s)) << ((int)3)))))) + ((short)(((int)((long)(((int)test2 ((void *)&s)) | ((int)3)))) ^ ((int)(3 + 41 + ((int)(((int)3) >> ((int)test2 ((void *)&s))))))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((long)(((int)(s.a.j)) % ((int)(s.a.j)))) * ((short)(((int)(s.a.j)) ^ ((int)(s.a.j)))) + ((int)(((double)(s.a.j)) * ((double)2))) - ((short)(((double)(s.a.j)) + ((double)2)));
  if (((int)test3 ((void *)&s) != 3 + 41 + ((int)(((double)3) + ((double)3))) * ((long)(((double)3) + ((double)3))) * ((int)(((int)test3 ((void *)&s)) % ((int)test3 ((void *)&s)))) + ((short)(((int)3) | ((int)test3 ((void *)&s)))) - ((int)(((int)3) % ((int)test3 ((void *)&s)))) - ((long)(((int)test3 ((void *)&s)) % ((int)3))) * ((long)(((int)test3 ((void *)&s)) & ((int)3))) * ((long)(((int)test3 ((void *)&s)) & ((int)test3 ((void *)&s))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
