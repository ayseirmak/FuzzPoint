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
  s.a.i = (0) + (-43) -((long)((((double)(s.a.i)) *((double)((0))))))*((short)((((int)(s.a.i)) >>((int)(s.a.i)))))-((long)((((int)(s.a.i)) %((int)((0))))))-((int)((((int)(s.a.i)) >>((int)(s.a.i)))));
  b->i = (3) + (0xB894) +((int)((((double)((11))) -((double)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (0xEF) + (58) -((short)((((double)((0))) +((double)((0xAA))))))-((short)((((int)((0))) <<((int)(s.a.i)))))*((int)((((int)((0))) ^((int)(s.a.i)))))+((long)((((int)((0))) |((int)(s.a.i)))));
  b->i = (0x64AC) + (-43) -((short)((((int)((3))) >>((int)((-4))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (0x688B) + (0xA534) -((int)((((double)(s.a.i)) *((double)((0))))))+((long)((((double)((0))) *((double)((3))))))*((short)((((double)(s.a.i)) -((double)(s.a.i)))))+((long)((((int)(s.a.i)) |((int)((8192))))))*((int)((((int)(s.a.i)) ^((int)((256))))));
  ((struct S *)((char *)q + sizeof (int)))->i = (-4) + (-43) -((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) >>((int)((1))))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (106) +((long)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) -((double)(offsetof (struct R, a) != sizeof (int))))))))
    { return (0); }
  s.a.i = (8) + (-43) *((short)((((int)((1))) ^((int)((0x32C33))))))-((int)((((double)(s.a.i)) *((double)((0xF321))))))*((long)((((int)(s.a.i)) ^((int)(s.a.i)))));
  s.a.j = (0x4D945) + (42) -((int)((((double)(s.a.j)) +((double)(s.a.j)))))-((short)((((double)(s.a.j)) -((double)((0xC46B1))))));
  if (((int)test1 ((void *)&s) != (-4) + (-43) -((int)((((int)(test1 ((void *)&s))) >>((int)(test1 ((void *)&s))))))*((long)((((int)((3))) |((int)(test1 ((void *)&s))))))-((long)((((int)((11))) &((int)((7))))))))
    { abort (); }
  s.a.i = (17) + (0xE94) *((short)((((double)((-2))) -((double)((33))))))+((long)((((double)((-2))) *((double)(s.a.i)))));
  s.a.j = (2) + (42) *((long)((((double)((2))) *((double)(s.a.j)))))-((long)((((double)((18))) +((double)(s.a.j)))))-((int)((((double)(s.a.j)) -((double)(s.a.j)))));
  if (((int)test2 ((void *)&s) != (-4) + (-43) +((int)((((int)((0xF0))) &((int)(test2 ((void *)&s))))))-((long)((((int)((0x4E2B))) >>((int)(test2 ((void *)&s))))))+((short)((((int)(test2 ((void *)&s))) <<((int)((3))))))-((short)((((int)((67))) %((int)(test2 ((void *)&s))))))-((short)((((int)((-4))) ^((int)(test2 ((void *)&s))))))))
    { abort (); }
  s.a.i = (1) + (42) -((int)((((double)((1))) +((double)((0))))))+((short)((((int)((5))) >>((int)(s.a.i)))))-((int)((((int)((-2))) <<((int)(s.a.i)))))+((int)((((double)((0xF4))) *((double)(s.a.i)))))*((long)((((int)((65))) %((int)(s.a.i)))));
  s.a.j = (-3) + (-43) +((short)((((double)((66))) +((double)(s.a.j)))));
  if (((int)test3 ((void *)&s) != (3) + (10) *((long)((((int)(test3 ((void *)&s))) >>((int)((-4))))))+((long)((((int)(test3 ((void *)&s))) >>((int)((3))))))-((short)((((int)((-4))) >>((int)(test3 ((void *)&s))))))-((long)((((int)((67))) %((int)(test3 ((void *)&s))))))-((long)((((double)((0x47347))) -((double)((1))))))*((short)((((int)((3))) |((int)(test3 ((void *)&s))))))+((int)((((int)(test3 ((void *)&s))) %((int)((-4))))))-((int)((((int)(test3 ((void *)&s))) >>((int)((3))))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
