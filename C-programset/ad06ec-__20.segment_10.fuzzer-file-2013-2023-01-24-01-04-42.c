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
  s.a.i = 0 + 42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i))))) + 42 - ((short)((((int)(42)) << ((int)(42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i)))))))))) + ((long)((((int)(0 + 42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i))))))) % ((int)(s.a.i))))) * ((int)((((int)(0 + 42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i))))))) & ((int)(((int)((((double)(s.a.i)) - ((double)(s.a.i)))))))))) - ((long)((((int)(42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i))))))) & ((int)(s.a.i))))) + ((long)((((int)(42)) & ((int)(0 + 42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i))))))))));
  b->i = 3 + 42 + ((short)((((int)(b->i)) << ((int)(b->i))))) + ((long)((((int)(b->i)) & ((int)(3))))) - ((int)((((double)(b->i)) * ((double)(3))))) * ((short)((((double)(3)) + ((double)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  b->i = 3 + 42 * ((int)((((int)(3)) % ((int)(b->i))))) - ((long)((((int)(3)) ^ ((int)(b->i))))) + ((long)((((double)(3)) + ((double)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 - ((long)((((double)(s.a.i)) + ((double)(0))))) + 42 + ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) * ((int)((((int)(s.a.i)) | ((int)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 - ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) % ((int)(3))))) + ((long)((((int)(3)) << ((int)(3))))) + ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^ ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) << ((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((int)(sizeof (int))) >> ((int)(sizeof (int)))))) - ((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((int)((((double)(sizeof (int))) + ((double)(offsetof (struct Q, a) != sizeof (int)))))) - ((int)((((int)(offsetof (struct Q, a))) >> ((int)(sizeof (int)))))) - ((long)((((int)(offsetof (struct R, a))) | ((int)(sizeof (float)))))) * ((long)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (float) != sizeof (int))) | ((int)(sizeof (float) != sizeof (int))))))) + 41 - ((int)((((int)(((long)((((int)(offsetof (struct R, a))) | ((int)(sizeof (float)))))) * ((long)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a)))))))) % ((int)(offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((int)(sizeof (int))) >> ((int)(sizeof (int)))))) - ((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((int)((((double)(sizeof (int))) + ((double)(offsetof (struct Q, a) != sizeof (int)))))) - ((int)((((int)(offsetof (struct Q, a))) >> ((int)(sizeof (int)))))) - ((long)((((int)(offsetof (struct R, a))) | ((int)(sizeof (float)))))) * ((long)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (float) != sizeof (int))) | ((int)(sizeof (float) != sizeof (int))))))))))) - ((long)((((int)(sizeof (int) + 41 + ((short)((((int)(sizeof (int))) >> ((int)(sizeof (int)))))) - ((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((int)((((double)(sizeof (int))) + ((double)(offsetof (struct Q, a) != sizeof (int)))))) - ((int)((((int)(offsetof (struct Q, a))) >> ((int)(sizeof (int)))))) - ((long)((((int)(offsetof (struct R, a))) | ((int)(sizeof (float)))))) * ((long)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a)))))))) ^ ((int)(offsetof (struct Q, a)))))) + ((short)((((int)(offsetof (struct R, a) != sizeof (int))) >> ((int)(offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((int)(sizeof (int))) >> ((int)(sizeof (int)))))) - ((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((int)((((double)(sizeof (int))) + ((double)(offsetof (struct Q, a) != sizeof (int)))))) - ((int)((((int)(offsetof (struct Q, a))) >> ((int)(sizeof (int)))))) - ((long)((((int)(offsetof (struct R, a))) | ((int)(sizeof (float)))))) * ((long)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (float) != sizeof (int))) | ((int)(sizeof (float) != sizeof (int))))))))))) * ((long)((((double)((int)sizeof (float) != sizeof (int))) * ((double)(((int)((((int)(offsetof (struct Q, a))) >> ((int)(sizeof (int))))))))))) * ((short)((((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) & ((int)(((int)((((int)(sizeof (float) != sizeof (int))) | ((int)(sizeof (float) != sizeof (int))))))))))) - ((long)((((int)(((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((int)((((double)(sizeof (int))) + ((double)(offsetof (struct Q, a) != sizeof (int)))))))) | ((int)(sizeof (int) + 41 + ((short)((((int)(sizeof (int))) >> ((int)(sizeof (int)))))) - ((short)((((double)(offsetof (struct Q, a))) - ((double)(offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((int)((((double)(sizeof (int))) + ((double)(offsetof (struct Q, a) != sizeof (int)))))) - ((int)((((int)(offsetof (struct Q, a))) >> ((int)(sizeof (int)))))) - ((long)((((int)(offsetof (struct R, a))) | ((int)(sizeof (float)))))) * ((long)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a))))))))))) - ((short)((((double)(((int)((((int)(sizeof (float) != sizeof (int))) | ((int)(sizeof (float) != sizeof (int)))))))) + ((double)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 - ((short)((((double)(1)) + ((double)(s.a.i)))));
  s.a.j = 2 + 42 * ((short)((((double)(2)) - ((double)(s.a.j))))) * ((int)((((double)(2)) + ((double)(2))))) - ((int)((((int)(s.a.j)) << ((int)(2))))) * ((long)((((int)(s.a.j)) ^ ((int)(2))))) + ((int)((((int)(2)) << ((int)(2)))));
  if (((int)((int)test1 ((void *)&s) != 3 + 41 * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))) * ((long)((((double)(3)) + ((double)(3)))))) + 41 * ((short)((((int)(3)) | ((int)((int)test1 ((void *)&s)))))) - ((int)((((int)(41 * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))) * ((long)((((double)(3)) + ((double)(3))))))) >> ((int)(41 * ((short)((((int)(3)) | ((int)(test1 ((void *)&s))))))))))) - ((short)((((int)(3)) & ((int)((int)test1 ((void *)&s)))))) * ((short)((((int)(41 * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))) * ((long)((((double)(3)) + ((double)(3))))))) % ((int)((int)test1 ((void *)&s)))))) - ((int)((((int)(41 * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))))) >> ((int)(3 + 41 * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))) * ((long)((((double)(3)) + ((double)(3)))))))))) - ((int)((((int)(41 * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))) * ((long)((((double)(3)) + ((double)(3))))))) & ((int)(((long)((((double)(3)) + ((double)(3)))))))))) + ((int)((((int)(3)) % ((int)(3)))))))
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((short)((((int)(2)) ^ ((int)(s.a.j)))));
  if (((int)((int)test2 ((void *)&s) != 3 + 41 - ((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s))))))) + 41 + ((int)((((int)((int)test2 ((void *)&s))) % ((int)(41))))) + ((int)((((int)(3)) ^ ((int)(3 + 41 - ((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s))))))))))) + ((int)((((int)(3 + 41)) % ((int)(3 + 41 - ((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s))))))))))) * ((short)((((int)(((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s)))))))) % ((int)(((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s))))))))))) * ((int)((((int)(((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s)))))))) | ((int)((int)test2 ((void *)&s)))))) * ((short)((((int)(41)) << ((int)(3))))) * ((long)((((int)(41)) | ((int)(((short)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s)))))))))))))
    { abort (); }
  s.a.i = 1 + 42 + ((int)((((int)(1)) % ((int)(1))))) * ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) + ((int)((((int)(1)) >> ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) * ((double)(1))))) + ((long)((((double)(s.a.i)) - ((double)(s.a.i))))) + 42 - ((long)((((int)(1 + 42 + ((int)((((int)(1)) % ((int)(1))))) * ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) + ((int)((((int)(1)) >> ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) * ((double)(1))))) + ((long)((((double)(s.a.i)) - ((double)(s.a.i))))))) >> ((int)(s.a.i))))) * ((short)((((int)(1 + 42 + ((int)((((int)(1)) % ((int)(1))))) * ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) + ((int)((((int)(1)) >> ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) * ((double)(1))))) + ((long)((((double)(s.a.i)) - ((double)(s.a.i))))))) & ((int)(s.a.i))))) - ((int)((((int)(1 + 42 + ((int)((((int)(1)) % ((int)(1))))) * ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) + ((int)((((int)(1)) >> ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) * ((double)(1))))) + ((long)((((double)(s.a.i)) - ((double)(s.a.i))))))) >> ((int)(s.a.i))))) - ((long)((((int)(1 + 42 + ((int)((((int)(1)) % ((int)(1))))) * ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) + ((int)((((int)(1)) >> ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) * ((double)(1))))) + ((long)((((double)(s.a.i)) - ((double)(s.a.i))))))) >> ((int)(s.a.i)))));
  s.a.j = 2 + 42 * ((int)((((double)(s.a.j)) + ((double)(2))))) * ((short)((((double)(2)) - ((double)(s.a.j))))) * ((short)((((int)(2)) | ((int)(2))))) + ((long)((((double)(2)) - ((double)(2)))));
  if (((int)test3 ((void *)&s) != 3 + 41 + ((int)((((int)(test3 ((void *)&s))) & ((int)(test3 ((void *)&s)))))) - ((long)((((int)(3)) << ((int)(test3 ((void *)&s)))))) + ((int)((((double)(3)) * ((double)(3))))) + ((short)((((int)(3)) & ((int)(test3 ((void *)&s)))))) + ((short)((((double)(3)) * ((double)(3))))) * ((short)((((int)(3)) % ((int)(test3 ((void *)&s)))))) + ((short)((((int)(test3 ((void *)&s))) % ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
