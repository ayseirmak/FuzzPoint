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
  
;
;b->i = 3 + 42 * ((short)((((double)(b->i)) - ((double)(b->i))))) + ((short)((((double)(3)) - ((double)(3))))) + ((short)((((int)(3)) & ((int)(3))))) + ((short)((((int)(3)) >> ((int)(3))))) * ((int)((((int)(3)) >> ((int)(3)))));
3;
0;
  b->i = 3 + 42 + ((int)((((double)(3)) - ((double)(b->i))))) + ((int)((((double)(3)) - ((double)(3))))) * ((long)((((int)(3)) % ((int)(b->i))))) + 42 * ((int)((((int)(b->i)) << ((int)(b->i))))) + ((long)((((int)(3 + 42 + ((int)((((double)(3)) - ((double)(b->i))))) + ((int)((((double)(3)) - ((double)(3))))) * ((long)((((int)(3)) % ((int)(b->i))))))) << ((int)(3 + 42 + ((int)((((double)(3)) - ((double)(b->i))))) + ((int)((((double)(3)) - ((double)(3))))) * ((long)((((int)(3)) % ((int)(b->i))))))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  0;
  3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;3;
0;
  3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 * ((long)((((double)(offsetof (struct Q, a) != sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((long)((((int)(sizeof (float))) >> ((int)(sizeof (int)))))) + ((int)((((int)(offsetof (struct R, a) != sizeof (int))) & ((int)(sizeof (float)))))) + ((int)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (int))))))) + 41 - ((int)((((int)(sizeof (int))) | ((int)(offsetof (struct R, a)))))) - ((short)((((int)(((long)((((int)(sizeof (float))) >> ((int)(sizeof (int)))))))) << ((int)(sizeof (int) + 41 * ((long)((((double)(offsetof (struct Q, a) != sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((long)((((int)(sizeof (float))) >> ((int)(sizeof (int)))))) + ((int)((((int)(offsetof (struct R, a) != sizeof (int))) & ((int)(sizeof (float)))))) + ((int)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (int))))))))))) + ((short)((((double)((int)sizeof (float))) - ((double)(offsetof (struct R, a)))))) + ((int)((((double)(((int)((((int)(offsetof (struct R, a) != sizeof (int))) & ((int)(sizeof (float)))))))) - ((double)(sizeof (int)))))) - ((long)((((int)(((int)((((int)(sizeof (float) != sizeof (int))) & ((int)(sizeof (int)))))))) ^ ((int)((int)sizeof (float) != sizeof (int)))))) + ((short)((((double)(sizeof (int))) * ((double)(((long)((((int)(sizeof (float))) >> ((int)(sizeof (int))))))))))) + ((short)((((int)(offsetof (struct R, a))) % ((int)(sizeof (int) + 41 * ((long)((((double)(offsetof (struct Q, a) != sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((long)((((int)(sizeof (float))) >> ((int)(sizeof (int)))))) + ((int)((((int)(offsetof (struct R, a) != sizeof (int))) & ((int)(sizeof (float))))))))))) + ((short)((((double)(sizeof (int))) + ((double)((int)sizeof (float) != sizeof (int)))))) - ((int)((((int)(sizeof (int) + 41 * ((long)((((double)(offsetof (struct Q, a) != sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))))) | ((int)(sizeof (int)))))) * ((short)((((int)(((long)((((int)(sizeof (float))) >> ((int)(sizeof (int)))))))) ^ ((int)(41 * ((long)((((double)(offsetof (struct Q, a) != sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))))))))))
    { return 0; }
  s.a.i;
  2;
  if (((int)((int)test1 ((void *)&s) != 3 + 41 - ((short)((((int)(test1 ((void *)&s))) ^ ((int)(3))))) * ((long)((((int)(test1 ((void *)&s))) % ((int)(3))))) * ((long)((((int)(test1 ((void *)&s))) & ((int)(3))))) + ((long)((((int)(test1 ((void *)&s))) % ((int)(3)))))) + 41 * ((int)((((int)((int)test1 ((void *)&s))) << ((int)(((short)((((int)(test1 ((void *)&s))) ^ ((int)(3)))))))))) * ((short)((((int)(((short)((((int)(test1 ((void *)&s))) ^ ((int)(3))))) * ((long)((((int)(test1 ((void *)&s))) % ((int)(3))))))) % ((int)(((long)((((int)(test1 ((void *)&s))) % ((int)(3))))))))))))
    { abort (); }
  1;
  
;
;s.a.j = 2;
1;
2;
  if (((int)((int)test2 ((void *)&s) != 3 + 41 - ((long)((((int)(3)) & ((int)(test2 ((void *)&s)))))) + ((int)((((int)(3)) ^ ((int)(test2 ((void *)&s)))))) + ((short)((((int)(3)) & ((int)(test2 ((void *)&s)))))) * ((short)((((double)(3)) + ((double)(3))))) * ((short)((((int)(test2 ((void *)&s))) & ((int)(3))))) + ((long)((((int)(test2 ((void *)&s))) & ((int)(3))))) + ((long)((((int)(3)) << ((int)(3))))) + ((long)((((int)(test2 ((void *)&s))) % ((int)(test2 ((void *)&s))))))) + 41 + ((int)((((int)(3 + 41)) ^ ((int)(((long)((((int)(test2 ((void *)&s))) & ((int)(3)))))))))) * ((long)((((int)((int)test2 ((void *)&s))) << ((int)(3 + 41 - ((long)((((int)(3)) & ((int)(test2 ((void *)&s)))))) + ((int)((((int)(3)) ^ ((int)(test2 ((void *)&s))))))))))) - ((int)((((int)(3 + 41 - ((long)((((int)(3)) & ((int)(test2 ((void *)&s)))))))) >> ((int)(((long)((((int)(test2 ((void *)&s))) & ((int)(3)))))))))) - ((int)((((int)(((long)((((int)(test2 ((void *)&s))) & ((int)(3))))))) ^ ((int)(3 + 41 - ((long)((((int)(3)) & ((int)(test2 ((void *)&s)))))) + ((int)((((int)(3)) ^ ((int)(test2 ((void *)&s)))))) + ((short)((((int)(3)) & ((int)(test2 ((void *)&s)))))) * ((short)((((double)(3)) + ((double)(3))))) * ((short)((((int)(test2 ((void *)&s))) & ((int)(3))))) + ((long)((((int)(test2 ((void *)&s))) & ((int)(3))))) + ((long)((((int)(3)) << ((int)(3))))) + ((long)((((int)(test2 ((void *)&s))) % ((int)(test2 ((void *)&s))))))))))) + ((short)((((int)(3 + 41)) >> ((int)(3 + 41 - ((long)((((int)(3)) & ((int)(test2 ((void *)&s)))))) + ((int)((((int)(3)) ^ ((int)(test2 ((void *)&s)))))) + ((short)((((int)(3)) & ((int)(test2 ((void *)&s)))))) * ((short)((((double)(3)) + ((double)(3))))) * ((short)((((int)(test2 ((void *)&s))) & ((int)(3))))) + ((long)((((int)(test2 ((void *)&s))) & ((int)(3))))))))))))
    { abort (); }
  
;s.a.j = 2 + 42 + ((short)((((int)(s.a.j)) | ((int)(s.a.j))))) * ((int)((((double)(s.a.j)) + ((double)(2))))) * ((long)((((double)(2)) - ((double)(s.a.j))))) * ((int)((((int)(s.a.j)) & ((int)(2))))) - ((int)((((int)(s.a.j)) | ((int)(2)))));
s.a.i;
  2;
  if (((int)((int)test3 ((void *)&s) != 3 + 41 * ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) * ((short)((((int)(test3 ((void *)&s))) >> ((int)(3))))) + ((short)((((int)(3)) & ((int)(3)))))) + 41 + ((long)((((int)(3 + 41 * ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) * ((short)((((int)(test3 ((void *)&s))) >> ((int)(3))))) + ((short)((((int)(3)) & ((int)(3))))))) << ((int)(3 + 41 * ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) * ((short)((((int)(test3 ((void *)&s))) >> ((int)(3))))) + ((short)((((int)(3)) & ((int)(3)))))))))) * ((int)((((int)(((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))))) ^ ((int)(3 + 41 * ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) * ((short)((((int)(test3 ((void *)&s))) >> ((int)(3)))))))))) - ((long)((((int)(((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))))) | ((int)(3 + 41 * ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) * ((short)((((int)(test3 ((void *)&s))) >> ((int)(3)))))))))) + ((int)((((int)(3 + 41 * ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) << ((int)(test3 ((void *)&s)))))) * ((short)((((int)(test3 ((void *)&s))) >> ((int)(3))))))) >> ((int)(3 + 41 * ((long)((((int)(3)) ^ ((int)(test3 ((void *)&s)))))))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
