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
  s.a.i = 0 + 42 + ((int)((((double)(0)) - ((double)(0))))) + ((int)((((double)(0)) + ((double)(0)))));
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;b->i = 3;
s.a.i;
  
;s.a.i = 0 + 42 + ((short)((((double)(0)) * ((double)(s.a.i))))) + ((int)((((double)(s.a.i)) - ((double)(0)))));
b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)(3)))));
s.a.i = 0 + 42 + ((short)((((double)(0)) * ((double)(s.a.i))))) + ((int)((((double)(s.a.i)) - ((double)(0)))));
  
;s.a.i = 1 + 42 - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((int)(s.a.i)) | ((int)(1))))) - ((int)((((double)(1)) + ((double)(1))))) + ((int)((((double)(1)) - ((double)(s.a.i))))) * ((short)((((int)(1)) ^ ((int)(1)))));
((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)(3)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 + ((long)((((int)(offsetof (struct R, a))) | ((int)(offsetof (struct R, a) != sizeof (int)))))) + ((short)((((double)(offsetof (struct R, a))) * ((double)(sizeof (int)))))) * ((long)((((int)(offsetof (struct Q, a) != sizeof (int))) ^ ((int)(offsetof (struct R, a) != sizeof (int)))))) - ((long)((((int)(sizeof (float) != sizeof (int))) >> ((int)(sizeof (int)))))) - ((long)((((double)(sizeof (float) != sizeof (int))) - ((double)(offsetof (struct R, a))))))))
    { return 0; }
  
;s.a.j = 2;
s.a.i = 1 + 42 - ((long)((((int)(s.a.i)) | ((int)(s.a.i))))) + ((long)((((int)(s.a.i)) | ((int)(1))))) - ((int)((((double)(1)) + ((double)(1))))) + ((int)((((double)(1)) - ((double)(s.a.i))))) * ((short)((((int)(1)) ^ ((int)(1)))));
  
;s.a.i = 1 + 42 - ((long)((((double)(s.a.i)) + ((double)(s.a.i))))) - ((int)((((double)(1)) + ((double)(1))))) + ((long)((((int)(1)) << ((int)(1))))) - ((long)((((double)(1)) * ((double)(1))))) - ((short)((((int)(s.a.i)) % ((int)(s.a.i)))));
s.a.j = 2;
  if (0)
    { abort (); }
  
;s.a.j = 2;
s.a.i = 1 + 42 - ((long)((((double)(s.a.i)) + ((double)(s.a.i))))) - ((int)((((double)(1)) + ((double)(1))))) + ((long)((((int)(1)) << ((int)(1))))) - ((long)((((double)(1)) * ((double)(1))))) - ((short)((((int)(s.a.i)) % ((int)(s.a.i)))));
  s.a.j = 2;
  if (0)
    { abort (); }
  1;
  2 + 42 + ((short)((((double)(2)) - ((double)(s.a.j)))));
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
