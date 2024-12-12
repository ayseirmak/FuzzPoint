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
  3 + 42 * ((long)((((double)(b->i)) * ((double)(3))))) * ((short)((((double)(3)) + ((double)(b->i))))) - ((short)((((int)(b->i)) << ((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  0 + 42 + ((short)((((int)(0)) | ((int)(0)))));
  
;1 + 42 + ((int)((((int)(s.a.i)) << ((int)(1))))) * ((short)((((int)(1)) ^ ((int)(1))))) - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((double)(s.a.i)) - ((double)(1)))));
3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  0 + 42 * ((long)((((int)(s.a.i)) & ((int)(s.a.i)))));
  
;
;
;s.a.i = 1 + 42 + ((int)((((int)(s.a.i)) << ((int)(1))))) * ((short)((((int)(1)) ^ ((int)(1))))) - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((double)(s.a.i)) - ((double)(1)))));
1 + 42 + ((int)((((int)(s.a.i)) << ((int)(1))))) * ((short)((((int)(1)) ^ ((int)(1))))) - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((double)(s.a.i)) - ((double)(1)))));

;s.a.i = 1 + 42 + ((int)((((int)(s.a.i)) << ((int)(1))))) * ((short)((((int)(1)) ^ ((int)(1))))) - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((double)(s.a.i)) - ((double)(1)))));
s.a.i = 1 + 42 + ((int)((((int)(s.a.i)) << ((int)(1))))) * ((short)((((int)(1)) ^ ((int)(1))))) - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((double)(s.a.i)) - ((double)(1)))));
3 + 42 + ((long)((((int)(3)) & ((int)(3))))) * ((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^ ((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((int)(offsetof (struct R, a))) | ((int)(sizeof (int)))))) + ((int)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (float))) ^ ((int)(offsetof (struct R, a)))))) * ((int)((((int)(sizeof (float) != sizeof (int))) & ((int)(offsetof (struct R, a))))))) + 41 - ((long)((((int)(sizeof (int) + 41 + ((short)((((int)(offsetof (struct R, a))) | ((int)(sizeof (int)))))) + ((int)((((double)(sizeof (float))) * ((double)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (float))) ^ ((int)(offsetof (struct R, a)))))) * ((int)((((int)(sizeof (float) != sizeof (int))) & ((int)(offsetof (struct R, a)))))))) % ((int)(41))))) - ((long)((((int)(((short)((((int)(offsetof (struct R, a))) | ((int)(sizeof (int)))))))) << ((int)(sizeof (int))))))))
    { return 0; }
  s.a.i = 1 + 42 + ((int)((((int)(s.a.i)) << ((int)(1))))) * ((short)((((int)(1)) ^ ((int)(1))))) - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((double)(s.a.i)) - ((double)(1)))));
  2 + 42 - ((int)((((double)(s.a.j)) + ((double)(s.a.j))))) + ((short)((((int)(s.a.j)) & ((int)(2))))) + 42 * ((int)((((int)(2 + 42)) << ((int)(2 + 42)))));
  if (((int)((int)test1 ((void *)&s) != 3 + 41 + ((long)((((int)(test1 ((void *)&s))) & ((int)(3))))) - ((int)((((int)(test1 ((void *)&s))) << ((int)(3))))) * ((short)((((double)(3)) * ((double)(3))))) - ((int)((((int)(test1 ((void *)&s))) ^ ((int)(3))))) + ((long)((((int)(3)) | ((int)(3))))) - ((long)((((int)(test1 ((void *)&s))) % ((int)(3))))) * ((int)((((int)(test1 ((void *)&s))) << ((int)(test1 ((void *)&s)))))) * ((int)((((int)(3)) << ((int)(3))))) - ((int)((((int)(3)) & ((int)(3))))) * ((int)((((int)(test1 ((void *)&s))) ^ ((int)(test1 ((void *)&s))))))) + 41 - ((short)((((int)(((int)((((int)(3)) & ((int)(3))))) * ((int)((((int)(test1 ((void *)&s))) ^ ((int)(test1 ((void *)&s)))))))) >> ((int)(3 + 41 + ((long)((((int)(test1 ((void *)&s))) & ((int)(3))))) - ((int)((((int)(test1 ((void *)&s))) << ((int)(3))))) * ((short)((((double)(3)) * ((double)(3))))) - ((int)((((int)(test1 ((void *)&s))) ^ ((int)(3))))) + ((long)((((int)(3)) | ((int)(3))))) - ((long)((((int)(test1 ((void *)&s))) % ((int)(3))))) * ((int)((((int)(test1 ((void *)&s))) << ((int)(test1 ((void *)&s)))))) * ((int)((((int)(3)) << ((int)(3))))) - ((int)((((int)(3)) & ((int)(3))))) * ((int)((((int)(test1 ((void *)&s))) ^ ((int)(test1 ((void *)&s)))))))))))))
    { abort (); }
  1;
  2;
  if (((int)test2 ((void *)&s) != 3 + 41 * ((int)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s)))))) * ((int)((((int)(test2 ((void *)&s))) << ((int)(3)))))))
    { abort (); }
  1;
  2 + 42 + ((short)((((double)(s.a.j)) + ((double)(2))))) * ((short)((((double)(s.a.j)) * ((double)(s.a.j))))) * ((short)((((int)(s.a.j)) << ((int)(s.a.j))))) * ((long)((((double)(2)) * ((double)(2))))) + ((short)((((double)(s.a.j)) - ((double)(2)))));
  if (((int)test3 ((void *)&s) != 3 + 41 + ((long)((((int)(3)) << ((int)(test3 ((void *)&s)))))) - ((long)((((int)(3)) | ((int)(test3 ((void *)&s)))))) + ((int)((((int)(test3 ((void *)&s))) | ((int)(test3 ((void *)&s)))))) * ((long)((((double)(3)) - ((double)(3))))) - ((long)((((int)(test3 ((void *)&s))) % ((int)(test3 ((void *)&s)))))) + ((int)((((int)(3)) >> ((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
