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
  3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;b->i = 3;
0;
  
;s.a.i = 0 + 42 - ((short)((((double)(0)) - ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) - ((long)((((double)(0)) * ((double)(0))))) - ((short)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((int)(s.a.i)) >> ((int)(s.a.i)))));
b->i = 3 + 42 * ((long)((((double)(3)) * ((double)(b->i))))) * ((short)((((double)(b->i)) * ((double)(3))))) + ((long)((((double)(3)) * ((double)(3))))) + ((int)((((int)(3)) >> ((int)(3)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;((struct S *)((char *)q + sizeof (int)))->i = 3;
s.a.i = 0 + 42 - ((long)((((int)(0)) & ((int)(0))))) + ((short)((((double)(0)) * ((double)(0))))) * ((long)((((int)(0)) >> ((int)(s.a.i))))) - ((long)((((double)(s.a.i)) + ((double)(0))))) - ((long)((((int)(0)) ^ ((int)(0)))));
  
;s.a.i = 1;
((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((short)((((double)(sizeof (int))) * ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) + ((short)((((int)(sizeof (int))) | ((int)(sizeof (int)))))) + ((short)((((int)(offsetof (struct R, a) != sizeof (int))) ^ ((int)(sizeof (float) != sizeof (int)))))) * ((long)((((double)(sizeof (float) != sizeof (int))) - ((double)(sizeof (float)))))) - ((int)((((double)(sizeof (float))) + ((double)(sizeof (float) != sizeof (int)))))) + ((short)((((int)(offsetof (struct Q, a))) | ((int)(offsetof (struct Q, a) != sizeof (int)))))) * ((int)((((int)(sizeof (float))) % ((int)(sizeof (int)))))) * ((short)((((int)(offsetof (struct Q, a))) ^ ((int)(sizeof (int)))))) * ((short)((((int)(offsetof (struct Q, a))) >> ((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))))
    { return 0; }
  
;s.a.j = 2 + 42 - ((long)((((double)(2)) * ((double)(2))))) - ((long)((((double)(s.a.j)) - ((double)(2))))) - ((long)((((double)(2)) - ((double)(2)))));
s.a.i = 1;
  
;s.a.i = 1 + 42 * ((long)((((int)(s.a.i)) >> ((int)(s.a.i)))));
s.a.j = 2 + 42 + ((int)((((double)(2)) * ((double)(s.a.j))))) + ((short)((((double)(2)) - ((double)(2))))) + ((int)((((int)(2)) % ((int)(s.a.j))))) - ((long)((((int)(s.a.j)) ^ ((int)(2))))) - ((short)((((double)(2)) * ((double)(s.a.j)))));
  if (0)
    { abort (); }
  
;s.a.j = 2 + 42 + ((int)((((int)(2)) % ((int)(s.a.j))))) - ((short)((((double)(s.a.j)) + ((double)(2))))) - ((int)((((double)(2)) * ((double)(s.a.j))))) + ((int)((((int)(2)) & ((int)(2)))));
s.a.i = 1;
  
;s.a.i = 1;
s.a.j = 2 + 42 + ((long)((((int)(s.a.j)) | ((int)(2))))) + ((long)((((double)(s.a.j)) - ((double)(2))))) + ((long)((((int)(s.a.j)) ^ ((int)(2))))) - ((int)((((double)(2)) + ((double)(2)))));
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j;
  if (((int)test3 ((void *)&s) != 3 + 41 - ((short)((((int)(test3 ((void *)&s))) | ((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
