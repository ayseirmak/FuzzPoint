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
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;s.a.i = 0;
0;
  
;
;s.a.i = 0;
s.a.i = 0;
3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;s.a.i = 1;
s.a.i = 0 + 42 - ((long)((((double)(0)) + ((double)(s.a.i))))) * ((short)((((int)(0)) ^ ((int)(s.a.i))))) - ((int)((((double)(0)) - ((double)(0))))) * ((short)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(0)) * ((double)(s.a.i)))));
  
;s.a.i = 1 + 42 + ((long)((((int)(1)) ^ ((int)(s.a.i))))) + ((short)((((int)(1)) & ((int)(s.a.i))))) - ((long)((((double)(1)) - ((double)(1))))) + ((long)((((int)(1)) | ((int)(s.a.i))))) * ((long)((((int)(s.a.i)) << ((int)(1)))));
3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 * ((short)((((double)(sizeof (float) != sizeof (int))) - ((double)(sizeof (int)))))) * ((long)((((double)(offsetof (struct R, a) != sizeof (int))) + ((double)(sizeof (int)))))) + ((long)((((int)(offsetof (struct R, a))) ^ ((int)(sizeof (int)))))) - ((int)((((int)(offsetof (struct R, a))) % ((int)(sizeof (int)))))) + ((int)((((int)(sizeof (int))) >> ((int)(sizeof (float))))))))
    { return 0; }
  
;2;

;s.a.j = 2;
1;
  s.a.j = 2;
  if (0)
    { abort (); }
  
;2;
1;
  
;1;
2;
  if (((int)test2 ((void *)&s) != 3 + 41 * ((short)((((int)(3)) & ((int)(test2 ((void *)&s)))))) - ((int)((((int)(test2 ((void *)&s))) << ((int)(3))))) - ((int)((((int)(3)) | ((int)(test2 ((void *)&s)))))) + ((long)((((int)(test2 ((void *)&s))) << ((int)(test2 ((void *)&s)))))) - ((long)((((int)(3)) & ((int)(test2 ((void *)&s)))))) - ((int)((((int)(test2 ((void *)&s))) >> ((int)(3))))) * ((int)((((int)(test2 ((void *)&s))) ^ ((int)(test2 ((void *)&s)))))) - ((int)((((int)(3)) | ((int)(test2 ((void *)&s))))))))
    { abort (); }
  1;
  2;
  if (((int)test3 ((void *)&s) != 3 + 41 - ((long)((((int)(test3 ((void *)&s))) | ((int)(test3 ((void *)&s)))))) - ((int)((((int)(test3 ((void *)&s))) ^ ((int)(test3 ((void *)&s)))))) - ((short)((((int)(test3 ((void *)&s))) << ((int)(3))))) * ((long)((((int)(3)) | ((int)(3))))) + ((short)((((int)(3)) ^ ((int)(3))))) - ((long)((((int)(test3 ((void *)&s))) ^ ((int)(3)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
