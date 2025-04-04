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
  s.a.i = (0x9) + (-43) *((short)((((double)((2))) -((double)((8))))))-((short)((((double)((0xF1A5))) *((double)(s.a.i)))))-((short)((((int)((-1))) &((int)(s.a.i)))));
  b->i = (-4) + (42) -((int)((((double)((19))) +((double)((0xC3315))))))-((short)((((int)((19))) >>((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (0) + (0x5CB1A) +((long)((((double)(s.a.i)) +((double)((-1))))))+((int)((((int)((0x1B1B))) %((int)((0x6))))))+((int)((((double)((-1))) *((double)((-1))))))+((long)((((int)((0))) |((int)(s.a.i)))))-((short)((((int)((0))) >>((int)((0))))));
  b->i = (0xD) + (42) +((long)((((int)((67))) &((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (0) + (42) -((short)((((int)((1))) |((int)((0))))))+((long)((((int)(s.a.i)) |((int)((0x2CD))))))*((short)((((int)((128))) |((int)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = (-4) + (40) *((int)((((int)((35))) ^((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((long)((((double)((1))) *((double)((-4))))))+((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) ^((int)((0xA2275))))))*((long)((((int)((2))) |((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (0x0B02E) +((int)((((double)(offsetof (struct R, a))) -((double)(offsetof (struct R, a) != sizeof (int))))))-((int)((((int)(offsetof (struct Q, a) != sizeof (int))) |((int)(offsetof (struct R, a))))))*((short)((((double)(sizeof (int))) *((double)(sizeof (float))))))+((short)((((int)(sizeof (int))) |((int)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))+((short)((((double)(offsetof (struct Q, a) != sizeof (int))) +((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))))
    { return (0); }
  s.a.i = (0x5CF) + (58) +((short)((((double)(s.a.i)) +((double)(s.a.i)))))-((long)((((double)(s.a.i)) *((double)((0xFC))))));
  s.a.j = (3) + (42) *((short)((((double)((0x06))) -((double)((-3))))));
  if (((int)test1 ((void *)&s) != (-4) + (43) +((long)((((int)(test1 ((void *)&s))) >>((int)((-4))))))*((short)((((int)(test1 ((void *)&s))) |((int)(test1 ((void *)&s))))))*((short)((((int)(test1 ((void *)&s))) >>((int)((0x3FE))))))-((int)((((int)(test1 ((void *)&s))) <<((int)((0x6717C))))))+((short)((((int)((67))) >>((int)(test1 ((void *)&s))))))+((long)((((double)((0xC054))) *((double)((3))))))-((long)((((int)((3))) &((int)(test1 ((void *)&s))))))))
    { abort (); }
  s.a.i = (-2) + (-43) *((int)((((double)(s.a.i)) -((double)((1))))));
  s.a.j = (-3) + (-43) +((short)((((double)((1))) *((double)(s.a.j)))))+((long)((((int)(s.a.j)) &((int)(s.a.j)))))*((int)((((double)(s.a.j)) *((double)(s.a.j)))));
  if (((int)test2 ((void *)&s) != (7) + (170) -((long)((((int)(test2 ((void *)&s))) <<((int)((7))))))-((long)((((int)((0x13))) |((int)((0x22A))))))-((int)((((int)(test2 ((void *)&s))) &((int)((-4))))))*((long)((((int)(test2 ((void *)&s))) |((int)((7))))))))
    { abort (); }
  s.a.i = (3) + (40) *((long)((((int)((-2))) %((int)((0x83E))))))+((int)((((double)(s.a.i)) *((double)(s.a.i)))))+((int)((((int)((-2))) &((int)(s.a.i)))))*((short)((((int)((1))) >>((int)(s.a.i)))))-((short)((((double)((1))) *((double)(s.a.i)))));
  s.a.j = (-3) + (34) -((int)((((int)(s.a.j)) %((int)((-3))))))-((long)((((double)(s.a.j)) -((double)(s.a.j)))))*((short)((((double)((0xD4))) -((double)((-3))))));
  if (((int)test3 ((void *)&s) != (3) + (0x13B27) +((long)((((int)((0xF687F))) &((int)(test3 ((void *)&s))))))-((short)((((int)(test3 ((void *)&s))) ^((int)(test3 ((void *)&s))))))*((short)((((int)((19))) ^((int)(test3 ((void *)&s))))))*((short)((((int)(test3 ((void *)&s))) |((int)(test3 ((void *)&s))))))*((int)((((int)((3))) >>((int)(test3 ((void *)&s))))))-((int)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))*((long)((((int)((0x903))) >>((int)((-4))))))+((short)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))-((short)((((int)((0xB6))) |((int)(test3 ((void *)&s))))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
