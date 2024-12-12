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
  s.a.i = ((2910));
  b->i = ((3801));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;s.a.i = ((19566));
((4065));
  
;
;s.a.i = ((5084));
s.a.i = ((4313)) + ((9883)) * ((short)((((double)(((28863)))) - ((double)(s.a.i)))));
((11979));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;s.a.i = ((6273));
s.a.i = ((18016));
  
;s.a.i = ((17223));
((20363));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((11413)))
    { return ((16896)); }
  
;(-(19186));

;s.a.j = ((11659));
((22225));
  s.a.j = ((11542));
  if (((884)))
    { abort (); }
  
;((10555));
((13070));
  
;((4955));
((7803));
  if (((29280)))
    { abort (); }
  ((27741));
  ((902));
  if (((16674)))
    { abort (); }
  return ((2321));
}
/* ProgramSourceLLVM */
