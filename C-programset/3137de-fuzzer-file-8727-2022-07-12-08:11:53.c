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
  
;s.a.i = 0;
b->i;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  3 + 42 + ((int)(((int)(b->i)) % ((int)(b->i)))) - ((short)(((double)3) * ((double)3))) * ((long)(((double)3) + ((double)(b->i))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;((struct S *)((char *)q + sizeof (int)))->i = 3;
0;
  
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
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((long)(((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int))))) * ((int)(((int)(offsetof (struct Q, a))) << ((int)(sizeof (float))))) * ((int)(((int)(offsetof (struct Q, a))) ^ ((int)(sizeof (int))))) + ((long)(((double)(offsetof (struct R, a) != sizeof (int))) + ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))) - ((long)(((int)(offsetof (struct Q, a))) & ((int)(sizeof (float) != sizeof (int))))) - ((int)(((double)(sizeof (int))) * ((double)(offsetof (struct Q, a)))))))
    { return 0; }
  
;s.a.j = 2;
s.a.i = 1;
  
;s.a.i = 1 + 42 + ((short)(((int)1) | ((int)1))) - ((short)(((int)(s.a.i)) ^ ((int)(s.a.i)))) * ((long)(((int)(s.a.i)) << ((int)1))) + ((int)(((int)1) >> ((int)(s.a.i)))) - ((int)(((int)(s.a.i)) ^ ((int)(s.a.i))));
s.a.j = 2;
  if (((int)test1 ((void *)&s) != 3 + 41 + ((int)(((int)3) | ((int)test1 ((void *)&s)))) - ((int)(((int)3) >> ((int)test1 ((void *)&s))))))
    { abort (); }
  
;s.a.j = 2;
s.a.i = 1 + 42 + ((short)(((int)1) | ((int)1))) - ((short)(((int)(s.a.i)) ^ ((int)(s.a.i)))) * ((long)(((int)(s.a.i)) << ((int)1))) + ((int)(((int)1) >> ((int)(s.a.i)))) - ((int)(((int)(s.a.i)) ^ ((int)(s.a.i))));
  s.a.j = 2;
  if (((int)test2 ((void *)&s) != 3 + 41 * ((long)(((int)test2 ((void *)&s)) | ((int)3))) - ((long)(((int)3) | ((int)test2 ((void *)&s)))) * ((long)(((int)test2 ((void *)&s)) % ((int)3))) * ((short)(((int)3) & ((int)3)))))
    { abort (); }
  
;s.a.j = 2;
1;
  s.a.j = 2;
  if (((int)test3 ((void *)&s) != 3 + 41 - ((short)(((int)test3 ((void *)&s)) << ((int)test3 ((void *)&s)))) * ((short)(((int)3) >> ((int)test3 ((void *)&s)))) + ((short)(((int)test3 ((void *)&s)) << ((int)test3 ((void *)&s)))) * ((long)(((double)3) * ((double)3))) * ((long)(((int)3) ^ ((int)3))) + ((short)(((int)3) % ((int)3))) - ((long)(((int)3) | ((int)test3 ((void *)&s)))) * ((long)(((int)test3 ((void *)&s)) << ((int)test3 ((void *)&s)))) - ((long)(((int)3) | ((int)test3 ((void *)&s))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
