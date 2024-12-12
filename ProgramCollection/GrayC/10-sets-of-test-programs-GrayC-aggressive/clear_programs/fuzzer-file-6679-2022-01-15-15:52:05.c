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
  s.a.i = (0) + (-43) +((short)((((double)((0x9E2E7))) -((double)(s.a.i)))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) ^((int)(s.a.i))))) + (-43) +((long)((((int)(s.a.i)) %((int)(s.a.i)))))-((short)((((double)((0xC) + (58) +((short)((((double)((0))) -((double)(s.a.i)))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) ^((int)(s.a.i))))))) -((double)((256) + (42) +((short)((((double)((0))) -((double)(s.a.i)))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) ^((int)(s.a.i))))))))))+((long)((((double)(s.a.i)) +((double)((0x9BAF) + (0x35) +((short)((((double)((0))) -((double)(s.a.i)))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) ^((int)(s.a.i))))))))))-((long)((((double)(s.a.i)) -((double)((0xB) + (42) +((short)((((double)((0x6D8F9))) -((double)(s.a.i)))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) ^((int)(s.a.i))))))))));
  b->i = (-4) + (43) +((int)((((double)(b->i)) *((double)(b->i)))))+((int)((((int)(b->i)) &((int)(b->i)))))+((short)((((int)(b->i)) <<((int)((-4)))))) + (0xC7) +((int)((((int)((11) + (-43) +((int)((((double)(b->i)) *((double)(b->i)))))+((int)((((int)(b->i)) &((int)(b->i)))))+((short)((((int)(b->i)) <<((int)((3)))))))) %((int)((0xF1EE) + (0x7D) +((int)((((double)(b->i)) *((double)(b->i)))))+((int)((((int)(b->i)) &((int)(b->i)))))+((short)((((int)(b->i)) <<((int)((11)))))))))))-((short)((((int)((35) + (-43))) ^((int)((4) + (0x14) +((int)((((double)(b->i)) *((double)(b->i)))))+((int)((((int)(b->i)) &((int)(b->i))))))))))-((short)((((double)(((int)((((int)(b->i)) &((int)(b->i))))))) -((double)(((short)((((int)(b->i)) <<((int)((0xA)))))))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (2048) + (42) *((long)((((int)(s.a.i)) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) %((int)((-1))))))+((long)((((double)((0))) -((double)(s.a.i))))) + (40) +((int)((((int)(s.a.i)) |((int)((-1) + (40) *((long)((((int)(s.a.i)) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) %((int)((0x0))))))+((long)((((double)((4398046511104))) -((double)(s.a.i))))))))));
  b->i = (4) + (-43) -((int)((((int)((-4))) &((int)((2))))))-((int)((((int)(b->i)) >>((int)((0x3))))))-((int)((((int)((-4))) %((int)(b->i))))) + (72) *((short)((((int)(b->i)) ^((int)((35) + (-43) -((int)((((int)((7))) &((int)((-4))))))-((int)((((int)(b->i)) >>((int)((3))))))-((int)((((int)((-4))) %((int)(b->i))))))))))*((int)((((double)((3) + (42) -((int)((((int)((-4))) &((int)((3)))))))) *((double)(((int)((((int)((-4))) &((int)((0x10DEE)))))))))))+((int)((((double)((2) + (-43) -((int)((((int)((-4))) &((int)((0x3))))))-((int)((((int)(b->i)) >>((int)((-4))))))-((int)((((int)((2))) %((int)(b->i))))))) -((double)(((int)((((int)(b->i)) >>((int)((0x2)))))))))))-((short)((((int)(b->i)) >>((int)((0xDA))))))*((short)((((int)((131) + (42) -((int)((((int)((-4))) &((int)((0x4CE64))))))-((int)((((int)(b->i)) >>((int)((0x315EE))))))-((int)((((int)((35))) %((int)(b->i))))))) &((int)(((int)((((int)((-4))) &((int)((0x52C3E)))))))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (0) + (34) +((int)((((int)(s.a.i)) &((int)(s.a.i)))))-((int)((((int)((0))) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)((-1))))))+((long)((((double)((0x43))) -((double)((0x8)))))) + (-43) +((short)((((double)((1) + (0x8FD98) +((int)((((int)(s.a.i)) &((int)(s.a.i)))))-((int)((((int)((16384))) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)((0))))))+((long)((((double)((0))) -((double)((0)))))))) +((double)(s.a.i)))))*((int)((((double)((0) + (34) +((int)((((int)(s.a.i)) &((int)(s.a.i)))))-((int)((((int)((0))) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)((-1))))))+((long)((((double)((64))) -((double)((67108864)))))))) +((double)(s.a.i)))))+((short)((((int)(s.a.i)) |((int)(s.a.i)))))*((int)((((double)((0) + (0x95) +((int)((((int)(s.a.i)) &((int)(s.a.i)))))-((int)((((int)((0))) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)((-1))))))+((long)((((double)((0))) -((double)((0)))))))) +((double)((4096) + (0xC4E) +((int)((((int)(s.a.i)) &((int)(s.a.i)))))-((int)((((int)((0))) ^((int)(s.a.i)))))+((int)((((int)(s.a.i)) |((int)((8))))))+((long)((((double)((1024))) -((double)((1)))))))))))-((int)((((int)(s.a.i)) ^((int)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = (3) + (-43) +((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i))))) + (10) +((int)((((int)((-4) + (42) +((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i))))))) ^((int)((3) + (40) +((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i))))))))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((4398046511104))
    { return (0); }
  s.a.i = (0x7) + (0x4568) -((int)((((double)((1))) *((double)(s.a.i)))))-((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((short)((((double)(s.a.i)) *((double)((0x69))))))+((long)((((double)(s.a.i)) -((double)(s.a.i))))) + (0xF53F40) *((int)((((int)(s.a.i)) ^((int)((0x856) + (0x7A2E6F) -((int)((((double)((9))) *((double)(s.a.i)))))-((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((short)((((double)(s.a.i)) *((double)((3))))))+((long)((((double)(s.a.i)) -((double)(s.a.i))))))))))-((short)((((int)((1) + (0x511C2) -((int)((((double)((129))) *((double)(s.a.i)))))-((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((short)((((double)(s.a.i)) *((double)((129))))))+((long)((((double)(s.a.i)) -((double)(s.a.i))))))) <<((int)((5) + (-43) -((int)((((double)((33))) *((double)(s.a.i)))))-((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((short)((((double)(s.a.i)) *((double)((0x7))))))+((long)((((double)(s.a.i)) -((double)(s.a.i))))))))))*((short)((((int)(s.a.i)) <<((int)((1) + (-43) -((int)((((double)((3))) *((double)(s.a.i)))))-((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((short)((((double)(s.a.i)) *((double)((17))))))+((long)((((double)(s.a.i)) -((double)(s.a.i))))))))));
  s.a.j = (0xE) + (46) -((int)((((double)((6))) -((double)(s.a.j)))))-((long)((((double)(s.a.j)) +((double)(s.a.j))))) + (0x46BCA8) +((short)((((double)(s.a.j)) -((double)(s.a.j)))))*((short)((((double)(s.a.j)) -((double)((0xB8E9) + (0x50F49) -((int)((((double)((66))) -((double)(s.a.j)))))-((long)((((double)(s.a.j)) +((double)(s.a.j))))))))));
  if ((-1))
    { abort (); }
  s.a.i = (-2) + (42) -((int)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((int)((1))) <<((int)(s.a.i)))))+((long)((((double)((0x0))) -((double)(s.a.i))))) + (-43) *((long)((((int)((1) + (42) -((int)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((int)((0xB0))) <<((int)(s.a.i)))))+((long)((((double)((-2))) -((double)(s.a.i))))))) &((int)((1) + (43) -((int)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((int)((0x5))) <<((int)(s.a.i)))))+((long)((((double)((-2))) -((double)(s.a.i))))))))))-((int)((((int)(s.a.i)) ^((int)((129) + (-43) -((int)((((double)(s.a.i)) +((double)(s.a.i)))))+((short)((((int)((1))) <<((int)(s.a.i)))))+((long)((((double)((1))) -((double)(s.a.i))))))))));
  s.a.j = (3) + (0x448) *((int)((((int)(s.a.j)) <<((int)(s.a.j)))))-((short)((((double)(s.a.j)) +((double)((0x77F))))))-((short)((((int)((0xC))) |((int)(s.a.j)))))*((int)((((double)(s.a.j)) +((double)((-3))))))-((int)((((int)(s.a.j)) %((int)(s.a.j))))) + (42) *((int)((((double)(((int)((((double)(s.a.j)) +((double)((2)))))))) *((double)(((short)((((double)(s.a.j)) +((double)((0x9F)))))))))))+((short)((((int)((0x9C) + (46) *((int)((((int)(s.a.j)) <<((int)(s.a.j)))))-((short)((((double)(s.a.j)) +((double)((66))))))-((short)((((int)((130))) |((int)(s.a.j)))))*((int)((((double)(s.a.j)) +((double)((2)))))))) |((int)(s.a.j)))));
  if ((0))
    { abort (); }
  s.a.i = (17) + (0xCED3) +((long)((((double)(s.a.i)) *((double)((-2))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((-2))) +((double)((1)))))) + (42) +((long)((((int)((0xD8DF4) + (-43) +((long)((((double)(s.a.i)) *((double)((17))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((0xD))) +((double)((9)))))))) >>((int)(s.a.i)))))*((long)((((int)((-2) + (42) +((long)((((double)(s.a.i)) *((double)((-2))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((1))) +((double)((5)))))))) <<((int)((3) + (-43) +((long)((((double)(s.a.i)) *((double)((17))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((0x7352C))) +((double)((-2)))))))))))*((int)((((int)((0x545A) + (42) +((long)((((double)(s.a.i)) *((double)((-2))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((1))) +((double)((-2)))))))) <<((int)((-2) + (-43) +((long)((((double)(s.a.i)) *((double)((5))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((65))) +((double)((3)))))))))))-((long)((((int)(s.a.i)) ^((int)(s.a.i)))))+((int)((((int)((129) + (40) +((long)((((double)(s.a.i)) *((double)((-2))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((0xB))) +((double)((3)))))))) ^((int)((3) + (-43) +((long)((((double)(s.a.i)) *((double)((0x61))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((double)((0x2A49))) +((double)((9)))))))))));
  s.a.j = (10) + (34) +((long)((((int)(s.a.j)) &((int)((2))))))+((short)((((double)(s.a.j)) *((double)(s.a.j)))))-((long)((((double)(s.a.j)) +((double)(s.a.j)))))*((long)((((double)(s.a.j)) *((double)(s.a.j))))) + (0xFB9A1A) -((short)((((int)((10) + (-43) +((long)((((int)(s.a.j)) &((int)((-3))))))+((short)((((double)(s.a.j)) *((double)(s.a.j)))))-((long)((((double)(s.a.j)) +((double)(s.a.j)))))*((long)((((double)(s.a.j)) *((double)(s.a.j))))))) %((int)((0x7DDC) + (0x13DAA7) +((long)((((int)(s.a.j)) &((int)((34))))))+((short)((((double)(s.a.j)) *((double)(s.a.j)))))-((long)((((double)(s.a.j)) +((double)(s.a.j)))))*((long)((((double)(s.a.j)) *((double)(s.a.j))))))))));
  if ((0))
    { abort (); }
  return (256);
}
/* ProgramSourceLLVM */
