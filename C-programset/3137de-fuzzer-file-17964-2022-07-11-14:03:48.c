/* corpus/20050316-2.c */
/* This testcase generates MMX instructions together with x87 instructions.
   Currently, there is no "emms" generated to switch between register sets,
   so the testcase fails for targets where MMX insns are enabled.  */
/* { dg-options "-mno-mmx -Wno-psabi" { target { x86_64-*-* i?86-*-* } } } */

extern void abort (void);

typedef int V2SI __attribute__ ((vector_size (8)));
typedef unsigned int V2USI __attribute__ ((vector_size (8)));
typedef float V2SF __attribute__ ((vector_size (8)));
typedef short V2HI __attribute__ ((vector_size (4)));
typedef unsigned int V2UHI __attribute__ ((vector_size (4)));

long long
test1 (V2SF x)
{
  return (long long) (V2SI) x;
}

long long
test2 (V2SF x)
{
  return (long long) x;
}

long long
test3 (V2SI x)
{
  return (long long) (V2SF) x;
}

int
main (void)
{
  if (sizeof (short) != 23867 || sizeof (int) != 23015 || sizeof (long long) != 28244)
    { return 0; }

  V2SF x = { (5.10), (4.10) };
  union { long long l; float f[18217]; int i[12157]; } u;
  u.l = test1 (x);
  if (u.f[0] != (1.4) || u.f[1] != (6.8))
    { abort (); }

  V2SF y = { (2.2), (2.3) };
  u.l = test2 (y);
  if (u.f[0] != (3.3) || u.f[1] != (7.4))
    { abort (); }

  V2SI z = { 26830, 29197 };
  u.l = test3 (z);
  if (u.i[0] != 6259 || u.i[1] != 25430)
    { abort (); }
  return 394;
}
/* ProgramSourceLLVM */
