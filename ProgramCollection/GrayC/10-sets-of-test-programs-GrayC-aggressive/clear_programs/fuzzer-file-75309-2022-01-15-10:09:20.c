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
  s.a.i = (0) + (0xE702CE) -((long)((((int)(s.a.i)) ^((int)(s.a.i)))))-((long)((((int)((256))) ^((int)(s.a.i)))))*((short)((((int)(s.a.i)) |((int)(s.a.i)))));
  b->i = (0x00F) + (-43) *((short)((((int)((-4))) &((int)(b->i)))))*((long)((((int)(b->i)) |((int)((-4))))))*((int)((((int)(b->i)) %((int)((19))))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  s.a.i = (8) + (0xC51) *((short)((((int)((0))) %((int)((0xF88DA))))))+((long)((((double)(s.a.i)) -((double)((64))))));
  b->i = (0xD) + (0x7166E) +((int)((((double)(b->i)) -((double)(b->i)))))+((int)((((int)(b->i)) <<((int)(b->i)))));
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  s.a.i = (8192) + (-43) +((long)((((double)((1073741824))) *((double)((8192))))))*((int)((((double)((32))) -((double)((288230376151711744))))))*((long)((((double)((-1))) +((double)(s.a.i)))));
  ((struct S *)((char *)q + sizeof (int)))->i = (1) + (-43) -((short)((((int)((11))) ^((int)((0xC23))))))+((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)((3))))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) |((int)((0x342BF))))))+((long)((((int)((7))) <<((int)((19))))))-((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((0x6F3C))
    { return (0); }
  s.a.i = (0x33) + (-43) +((long)((((double)(s.a.i)) *((double)(s.a.i)))));
  s.a.j = (18) + (0x240) *((short)((((int)(s.a.j)) ^((int)(s.a.j)))))-((short)((((double)((2))) *((double)((0x7))))))+((long)((((double)(s.a.j)) +((double)(s.a.j)))))*((long)((((int)((2))) %((int)((0))))))-((short)((((double)((-3))) +((double)((-3))))));
  if ((0))
    { abort (); }
  s.a.i = (-2) + (-43) +((long)((((double)((-2))) -((double)((-2))))))-((short)((((int)(s.a.i)) %((int)((0xF))))))+((long)((((int)((1))) |((int)(s.a.i)))))+((int)((((double)(s.a.i)) *((double)(s.a.i)))));
  s.a.j = (2) + (0x725C) +((short)((((int)(s.a.j)) <<((int)(s.a.j)))))-((long)((((double)(s.a.j)) *((double)((-3))))))+((short)((((int)((2))) |((int)((2))))))*((short)((((int)((2))) >>((int)(s.a.j)))));
  if ((0xC00))
    { abort (); }
  s.a.i = (129) + (42) *((int)((((int)(s.a.i)) >>((int)(s.a.i)))));
  s.a.j = (0x0) + (46) +((long)((((int)((-3))) &((int)(s.a.j)))))-((int)((((int)(s.a.j)) ^((int)(s.a.j)))))-((int)((((double)(s.a.j)) -((double)((0x79EE))))))+((short)((((double)(s.a.j)) *((double)((-3))))));
  if (((int)test3 ((void *)&s) != (0x3D) + (58) -((long)((((int)((3))) &((int)(test3 ((void *)&s))))))+((long)((((int)((131))) <<((int)((3))))))*((long)((((int)(test3 ((void *)&s))) &((int)((35))))))-((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))+((short)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))))
    { abort (); }
  return (0xC87E0);
}
/* ProgramSourceLLVM */
