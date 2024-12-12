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
  s.a.i = 0 + 42 * ((int)((((double)(s.a.i)) - ((double)(s.a.i)))));
  b->i = 3 + 42 * ((short)((((double)(3)) - ((double)(3))))) - ((int)((((double)(3)) * ((double)(3))))) * ((long)((((double)(3)) + ((double)(3))))) * ((long)((((double)(3)) - ((double)(3))))) * ((short)((((int)(3)) & ((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0;
  b->i = 3;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0 + 42 - ((long)((((double)(s.a.i)) + ((double)(0)))));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 - ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) % ((int)(3))))) + ((long)((((int)(3)) << ((int)(3))))) + ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^ ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) << ((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  s.a.i = 1;
  s.a.j = 2 + 42 * ((int)((((int)(2)) >> ((int)(s.a.j)))));
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 + ((short)((((int)(2)) ^ ((int)(s.a.j)))));
  if (0)
    { abort (); }
  s.a.i = 1 + 42 + ((int)((((int)(1)) % ((int)(1))))) * ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) + ((int)((((int)(1)) >> ((int)(s.a.i))))) * ((long)((((double)(s.a.i)) * ((double)(1))))) + ((long)((((double)(s.a.i)) - ((double)(s.a.i)))));
  s.a.j = 2 + 42 * ((long)((((int)(s.a.j)) >> ((int)(2)))));
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
