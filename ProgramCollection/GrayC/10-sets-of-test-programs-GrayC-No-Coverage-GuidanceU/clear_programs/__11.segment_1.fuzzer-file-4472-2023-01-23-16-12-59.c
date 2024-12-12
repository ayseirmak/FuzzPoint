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
  3 + 42 - ((long)((((double)(b->i)) - ((double)(b->i))))) + ((int)((((int)(3)) & ((int)(b->i))))) * ((long)((((double)(b->i)) - ((double)(b->i))))) - ((long)((((int)(3)) | ((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;b->i = 3;
0 + 42 * ((long)((((int)(0)) | ((int)(s.a.i))))) - ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) * ((short)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((short)((((double)(s.a.i)) * ((double)(0))))) + ((short)((((int)(s.a.i)) >> ((int)(s.a.i)))));
  
;s.a.i = 0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0)))));
b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0)))));
  3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((short)((((int)(sizeof (float) != sizeof (int))) | ((int)(sizeof (float) != sizeof (int)))))) - ((short)((((double)(sizeof (int))) * ((double)(offsetof (struct Q, a)))))) - ((int)((((double)(offsetof (struct R, a) != sizeof (int))) - ((double)(sizeof (int))))))))
    { return 0; }
  
;s.a.j = 2 + 42 - ((short)((((double)(s.a.j)) * ((double)(2)))));
1;
  s.a.j = 2 + 42 - ((short)((((double)(s.a.j)) * ((double)(2)))));
  if (((int)test1 ((void *)&s) != 3 + 41 + ((short)((((int)(test1 ((void *)&s))) << ((int)(test1 ((void *)&s)))))) - ((short)((((int)(test1 ((void *)&s))) % ((int)(3))))) - ((long)((((int)(3)) ^ ((int)(test1 ((void *)&s)))))) + ((short)((((int)(test1 ((void *)&s))) ^ ((int)(test1 ((void *)&s)))))) + ((long)((((int)(3)) % ((int)(3))))) - ((int)((((double)(3)) + ((double)(3))))) * ((short)((((int)(test1 ((void *)&s))) << ((int)(3))))) + ((short)((((int)(test1 ((void *)&s))) % ((int)(3)))))))
    { abort (); }
  
;s.a.j = 2;
1;
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 - ((long)((((int)(3)) ^ ((int)(test2 ((void *)&s)))))) * ((short)((((int)(3)) % ((int)(test2 ((void *)&s)))))) - ((long)((((int)(test2 ((void *)&s))) << ((int)(3))))) * ((short)((((int)(3)) % ((int)(3)))))))
    { abort (); }
  
;s.a.j = 2;
1;
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 - ((short)((((int)(test3 ((void *)&s))) & ((int)(3))))) * ((long)((((int)(test3 ((void *)&s))) << ((int)(3))))) * ((short)((((int)(test3 ((void *)&s))) % ((int)(test3 ((void *)&s)))))) - ((int)((((double)(3)) + ((double)(3))))) * ((long)((((int)(test3 ((void *)&s))) << ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
