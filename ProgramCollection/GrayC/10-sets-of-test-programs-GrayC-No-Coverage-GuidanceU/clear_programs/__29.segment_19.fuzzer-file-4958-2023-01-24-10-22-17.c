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
  3 + 42 - ((long)((((double)(b->i)) - ((double)(b->i))))) + ((int)((((int)(3)) & ((int)(b->i))))) * ((long)((((double)(b->i)) - ((double)(b->i))))) - ((long)((((int)(3)) | ((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;3 + 42 - ((long)((((double)(b->i)) - ((double)(b->i))))) + ((int)((((int)(3)) & ((int)(b->i))))) * ((long)((((double)(b->i)) - ((double)(b->i))))) - ((long)((((int)(3)) | ((int)(b->i)))));
0 + 42 * ((long)((((int)(0)) | ((int)(s.a.i))))) - ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) * ((short)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((short)((((double)(s.a.i)) * ((double)(0))))) + ((short)((((int)(s.a.i)) >> ((int)(s.a.i)))));
  
;
;b->i = 3;
0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))) + 42 * ((long)((((int)(0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))))) | ((int)(s.a.i))))) - ((short)((((double)(s.a.i)) - ((double)(s.a.i))))) * ((short)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((short)((((int)(s.a.i)) & ((int)(0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0)))))))))) + ((short)((((int)(s.a.i)) >> ((int)(s.a.i)))));

;s.a.i = 0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))) + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((int)(0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))))) ^ ((int)(0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))))))));
b->i;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;s.a.j;
0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))) + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((int)(0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))))) ^ ((int)(0 + 42 - ((long)((((double)(s.a.i)) * ((double)(s.a.i))))) - ((short)((((double)(s.a.i)) + ((double)(s.a.i))))) + ((long)((((int)(s.a.i)) >> ((int)(s.a.i))))) - ((long)((((double)(0)) + ((double)(0))))))))));
  3;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (0)
    { return 0; }
  
;2 + 42 - ((short)((((double)(s.a.j)) * ((double)(2))))) + 42 * ((short)((((int)(2 + 42)) ^ ((int)(2))))) * ((int)((((double)(2)) * ((double)(2))))) * ((short)((((int)(((short)((((double)(s.a.j)) * ((double)(2))))))) | ((int)(s.a.j))))) + ((long)((((int)(((short)((((double)(s.a.j)) * ((double)(2))))))) ^ ((int)(s.a.j)))));
1;
  
;
;
;s.a.j = 2;
2;

;s.a.j = 2;
s.a.j = 2;
2 + 42 - ((short)((((double)(s.a.j)) * ((double)(2)))));
  if (0)
    { abort (); }
  
;s.a.j = 2;
1;
  
;
;
;s.a.j = 2 + 42 + ((long)((((double)(2)) - ((double)(2))))) + ((short)((((int)(2)) >> ((int)(2)))));
s.a.j;
s.a.j;
2;
  if (0)
    { abort (); }
  
;s.a.j = 2 + 42 + ((long)((((double)(2)) - ((double)(2))))) + ((short)((((int)(2)) >> ((int)(2)))));
1;
  2;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
