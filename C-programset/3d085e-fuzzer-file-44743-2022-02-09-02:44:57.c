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
  b->i = (0x1) + (-43) +((int)((((double)((-4))) -((double)((131))))))+((int)((((int)(b->i)) >>((int)(b->i))))) + (0x5F02) +((short)((((int)((11) + (106) +((int)((((double)((0xEF8E))) -((double)((0x081)))))))) >>((int)((0x90CC))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (16) + (42) *((short)((((double)(s.a.i)) -((double)((0xEE99))))))*((long)((((int)((0))) &((int)(s.a.i))))) + (0x3186D) +((int)((((int)(s.a.i)) &((int)(s.a.i)))));
  b->i = (-4) + (170) *((short)((((int)((0x04922))) &((int)((67)))))) + (43) *((short)((((int)((-4) + (0xE1D2) *((short)((((int)((1))) &((int)((2)))))))) |((int)(b->i)))))+((long)((((int)((42) *((short)((((int)((7))) &((int)((1)))))))) <<((int)(b->i)))))*((short)((((double)((0xCD058))) -((double)(b->i)))))+((short)((((double)(b->i)) *((double)((-4))))))+((long)((((int)(b->i)) &((int)(((short)((((int)((1))) &((int)((-4)))))))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (0) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((0))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((268435456))))))+((int)((((int)((0))) %((int)((0xFDFE0))))))-((int)((((int)((0x9AE4))) >>((int)(s.a.i))))) + (42) -((int)((((int)((0x529D8) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((2097152))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((-1))))))+((int)((((int)((17592186044416))) %((int)((0))))))-((int)((((int)((262144))) >>((int)(s.a.i))))))) &((int)(((int)((((int)((0))) >>((int)(s.a.i))))))))))*((long)((((int)((170))) &((int)((-1) + (-43) *((short)((((double)(s.a.i)) *((double)(s.a.i))))))))))+((int)((((int)(((int)((((int)((0x94475))) %((int)((4)))))))) &((int)(((short)((((int)((2))) <<((int)(s.a.i))))))))))+((long)((((int)((1073741824) + (42) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((16))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((0x6))))))+((int)((((int)((0x4))) %((int)((32))))))-((int)((((int)((0))) >>((int)(s.a.i))))))) &((int)((0x23B0) + (0x373C) *((short)((((double)(s.a.i)) *((double)(s.a.i)))))-((short)((((int)((0))) <<((int)(s.a.i)))))-((short)((((int)(s.a.i)) <<((int)((0)))))))))))-((long)((((int)(((short)((((int)((-1))) <<((int)(s.a.i))))))) |((int)(((short)((((int)((0))) <<((int)(s.a.i))))))))));
  ((struct S *)((char *)q + sizeof (int)))->i = (3) + (0x0FF7) -((short)((((int)((7))) >>((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + (40) -((long)((((int)((-4))) &((int)((3) + (0x433A) -((short)((((int)((0x58D1))) >>((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))*((long)((((int)((131))) |((int)(((short)((((int)((0xAE3))) >>((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^((int)((58))))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((64))
    { return (32768); }
  s.a.i = (0x8AA42) + (-43) +((long)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((double)(s.a.i)) -((double)((0x47D)))))) + (106) *((int)((((int)(s.a.i)) %((int)((-2) + (0xB64) +((long)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((double)(s.a.i)) -((double)((1)))))))))))*((short)((((int)(s.a.i)) |((int)((129) + (42) +((long)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((double)(s.a.i)) -((double)((0x3B1D)))))))))));
  s.a.j = (0) + (48) *((int)((((double)((6))) -((double)((2))))))+((long)((((double)((6))) -((double)(s.a.j)))))+((short)((((double)((0xBB))) +((double)(s.a.j)))))+((long)((((double)((2))) *((double)(s.a.j)))))+((short)((((int)((34))) &((int)(s.a.j))))) + (-43) +((int)((((int)((-3) + (-43) *((int)((((double)((2))) -((double)((2))))))+((long)((((double)((0x6B7))) -((double)(s.a.j)))))+((short)((((double)((0xC14))) +((double)(s.a.j)))))+((long)((((double)((2))) *((double)(s.a.j)))))+((short)((((int)((0xA))) &((int)(s.a.j))))))) >>((int)((-3) + (42) *((int)((((double)((2))) -((double)((0x8))))))+((long)((((double)((6))) -((double)(s.a.j)))))+((short)((((double)((2))) +((double)(s.a.j)))))+((long)((((double)((1))) *((double)(s.a.j)))))+((short)((((int)((0xCAD1))) &((int)(s.a.j))))))))))-((long)((((int)(s.a.j)) %((int)((-3) + (42) *((int)((((double)((0x7884F))) -((double)((0xC9081))))))+((long)((((double)((-3))) -((double)(s.a.j)))))+((short)((((double)((2))) +((double)(s.a.j)))))+((long)((((double)((-3))) *((double)(s.a.j)))))+((short)((((int)((34))) &((int)(s.a.j))))))))))*((short)((((int)(s.a.j)) %((int)(s.a.j)))))*((short)((((double)(s.a.j)) +((double)(s.a.j)))));
  if (((int)((int)test1 ((void *)&s) != (-4) + (0x0228B6) -((long)((((int)(test1 ((void *)&s))) %((int)((3))))))-((int)((((double)((19))) +((double)((7))))))) + (106) *((short)((((int)((-4) + (0xD69) -((long)((((int)(test1 ((void *)&s))) %((int)((131))))))-((int)((((double)((-4))) +((double)((-4)))))))) >>((int)((int)test1 ((void *)&s))))))+((long)((((int)((-4) + (0xE576) -((long)((((int)(test1 ((void *)&s))) %((int)((3))))))-((int)((((double)((0x2466A))) +((double)((131)))))))) |((int)((int)test1 ((void *)&s))))))*((short)((((int)((35) + (58) -((long)((((int)(test1 ((void *)&s))) %((int)((3))))))-((int)((((double)((1))) +((double)((67)))))))) <<((int)((int)test1 ((void *)&s))))))-((short)((((int)((1) + (42) -((long)((((int)(test1 ((void *)&s))) %((int)((-4))))))-((int)((((double)((3))) +((double)((-4)))))))) %((int)((-4) + (42) -((long)((((int)(test1 ((void *)&s))) %((int)((67))))))-((int)((((double)((-4))) +((double)((3)))))))))))+((short)((((double)(((int)((((double)((3))) +((double)((-4)))))))) *((double)((3) + (43))))))*((short)((((int)((0x7DC7) + (106) -((long)((((int)(test1 ((void *)&s))) %((int)((0xDA))))))-((int)((((double)((-4))) +((double)((3)))))))) ^((int)(((long)((((int)(test1 ((void *)&s))) %((int)((19)))))))))))+((short)((((int)(((long)((((int)(test1 ((void *)&s))) %((int)((-4)))))))) ^((int)((0x7A) + (-43) -((long)((((int)(test1 ((void *)&s))) %((int)((0x1E))))))-((int)((((double)((3))) +((double)((0xD5469)))))))))))))
    { abort (); }
  s.a.i = (1) + (40) +((int)((((double)((65))) +((double)(s.a.i)))))*((short)((((double)((0xB1))) *((double)((1)))))) + (02) *((short)((((double)((10))) -((double)((0xD8C) + (42))))))*((long)((((double)(s.a.i)) +((double)((-2) + (-43))))));
  s.a.j = (2) + (-43) +((short)((((double)((2))) +((double)((-3))))))-((short)((((double)((0))) *((double)(s.a.j)))))+((int)((((int)((2))) |((int)((0x1557A))))))+((short)((((int)((0))) |((int)(s.a.j)))))-((int)((((double)((0x0497))) -((double)((0xE)))))) + (58) +((long)((((int)(((short)((((double)((2))) *((double)(s.a.j))))))) <<((int)(s.a.j)))))+((int)((((int)(((int)((((double)((3))) -((double)((-3)))))))) &((int)((66))))));
  if (((int)((int)test2 ((void *)&s) != (3) + (-43) +((short)((((double)((0xCC09))) +((double)((-4))))))) + (10) -((short)((((int)((-43))) <<((int)((0x15A6) + (0xEF862E) +((short)((((double)((9))) +((double)((0x997E1)))))))))))))
    { abort (); }
  s.a.i = (0xFC2) + (170) +((long)((((double)((-2))) -((double)(s.a.i)))))+((short)((((int)(s.a.i)) %((int)((65)))))) + (-43) *((long)((((double)((1) + (-43) +((long)((((double)((0))) -((double)(s.a.i)))))+((short)((((int)(s.a.i)) %((int)((0)))))))) -((double)(s.a.i)))))*((short)((((int)((0xFC4) + (106) +((long)((((double)((0x6846F))) -((double)(s.a.i)))))+((short)((((int)(s.a.i)) %((int)((0x4E2FD)))))))) ^((int)((0xA782) + (-43) +((long)((((double)((-2))) -((double)(s.a.i)))))+((short)((((int)(s.a.i)) %((int)((17)))))))))));
  s.a.j = (-3) + (170) +((long)((((double)(s.a.j)) *((double)((2))))))*((int)((((double)(s.a.j)) *((double)((2))))))+((int)((((int)(s.a.j)) >>((int)(s.a.j))))) + (46) +((int)((((int)((-3) + (58) +((long)((((double)(s.a.j)) *((double)((-3))))))*((int)((((double)(s.a.j)) *((double)((0x21))))))+((int)((((int)(s.a.j)) >>((int)(s.a.j))))))) %((int)((18) + (42) +((long)((((double)(s.a.j)) *((double)((18))))))*((int)((((double)(s.a.j)) *((double)((0x8))))))+((int)((((int)(s.a.j)) >>((int)(s.a.j))))))))))+((long)((((int)((-3) + (0x5E779) +((long)((((double)(s.a.j)) *((double)((2))))))*((int)((((double)(s.a.j)) *((double)((-3))))))+((int)((((int)(s.a.j)) >>((int)(s.a.j))))))) %((int)(s.a.j)))))+((int)((((int)(s.a.j)) %((int)(s.a.j)))))*((int)((((int)(s.a.j)) &((int)((-3) + (0x6C8A2) +((long)((((double)(s.a.j)) *((double)((-3))))))*((int)((((double)(s.a.j)) *((double)((0))))))+((int)((((int)(s.a.j)) >>((int)(s.a.j))))))))))-((short)((((int)(s.a.j)) ^((int)((18) + (10) +((long)((((double)(s.a.j)) *((double)((2))))))*((int)((((double)(s.a.j)) *((double)((18))))))+((int)((((int)(s.a.j)) >>((int)(s.a.j))))))))));
  if (((int)((int)test3 ((void *)&s) != (3) + (0x4F) -((int)((((int)((0x1095A))) >>((int)(test3 ((void *)&s))))))) + (42) +((int)((((int)(((int)((((int)((11))) >>((int)(test3 ((void *)&s)))))))) |((int)((-4))))))*((short)((((int)((int)test3 ((void *)&s))) %((int)((0x4F20))))))+((short)((((double)((67) + (0xE87B2))) -((double)((0x15) + (10))))))+((short)((((int)((int)test3 ((void *)&s))) <<((int)((3) + (106) -((int)((((int)((-4))) >>((int)(test3 ((void *)&s)))))))))))-((int)((((int)((-4))) >>((int)((42))))))-((short)((((int)((int)test3 ((void *)&s))) |((int)((42))))))+((int)((((double)((3))) -((double)((42))))))+((long)((((int)((int)test3 ((void *)&s))) <<((int)((0xD1) + (22))))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
