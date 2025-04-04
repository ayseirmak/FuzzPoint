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
  s.a.i;
  
;
;b->i = 3;
0 + 42 * ((long)(((int)(s.a.i)) | ((int)(s.a.i)))) + ((int)(((int)(s.a.i)) << ((int)(s.a.i)))) * ((int)(((double)0) + ((double)0))) * ((int)(((int)0) << ((int)(s.a.i))));
3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;
;0 + 42 - ((long)(((int)(s.a.i)) >> ((int)0))) - ((int)(((double)(s.a.i)) + ((double)0))) - ((int)(((int)0) >> ((int)0)));
3;
0 + 42 - ((long)(((int)(s.a.i)) >> ((int)0))) - ((int)(((double)(s.a.i)) + ((double)0))) - ((int)(((int)0) >> ((int)0)));
  3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  0;
  3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((long)(((double)(sizeof (int))) + ((double)(sizeof (int))))) - ((long)(((int)(sizeof (int))) | ((int)(sizeof (int))))) - ((int)(((int)(offsetof (struct R, a) != sizeof (int))) % ((int)(offsetof (struct Q, a)))))))
    { return 0; }
  
;2 + 42 - ((short)(((double)2) - ((double)(s.a.j)))) - ((short)(((double)2) * ((double)(s.a.j)))) * ((int)(((int)(s.a.j)) ^ ((int)(s.a.j)))) + ((long)(((double)(s.a.j)) + ((double)2))) - ((short)(((int)2) % ((int)(s.a.j))));
s.a.i;
  
;
;
;s.a.j = 2;
2;
1 + 42 * ((long)(((double)1) + ((double)1))) * ((short)(((int)(s.a.i)) & ((int)(s.a.i)))) * ((int)(((double)(s.a.i)) + ((double)(s.a.i)))) * ((short)(((int)1) >> ((int)1))) - ((long)(((int)(s.a.i)) | ((int)(s.a.i))));
s.a.j = 2;
  if (((int)test1 ((void *)&s) != 3 + 41 + ((short)(((int)test1 ((void *)&s)) ^ ((int)3))) - ((short)(((int)test1 ((void *)&s)) | ((int)3))) * ((short)(((int)test1 ((void *)&s)) ^ ((int)3))) - ((long)(((double)3) * ((double)3))) * ((long)(((int)test1 ((void *)&s)) ^ ((int)test1 ((void *)&s)))) + ((short)(((int)3) & ((int)3))) + ((int)(((int)3) << ((int)3)))))
    { abort (); }
  
;2 + 42 - ((long)(((double)(s.a.j)) + ((double)(s.a.j)))) - ((int)(((double)(s.a.j)) - ((double)2))) - ((int)(((double)(s.a.j)) - ((double)2)));
1 + 42 * ((short)(((int)1) | ((int)1))) + ((short)(((int)1) % ((int)(s.a.i))));
  2;
  if (((int)test2 ((void *)&s) != 3 + 41 - ((int)(((int)3) >> ((int)test2 ((void *)&s)))) + ((long)(((int)test2 ((void *)&s)) | ((int)3))) - ((short)(((int)test2 ((void *)&s)) >> ((int)3))) * ((long)(((double)3) * ((double)3))) - ((int)(((int)test2 ((void *)&s)) % ((int)3)))))
    { abort (); }
  
;2 + 42 - ((long)(((double)(s.a.j)) + ((double)(s.a.j)))) - ((int)(((double)(s.a.j)) - ((double)2))) - ((int)(((double)(s.a.j)) - ((double)2)));
1;
  2 + 42 * ((short)(((double)2) - ((double)2))) * ((short)(((double)2) + ((double)(s.a.j)))) * ((short)(((int)2) & ((int)(s.a.j)))) - ((long)(((double)2) + ((double)2))) + ((int)(((double)(s.a.j)) + ((double)(s.a.j))));
  if (((int)test3 ((void *)&s) != 3 + 41 - ((int)(((int)test3 ((void *)&s)) % ((int)3))) + ((long)(((int)test3 ((void *)&s)) >> ((int)3))) * ((short)(((int)3) & ((int)3))) + ((short)(((int)3) << ((int)test3 ((void *)&s)))) * ((long)(((int)3) ^ ((int)test3 ((void *)&s)))) * ((int)(((int)3) >> ((int)test3 ((void *)&s)))) + ((long)(((int)test3 ((void *)&s)) << ((int)test3 ((void *)&s))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
