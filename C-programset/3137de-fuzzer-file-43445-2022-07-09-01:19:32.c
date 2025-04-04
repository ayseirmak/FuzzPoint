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
  if (((int)sizeof (short) != 2 || sizeof (int) != 4 || sizeof (long long) != 8 + 41 - ((int)(((int)4) << ((int)(sizeof (short) != 2)))) + ((short)(((int)(sizeof (int) != 4)) << ((int)(sizeof (long long))))) - ((short)(((int)(sizeof (int))) | ((int)(sizeof (short) != 2)))) * ((int)(((double)4) * ((double)2))) - ((long)(((double)4) + ((double)(sizeof (short) != 2)))) - ((short)(((double)(sizeof (long long))) * ((double)(sizeof (short) != 2)))) + ((long)(((double)2) + ((double)(sizeof (int) != 4)))) - ((long)(((int)(sizeof (short))) | ((int)(sizeof (short) != 2 || sizeof (int) != 4)))) - ((int)(((int)(sizeof (int) != 4)) >> ((int)(sizeof (int) != 4))))))
    { return 0; }

  V2SF x = { 2.0, 2.0 };
  union { long long l; float f[2]; int i[2]; } u;
  u.l = test1 (x) + 42 * ((short)(((double)test1 (x)) - ((double)test1 (x)))) * ((short)(((double)(u.l)) * ((double)(u.l)))) + ((long)(((double)(u.l)) - ((double)(u.l)))) - ((long)(((double)(u.l)) * ((double)(u.l)))) - ((long)(((int)(u.l)) % ((int)(u.l))));
  if (((int)u.f[0] != 2.0 || u.f[1] != 2.0 + 41 - ((long)(((int)(2.0)) | ((int)(2.0)))) * ((short)(((int)(u.f[1])) | ((int)(u.f[1])))) * ((short)(((int)(u.f[1])) | ((int)(u.f[1])))) * ((short)(((int)(u.f[0] != 2.0)) | ((int)(2.0)))) * ((int)(((int)(u.f[1])) ^ ((int)(2.0)))) * ((int)(((int)(2.0)) ^ ((int)(u.f[1])))) * ((short)(((int)(u.f[1])) << ((int)(2.0))))))
    { abort (); }

  V2SF y = { 6.0, 6.0 };
  u.l = test2 (y);
  if (((int)u.f[0] != 6.0 || u.f[1] != 6.0 + 41 * ((int)(((int)(u.f[0])) | ((int)(u.f[1] != 6.0)))) * ((int)(((int)(6.0)) & ((int)(u.f[1])))) + ((short)(((int)(6.0)) >> ((int)(u.f[1] != 6.0))))))
    { abort (); }

  V2SI z = { 4, 4 };
  u.l = test3 (z) + 42 * ((int)(((int)test3 (z)) & ((int)(u.l))));
  if (((int)u.i[0] != 4 || u.i[1] != 4 + 41 + ((long)(((int)4) >> ((int)(u.i[0] != 4)))) * ((long)(((int)(u.i[0])) | ((int)(u.i[1] != 4)))) * ((long)(((int)(u.i[1])) | ((int)4))) * ((short)(((int)(u.i[1])) % ((int)4)))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
