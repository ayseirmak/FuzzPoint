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
  0;
  3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;((struct S *)((char *)q + sizeof (int)))->i = 3;
0;
  
;
;((struct S *)((char *)q + sizeof (int)))->i = 3;
1;
((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int))
    { return 0; }
  
;
;s.a.i = 1;
2;

;s.a.j = 2;
s.a.i = 1;
  s.a.j = 2;
  if (test1 ((void *)&s) != 3)
    { abort (); }
  
;
;s.a.j = 2;
2;
1;
  s.a.j = 2;
  if (test2 ((void *)&s) != 3)
    { abort (); }
  1;
  2;
  if (test3 ((void *)&s) != 3)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
