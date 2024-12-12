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
  
b->i = (0x108) + (43) -((short)((((int)(b->i)) >>((int)((1))))))*((long)((((int)((3))) &((int)((-4))))));
b->i = (131) + (43) -((short)((((int)(b->i)) >>((int)((3))))))*((long)((((int)((3))) &((int)((0x567))))));
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
  
s.a.i = (-1) + (-43) -((int)((((int)(s.a.i)) ^((int)((0))))))-((int)((((double)(s.a.i)) +((double)((0x388DF))))))*((long)((((double)((0))) *((double)(s.a.i)))))+((int)((((double)(s.a.i)) -((double)(s.a.i)))))*((short)((((double)((2251799813685248))) *((double)((0xAAB))))));
s.a.i = (-1) + (-43) -((int)((((int)(s.a.i)) ^((int)((-1))))))-((int)((((double)(s.a.i)) +((double)((288230376151711744))))))*((long)((((double)((512))) *((double)(s.a.i)))))+((int)((((double)(s.a.i)) -((double)(s.a.i)))))*((short)((((double)((0))) *((double)((0))))));
;
  
((struct S *)((char *)q + sizeof (int)))->i = (3) + (42) -((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(((struct S *)((char *)q + sizeof (int)))->i)))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
((struct S *)((char *)q + sizeof (int)))->i = (2) + (42) -((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(((struct S *)((char *)q + sizeof (int)))->i)))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((0x6D))
    { return (0); }
  
s.a.i = (-2) + (-43) -((long)((((double)(s.a.i)) *((double)((1))))))+((int)((((int)((0x05329))) >>((int)(s.a.i)))))-((short)((((int)((1))) >>((int)((-2))))));
s.a.i = (1) + (40) -((long)((((double)(s.a.i)) *((double)((1))))))+((int)((((int)((1))) >>((int)(s.a.i)))))-((short)((((int)((0xAA))) >>((int)((0x201))))));
;
  ;
  if ((0))
    { abort (); }
  ;
  ;
  if (((int)test2 ((void *)&s) != (0xAE7) + (46) -((short)((((int)((-4))) >>((int)(test2 ((void *)&s))))))+((short)((((int)((0xE))) ^((int)((-4))))))*((int)((((double)((35))) *((double)((0x96768))))))-((int)((((int)(test2 ((void *)&s))) >>((int)((67))))))*((long)((((int)((-4))) >>((int)(test2 ((void *)&s))))))))
    { abort (); }
  ;
  
s.a.j = (-3) + (34) -((short)((((double)(s.a.j)) -((double)((6))))))+((long)((((double)((-3))) *((double)((0xC8))))))*((long)((((int)(s.a.j)) %((int)(s.a.j)))))*((short)((((double)((-3))) +((double)((0xAD8))))));
s.a.j = (0xC5481) + (0x69) -((short)((((double)(s.a.j)) -((double)((0xB7AB))))))+((long)((((double)((0))) *((double)((2))))))*((long)((((int)(s.a.j)) %((int)(s.a.j)))))*((short)((((double)((-3))) +((double)((18))))));
;
  if (((int)test3 ((void *)&s) != (-4) + (40) +((short)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))-((int)((((int)((0xE))) %((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))+((int)((((int)((0xEAD))) &((int)(test3 ((void *)&s))))))+((short)((((int)((2))) <<((int)((-4))))))-((long)((((int)((3))) <<((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))-((int)((((int)(test3 ((void *)&s))) %((int)((131))))))*((int)((((int)(test3 ((void *)&s))) ^((int)(test3 ((void *)&s))))))))
    { abort (); }
  return (0x22E);
}
/* ProgramSourceLLVM */
