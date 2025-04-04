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
  b->i = 3 + 42 - ((short)(((int)(b->i)) ^ ((int)3))) - ((long)(((double)(b->i)) * ((double)3))) * ((long)(((double)(b->i)) * ((double)3))) + ((int)(((double)3) + ((double)3)));
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
  s.a.i = 0 + 42 - ((int)(((int)0) << ((int)0))) * ((short)(((int)(s.a.i)) << ((int)0)));
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 - ((short)(((int)(((struct S *)((char *)q + sizeof (int)))->i)) >> ((int)(((struct S *)((char *)q + sizeof (int)))->i)))) - ((int)(((double)3) * ((double)3))) + ((short)(((int)3) ^ ((int)(((struct S *)((char *)q + sizeof (int)))->i)))) + ((short)(((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)(((struct S *)((char *)q + sizeof (int)))->i)))) * ((long)(((int)3) | ((int)(((struct S *)((char *)q + sizeof (int)))->i))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  s.a.i = 1 + 42 - ((int)(((double)1) + ((double)1)));
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1 + 42 - ((int)(((double)(s.a.i)) + ((double)(s.a.i)))) * ((long)(((int)(s.a.i)) << ((int)1)));
  s.a.j = 2 + 42 + ((long)(((double)(s.a.j)) + ((double)2))) * ((int)(((double)2) - ((double)(s.a.j)))) - ((long)(((int)2) ^ ((int)2))) + ((long)(((double)2) - ((double)2)));
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
