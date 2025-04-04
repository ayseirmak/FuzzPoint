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
  

s.a.i = (0) + (46) -((short)((((int)(s.a.i)) %((int)((2048))))))+((int)((((double)((512))) -((double)(s.a.i)))))+((long)((((double)((0x3B))) +((double)((512))))))-((short)((((int)(s.a.i)) ^((int)((0))))));
s.a.i = (0x4DECC) + (42) -((short)((((int)(s.a.i)) %((int)((-1))))))+((int)((((double)((0))) -((double)(s.a.i)))))+((long)((((double)((0xEF16))) +((double)((256))))))-((short)((((int)(s.a.i)) ^((int)((0xEA6E9))))));
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
  if ((0x9DE9))
    { return (0); }
  
;

s.a.i = (1) + (34) *((int)((((int)(s.a.i)) |((int)((0x9))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
s.a.i = (65) + (106) *((int)((((int)(s.a.i)) |((int)((1))))))-((int)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
;
  ;
  if (((int)test1 ((void *)&s) != (0xB5AB9) + (46) +((long)((((double)((0x24C))) *((double)((3))))))-((long)((((int)((-4))) &((int)((-4))))))*((long)((((int)(test1 ((void *)&s))) ^((int)(test1 ((void *)&s))))))-((int)((((int)((11))) %((int)((0x77B))))))-((int)((((int)((3))) <<((int)((-4))))))*((long)((((int)(test1 ((void *)&s))) <<((int)((-4))))))*((long)((((int)(test1 ((void *)&s))) |((int)(test1 ((void *)&s))))))-((long)((((double)((0xA))) *((double)((7))))))+((long)((((int)((0xB3733))) <<((int)(test1 ((void *)&s))))))*((short)((((int)(test1 ((void *)&s))) |((int)((-4))))))))
    { abort (); }
  ;
  
;
;
;
  if (0)
    { abort (); }
  

s.a.i = (-2) + (-43) -((int)((((int)(s.a.i)) &((int)((-2))))));
s.a.i = (129) + (0x1600) -((int)((((int)(s.a.i)) &((int)((1))))));
;
;
;
  

s.a.j = (0x9E9F) + (0x7B1) *((int)((((double)(s.a.j)) +((double)((34))))));
s.a.j = (2) + (10) *((int)((((double)(s.a.j)) +((double)((-3))))));
;
;
;
  if ((0xEB))
    { abort (); }
  return (2048);
}
/* ProgramSourceLLVM */
