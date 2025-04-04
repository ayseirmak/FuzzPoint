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
  s.a.i = 0;
  b->i = 3 + 42 * ((int)(((double)3) - ((double)(b->i)))) * ((short)(((int)3) % ((int)3))) - ((short)(((int)3) & ((int)3)));
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
  s.a.i = 1 + 42 * ((short)(((double)1) + ((double)(s.a.i)))) * ((short)(((int)(s.a.i)) & ((int)(s.a.i))));
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1 + 42 * ((int)(((int)1) ^ ((int)(s.a.i)))) + ((long)(((int)(s.a.i)) ^ ((int)(s.a.i))));
  s.a.j = 2 + 42 - ((int)(((int)(s.a.j)) | ((int)(s.a.j)))) * ((int)(((int)2) ^ ((int)2))) + ((short)(((int)(s.a.j)) & ((int)(s.a.j)))) * ((int)(((double)2) * ((double)(s.a.j)))) + ((long)(((double)(s.a.j)) + ((double)2)));
  if (0)
    { abort (); }
  s.a.i = 1 + 42 * ((long)(((double)(s.a.i)) + ((double)(s.a.i)))) * ((long)(((double)(s.a.i)) * ((double)(s.a.i)))) - ((long)(((double)1) * ((double)1)));
  s.a.j = 2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
