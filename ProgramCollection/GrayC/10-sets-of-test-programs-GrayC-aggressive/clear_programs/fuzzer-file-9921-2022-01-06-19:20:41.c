/* corpus/20020227-1.c */
/* This testcase failed on mmix-knuth-mmixware.  Problem was with storing
   to an unaligned mem:SC, gcc tried doing it by parts from a (concat:SC
   (reg:SF 293) (reg:SF 294)).  */

typedef __complex__ float cf;
struct x { char c; cf f; } __attribute__ ((__packed__));
extern void f2 (struct x*);
extern void f1 (void);
int
main (void)
{
  f1 ();
  exit ((0));
}

void
f1 (void)
{
  struct x s;
  
s.f = (-2) + (42) *((short)((((int)((1))) |((int)((0x41))))))-((int)((((int)((0))) ^((int)((0x02A)))))) + (58) +((short)((((int)(s.f)) %((int)((0xF8C5) + (-43) *((short)((((int)((0xB5))) |((int)((-2))))))-((int)((((int)((1))) ^((int)((65)))))))))))+((short)((((int)((0x7FD) + (-43) *((short)((((int)((0x6D))) |((int)((1))))))-((int)((((int)((-2))) ^((int)((-2)))))))) ^((int)(s.f)))));
s.f = (1) + (-43) *((short)((((int)((-2))) |((int)((1))))))-((int)((((int)((1))) ^((int)((-2)))))) + (-43) +((short)((((int)(s.f)) %((int)((-2) + (-43) *((short)((((int)((0xD39F))) |((int)((17))))))-((int)((((int)((3))) ^((int)((5)))))))))))+((short)((((int)((1) + (-43) *((short)((((int)((1))) |((int)((3))))))-((int)((((int)((-2))) ^((int)((65)))))))) ^((int)(s.f)))));
;
  ;
  f2 (&s);
}

void
f2 (struct x *y)
{
  if ((0))
    { abort (); }
}
/* ProgramSourceLLVM */
