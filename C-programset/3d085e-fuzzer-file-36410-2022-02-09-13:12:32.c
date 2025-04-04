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
  
b->i = (3);
b->i = (3);
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  ;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((128))
    { return (0); }
  
s.a.i = (65);
s.a.i = (1);
;
  
s.a.j = (34);
s.a.j = (2);
;
  if (test1 ((void *)&s) != (3))
    { abort (); }
  ;
  
s.a.j = (0x59431);
s.a.j = (0xA5083);
;
  if (test2 ((void *)&s) != (0x16B2F))
    { abort (); }
  ;
  
s.a.j = (2);
s.a.j = (0xFA0F8);
;
  if (test3 ((void *)&s) != (0x6F))
    { abort (); }
  return (8);
}
/* ProgramSourceLLVM */
