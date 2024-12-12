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
  0;
  3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;
;s.a.i = 0 + 42 - ((int)((((int)(0)) % ((int)(0))))) + ((short)((((int)(s.a.i)) % ((int)(s.a.i))))) + ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((long)((((int)(0)) ^ ((int)(0))))) * ((int)((((int)(0)) % ((int)(s.a.i)))));
3;
0;
  
;
;b->i = 3;
s.a.i = 0;

;((struct S *)((char *)q + sizeof (int)))->i = 3;
b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;((struct S *)((char *)q + sizeof (int)))->i = 3;
0;
  
;1;

;s.a.i = 1 + 42 + ((int)((((double)(1)) - ((double)(s.a.i))))) * ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) * ((long)((((int)(1)) & ((int)(s.a.i))))) - ((int)((((int)(s.a.i)) | ((int)(s.a.i))))) * ((long)((((int)(s.a.i)) ^ ((int)(1)))));
3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((short)((((double)(offsetof (struct Q, a) != sizeof (int))) * ((double)(sizeof (float)))))) * ((short)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((int)((((double)(sizeof (int))) + ((double)(sizeof (int)))))) + ((short)((((double)(sizeof (int))) - ((double)(sizeof (int)))))) * ((int)((((double)(offsetof (struct R, a) != sizeof (int))) + ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) - ((short)((((double)(offsetof (struct R, a) != sizeof (int))) * ((double)(offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  
;s.a.i = 1 + 42 + ((int)((((int)(1)) | ((int)(1)))));
s.a.i = 1;
  
;
;s.a.j = 2;
s.a.i = 1 + 42 + ((short)((((double)(1)) * ((double)(s.a.i))))) - ((long)((((int)(1)) >> ((int)(s.a.i))))) * ((int)((((double)(s.a.i)) * ((double)(s.a.i)))));
2;
  if (((int)test1 ((void *)&s) != 3 + 41 * ((int)((((int)(test1 ((void *)&s))) ^ ((int)(3))))) * ((short)((((int)(3)) | ((int)(test1 ((void *)&s)))))) - ((int)((((int)(3)) & ((int)(test1 ((void *)&s)))))) - ((short)((((int)(3)) >> ((int)(test1 ((void *)&s)))))) - ((int)((((int)(test1 ((void *)&s))) >> ((int)(test1 ((void *)&s)))))) - ((long)((((int)(test1 ((void *)&s))) % ((int)(test1 ((void *)&s)))))) - ((short)((((int)(3)) & ((int)(test1 ((void *)&s)))))) - ((int)((((double)(3)) * ((double)(3))))) * ((int)((((double)(3)) * ((double)(3)))))))
    { abort (); }
  
;s.a.j = 2;

;s.a.i = 1 + 42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i)))));
1;
  
;s.a.i = 1 + 42 * ((int)((((int)(1)) ^ ((int)(s.a.i))))) + ((long)((((int)(1)) & ((int)(s.a.i))))) - ((long)((((int)(1)) % ((int)(1))))) * ((int)((((int)(1)) | ((int)(s.a.i))))) - ((long)((((double)(s.a.i)) + ((double)(1)))));

;s.a.j = 2;
2;
  if (((int)test2 ((void *)&s) != 3 + 41 * ((short)((((int)(3)) % ((int)(3))))) - ((int)((((int)(test2 ((void *)&s))) >> ((int)(3))))) * ((short)((((int)(test2 ((void *)&s))) & ((int)(3))))) + ((int)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) - ((long)((((int)(test2 ((void *)&s))) | ((int)(test2 ((void *)&s)))))) - ((int)((((int)(3)) << ((int)(3))))) + ((short)((((int)(test2 ((void *)&s))) | ((int)(3))))) - ((long)((((int)(test2 ((void *)&s))) & ((int)(3)))))))
    { abort (); }
  
;
;s.a.i = 1;
s.a.j = 2 + 42 + ((long)((((double)(2)) * ((double)(2))))) + ((short)((((double)(s.a.j)) * ((double)(s.a.j))))) + ((int)((((double)(2)) - ((double)(s.a.j))))) + ((int)((((int)(s.a.j)) << ((int)(2))))) * ((long)((((double)(s.a.j)) * ((double)(2)))));

;s.a.j = 2;
s.a.i = 1 + 42 - ((short)((((int)(1)) | ((int)(s.a.i))))) - ((int)((((int)(1)) << ((int)(1))))) + ((long)((((int)(1)) % ((int)(s.a.i))))) - ((short)((((int)(1)) ^ ((int)(1))))) - ((int)((((double)(1)) - ((double)(1)))));
  s.a.j = 2 + 42 + ((short)((((int)(2)) & ((int)(2))))) - ((long)((((double)(s.a.j)) * ((double)(2))))) * ((int)((((int)(s.a.j)) ^ ((int)(2))))) * ((long)((((int)(2)) >> ((int)(s.a.j)))));
  if (((int)test3 ((void *)&s) != 3 + 41 - ((int)((((int)(3)) % ((int)(test3 ((void *)&s)))))) + ((int)((((double)(3)) - ((double)(3))))) + ((short)((((int)(3)) & ((int)(test3 ((void *)&s)))))) - ((long)((((int)(test3 ((void *)&s))) % ((int)(3))))) + ((short)((((int)(test3 ((void *)&s))) | ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
