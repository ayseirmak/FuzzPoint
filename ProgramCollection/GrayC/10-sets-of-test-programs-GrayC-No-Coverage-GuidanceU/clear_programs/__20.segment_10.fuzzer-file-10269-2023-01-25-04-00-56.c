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
  s.a.i = 0 + 42 * ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) + ((short)((((double)(0)) - ((double)(0))))) + ((short)((((int)(0)) & ((int)(0))))) + ((short)((((int)(0)) >> ((int)(0))))) * ((int)((((int)(0)) >> ((int)(0)))));
  b->i = 3 + 42 + ((int)((((double)(3)) - ((double)(b->i))))) + ((int)((((double)(3)) - ((double)(3))))) * ((long)((((int)(3)) % ((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;b->i = 3 + 42 - ((short)((((double)(b->i)) - ((double)(b->i))))) * ((long)((((int)(3)) << ((int)(3)))));
0;
  b->i = 3;
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
  if (0)
    { return 0; }
  s.a.i;
  2;
  if (0)
    { abort (); }
  
;s.a.j = 2 + 42 + ((int)((((int)(s.a.j)) & ((int)(2))))) * ((long)((((int)(2)) >> ((int)(s.a.j))))) + ((short)((((double)(s.a.j)) - ((double)(s.a.j)))));
1;
  
;s.a.i = 1;
s.a.j = 2 + 42 * ((long)((((double)(2)) + ((double)(s.a.j))))) - ((long)((((double)(2)) - ((double)(s.a.j)))));
  if (0)
    { abort (); }
  
;s.a.j = 2;
s.a.i = 1 + 42 * ((int)((((double)(s.a.i)) - ((double)(1))))) + ((int)((((double)(1)) - ((double)(1)))));
  s.a.j = 2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
