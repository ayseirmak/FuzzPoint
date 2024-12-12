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
  s.a.i = (268435456) + (-43) *((long)((((double)((0x4))) +((double)((524288))))))*((long)((((int)((0x9))) |((int)(s.a.i)))))-((long)((((int)((-1))) &((int)((0))))));
  b->i = (19) + (0xCCF) -((short)((((double)((1))) +((double)(b->i)))))+((int)((((double)((67))) +((double)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (0x7716A) + (40) +((int)((((int)((0xAA9B))) %((int)(s.a.i)))));
  b->i = (3) + (-43) -((long)((((double)(b->i)) -((double)((131))))))*((long)((((double)(b->i)) *((double)(b->i)))))-((int)((((double)(b->i)) +((double)((2))))))+((long)((((int)(b->i)) ^((int)((0xB8))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (2) + (0xD002) *((int)((((double)((2147483648))) -((double)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = (3) + (-43) *((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) >>((int)((0x27C5))))))*((short)((((double)((0x0CE))) -((double)((0x9E01C))))))*((short)((((double)((0x8633))) +((double)((131))))))+((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)((0x26AFB))))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((128))
    { return (0); }
  s.a.i = (1) + (43) *((short)((((int)((1))) <<((int)((0x7B47))))))+((short)((((double)((5))) *((double)((1))))))*((int)((((int)(s.a.i)) %((int)(s.a.i)))))+((short)((((double)(s.a.i)) -((double)(s.a.i)))));
  s.a.j = (2) + (0x674370) -((short)((((double)((130))) -((double)((130))))))*((short)((((double)(s.a.j)) *((double)((0xE0))))))-((long)((((double)((2))) *((double)((2))))));
  if (((int)test1 ((void *)&s) != (-4) + (0x8094) *((long)((((int)((3))) >>((int)(test1 ((void *)&s))))))-((long)((((int)(test1 ((void *)&s))) |((int)(test1 ((void *)&s))))))*((long)((((int)(test1 ((void *)&s))) <<((int)(test1 ((void *)&s))))))*((short)((((int)(test1 ((void *)&s))) |((int)((3))))))-((long)((((int)((3))) |((int)(test1 ((void *)&s))))))+((long)((((int)(test1 ((void *)&s))) ^((int)(test1 ((void *)&s))))))*((short)((((int)(test1 ((void *)&s))) <<((int)((67))))))))
    { abort (); }
  s.a.i = (-2) + (106) *((int)((((int)((0xB))) %((int)((0xA5BF))))))+((long)((((double)((1))) +((double)(s.a.i)))));
  s.a.j = (2) + (40) *((long)((((double)((0xCA))) -((double)(s.a.j)))))*((short)((((double)((66))) +((double)(s.a.j)))));
  if ((0))
    { abort (); }
  s.a.i = (1) + (170) -((long)((((int)(s.a.i)) ^((int)((65))))))*((int)((((double)((1))) -((double)(s.a.i)))));
  s.a.j = (0xD2F) + (42) *((short)((((int)(s.a.j)) >>((int)(s.a.j)))))-((long)((((double)((-3))) *((double)((8))))));
  if (((int)test3 ((void *)&s) != (67) + (-43) +((int)((((int)((2))) |((int)((3))))))-((short)((((int)(test3 ((void *)&s))) |((int)((0xCBD))))))*((long)((((double)((3))) +((double)((67))))))*((long)((((int)(test3 ((void *)&s))) |((int)((0xA))))))+((int)((((int)((1))) <<((int)((-4))))))+((short)((((int)((19))) <<((int)(test3 ((void *)&s))))))*((int)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))*((short)((((int)((-4))) <<((int)(test3 ((void *)&s))))))+((int)((((int)(test3 ((void *)&s))) >>((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))))
    { abort (); }
  return (1073741824);
}
/* ProgramSourceLLVM */
