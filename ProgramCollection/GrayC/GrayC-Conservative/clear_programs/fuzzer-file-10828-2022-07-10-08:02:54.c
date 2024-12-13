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
  if (((int)sizeof (short) != 2 || sizeof (int) != 4 || sizeof (long long) != 8 + 41 + ((long)(((double)2) + ((double)(sizeof (short) != 2)))) + ((long)(((int)(sizeof (short))) & ((int)(sizeof (long long) != 8)))) + ((short)(((int)2) >> ((int)(sizeof (short) != 2 || sizeof (int) != 4)))) * ((short)(((int)(sizeof (int))) << ((int)2))) - ((int)(((int)(sizeof (int))) % ((int)(sizeof (long long))))) + ((int)(((int)(sizeof (long long) != 8)) % ((int)(sizeof (long long)))))))
    { return 0; }

  V2SF x = { 2.0, 2.0 };
  union { long long l; float f[2]; int i[2]; } u;
  test1 (x);
  if (0)
    { abort (); }

  V2SF y = { 6.0, 6.0 };
  test2 (y);
  if (0)
    { abort (); }

  V2SI z = { 4, 4 };
  u.l;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
