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
  

s.a.i = (0xFD58) + (-43) -((short)((((int)(s.a.i)) %((int)((7))))))+((int)((((double)((0))) -((double)(s.a.i)))))+((long)((((double)((512))) +((double)((-1))))))-((short)((((int)(s.a.i)) ^((int)((0xA))))));
s.a.i = (0x8C63A) + (0x3AD632) -((short)((((int)(s.a.i)) %((int)((4096))))))+((int)((((double)((0))) -((double)(s.a.i)))))+((long)((((double)((0))) +((double)((0x1DC))))))-((short)((((int)(s.a.i)) ^((int)((0))))));
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

s.a.i = (-2) + (42) *((int)((((int)(s.a.i)) |((int)((0))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
s.a.i = (1) + (42) *((int)((((int)(s.a.i)) |((int)((33))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
;
  ;
  if (((int)test1 ((void *)&s) != (-4) + (46) +((long)((((double)((-4))) *((double)((0x26E))))))-((long)((((int)((0xB730))) &((int)((131))))))*((long)((((int)(test1 ((void *)&s))) ^((int)(test1 ((void *)&s))))))-((int)((((int)((7))) %((int)((0x7))))))-((int)((((int)((0x7F))) <<((int)((7))))))*((long)((((int)(test1 ((void *)&s))) <<((int)((3))))))*((long)((((int)(test1 ((void *)&s))) |((int)(test1 ((void *)&s))))))-((long)((((double)((0x167A))) *((double)((7))))))+((long)((((int)((0x09))) <<((int)(test1 ((void *)&s))))))*((short)((((int)(test1 ((void *)&s))) |((int)((3))))))))
    { abort (); }
  ;
  
;
;
;
  if ((0))
    { abort (); }
  

s.a.i = (0xE9E) + (42) -((int)((((int)(s.a.i)) &((int)((0xA900))))));
s.a.i = (0x2) + (43) -((int)((((int)(s.a.i)) &((int)((0x4))))));
;
;
;
  

s.a.j = (2) + (34) *((int)((((double)(s.a.j)) +((double)((10))))));
s.a.j = (2) + (10) *((int)((((double)(s.a.j)) +((double)((-3))))));
;
;
;
  if ((0))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
