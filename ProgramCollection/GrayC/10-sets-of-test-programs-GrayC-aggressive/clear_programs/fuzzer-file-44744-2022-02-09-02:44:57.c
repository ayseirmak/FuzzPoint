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
  
s.a.i = (4) + (42) *((short)((((double)(s.a.i)) *((double)((1))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((64))) |((int)(s.a.i)))))*((short)((((double)((-1))) +((double)((0xFB5)))))) + (170) -((long)((((int)((0x8119) + (-43) *((short)((((double)(s.a.i)) *((double)((0x5))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((0))) |((int)(s.a.i)))))*((short)((((double)((0))) +((double)((0)))))))) %((int)(s.a.i)))))-((long)((((int)((0) + (-43) *((short)((((double)(s.a.i)) *((double)((0))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((0xC5))) |((int)(s.a.i)))))*((short)((((double)((1048576))) +((double)((0x5)))))))) >>((int)(s.a.i)))))-((long)((((int)((0x8) + (0x707) *((short)((((double)(s.a.i)) *((double)((0))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((0))) |((int)(s.a.i)))))*((short)((((double)((2))) +((double)((0)))))))) ^((int)(s.a.i)))))*((int)((((int)(s.a.i)) |((int)(s.a.i)))))*((int)((((double)(s.a.i)) +((double)(s.a.i)))));
s.a.i = (4) + (42) *((short)((((double)(s.a.i)) *((double)((1))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((64))) |((int)(s.a.i)))))*((short)((((double)((-1))) +((double)((0xFB5)))))) + (170) -((long)((((int)((0x8119) + (-43) *((short)((((double)(s.a.i)) *((double)((0x5))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((0))) |((int)(s.a.i)))))*((short)((((double)((0))) +((double)((0)))))))) %((int)(s.a.i)))))-((long)((((int)((0) + (-43) *((short)((((double)(s.a.i)) *((double)((0))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((0xC5))) |((int)(s.a.i)))))*((short)((((double)((1048576))) +((double)((0x5)))))))) >>((int)(s.a.i)))))-((long)((((int)((0x8) + (0x707) *((short)((((double)(s.a.i)) *((double)((0))))))*((long)((((int)(s.a.i)) |((int)(s.a.i)))))-((long)((((int)((0))) |((int)(s.a.i)))))*((short)((((double)((2))) +((double)((0)))))))) ^((int)(s.a.i)))))*((int)((((int)(s.a.i)) |((int)(s.a.i)))))*((int)((((double)(s.a.i)) +((double)(s.a.i)))));
;
  ;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  ;
  
b->i = (-4) + (170) *((short)((((int)((0x04922))) &((int)((67)))))) + (43) *((short)((((int)((-4) + (0xE1D2) *((short)((((int)((1))) &((int)((2)))))))) |((int)(b->i)))))+((long)((((int)((42) *((short)((((int)((7))) &((int)((1)))))))) <<((int)(b->i)))))*((short)((((double)((0xCD058))) -((double)(b->i)))))+((short)((((double)(b->i)) *((double)((-4))))))+((long)((((int)(b->i)) &((int)(((short)((((int)((1))) &((int)((-4)))))))))));
b->i = (-4) + (170) *((short)((((int)((0x04922))) &((int)((67)))))) + (43) *((short)((((int)((-4) + (0xE1D2) *((short)((((int)((1))) &((int)((2)))))))) |((int)(b->i)))))+((long)((((int)((42) *((short)((((int)((7))) &((int)((1)))))))) <<((int)(b->i)))))*((short)((((double)((0xCD058))) -((double)(b->i)))))+((short)((((double)(b->i)) *((double)((-4))))))+((long)((((int)(b->i)) &((int)(((short)((((int)((1))) &((int)((-4)))))))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = (0) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((0))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((268435456))))))+((int)((((int)((0))) %((int)((0xFDFE0))))))-((int)((((int)((0x9AE4))) >>((int)(s.a.i))))) + (42) -((int)((((int)((0x529D8) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((2097152))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((-1))))))+((int)((((int)((17592186044416))) %((int)((0))))))-((int)((((int)((262144))) >>((int)(s.a.i))))))) &((int)(((int)((((int)((0))) >>((int)(s.a.i))))))))))*((long)((((int)((170))) &((int)((-1) + (-43) *((short)((((double)(s.a.i)) *((double)(s.a.i))))))))))+((int)((((int)(((int)((((int)((0x94475))) %((int)((4)))))))) &((int)(((short)((((int)((2))) <<((int)(s.a.i))))))))))+((long)((((int)((1073741824) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((16))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((0x6))))))+((int)((((int)((0x4))) %((int)((32))))))-((int)((((int)((0))) >>((int)(s.a.i))))))) &((int)((0x23B0) + (0x373C) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((0))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((0)))))))))))-((long)((((int)(((short)((((int)((-1))) <<((int)(s.a.i))))))) |((int)(((short)((((int)((0))) <<((int)(s.a.i))))))))));
s.a.i = (0) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((0))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((268435456))))))+((int)((((int)((0))) %((int)((0xFDFE0))))))-((int)((((int)((0x9AE4))) >>((int)(s.a.i))))) + (42) -((int)((((int)((0x529D8) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((2097152))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((-1))))))+((int)((((int)((17592186044416))) %((int)((0))))))-((int)((((int)((262144))) >>((int)(s.a.i))))))) &((int)(((int)((((int)((0))) >>((int)(s.a.i))))))))))*((long)((((int)((170))) &((int)((-1) + (-43) *((short)((((double)(s.a.i)) *((double)(s.a.i))))))))))+((int)((((int)(((int)((((int)((0x94475))) %((int)((4)))))))) &((int)(((short)((((int)((2))) <<((int)(s.a.i))))))))))+((long)((((int)((1073741824) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((16))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((0x6))))))+((int)((((int)((0x4))) %((int)((32))))))-((int)((((int)((0))) >>((int)(s.a.i))))))) &((int)((0x23B0) + (0x373C) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((0))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((0)))))))))))-((long)((((int)(((short)((((int)((-1))) <<((int)(s.a.i))))))) |((int)(((short)((((int)((0))) <<((int)(s.a.i))))))))));
;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((64))
    { return (32768); }
  ;
  ;
  if (((int)((int)test1 ((void *)&s) != (-4) + (0x0228B6) -((long)((((int)(test1 ((void *)&s))) %((int)((3))))))-((int)((((double)((19))) +((double)((7))))))) + (106) *((short)((((int)((-4) + (0xD69) -((long)((((int)(test1 ((void *)&s))) %((int)((131))))))-((int)((((double)((-4))) +((double)((-4)))))))) >>((int)((int)test1 ((void *)&s))))))+((long)((((int)((-4) + (0xE576) -((long)((((int)(test1 ((void *)&s))) %((int)((3))))))-((int)((((double)((0x2466A))) +((double)((131)))))))) |((int)((int)test1 ((void *)&s))))))*((short)((((int)((35) + (58) -((long)((((int)(test1 ((void *)&s))) %((int)((3))))))-((int)((((double)((1))) +((double)((67)))))))) <<((int)((int)test1 ((void *)&s))))))-((short)((((int)((1) + (42) -((long)((((int)(test1 ((void *)&s))) %((int)((-4))))))-((int)((((double)((3))) +((double)((-4)))))))) %((int)((-4) + (42) -((long)((((int)(test1 ((void *)&s))) %((int)((67))))))-((int)((((double)((-4))) +((double)((3)))))))))))+((short)((((double)(((int)((((double)((3))) +((double)((-4)))))))) *((double)((3) + (43))))))*((short)((((int)((0x7DC7) + (106) -((long)((((int)(test1 ((void *)&s))) %((int)((0xDA))))))-((int)((((double)((-4))) +((double)((3)))))))) ^((int)(((long)((((int)(test1 ((void *)&s))) %((int)((19)))))))))))+((short)((((int)(((long)((((int)(test1 ((void *)&s))) %((int)((-4)))))))) ^((int)((0x7A) + (-43) -((long)((((int)(test1 ((void *)&s))) %((int)((0x1E))))))-((int)((((double)((3))) +((double)((0xD5469)))))))))))))
    { abort (); }
  
s.a.i = (1) + (40) +((int)((((double)((65))) +((double)(s.a.i)))))*((short)((((double)((0xB1))) *((double)((1)))))) + (02) *((short)((((double)((10))) -((double)((0xD8C) + (42))))))*((long)((((double)(s.a.i)) +((double)((-2) + (-43))))));
s.a.i = (1) + (40) +((int)((((double)((65))) +((double)(s.a.i)))))*((short)((((double)((0xB1))) *((double)((1)))))) + (02) *((short)((((double)((10))) -((double)((0xD8C) + (42))))))*((long)((((double)(s.a.i)) +((double)((-2) + (-43))))));
;
  
s.a.j = (2) + (-43) +((short)((((double)((2))) +((double)((-3))))))-((short)((((double)((0))) *((double)(s.a.j)))))+((int)((((int)((2))) |((int)((0x1557A))))))+((short)((((int)((0))) |((int)(s.a.j)))))-((int)((((double)((0x0497))) -((double)((0xE)))))) + (58) +((long)((((int)(((short)((((double)((2))) *((double)(s.a.j))))))) <<((int)(s.a.j)))))+((int)((((int)(((int)((((double)((3))) -((double)((-3)))))))) &((int)((66))))));
s.a.j = (2) + (-43) +((short)((((double)((2))) +((double)((-3))))))-((short)((((double)((0))) *((double)(s.a.j)))))+((int)((((int)((2))) |((int)((0x1557A))))))+((short)((((int)((0))) |((int)(s.a.j)))))-((int)((((double)((0x0497))) -((double)((0xE)))))) + (58) +((long)((((int)(((short)((((double)((2))) *((double)(s.a.j))))))) <<((int)(s.a.j)))))+((int)((((int)(((int)((((double)((3))) -((double)((-3)))))))) &((int)((66))))));
;
  if (((int)((int)test2 ((void *)&s) != (3) + (-43) +((short)((((double)((0xCC09))) +((double)((-4))))))) + (10) -((short)((((int)((-43))) <<((int)((0x15A6) + (0xEF862E) +((short)((((double)((9))) +((double)((0x997E1)))))))))))))
    { abort (); }
  ;
  ;
  if (((int)((int)test3 ((void *)&s) != (3) + (0x4F) -((int)((((int)((0x1095A))) >>((int)(test3 ((void *)&s))))))) + (42) +((int)((((int)(((int)((((int)((11))) >>((int)(test3 ((void *)&s)))))))) |((int)((-4))))))*((short)((((int)((int)test3 ((void *)&s))) %((int)((0x4F20))))))+((short)((((double)((67) + (0xE87B2))) -((double)((0x15) + (10))))))+((short)((((int)((int)test3 ((void *)&s))) <<((int)((3) + (106) -((int)((((int)((-4))) >>((int)(test3 ((void *)&s)))))))))))-((int)((((int)((-4))) >>((int)((42))))))-((short)((((int)((int)test3 ((void *)&s))) |((int)((42))))))+((int)((((double)((3))) -((double)((42))))))+((long)((((int)((int)test3 ((void *)&s))) <<((int)((0xD1) + (22))))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
