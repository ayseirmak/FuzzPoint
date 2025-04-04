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
  s.a.i = (512) + (42) +((long)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((int)(s.a.i)) %((int)(s.a.i)))))*((long)((((int)(s.a.i)) >>((int)((4194304))))))+((int)((((double)(s.a.i)) *((double)(s.a.i)))))*((long)((((double)((0xD5))) -((double)(s.a.i)))));
  b->i = (0xD1B5) + (-43) -((short)((((int)(b->i)) >>((int)((7))))))*((long)((((int)((0xD3340))) &((int)((-4))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (128) + (46) +((long)((((double)(s.a.i)) -((double)((0))))))+((long)((((double)(s.a.i)) *((double)((0))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))));
  b->i = (67) + (42) +((long)((((int)(b->i)) <<((int)((-4))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (-1) + (34) -((int)((((int)(s.a.i)) ^((int)((8))))))-((int)((((double)(s.a.i)) +((double)((0))))))*((long)((((double)((144115188075855872))) *((double)(s.a.i)))))+((int)((((double)(s.a.i)) -((double)(s.a.i)))))*((short)((((double)((0))) *((double)((0x9))))));
  ((struct S *)((char *)q + sizeof (int)))->i = (3) + (42) -((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(((struct S *)((char *)q + sizeof (int)))->i)))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (0xD26AF) +((long)((((double)(sizeof (int))) -((double)(sizeof (int))))))-((short)((((int)(sizeof (float) != sizeof (int))) &((int)(offsetof (struct R, a))))))+((long)((((double)(sizeof (float))) +((double)(offsetof (struct Q, a) != sizeof (int))))))))
    { return (0); }
  s.a.i = (0xC0) + (-43) -((long)((((double)(s.a.i)) *((double)((0xE))))))+((int)((((int)((9))) >>((int)(s.a.i)))))-((short)((((int)((0xA20F))) >>((int)((6))))));
  s.a.j = (-3) + (42) -((short)((((int)((0x2))) |((int)(s.a.j)))))+((int)((((int)(s.a.j)) |((int)((66))))))-((short)((((int)((34))) %((int)((-3))))))-((long)((((int)(s.a.j)) ^((int)(s.a.j)))));
  if (((int)test1 ((void *)&s) != (1) + (170) +((long)((((int)(test1 ((void *)&s))) ^((int)((5))))))*((long)((((int)(test1 ((void *)&s))) >>((int)((3))))))))
    { abort (); }
  s.a.i = (0) + (0x63B50C) +((long)((((double)((1))) -((double)(s.a.i)))));
  s.a.j = (0x43) + (0x16AF3D) +((long)((((double)((18))) +((double)(s.a.j)))));
  if (((int)test2 ((void *)&s) != (0xBA) + (0xFB6B) -((short)((((int)((0xF))) >>((int)(test2 ((void *)&s))))))+((short)((((int)((-4))) ^((int)((-4))))))*((int)((((double)((-4))) *((double)((0x2))))))-((int)((((int)(test2 ((void *)&s))) >>((int)((0xD60D4))))))*((long)((((int)((19))) >>((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = (17) + (0x6F0EB5) +((short)((((double)(s.a.i)) -((double)(s.a.i)))));
  s.a.j = (2) + (10) -((short)((((double)(s.a.j)) -((double)((10))))))+((long)((((double)((0x602DB))) *((double)((-3))))))*((long)((((int)(s.a.j)) %((int)(s.a.j)))))*((short)((((double)((-3))) +((double)((3))))));
  if (((int)test3 ((void *)&s) != (2) + (-43) +((short)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))-((int)((((int)((-4))) %((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))+((int)((((int)((3))) &((int)(test3 ((void *)&s))))))+((short)((((int)((3))) <<((int)((131))))))-((long)((((int)((-4))) <<((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))-((int)((((int)(test3 ((void *)&s))) %((int)((3))))))*((int)((((int)(test3 ((void *)&s))) ^((int)(test3 ((void *)&s))))))))
    { abort (); }
  return (2);
}
/* ProgramSourceLLVM */
