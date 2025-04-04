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
  
b->i = (0x03) + (-(43)) +((short)((((int)(b->i)) &((int)(b->i)))))*((int)((((int)(b->i)) %((int)((0x3A))))))+((int)((((int)(b->i)) %((int)((0x4))))))+((long)((((int)(b->i)) &((int)((0x4E16))))))-((long)((((double)(((66)))) +((double)(b->i)))));
b->i = ((-20)) + (-(-44)) *((long)((((double)(((67)))) -((double)(((-36)))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
s.a.i = ((-4097)) + ((-43)) +((long)((((double)(s.a.i)) -((double)(s.a.i)))))+((short)((((int)((-(0x3D)))) |((int)(((9007199254740992)))))));
s.a.i = ((0xEE37)) + ((-43)) +((long)((((int)((0xE))) <<((int)(s.a.i)))))+((int)((((double)(((3)))) -((double)((-(1)))))))+((short)((((double)(s.a.i)) +((double)(s.a.i)))))-((short)((((double)(s.a.i)) +((double)(s.a.i)))))*((long)((((int)(s.a.i)) <<((int)(s.a.i)))));
;
  
b->i = (-(36)) + ((-43)) *((short)((((double)(b->i)) -((double)(((36)))))))+((long)((((double)(b->i)) *((double)(b->i)))));
b->i = ((139)) + ((0xD31)) -((int)((((int)(b->i)) &((int)(b->i)))))-((int)((((double)(((3)))) *((double)(((39)))))));
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
s.a.i = (0xB1) + (0x8F01B) -((long)((((int)(((0)))) &((int)(s.a.i)))))-((int)((((double)(s.a.i)) +((double)((0xE41D4))))));
s.a.i = (0x86) + (-(-44)) *((short)((((double)(((0)))) +((double)(s.a.i)))))*((short)((((double)(((0x5)))) *((double)((-(1)))))));
;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if (((int)sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int)
      || offsetof (struct Q, a) != sizeof (int) + (-(43)) +((int)((((double)(sizeof (int))) *((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))))))-((short)((((int)(offsetof (struct Q, a))) %((int)(offsetof (struct R, a))))))+((short)((((double)(sizeof (float))) *((double)(sizeof (float) != sizeof (int))))))*((long)((((int)(offsetof (struct Q, a) != sizeof (int))) |((int)(sizeof (int))))))-((short)((((double)(sizeof (float) != sizeof (int)
      || offsetof (struct R, a) != sizeof (int))) *((double)(offsetof (struct Q, a))))))+((short)((((int)(offsetof (struct R, a))) &((int)(offsetof (struct R, a) != sizeof (int))))))))
    { return ((67108864)); }
  
s.a.i = ((-2)) + (0x0A) *((long)((((int)(((-2)))) &((int)((0xB4))))))+((int)((((int)((-(0xA)))) |((int)(((65)))))))+((long)((((int)(s.a.i)) <<((int)(s.a.i)))))*((short)((((int)(s.a.i)) >>((int)((-(-3)))))));
s.a.i = ((-2)) + ((42)) -((long)((((double)((-(-3)))) -((double)(s.a.i)))))*((int)((((double)(((33)))) +((double)(s.a.i)))));
;
  ;
  if (((int)test1 ((void *)&s) != (0x74E3) + ((0x469D11)) -((short)((((int)(test1 ((void *)&s))) |((int)((-(132)))))))-((short)((((double)((0xBA))) *((double)((0x7DA8))))))))
    { abort (); }
  
s.a.i = ((0)) + ((0x42C09)) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
s.a.i = ((0x77E3)) + ((-47)) *((int)((((int)(((33)))) %((int)(((0x703D)))))))-((long)((((int)(s.a.i)) >>((int)(((0x4)))))));
;
  
s.a.j = (0x39AC) + (-(43)) *((long)((((int)(((0x0)))) &((int)(s.a.j)))))*((int)((((double)(s.a.j)) *((double)(s.a.j)))))*((int)((((int)(s.a.j)) &((int)(((8)))))));
s.a.j = (0x50F) + (0xD64C) -((short)((((int)(s.a.j)) >>((int)((-(-4)))))))-((long)((((double)(s.a.j)) *((double)(((-3)))))));
;
  if (((int)test2 ((void *)&s) != (-(132)) + ((0xA0B0A5)) *((int)((((double)((0x5A65E))) +((double)((-(4)))))))*((long)((((int)(test2 ((void *)&s))) <<((int)((-(-5)))))))-((long)((((int)((-(5)))) <<((int)(test2 ((void *)&s))))))))
    { abort (); }
  ;
  ;
  if (((int)test3 ((void *)&s) != ((3)) + ((10)) +((int)((((double)((0xA2))) +((double)(((-4)))))))))
    { abort (); }
  return (0xC);
}
/* ProgramSourceLLVM */
