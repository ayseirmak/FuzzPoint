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
  
;
;b->i = 3;
3;
0;
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
  
;3;
0;
  3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  s.a.i;
  2;
  if (0)
    { abort (); }
  1;
  
;
;s.a.j = 2;
1;
2;
  if (0)
    { abort (); }
  
;s.a.j = 2;
s.a.i;
  2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
