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
  
b->i = (0xD1B5) + (-(-44)) -((short)((((int)(b->i)) >>((int)(((0xD9BE3)))))))*((long)((((int)((0xD3340))) &((int)((-(68)))))));
b->i = (0xD1B5) + (-(-44)) -((short)((((int)(b->i)) >>((int)(((0xD9BE3)))))))*((long)((((int)((0xD3340))) &((int)((-(68)))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
s.a.i = ((-129)) + ((66)) +((long)((((double)(s.a.i)) -((double)(((2251799813685248)))))))+((long)((((double)(s.a.i)) *((double)(((0x176F)))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))));
s.a.i = ((-129)) + ((66)) +((long)((((double)(s.a.i)) -((double)(((2251799813685248)))))))+((long)((((double)(s.a.i)) *((double)(((0x176F)))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))));
;
  
b->i = ((0xFE34)) + ((0x1F7B3)) +((long)((((int)(b->i)) <<((int)((-(4)))))));
b->i = ((0xFE34)) + ((0x1F7B3)) +((long)((((int)(b->i)) <<((int)((-(4)))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = (-(0xE816)) + ((34)) -((int)((((int)(s.a.i)) ^((int)(((8)))))))-((int)((((double)(s.a.i)) +((double)(((16384)))))))*((long)((((double)(((153122387330596864)))) *((double)(s.a.i)))))+((int)((((double)(s.a.i)) -((double)(s.a.i)))))*((short)((((double)(((-1)))) *((double)((0x9))))));
s.a.i = (-(0xE816)) + ((34)) -((int)((((int)(s.a.i)) ^((int)(((8)))))))-((int)((((double)(s.a.i)) +((double)(((16384)))))))*((long)((((double)(((153122387330596864)))) *((double)(s.a.i)))))+((int)((((double)(s.a.i)) -((double)(s.a.i)))))*((short)((((double)(((-1)))) *((double)((0x9))))));
;
  
((struct S *)((char *)q + sizeof (int)))->i = ((0x40F8D)) + ((42)) -((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(((struct S *)((char *)q + sizeof (int)))->i)))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
((struct S *)((char *)q + sizeof (int)))->i = ((0x40F8D)) + ((42)) -((long)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) <<((int)(((struct S *)((char *)q + sizeof (int)))->i)))))*((short)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) &((int)(((struct S *)((char *)q + sizeof (int)))->i)))))+((int)((((int)(((struct S *)((char *)q + sizeof (int)))->i)) %((int)(((struct S *)((char *)q + sizeof (int)))->i)))));
;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (0xD26AF) +((long)((((double)(sizeof (int))) -((double)(sizeof (int))))))-((short)((((int)(sizeof (float) != sizeof (int))) &((int)(offsetof (struct R, a))))))+((long)((((double)(sizeof (float))) +((double)(offsetof (struct Q, a) != sizeof (int))))))))
    { return ((0)); }
  
s.a.i = (0xC0) + (-(0xDEE7C)) -((long)((((double)(s.a.i)) *((double)((0xE))))))+((int)((((int)(((-10)))) >>((int)(s.a.i)))))-((short)((((int)((0xA20F))) >>((int)(((0x0)))))));
s.a.i = (0xC0) + (-(0xDEE7C)) -((long)((((double)(s.a.i)) *((double)((0xE))))))+((int)((((int)(((-10)))) >>((int)(s.a.i)))))-((short)((((int)((0xA20F))) >>((int)(((0x0)))))));
;
  ;
  if (((int)test1 ((void *)&s) != ((0x6306)) + ((970)) +((long)((((int)(test1 ((void *)&s))) ^((int)(((21)))))))*((long)((((int)(test1 ((void *)&s))) >>((int)(((0xEE8E9)))))))))
    { abort (); }
  ;
  
s.a.j = (0x43) + (0x16AF3D) +((long)((((double)(((0x71)))) +((double)(s.a.j)))));
s.a.j = (0x43) + (0x16AF3D) +((long)((((double)(((0x71)))) +((double)(s.a.j)))));
;
  if (((int)test2 ((void *)&s) != (0xBA) + (0xFB6B) -((short)((((int)((0xF))) >>((int)(test2 ((void *)&s))))))+((short)((((int)((-(0x36CCB)))) ^((int)((-(-5)))))))*((int)((((double)((-(-5)))) *((double)((0x2))))))-((int)((((int)(test2 ((void *)&s))) >>((int)((0xD60D4))))))*((long)((((int)(((17)))) >>((int)(test2 ((void *)&s))))))))
    { abort (); }
  ;
  
s.a.j = ((0)) + ((-11)) -((short)((((double)(s.a.j)) -((double)(((26)))))))+((long)((((double)((0x602DB))) *((double)((-(0x80)))))))*((long)((((int)(s.a.j)) %((int)(s.a.j)))))*((short)((((double)((-(1)))) +((double)(((-4)))))));
s.a.j = ((0)) + ((-11)) -((short)((((double)(s.a.j)) -((double)(((26)))))))+((long)((((double)((0x602DB))) *((double)((-(0x80)))))))*((long)((((int)(s.a.j)) %((int)(s.a.j)))))*((short)((((double)((-(1)))) +((double)(((-4)))))));
;
  if (((int)test3 ((void *)&s) != ((0x8)) + (-(-44)) +((short)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))-((int)((((int)((-(4)))) %((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) &((int)(test3 ((void *)&s))))))+((int)((((int)(((3)))) &((int)(test3 ((void *)&s))))))+((short)((((int)(((1)))) <<((int)(((-132)))))))-((long)((((int)((-(-5)))) <<((int)(test3 ((void *)&s))))))+((long)((((int)(test3 ((void *)&s))) %((int)(test3 ((void *)&s))))))-((int)((((int)(test3 ((void *)&s))) %((int)(((3)))))))*((int)((((int)(test3 ((void *)&s))) ^((int)(test3 ((void *)&s))))))))
    { abort (); }
  return ((2));
}
/* ProgramSourceLLVM */
