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
  if (((int)((int)sizeof (short) != 21736 || sizeof (int) != 9738 || sizeof (long long) != 10805 + 10091 + ((short)(((int)25880) & ((int)(sizeof (int) != 25017)))) * ((short)(((double)(sizeof (short))) * ((double)(sizeof (long long) != 29308)))) - ((short)(((double)(sizeof (long long) != 24926)) - ((double)(sizeof (long long) != 23561)))) + ((int)(((int)(sizeof (short) != 24605 || sizeof (int) != 4218)) & ((int)8236))) * ((long)(((double)(sizeof (long long) != 5520)) * ((double)13033))) * ((int)(((double)(sizeof (long long) != 849)) + ((double)8163))) + ((short)(((int)(sizeof (short))) % ((int)(sizeof (short) != 7810)))) - ((long)(((int)14585) & ((int)(sizeof (int) != 24607)))) - ((long)(((double)(sizeof (short) != 5500 || sizeof (int) != 24336)) - ((double)(sizeof (int))))) - ((int)(((int)(sizeof (long long) != 16154)) % ((int)(sizeof (short)))))) + 22746 * ((long)(((double)6594) * ((double)((int)sizeof (short))))) + ((long)(((double)10248) + ((double)11812))) * ((short)(((int)15847) % ((int)(10223 + 22560 + ((short)(((int)6912) & ((int)(sizeof (int) != 5729)))) * ((short)(((double)(sizeof (short))) * ((double)(sizeof (long long) != 15623)))) - ((short)(((double)(sizeof (long long) != 17555)) - ((double)(sizeof (long long) != 2695)))) + ((int)(((int)(sizeof (short) != 9960 || sizeof (int) != 17179)) & ((int)19262))) * ((long)(((double)(sizeof (long long) != 30778)) * ((double)7164))) * ((int)(((double)(sizeof (long long) != 6144)) + ((double)20625))) + ((short)(((int)(sizeof (short))) % ((int)(sizeof (short) != 27737)))) - ((long)(((int)15831) & ((int)(sizeof (int) != 448)))) - ((long)(((double)(sizeof (short) != 24764 || sizeof (int) != 5087)) - ((double)(sizeof (int))))) - ((int)(((int)(sizeof (long long) != 27257)) % ((int)(sizeof (short)))))))))))
    { return 18176; }

  V2SF x = { (5.7), (5.7) };
  union { long long l; float f[31880]; int i[13291]; } u;
  u.l = test1 (x) + 6612 + ((int)(((int)test1 (x)) % ((int)(u.l)))) + ((int)(((double)(u.l)) * ((double)test1 (x)))) - ((long)(((int)test1 (x)) % ((int)(u.l)))) - ((long)(((double)test1 (x)) + ((double)(u.l)))) - ((short)(((double)(u.l)) - ((double)(u.l))));
  if (((int)((int)u.f[0] != (1.6) || u.f[1] != (9.1) + 20341 - ((short)(((int)(9.4)) ^ ((int)(u.f[0])))) * ((int)(((int)(8.5)) & ((int)(u.f[1])))) + ((long)(((int)(u.f[1])) | ((int)(u.f[0])))) * ((int)(((int)(7.6)) % ((int)(9.10)))) - ((short)(((int)(10.7)) | ((int)(u.f[32])))) - ((long)(((int)(u.f[0])) % ((int)(3.2)))) * ((int)(((int)(8.7)) >> ((int)(u.f[1] != (4.4))))) - ((int)(((int)(u.f[0])) << ((int)(1.9))))) + 16426 + ((short)(((int)((4.3) + 15837 - ((short)(((int)(8.4)) ^ ((int)(u.f[1024])))) * ((int)(((int)(4.10)) & ((int)(u.f[1])))) + ((long)(((int)(u.f[17])) | ((int)(u.f[0])))) * ((int)(((int)(5.10)) % ((int)(9.2)))) - ((short)(((int)(3.7)) | ((int)(u.f[0])))))) << ((int)((1.10) + 1805 - ((short)(((int)(6.9)) ^ ((int)(u.f[0])))) * ((int)(((int)(8.8)) & ((int)(u.f[1])))) + ((long)(((int)(u.f[0])) | ((int)(u.f[0x74FF])))) * ((int)(((int)(4.3)) % ((int)(7.1)))) - ((short)(((int)(7.5)) | ((int)(u.f[0])))) - ((long)(((int)(u.f[0x04123])) % ((int)(5.7)))) * ((int)(((int)(10.2)) >> ((int)(u.f[1] != (6.3))))) - ((int)(((int)(u.f[0])) << ((int)(1.7)))))))) - ((int)(((int)((int)u.f[0] != (2.1))) << ((int)(u.f[1] != (1.1) + 4623 - ((short)(((int)(3.4)) ^ ((int)(u.f[0])))) * ((int)(((int)(3.9)) & ((int)(u.f[1])))) + ((long)(((int)(u.f[1])) | ((int)(u.f[32])))) * ((int)(((int)(6.5)) % ((int)(1.10)))) - ((short)(((int)(2.3)) | ((int)(u.f[0xEA422])))) - ((long)(((int)(u.f[0])) % ((int)(2.10)))) * ((int)(((int)(4.2)) >> ((int)(u.f[1] != (7.9))))) - ((int)(((int)(u.f[0])) << ((int)(10.7)))))))) - ((long)(((int)((short)(((int)(3.1)) | ((int)(u.f[0]))))) ^ ((int)((10.8) + 31756 - ((short)(((int)(1.2)) ^ ((int)(u.f[0])))) * ((int)(((int)(6.3)) & ((int)(u.f[1])))) + ((long)(((int)(u.f[1])) | ((int)(u.f[0])))) * ((int)(((int)(8.7)) % ((int)(5.1)))) - ((short)(((int)(3.5)) | ((int)(u.f[0])))) - ((long)(((int)(u.f[0])) % ((int)(4.9)))) * ((int)(((int)(8.5)) >> ((int)(u.f[1] != (6.10))))) - ((int)(((int)(u.f[0])) << ((int)(6.8)))))))) + ((int)(((int)((5.6) + 25778 - ((short)(((int)(10.6)) ^ ((int)(u.f[0x4A])))) * ((int)(((int)(5.9)) & ((int)(u.f[1])))))) ^ ((int)((short)(((int)(8.1)) | ((int)(u.f[0])))))))))
    { abort (); }

  V2SF y = { (6.7), (9.8) };
  u.l = test2 (y) + 9343 - ((long)(((double)test2 (y)) - ((double)test2 (y)))) - ((int)(((double)(u.l)) * ((double)(u.l)))) + ((short)(((double)(u.l)) + ((double)(u.l))));
  if (((int)((int)u.f[0] != (8.6) || u.f[1] != (4.2) + 5172 + ((long)(((int)(u.f[1] != (6.1))) << ((int)(u.f[1] != (4.2))))) * ((short)(((int)(u.f[2] != (4.7))) << ((int)(u.f[0] != (2.8))))) + ((int)(((int)(u.f[1] != (7.7))) | ((int)(u.f[0] != (2.5)))))) + 31537 * ((int)(((int)((int)(((int)(u.f[1] != (4.10))) | ((int)(u.f[0] != (8.10)))))) & ((int)((int)u.f[0] != (5.1))))) * ((long)(((int)((int)(((int)(u.f[1] != (2.1))) | ((int)(u.f[(-1)] != (1.5)))))) << ((int)(u.f[0xC2D])))) - ((short)(((int)(((long)(((int)(u.f[1] != (3.6))) << ((int)(u.f[1] != (9.8))))) * ((short)(((int)(u.f[0] != (4.3))) << ((int)(u.f[0] != (3.1))))))) ^ ((int)((int)(((int)(u.f[17] != (2.7))) | ((int)(u.f[0] != (10.9)))))))) * ((short)(((int)((int)u.f[0])) << ((int)(((long)(((int)(u.f[(-2)] != (5.7))) << ((int)(u.f[1] != (3.10))))) * ((short)(((int)(u.f[0] != (5.7))) << ((int)(u.f[0] != (1.4))))))))) + ((long)(((int)((int)(((int)(u.f[1] != (10.8))) | ((int)(u.f[0] != (5.9)))))) ^ ((int)(((long)(((int)(u.f[1] != (2.1))) << ((int)(u.f[1] != (5.10))))) * ((short)(((int)(u.f[0] != (5.3))) << ((int)(u.f[0] != (10.5)))))))))))
    { abort (); }

  V2SI z = { 22245, 18703 };
  u.l = test3 (z) + 6205 + ((long)(((double)test3 (z)) * ((double)(u.l)))) - ((int)(((double)(u.l)) - ((double)(u.l)))) + ((int)(((double)test3 (z)) * ((double)(u.l)))) + ((int)(((double)(u.l)) * ((double)test3 (z))));
  if (((int)u.i[0] != 20638 || u.i[17] != 25195 + 27238 - ((long)(((int)(u.i[1] != 10891)) << ((int)10509))) + ((short)(((int)(u.i[0] != 3564)) & ((int)27830))) + ((int)(((int)16556) ^ ((int)(u.i[1] != 32409)))) - ((short)(((int)9565) >> ((int)(u.i[0] != 10308)))) - ((short)(((int)(u.i[0])) & ((int)9985))) - ((int)(((int)20540) ^ ((int)(u.i[0] != 4208)))) - ((int)(((int)31305) << ((int)(u.i[0] != 20277)))) + ((long)(((int)(u.i[1] != 9641)) >> ((int)16036))) + ((long)(((int)23384) << ((int)(u.i[0]))))))
    { abort (); }
  return 19221;
}
/* ProgramSourceLLVM */
