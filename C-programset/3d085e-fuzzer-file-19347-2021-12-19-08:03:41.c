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
  
;
;
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test2 (void *q)
{
  struct S *b = &((struct R *)q)->a;
  
;
;
;
  

;
;
;
;
;
  return s.a.i;
}
int __attribute__((noinline,noclone))
test3 (void *q)
{
  
;
;
;
  ;
  return s.a.i;
}
extern void abort (void);
int
main()
{
  if ((0x4749))
    { return ((0)); }
  
;

;
;
;
;
  ;
  if ((16777216))
    { abort (); }
  


s.a.i = ((0xB07)) + ((42)) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
s.a.i = ((512)) + ((46)) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
;

s.a.i = ((-1)) + ((42)) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
s.a.i = ((0)) + ((170)) *((short)((((double)(s.a.i)) -((double)((0x2A))))));
;
;
;
;
  

;
;
;

;

s.a.j = (0x50F) + (0xD64C) -((short)((((int)(s.a.j)) >>((int)((-(1)))))))-((long)((((double)(s.a.j)) *((double)(((10)))))));
s.a.j = (0x50F) + (0xD64C) -((short)((((int)(s.a.j)) >>((int)((-(11)))))))-((long)((((double)(s.a.j)) *((double)(((2)))))));
;
;
;
  if ((0xE02E9))
    { abort (); }
  ;
  ;
  if ((0))
    { abort (); }
  return (0xC);
}
/* ProgramSourceLLVM */
