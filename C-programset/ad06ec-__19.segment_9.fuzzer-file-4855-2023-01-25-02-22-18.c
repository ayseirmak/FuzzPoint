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
  b->i = 3 + 42 - ((int)((((int)(b->i)) % ((int)(b->i))))) + ((int)((((int)(b->i)) << ((int)(b->i))))) - ((short)((((double)(b->i)) + ((double)(3)))));
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
  s.a.i = 0;
  ((struct S *)((char *)q + sizeof (int)))->i = 3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  s.a.i = 1 + 42 * ((int)((((double)(s.a.i)) * ((double)(1))))) * ((int)((((double)(1)) - ((double)(s.a.i))))) * ((int)((((int)(1)) << ((int)(1))))) + ((int)((((int)(1)) ^ ((int)(s.a.i)))));
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1 + 42 + ((int)((((int)(s.a.i)) >> ((int)(1))))) + ((short)((((double)(s.a.i)) * ((double)(1)))));
  s.a.j = 2 + 42 - ((short)((((int)(s.a.j)) << ((int)(s.a.j))))) - ((int)((((double)(s.a.j)) + ((double)(s.a.j))))) - ((short)((((double)(s.a.j)) + ((double)(2))))) * ((short)((((double)(s.a.j)) * ((double)(2)))));
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j = 2 + 42 * ((short)((((int)(2)) ^ ((int)(s.a.j))))) * ((long)((((int)(s.a.j)) & ((int)(s.a.j))))) * ((int)((((int)(2)) | ((int)(2))))) + ((int)((((double)(2)) + ((double)(s.a.j))))) * ((int)((((int)(2)) ^ ((int)(2)))));
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
