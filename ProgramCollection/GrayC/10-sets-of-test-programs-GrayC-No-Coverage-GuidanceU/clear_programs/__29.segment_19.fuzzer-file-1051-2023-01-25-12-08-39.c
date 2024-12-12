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
  
;b->i = 3;
b->i;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;b->i = 3;
0;
  
;s.a.j = 2 + 42 + ((long)((((int)(2)) | ((int)(s.a.j))))) - ((long)((((double)(2)) + ((double)(s.a.j))))) * ((long)((((double)(s.a.j)) - ((double)(2)))));
3;
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
  
;
;s.a.i = 1;
s.a.j = 2;
1;
  
;
;s.a.j = 2;
s.a.i = 1;

;s.a.j = 2;
s.a.j = 2 + 42 - ((long)((((int)(2)) << ((int)(s.a.j))))) - ((short)((((int)(2)) % ((int)(s.a.j))))) + ((long)((((double)(s.a.j)) + ((double)(2))))) - ((short)((((double)(s.a.j)) * ((double)(s.a.j)))));
  if (0)
    { abort (); }
  
;s.a.j = 2 + 42 * ((int)((((double)(2)) + ((double)(s.a.j))))) - ((int)((((int)(s.a.j)) % ((int)(s.a.j))))) * ((int)((((double)(s.a.j)) - ((double)(s.a.j))))) + ((int)((((int)(2)) | ((int)(2)))));

;s.a.j = 2;
s.a.i;
  s.a.j = 2 + 42 * ((short)((((double)(2)) + ((double)(s.a.j))))) - ((long)((((double)(2)) - ((double)(s.a.j)))));
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
