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

s.a.i = (0) + (42) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((2251799813685248))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))) + (10) -((short)((((int)((0) + (0xC0EA08) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))) ^((int)((0) + (0xD93D) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((-1))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))))*((int)((((int)((0) + (0x69E59) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0x4387F))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))) &((int)((68719476736) + (0x7865C) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0x0))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))))*((int)((((int)((0x9C) + (42) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))) >>((int)((0) + (0x2E7F) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((268435456))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))))*((short)((((int)(s.a.i)) &((int)((-1) + (40) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0x18))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))));
s.a.i = (0) + (34) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((-1))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))) + (-43) -((short)((((int)((18014398509481984) + (0x3DF) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((-1))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))) ^((int)((-1) + (10) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((2))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))))*((int)((((int)((0) + (42) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0xFC2A6))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))) &((int)((-1) + (34) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))))*((int)((((int)((0xD) + (-43) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((-1))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))) >>((int)((-1) + (-43) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0x38E95))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))))*((short)((((int)(s.a.i)) &((int)((524288) + (170) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((0xBEC))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i))))))))));
;
;
  
;

b->i = (-4) + (-43) *((short)((((int)((0x9))) &((int)(b->i)))))*((long)((((int)(b->i)) |((int)((7))))))*((int)((((int)(b->i)) %((int)((-4)))))) + (58) +((long)((((int)(b->i)) &((int)(b->i)))))*((long)((((int)((131) + (58) *((short)((((int)((1))) &((int)(b->i)))))*((long)((((int)(b->i)) |((int)((1))))))*((int)((((int)(b->i)) %((int)((-4)))))))) ^((int)(b->i)))));
b->i = (3) + (42) *((short)((((int)((3))) &((int)(b->i)))))*((long)((((int)(b->i)) |((int)((19))))))*((int)((((int)(b->i)) %((int)((35)))))) + (0xF9F2) +((long)((((int)(b->i)) &((int)(b->i)))))*((long)((((int)((0x8E3) + (0x3F34) *((short)((((int)((6))) &((int)(b->i)))))*((long)((((int)(b->i)) |((int)((0x0DE7))))))*((int)((((int)(b->i)) %((int)((-4)))))))) ^((int)(b->i)))));
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
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;

s.a.i = (32768) + (0x51) +((long)((((double)((0))) *((double)((0))))))*((int)((((double)((512))) -((double)((0))))))*((long)((((double)((0))) +((double)(s.a.i))))) + (0xEBB) *((int)((((int)(s.a.i)) &((int)(s.a.i)))));
s.a.i = (0xBD154) + (42) +((long)((((double)((-1))) *((double)((0))))))*((int)((((double)((1))) -((double)((0))))))*((long)((((double)((-1))) +((double)(s.a.i))))) + (170) *((int)((((int)(s.a.i)) &((int)(s.a.i)))));
;
;
  

((struct S *)((char *)q + sizeof (int)))->i = (0x9) + (42) -((short)((((int)((-4))) ^((int)((0x503))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((0xCF))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((67))))))+((long)((((int)((0x49))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + (0x4FD) +((short)((((int)((1) + (0xC04BAF) -((short)((((int)((2))) ^((int)((0x330))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((3))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((7))))))+((long)((((int)((11))) <<((int)((67))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((3) + (-43) -((short)((((int)((2))) ^((int)((-4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((3))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((19))))))+((long)((((int)((19))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((short)((((int)((3) + (106) -((short)((((int)((0x2B0))) ^((int)((35))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((-4))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0x94F2E))))))+((long)((((int)((3))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((35) + (-43) -((short)((((int)((0x86A))) ^((int)((3))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((0x63A9C))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0x273F))))))+((long)((((int)((2))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((int)((((int)((3) + (10) -((short)((((int)((3))) ^((int)((-4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((0x2A))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0xACA))))))+((long)((((int)((131))) <<((int)((19))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) |((int)((-4) + (46) -((short)((((int)((1))) ^((int)((2))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((0x774))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0x025C3))))))+((long)((((int)((19))) <<((int)((131))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))));
((struct S *)((char *)q + sizeof (int)))->i = (-4) + (-43) -((short)((((int)((0x8BB3))) ^((int)((1))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((-4))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((3))))))+((long)((((int)((3))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + (42) +((short)((((int)((0xEB008) + (42) -((short)((((int)((0xCD5C))) ^((int)((-4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((3))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((7))))))+((long)((((int)((0x0A4A))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((0xC3156) + (82) -((short)((((int)((131))) ^((int)((0x97AB))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((19))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((-4))))))+((long)((((int)((3))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((short)((((int)((-4) + (-43) -((short)((((int)((0x4))) ^((int)((3))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((2))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((3))))))+((long)((((int)((11))) <<((int)((1))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((-4) + (42) -((short)((((int)((-4))) ^((int)((0xD0EE))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((-4))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((1))))))+((long)((((int)((19))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((int)((((int)((0x3792) + (-43) -((short)((((int)((3))) ^((int)((-4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((0xA43))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0xF))))))+((long)((((int)((-4))) <<((int)((67))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) |((int)((-4) + (-43) -((short)((((int)((0x6DE))) ^((int)((-4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((1))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((-4))))))+((long)((((int)((3))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))));
;

((struct S *)((char *)q + sizeof (int)))->i = (0x5303B) + (0x99EA) -((short)((((int)((3))) ^((int)((0x6))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((7))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((67))))))+((long)((((int)((9))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + (42) +((short)((((int)((0x3) + (-43) -((short)((((int)((0xDA))) ^((int)((1))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((0x31))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0x7))))))+((long)((((int)((-4))) <<((int)((7))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((35) + (32) -((short)((((int)((3))) ^((int)((3))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((0xFA7B1))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((7))))))+((long)((((int)((3))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((short)((((int)((6) + (-43) -((short)((((int)((2))) ^((int)((11))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((2))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((3))))))+((long)((((int)((-4))) <<((int)((1))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((-4) + (-43) -((short)((((int)((-4))) ^((int)((0x5C9F4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((3))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((3))))))+((long)((((int)((3))) <<((int)((7))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((int)((((int)((3) + (-43) -((short)((((int)((-4))) ^((int)((-4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((-4))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((3))))))+((long)((((int)((0xB0139))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) |((int)((3) + (0x806) -((short)((((int)((0xC40))) ^((int)((131))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((2))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((19))))))+((long)((((int)((0x43F))) <<((int)((7))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))));
((struct S *)((char *)q + sizeof (int)))->i = (0x53) + (10) -((short)((((int)((3))) ^((int)((-4))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((7))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((3))))))+((long)((((int)((-4))) <<((int)((0x1B))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + (-43) +((short)((((int)((1) + (42) -((short)((((int)((67))) ^((int)((3))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((11))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((7))))))+((long)((((int)((7))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((-4) + (34) -((short)((((int)((-4))) ^((int)((35))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((3))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((2))))))+((long)((((int)((0x10))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((short)((((int)((3) + (42) -((short)((((int)((35))) ^((int)((19))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((131))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((-4))))))+((long)((((int)((67))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) >>((int)((-4) + (42) -((short)((((int)((0x94))) ^((int)((2))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((3))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((-4))))))+((long)((((int)((0xEE))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))+((int)((((int)((0x4) + (-43) -((short)((((int)((-4))) ^((int)((0xDA2CC))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((-4))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0xB))))))+((long)((((int)((2))) <<((int)((-4))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) |((int)((3) + (0xF2C) -((short)((((int)((-4))) ^((int)((131))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((1))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0xE7))))))+((long)((((int)((0x9))) <<((int)((3))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))));
;
;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((-1))
    { return (1024); }
  ;
  ;
  if ((0x96B51))
    { abort (); }
  

s.a.i = (-2) + (106) +((long)((((double)((0x14))) -((double)((-2))))))-((short)((((int)(s.a.i)) %((int)((1))))))+((long)((((int)((1))) |((int)(s.a.i)))))+((int)((((double)(s.a.i)) *((double)(s.a.i))))) + (58) -((long)((((int)(s.a.i)) |((int)(s.a.i)))));
s.a.i = (1) + (43) +((long)((((double)((-2))) -((double)((1))))))-((short)((((int)(s.a.i)) %((int)((0))))))+((long)((((int)((1))) |((int)(s.a.i)))))+((int)((((double)(s.a.i)) *((double)(s.a.i))))) + (-43) -((long)((((int)(s.a.i)) |((int)(s.a.i)))));
;

s.a.i = (-2) + (42) +((long)((((double)((8))) -((double)((1))))))-((short)((((int)(s.a.i)) %((int)((0x14))))))+((long)((((int)((-2))) |((int)(s.a.i)))))+((int)((((double)(s.a.i)) *((double)(s.a.i))))) + (58) -((long)((((int)(s.a.i)) |((int)(s.a.i)))));
s.a.i = (-2) + (106) +((long)((((double)((65))) -((double)((0x47))))))-((short)((((int)(s.a.i)) %((int)((-2))))))+((long)((((int)((4))) |((int)(s.a.i)))))+((int)((((double)(s.a.i)) *((double)(s.a.i))))) + (-43) -((long)((((int)(s.a.i)) |((int)(s.a.i)))));
;
;
  
;
;
;
  if ((9))
    { abort (); }
  ;
  ;
  if (((int)((int)test3 ((void *)&s) != (3) + (42) -((long)((((int)((-4))) &((int)(test3 ((void *)&s))))))+((long)((((int)((0x49457))) <<((int)((0x930))))))*((long)((((int)(test3 ((void *)&s))) &((int)((2))))))-((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))+((short)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))) + (-43) -((long)((((int)(((long)((((int)((-4))) &((int)(test3 ((void *)&s)))))))) &((int)((0x2F8C) + (-43) -((long)((((int)((-4))) &((int)(test3 ((void *)&s))))))+((long)((((int)((35))) <<((int)((0xED))))))*((long)((((int)(test3 ((void *)&s))) &((int)((7)))))))))))-((long)((((int)((int)test3 ((void *)&s))) |((int)(((long)((((int)((-4))) <<((int)((0x4E2))))))*((long)((((int)(test3 ((void *)&s))) &((int)((3)))))))))))*((int)((((int)(((long)((((int)((3))) <<((int)((-4)))))))) %((int)((0x95F97) + (0x27))))))-((long)((((int)((0x3F) + (0xDB417E) -((long)((((int)((3))) &((int)(test3 ((void *)&s))))))+((long)((((int)((7))) <<((int)((1))))))*((long)((((int)(test3 ((void *)&s))) &((int)((0x3F01))))))-((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))+((short)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s)))))))) ^((int)((0x0DDB) + (22) -((long)((((int)((3))) &((int)(test3 ((void *)&s))))))+((long)((((int)((3))) <<((int)((3))))))*((long)((((int)(test3 ((void *)&s))) &((int)((35))))))-((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s)))))))))))-((long)((((int)(((long)((((int)(test3 ((void *)&s))) &((int)((0)))))))) %((int)(((long)((((int)((0x3ED))) <<((int)((7))))))*((long)((((int)(test3 ((void *)&s))) &((int)((0x9B7)))))))))))-((int)((((int)((0x552) + (0xCD) -((long)((((int)((3))) &((int)(test3 ((void *)&s))))))+((long)((((int)((3))) <<((int)((3))))))*((long)((((int)(test3 ((void *)&s))) &((int)((67))))))-((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s)))))))) |((int)(((long)((((int)(test3 ((void *)&s))) &((int)((3)))))))))))*((short)((((int)(((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s)))))))) %((int)(((long)((((int)(test3 ((void *)&s))) &((int)((-4)))))))))))))
    { abort (); }
  return (-1);
}
/* ProgramSourceLLVM */
