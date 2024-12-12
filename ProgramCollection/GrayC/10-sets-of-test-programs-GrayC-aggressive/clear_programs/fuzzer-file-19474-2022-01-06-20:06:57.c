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
  
s.f = (1) + (0xFDB) *((short)((((int)((-2))) |((int)((2))))))-((int)((((int)((1))) ^((int)((0x21206)))))) + (42) +((short)((((int)(s.f)) %((int)((-2) + (43) *((short)((((int)((1))) |((int)((9))))))-((int)((((int)((9))) ^((int)((33)))))))))))+((short)((((int)((3) + (58) *((short)((((int)((33))) |((int)((65))))))-((int)((((int)((0))) ^((int)((1)))))))) ^((int)(s.f)))));
s.f = (0) + (-43) *((short)((((int)((1))) |((int)((-2))))))-((int)((((int)((4))) ^((int)((0xF2B1)))))) + (58) +((short)((((int)(s.f)) %((int)((0x82E) + (0x613B9C) *((short)((((int)((1))) |((int)((1))))))-((int)((((int)((0x968))) ^((int)((1)))))))))))+((short)((((int)((0x58299) + (0x1FD) *((short)((((int)((-2))) |((int)((-2))))))-((int)((((int)((-2))) ^((int)((1)))))))) ^((int)(s.f)))));
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
