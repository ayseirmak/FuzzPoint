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
  0;
  
;s.a.i = 0;
3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;((struct S *)((char *)q + sizeof (int)))->i = 3;
s.a.i = 0;
  
;s.a.i = 1;
((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  s.a.i = 1 + 42 + ((long)((((int)(s.a.i)) ^ ((int)(s.a.i))))) + ((short)((((double)(1)) + ((double)(1))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i)))));
  
;s.a.i = 1;
2;
  if (0)
    { abort (); }
  
;s.a.j = 2;
s.a.i = 1;
  
;s.a.i = 1 + 42 - ((short)((((int)(s.a.i)) >> ((int)(1))))) + ((short)((((double)(1)) - ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) * ((double)(s.a.i))))) * ((short)((((int)(1)) % ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) - ((double)(1)))));
s.a.j = 2 + 42 * ((long)((((double)(s.a.j)) * ((double)(s.a.j))))) * ((int)((((double)(2)) + ((double)(s.a.j))))) + ((int)((((double)(2)) - ((double)(2))))) + ((short)((((double)(2)) + ((double)(2))))) + ((short)((((int)(s.a.j)) << ((int)(2)))));
  if (0)
    { abort (); }
  
;s.a.j = 2;
s.a.i = 1 + 42 + ((int)((((double)(s.a.i)) * ((double)(1)))));
  s.a.j = 2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
