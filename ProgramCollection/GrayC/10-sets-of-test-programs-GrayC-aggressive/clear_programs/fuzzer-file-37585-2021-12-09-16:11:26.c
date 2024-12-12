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
  exit ((576460752303423488));
}

void
f1 (void)
{
  struct x s;
  
s.f = (0xC1D1) + (42) +((long)((((double)((2))) *((double)(s.f)))))+((long)((((double)((0x8C8))) *((double)(s.f)))))*((long)((((int)((-2))) %((int)((0x54E95))))));
s.f = (1) + (0x6925A) +((long)((((double)((1))) *((double)(s.f)))))+((long)((((double)((9))) *((double)(s.f)))))*((long)((((int)((1))) %((int)((0xBF))))));
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
