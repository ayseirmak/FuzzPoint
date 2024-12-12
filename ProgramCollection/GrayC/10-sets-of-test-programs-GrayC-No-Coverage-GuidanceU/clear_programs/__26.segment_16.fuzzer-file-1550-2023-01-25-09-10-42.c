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
  s.a.i = 0 + 42 - ((short)((((double)(0)) * ((double)(0))))) * ((int)((((double)(s.a.i)) - ((double)(s.a.i))))) * ((long)((((double)(0)) - ((double)(s.a.i))))) + ((short)((((int)(s.a.i)) >> ((int)(s.a.i))))) * ((int)((((double)(s.a.i)) * ((double)(s.a.i)))));
  b->i = 3 + 42 + ((short)((((int)(b->i)) % ((int)(b->i))))) * ((int)((((int)(b->i)) % ((int)(3))))) * ((int)((((double)(b->i)) * ((double)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 * ((long)((((double)(0)) - ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) & ((int)(s.a.i))))) * ((int)((((double)(0)) * ((double)(s.a.i))))) + ((long)((((double)(0)) * ((double)(0)))));
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
  if (((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((int)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) * ((double)(offsetof (struct Q, a)))))) + ((long)((((double)(sizeof (int))) * ((double)(offsetof (struct Q, a) != sizeof (int)))))) * ((long)((((int)(sizeof (int))) % ((int)(offsetof (struct R, a)))))) + ((int)((((int)(offsetof (struct R, a))) ^ ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((short)((((int)(sizeof (int))) & ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (int))) - ((double)(sizeof (int)))))) + ((long)((((int)(sizeof (float) != sizeof (int))) >> ((int)(offsetof (struct Q, a))))))) + 41 * ((short)((((int)(sizeof (int) + 41 + ((int)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) * ((double)(offsetof (struct Q, a)))))) + ((long)((((double)(sizeof (int))) * ((double)(offsetof (struct Q, a) != sizeof (int)))))) * ((long)((((int)(sizeof (int))) % ((int)(offsetof (struct R, a)))))))) & ((int)(((int)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) * ((double)(offsetof (struct Q, a))))))))))) * ((long)((((int)(sizeof (int) + 41 + ((int)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) * ((double)(offsetof (struct Q, a)))))) + ((long)((((double)(sizeof (int))) * ((double)(offsetof (struct Q, a) != sizeof (int)))))) * ((long)((((int)(sizeof (int))) % ((int)(offsetof (struct R, a)))))) + ((int)((((int)(offsetof (struct R, a))) ^ ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((short)((((int)(sizeof (int))) & ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (int))) - ((double)(sizeof (int)))))))) % ((int)(sizeof (int) + 41 + ((int)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) * ((double)(offsetof (struct Q, a)))))) + ((long)((((double)(sizeof (int))) * ((double)(offsetof (struct Q, a) != sizeof (int)))))) * ((long)((((int)(sizeof (int))) % ((int)(offsetof (struct R, a)))))) + ((int)((((int)(offsetof (struct R, a))) ^ ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((short)((((int)(sizeof (int))) & ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (int))) - ((double)(sizeof (int)))))))))))))
    { return 0; }
  s.a.i = 1;
  s.a.j = 2 + 42 - ((long)((((int)(2)) << ((int)(s.a.j)))));
  if (0)
    { abort (); }
  s.a.i = 1 + 42 + ((long)((((int)(1)) | ((int)(s.a.i)))));
  s.a.j = 2;
  if (((int)((int)test2 ((void *)&s) != 3 + 41 - ((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) * ((short)((((int)(3)) % ((int)(3)))))) + 41 - ((short)((((int)(3 + 41)) | ((int)(((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) * ((short)((((int)(3)) % ((int)(3)))))))))) + ((short)((((int)(41)) | ((int)(((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) * ((short)((((int)(3)) % ((int)(3)))))))))) + ((short)((((int)(((short)((((int)(3)) % ((int)(3))))))) % ((int)(((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s))))))))))) - ((long)((((int)(((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))))) | ((int)(((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) * ((short)((((int)(3)) % ((int)(3)))))))))) * ((short)((((double)(3 + 41)) * ((double)(((short)((((int)(3)) % ((int)(3)))))))))) - ((int)((((int)(3)) ^ ((int)((int)test2 ((void *)&s)))))) * ((long)((((int)(((short)((((int)(3)) % ((int)(3))))))) >> ((int)(((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) * ((short)((((int)(3)) % ((int)(3)))))))))) * ((int)((((double)(3 + 41)) - ((double)(41)))))))
    { abort (); }
  s.a.i = 1 + 42 - ((long)((((int)(s.a.i)) | ((int)(1))))) * ((short)((((int)(s.a.i)) >> ((int)(1))))) + ((long)((((int)(s.a.i)) | ((int)(1))))) + ((long)((((int)(1)) << ((int)(s.a.i)))));
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 + ((int)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((short)((((int)(3)) >> ((int)(3))))) * ((int)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) + ((int)((((int)(test3 ((void *)&s))) | ((int)(test3 ((void *)&s)))))) + ((int)((((int)(3)) ^ ((int)(3))))) * ((short)((((int)(test3 ((void *)&s))) >> ((int)(3))))) + ((int)((((int)(test3 ((void *)&s))) ^ ((int)(3))))) + ((short)((((int)(3)) << ((int)(3))))) - ((int)((((int)(test3 ((void *)&s))) % ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
