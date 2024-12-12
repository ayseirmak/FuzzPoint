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
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  ;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  ;
  
((struct S *)((char *)q + sizeof (int)))->i = 3;
((struct S *)((char *)q + sizeof (int)))->i = 3;
;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  
s.a.i = 1;
s.a.i = 1;
;
  ;
  if (0)
    { abort (); }
  ;
  
s.a.j = 2;
s.a.j = 2;
;
  if (0)
    { abort (); }
  ;
  
s.a.j = 2;
s.a.j = 2;
;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
