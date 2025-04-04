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
  
;b->i = 3;
0;
  
;s.a.i = 0;
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
;
;s.a.i = 0;
0;

;s.a.i = 1;
s.a.i = 0;
3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;s.a.i = 1;
0;
  
;
;s.a.j = 2;
1;
3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  
;2;

;s.a.j = 2;
1;
  2;
  if (0)
    { abort (); }
  
;2;
1;
  
;1;
2;
  if (0)
    { abort (); }
  1;
  2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
