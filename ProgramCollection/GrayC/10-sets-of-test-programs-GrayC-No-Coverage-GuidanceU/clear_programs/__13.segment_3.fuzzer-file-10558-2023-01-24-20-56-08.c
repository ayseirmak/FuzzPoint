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
  b->i;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i;
  3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  0;
  
;s.a.i = 1;
3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((int)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a)))))) - ((short)((((int)(offsetof (struct Q, a))) % ((int)(offsetof (struct R, a)))))) - ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^ ((int)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (int))) >> ((int)(offsetof (struct R, a) != sizeof (int)))))) + ((short)((((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float))) & ((int)(sizeof (int)))))) - ((int)((((double)(sizeof (float) != sizeof (int))) + ((double)(sizeof (float))))))) + 41 - ((int)((((int)(sizeof (int))) | ((int)(sizeof (int) + 41 - ((int)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a)))))) - ((short)((((int)(offsetof (struct Q, a))) % ((int)(offsetof (struct R, a)))))) - ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^ ((int)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (int))) >> ((int)(offsetof (struct R, a) != sizeof (int)))))) + ((short)((((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float))) & ((int)(sizeof (int))))))))))) * ((short)((((double)(offsetof (struct R, a))) + ((double)(offsetof (struct Q, a)))))) - ((short)((((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) % ((int)(sizeof (int)))))) - ((long)((((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^ ((int)(sizeof (int) + 41 - ((int)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a))))))))))) + ((int)((((int)(offsetof (struct Q, a) != sizeof (int) + 41 - ((int)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a)))))) - ((short)((((int)(offsetof (struct Q, a))) % ((int)(offsetof (struct R, a)))))) - ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^ ((int)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (int))) >> ((int)(offsetof (struct R, a) != sizeof (int)))))) + ((short)((((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float))) & ((int)(sizeof (int)))))) - ((int)((((double)(sizeof (float) != sizeof (int))) + ((double)(sizeof (float)))))))) >> ((int)(sizeof (int)))))) + ((short)((((double)(sizeof (int))) - ((double)(offsetof (struct R, a)))))) * ((short)((((int)(sizeof (int) + 41 - ((int)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a)))))) - ((short)((((int)(offsetof (struct Q, a))) % ((int)(offsetof (struct R, a)))))) - ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^ ((int)(offsetof (struct Q, a)))))))) & ((int)(sizeof (int)))))) - ((int)((((int)(offsetof (struct Q, a))) << ((int)(sizeof (int) + 41 - ((int)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a)))))) - ((short)((((int)(offsetof (struct Q, a))) % ((int)(offsetof (struct R, a)))))) - ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^ ((int)(offsetof (struct Q, a)))))))))))))
    { return 0; }
  
;s.a.j = 2;
s.a.i = 1 + 42 + ((int)((((double)(s.a.i)) * ((double)(1))))) + 42 + ((int)((((int)(1)) | ((int)(((int)((((double)(s.a.i)) * ((double)(1))))))))));
  s.a.j = 2 + 42 + ((short)((((int)(2)) & ((int)(s.a.j))))) + 42 + ((short)((((int)(42)) & ((int)(s.a.j)))));
  if (((int)((int)test1 ((void *)&s) != 3 + 41 - ((short)((((double)(3)) + ((double)(3)))))) + 41 - ((short)((((double)(3 + 41 - ((short)((((double)(3)) + ((double)(3))))))) + ((double)(3 + 41 - ((short)((((double)(3)) + ((double)(3))))))))))))
    { abort (); }
  s.a.i;
  2;
  if (((int)((int)test2 ((void *)&s) != 3 + 41 - ((short)((((int)(3)) | ((int)(test2 ((void *)&s)))))) - ((long)((((double)(3)) + ((double)(3))))) - ((int)((((double)(3)) + ((double)(3)))))) + 41 - ((short)((((int)(((int)((((double)(3)) + ((double)(3))))))) | ((int)((int)test2 ((void *)&s)))))) - ((long)((((double)(((long)((((double)(3)) + ((double)(3))))))) + ((double)(((int)((((double)(3)) + ((double)(3)))))))))) - ((int)((((int)(3 + 41 - ((short)((((int)(3)) | ((int)(test2 ((void *)&s)))))) - ((long)((((double)(3)) + ((double)(3))))) - ((int)((((double)(3)) + ((double)(3))))))) ^ ((int)(((int)((((double)(3)) + ((double)(3))))))))))))
    { abort (); }
  1;
  2;
  if (((int)((int)test3 ((void *)&s) != 3 + 41 * ((short)((((int)(test3 ((void *)&s))) % ((int)(3))))) * ((long)((((int)(test3 ((void *)&s))) >> ((int)(3))))) - ((int)((((int)(3)) >> ((int)(test3 ((void *)&s))))))) + 41 * ((short)((((int)((int)test3 ((void *)&s))) % ((int)(((int)((((int)(3)) >> ((int)(test3 ((void *)&s))))))))))) * ((long)((((int)(3 + 41 * ((short)((((int)(test3 ((void *)&s))) % ((int)(3))))) * ((long)((((int)(test3 ((void *)&s))) >> ((int)(3))))))) >> ((int)(41 * ((short)((((int)(test3 ((void *)&s))) % ((int)(3))))) * ((long)((((int)(test3 ((void *)&s))) >> ((int)(3)))))))))) - ((int)((((int)(41 * ((short)((((int)(test3 ((void *)&s))) % ((int)(3))))) * ((long)((((int)(test3 ((void *)&s))) >> ((int)(3))))))) >> ((int)((int)test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
