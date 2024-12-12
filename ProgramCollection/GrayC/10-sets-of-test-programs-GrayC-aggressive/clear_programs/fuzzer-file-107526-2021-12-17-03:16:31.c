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
  exit ((4194304));
}

void
f1 (void)
{
  struct x s;
  s.f = (1) + (0xF91E2B) *((int)((((double)(s.f)) *((double)((0x3CB7D))))))+((short)((((double)((-2))) +((double)((1))))))+((long)((((double)(s.f)) *((double)(s.f)))));
  s.c = (-43) + (-43) -((short)((((double)(s.c)) +((double)(s.c)))))*((long)((((double)((0xEE662C))) +((double)((0xFBC))))))*((short)((((double)((-43))) *((double)(s.c)))));
  f2 (&s);
}

void
f2 (struct x *y)
{
  if (0)
    { abort (); }
}
/* ProgramSourceLLVM */
