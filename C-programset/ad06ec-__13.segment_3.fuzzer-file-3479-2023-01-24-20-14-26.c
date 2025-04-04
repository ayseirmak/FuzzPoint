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
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + 41 - ((int)((((int)(offsetof (struct Q, a) != sizeof (int))) | ((int)(sizeof (float)))))) * ((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) + ((double)(offsetof (struct Q, a)))))) - ((short)((((int)(offsetof (struct Q, a))) % ((int)(offsetof (struct R, a)))))) - ((long)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) ^ ((int)(offsetof (struct Q, a)))))) + ((int)((((int)(sizeof (int))) >> ((int)(offsetof (struct R, a) != sizeof (int)))))) + ((short)((((double)(sizeof (int))) - ((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)))))) * ((short)((((int)(sizeof (float))) & ((int)(sizeof (int)))))) - ((int)((((double)(sizeof (float) != sizeof (int))) + ((double)(sizeof (float))))))))
    { return 0; }
  
;s.a.j = 2;
s.a.i = 1 + 42 + ((int)((((double)(s.a.i)) * ((double)(1)))));
  s.a.j = 2 + 42 + ((short)((((int)(2)) & ((int)(s.a.j)))));
  if (((int)test1 ((void *)&s) != 3 + 41 - ((short)((((double)(3)) + ((double)(3)))))))
    { abort (); }
  s.a.i;
  2;
  if (((int)test2 ((void *)&s) != 3 + 41 - ((short)((((int)(3)) | ((int)(test2 ((void *)&s)))))) - ((long)((((double)(3)) + ((double)(3))))) - ((int)((((double)(3)) + ((double)(3)))))))
    { abort (); }
  1;
  2;
  if (((int)test3 ((void *)&s) != 3 + 41 * ((short)((((int)(test3 ((void *)&s))) % ((int)(3))))) * ((long)((((int)(test3 ((void *)&s))) >> ((int)(3))))) - ((int)((((int)(3)) >> ((int)(test3 ((void *)&s))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
