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
  
;b->i = 3;
0;
  
;s.a.i = 0 + 42 + ((int)((((int)(0)) | ((int)(s.a.i)))));
b->i = 3 + 42 + ((long)((((double)(3)) + ((double)(3))))) + ((int)((((int)(b->i)) | ((int)(3))))) + ((short)((((double)(3)) * ((double)(3))))) + ((long)((((double)(3)) - ((double)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 - ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) | ((int)(3)))));
s.a.i = 0;
  
;s.a.i = 1;
((struct S *)((char *)q + sizeof (int)))->i = 3 + 42 * ((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^ ((int)(3))))) * ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^ ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) - ((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) & ((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + ((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) >> ((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  
;s.a.j = 2 + 42 - ((long)((((int)(2)) | ((int)(2))))) - ((long)((((int)(2)) ^ ((int)(2))))) + ((int)((((double)(2)) * ((double)(s.a.j)))));
s.a.i = 1 + 42 - ((long)((((double)(1)) - ((double)(s.a.i))))) * ((short)((((int)(s.a.i)) << ((int)(1))))) - ((long)((((double)(1)) + ((double)(1))))) + ((short)((((double)(1)) * ((double)(s.a.i)))));
  
;s.a.i = 1;
s.a.j = 2;
  if (0)
    { abort (); }
  
;s.a.j = 2 + 42 - ((long)((((double)(2)) + ((double)(2))))) + ((short)((((double)(s.a.j)) * ((double)(s.a.j))))) * ((long)((((double)(2)) * ((double)(2))))) - ((int)((((double)(s.a.j)) * ((double)(s.a.j))))) + ((int)((((double)(s.a.j)) - ((double)(2)))));
s.a.i = 1;
  
;s.a.i = 1;
s.a.j = 2;
  if (0)
    { abort (); }
  s.a.i = 1;
  s.a.j;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
