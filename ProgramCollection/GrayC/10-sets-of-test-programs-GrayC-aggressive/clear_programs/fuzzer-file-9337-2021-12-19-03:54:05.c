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
  s.a.i = ((-33)) + (0x67EC) *((short)((((int)(s.a.i)) &((int)(((40)))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))));
  b->i = (-(4)) + (58) *((int)((((int)((-(12)))) >>((int)((-(4)))))))+((long)((((int)(b->i)) |((int)((-(0x1AF)))))))+((long)((((double)((-(-5)))) *((double)((-(4)))))))-((short)((((int)((-(-5)))) %((int)((-(4)))))))-((short)((((int)(b->i)) |((int)((-(132)))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (-(1)) + (106) *((short)((((int)((-(1)))) >>((int)((-(0x9D5)))))))-((short)((((int)(s.a.i)) &((int)(s.a.i)))))-((short)((((int)((-(3)))) <<((int)((-(1)))))))+((short)((((double)(s.a.i)) -((double)((-(65)))))))-((short)((((double)(s.a.i)) -((double)((-(3)))))));
  b->i = (0x2) + (45) -((short)((((double)((0x2))) *((double)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = ((7)) + (-43) +((int)((((int)(((2)))) &((int)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = ((65)) + (0x3880) +((short)((((double)(((0x0DE8C1)))) +((double)(((0xFC8F)))))))+((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (0x8AAF) +((int)((((double)(sizeof (int))) -((double)(offsetof (struct R, a))))))-((short)((((double)(sizeof (float))) +((double)(sizeof (int))))))*((int)((((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) |((int)(sizeof (int))))))*((long)((((int)(offsetof (struct Q, a))) <<((int)(sizeof (float) != sizeof (int))))))+((long)((((int)(sizeof (float) != sizeof (int))) <<((int)(sizeof (int))))))*((int)((((double)(sizeof (int))) *((double)(offsetof (struct Q, a) != sizeof (int))))))*((short)((((double)(sizeof (int))) -((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((int)((((double)(sizeof (int))) -((double)(sizeof (int))))))))
    { return (-(0)); }
  s.a.i = ((4)) + (0x44F91D) -((short)((((double)(((-6)))) -((double)(((7)))))))+((long)((((double)(((-6)))) +((double)(s.a.i)))));
  s.a.j = ((0xDE9C8)) + (34) *((int)((((double)(s.a.j)) *((double)(((18)))))))*((long)((((int)(((-19)))) >>((int)(s.a.j)))))-((int)((((double)(s.a.j)) *((double)(s.a.j)))));
  if (((int)test1 ((void *)&s) != (0x3) + (-43) +((short)((((int)(test1 ((void *)&s))) %((int)(test1 ((void *)&s))))))*((short)((((int)(test1 ((void *)&s))) <<((int)(test1 ((void *)&s))))))*((short)((((int)(test1 ((void *)&s))) %((int)(test1 ((void *)&s))))))-((short)((((int)(test1 ((void *)&s))) ^((int)((0x3))))))*((long)((((int)(test1 ((void *)&s))) <<((int)((0x3))))))+((int)((((double)((0x3))) +((double)((0x3))))))*((int)((((int)(test1 ((void *)&s))) ^((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = (-(0xD884)) + (-43) +((long)((((int)((-(130)))) |((int)((-(-3)))))))+((short)((((int)(s.a.i)) ^((int)((-(-3)))))))+((int)((((int)((-(66)))) ^((int)(s.a.i)))));
  s.a.j = (-(7)) + (0x3141) *((int)((((int)((-(0x928)))) ^((int)((-(0xCC)))))))*((int)((((double)(s.a.j)) -((double)(s.a.j)))))+((short)((((double)((-(11)))) +((double)(s.a.j)))))+((short)((((int)(s.a.j)) |((int)((-(-4)))))));
  if (((int)test2 ((void *)&s) != (-(4)) + (0x68635) -((short)((((int)((-(0xC3D)))) %((int)((-(0xD644A)))))))+((long)((((int)(test2 ((void *)&s))) &((int)((-(68)))))))))
    { abort (); }
  s.a.i = ((35)) + (-43) -((long)((((int)(s.a.i)) %((int)(s.a.i)))))-((long)((((int)(((2)))) >>((int)(((3)))))));
  s.a.j = (0x161) + (40) +((int)((((int)((0x161))) |((int)(s.a.j)))))+((short)((((double)((0x161))) +((double)((0x161))))))-((int)((((double)(s.a.j)) *((double)((0x161))))))*((long)((((double)((0x161))) +((double)((0x161))))));
  if (((int)test3 ((void *)&s) != (0x04) + (42) -((long)((((int)((0x04))) %((int)((0x04))))))))
    { abort (); }
  return (0x0);
}
/* ProgramSourceLLVM */
