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
  s.a.i = 0 + 42 * ((int)((((int)(0)) ^ ((int)(s.a.i))))) * ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((int)((((int)(s.a.i)) % ((int)(s.a.i))))) + ((long)((((double)(0)) + ((double)(s.a.i))))) + 42 + ((int)((((int)(s.a.i)) >> ((int)(0 + 42 * ((int)((((int)(0)) ^ ((int)(s.a.i))))) * ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((int)((((int)(s.a.i)) % ((int)(s.a.i))))) + ((long)((((double)(0)) + ((double)(s.a.i)))))))))) + ((short)((((int)(0 + 42 * ((int)((((int)(0)) ^ ((int)(s.a.i))))) * ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((int)((((int)(s.a.i)) % ((int)(s.a.i))))) + ((long)((((double)(0)) + ((double)(s.a.i))))))) << ((int)(0 + 42 * ((int)((((int)(0)) ^ ((int)(s.a.i))))) * ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((int)((((int)(s.a.i)) % ((int)(s.a.i))))) + ((long)((((double)(0)) + ((double)(s.a.i)))))))))) * ((long)((((int)(0 + 42 * ((int)((((int)(0)) ^ ((int)(s.a.i))))) * ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((int)((((int)(s.a.i)) % ((int)(s.a.i))))) + ((long)((((double)(0)) + ((double)(s.a.i))))))) % ((int)(s.a.i))))) * ((long)((((int)(s.a.i)) ^ ((int)(s.a.i)))));
  b->i = 3 + 42 * ((long)((((int)(b->i)) % ((int)(3))))) + 42 - ((int)((((int)(3 + 42 * ((long)((((int)(b->i)) % ((int)(3))))))) << ((int)(3 + 42 * ((long)((((int)(b->i)) % ((int)(3)))))))))) - ((long)((((double)(b->i)) - ((double)(b->i))))) - ((int)((((int)(3 + 42 * ((long)((((int)(b->i)) % ((int)(3))))))) ^ ((int)(3 + 42 * ((long)((((int)(b->i)) % ((int)(3)))))))))) - ((short)((((int)(b->i)) % ((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = 0 + 42 * ((int)((((int)(0)) & ((int)(s.a.i))))) + ((short)((((int)(s.a.i)) % ((int)(0))))) + ((short)((((int)(0)) >> ((int)(s.a.i))))) - ((short)((((int)(0)) % ((int)(s.a.i)))));
  b->i = 3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i))))) + 42 - ((int)((((int)(3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i))))))) & ((int)(3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i)))))))))) + ((short)((((int)(3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i))))))) & ((int)(3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i)))))))))) + ((long)((((int)(b->i)) | ((int)(3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i)))))))))) - ((int)((((int)(3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i))))))) >> ((int)(3 + 42 + ((long)((((double)(3)) - ((double)(b->i))))) * ((long)((((double)(b->i)) + ((double)(b->i))))) - ((long)((((int)(b->i)) >> ((int)(b->i))))))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = 0;
  ((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) << ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + 42 + ((long)((((int)(((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) << ((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) << ((int)(3 + 42 * ((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) << ((int)(((struct S *)((char *)q + sizeof (int)))->i)))))))))) * ((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^ ((int)(42)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  s.a.i = 1 + 42 * ((short)((((double)(s.a.i)) * ((double)(s.a.i)))));
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1 + 42 * ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) + ((long)((((int)(1)) | ((int)(s.a.i))))) + ((short)((((int)(1)) % ((int)(1))))) - ((long)((((int)(1)) << ((int)(1)))));
  s.a.j = 2 + 42 - ((int)((((double)(2)) - ((double)(2))))) + ((int)((((double)(s.a.j)) + ((double)(s.a.j))))) * ((long)((((int)(2)) ^ ((int)(s.a.j)))));
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
