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
  ;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;
;
;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  

s.a.i = (0) + (0x9EF501) -((short)((((int)(s.a.i)) %((int)((0))))))+((int)((((double)((67108864))) -((double)(s.a.i)))))+((long)((((double)((2147483648))) +((double)((2048))))))-((short)((((int)(s.a.i)) ^((int)((-1))))));
s.a.i = (0x84EE) + (0x07CA) -((short)((((int)(s.a.i)) %((int)((0))))))+((int)((((double)((0))) -((double)(s.a.i)))))+((long)((((double)((0xD3ED))) +((double)((0))))))-((short)((((int)(s.a.i)) ^((int)((0xF738))))));
;
;
;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((-1))
    { return (0); }
  
;

s.a.i = (65) + (42) *((int)((((int)(s.a.i)) |((int)((-2))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
s.a.i = (0) + (42) *((int)((((int)(s.a.i)) |((int)((-2))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
;
  ;
  if ((0))
    { abort (); }
  ;
  
;
;
;
  if (((int)test2 ((void *)&s) != (2) + (-43) *((long)((((int)(test2 ((void *)&s))) <<((int)(test2 ((void *)&s))))))+((short)((((int)((3))) %((int)(test2 ((void *)&s))))))-((int)((((int)(test2 ((void *)&s))) <<((int)(test2 ((void *)&s))))))*((int)((((int)(test2 ((void *)&s))) <<((int)(test2 ((void *)&s))))))+((short)((((int)((-4))) %((int)(test2 ((void *)&s))))))-((short)((((int)((0x6C))) %((int)(test2 ((void *)&s))))))+((int)((((int)(test2 ((void *)&s))) |((int)(test2 ((void *)&s))))))))
    { abort (); }
  

s.a.i = (0x5A) + (-43) -((int)((((int)(s.a.i)) &((int)((-2))))));
s.a.i = (9) + (46) -((int)((((int)(s.a.i)) &((int)((0x30E1D))))));
;
;
;
  

s.a.j = (2) + (0x1D71) *((int)((((double)(s.a.j)) +((double)((10))))));
s.a.j = (0x8F) + (42) *((int)((((double)(s.a.j)) +((double)((6))))));
;
;
;
  if ((0x5FC))
    { abort (); }
  return (0x0735);
}
/* ProgramSourceLLVM */
