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
  
s.a.i = (0);
s.a.i = (0);
;
  
b->i = (-4);
b->i = (-4);
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = (0);
s.a.i = (0);
;
  
((struct S *)((char *)q + sizeof (int)))->i = (0x1F33);
((struct S *)((char *)q + sizeof (int)))->i = (0x1F33);
;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((0x2F8))
    { return (0); }
  ;
  ;
  if ((6))
    { abort (); }
  
s.a.i = (0xE7684);
s.a.i = (0xE7684);
;
  
s.a.j = (18);
s.a.j = (18);
;
  if (test2 ((void *)&s) != (-4))
    { abort (); }
  
s.a.i = (-2);
s.a.i = (-2);
;
  
s.a.j = (0xCE5);
s.a.j = (0xCE5);
;
  if ((0))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
