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
  exit (0);
}

void
f1 (void)
{
  struct x s;
  s.f = 1 + 42 +((int)((((double)(s.f)) +((double)(1)))))*((int)((((int)(s.f)) ^((int)(s.f)))))*((short)((((int)(s.f)) >>((int)(1)))))*((long)((((double)(s.f)) +((double)(s.f)))))*((short)((((int)(s.f)) ^((int)(s.f)))));
  s.c = 42 + 42 -((int)((((double)(42)) -((double)(42)))))*((short)((((double)(s.c)) -((double)(42)))));
  f2 (&s);
}

void
f2 (struct x *y)
{
  if (0)
    { abort (); }
}
/* ProgramSourceLLVM */
