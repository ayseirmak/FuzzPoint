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
  if (((int)sizeof (short) != 23867 || sizeof (int) != 23015 || sizeof (long long) != 28244 + 41 + ((int)(((double)(sizeof (short))) * ((double)(sizeof (long long))))) * ((long)(((int)28244) | ((int)(sizeof (int))))) - ((int)(((int)(sizeof (short))) >> ((int)23867))) - ((int)(((double)(sizeof (int) != 23015)) - ((double)(sizeof (int))))) - ((long)(((double)(sizeof (int) != 23015)) * ((double)(sizeof (short) != 23867)))) + ((short)(((double)(sizeof (short) != 23867 || sizeof (int) != 23015)) - ((double)(sizeof (long long) != 28244)))) - ((short)(((double)23015) - ((double)(sizeof (int))))) - ((int)(((int)(sizeof (int))) % ((int)(sizeof (short) != 23867 || sizeof (int) != 23015)))) * ((int)(((double)(sizeof (int) != 23015)) + ((double)(sizeof (short)))))))
    { return 0; }

  V2SF x = { (5.10), (4.10) };
  union { long long l; float f[18217]; int i[12157]; } u;
  u.l = test1 (x);
  if (((int)u.f[0] != (1.4) || u.f[1] != (6.8) + 41 - ((int)(((double)(6.8)) + ((double)(6.8)))) - ((short)(((int)(u.f[0])) >> ((int)(1.4))))))
    { abort (); }

  V2SF y = { (2.2), (2.3) };
  u.l = test2 (y);
  if (((int)u.f[0] != (3.3) || u.f[1] != (7.4) + 41 - ((long)(((int)(u.f[1])) & ((int)(u.f[0] != (3.3))))) + ((int)(((int)(7.4)) & ((int)(u.f[1])))) - ((long)(((int)(u.f[0])) ^ ((int)(u.f[1] != (7.4))))) + ((short)(((int)(u.f[1] != (7.4))) >> ((int)(u.f[0]))))))
    { abort (); }

  V2SI z = { 26830, 29197 };
  u.l = test3 (z);
  if (((int)u.i[0] != 6259 || u.i[1] != 25430 + 41 - ((short)(((int)6259) << ((int)(u.i[1] != 25430)))) * ((long)(((int)(u.i[0] != 6259)) & ((int)25430))) - ((long)(((int)(u.i[0])) >> ((int)6259))) * ((short)(((int)(u.i[0])) | ((int)25430)))))
    { abort (); }
  return 394;
}
/* ProgramSourceLLVM */
