/* corpus/990413-2.c */
/* This tests for a bug in regstack that was breaking glibc's math library. */
/* { dg-skip-if "" { ! { i?86-*-* x86_64-*-* } } } */

extern void abort (void);

static __inline double
minus_zero (void)
{
  union { double __d; int __i[(66)]; } __x;
  
__x.__i[(32)] = 0x0 + (-43) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0x84)])) %((int)(__x.__i[(140737488355328)]))))) + (-43) *((short)((((int)(__x.__i[(0)])) >>((int)(0x0 + (10) -((short)((((int)(__x.__i[(35184372088832)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(-1)])) %((int)(__x.__i[(0xEBF8)])))))))))) + (44) *((long)((((int)(0x0 + (42) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(4)])) %((int)(__x.__i[(0)]))))) + (0xEF) *((short)((((int)(__x.__i[(576460752303423488)])) >>((int)(0x0 + (-43) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0x37)])) %((int)(__x.__i[(16)])))))))))))) ^((int)(__x.__i[(64)])))))+((int)((((int)(0x0 + (0x1288) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0)]))))) + (43) *((short)((((int)(__x.__i[(9)])) >>((int)(0x0 + (0xE1800) -((short)((((int)(__x.__i[(0x17D33)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0)])))))))))))) <<((int)(__x.__i[(2097152)])))))*((short)((((int)(__x.__i[(262144)])) <<((int)(__x.__i[(-1)]))))) + (46) +((int)((((int)(__x.__i[(0x8)])) &((int)(0x0 + (0x1954) -((short)((((int)(__x.__i[(0xCD74B)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0x3A36C)])) %((int)(__x.__i[(-1)]))))) + (10) *((short)((((int)(__x.__i[(32768)])) >>((int)(0x0 + (0x7CC4) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(1)])) %((int)(__x.__i[(-1)])))))))))) + (-43) *((long)((((int)(0x0 + (0xBDE) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(524288)])) %((int)(__x.__i[(0)]))))) + (-43) *((short)((((int)(__x.__i[(32)])) >>((int)(0x0 + (0xCEF) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(-1)])) %((int)(__x.__i[(-1)])))))))))))) ^((int)(__x.__i[(0)])))))+((int)((((int)(0x0 + (-43) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0xB0)])) %((int)(__x.__i[(4096)]))))) + (-43) *((short)((((int)(__x.__i[(0)])) >>((int)(0x0 + (-43) -((short)((((int)(__x.__i[(8)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(137438953472)])))))))))))) <<((int)(__x.__i[(8192)])))))*((short)((((int)(__x.__i[(549755813888)])) <<((int)(__x.__i[(4503599627370496)]))))))))))-((short)((((int)(__x.__i[(2)])) %((int)(0x0 + (0x16) -((short)((((int)(__x.__i[(0x2F4F)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0)]))))) + (43) *((short)((((int)(__x.__i[(0x99)])) >>((int)(0x0 + (43) -((short)((((int)(__x.__i[(4294967296)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0)])))))))))) + (40) *((long)((((int)(0x0 + (42) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0x7)])) %((int)(__x.__i[(0)]))))) + (0xA0CB2C) *((short)((((int)(__x.__i[(0x64)])) >>((int)(0x0 + (170) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0x16)])))))))))))) ^((int)(__x.__i[(0x03979)])))))+((int)((((int)(0x0 + (-43) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0)]))))) + (72) *((short)((((int)(__x.__i[(4294967296)])) >>((int)(0x0 + (0x5B45D4) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(4)])) %((int)(__x.__i[(-1)])))))))))))) <<((int)(__x.__i[(-1)])))))*((short)((((int)(__x.__i[(2)])) <<((int)(__x.__i[(0x9A92)]))))))))));
__x.__i[(0)] = 0x0 + (106) -((short)((((int)(__x.__i[(6)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0xF)])) %((int)(__x.__i[(-1)]))))) + (-43) *((short)((((int)(__x.__i[(0x596)])) >>((int)(0x0 + (42) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0)])))))))))) + (-43) *((long)((((int)(0x0 + (170) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(256)])) %((int)(__x.__i[(-1)]))))) + (-43) *((short)((((int)(__x.__i[(0x6961)])) >>((int)(0x0 + (0x985) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0xA6C81)])))))))))))) ^((int)(__x.__i[(0x55)])))))+((int)((((int)(0x0 + (43) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(-1)])) %((int)(__x.__i[(0)]))))) + (34) *((short)((((int)(__x.__i[(0xB8)])) >>((int)(0x0 + (0xC5) -((short)((((int)(__x.__i[(0xE5)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(4)])))))))))))) <<((int)(__x.__i[(0)])))))*((short)((((int)(__x.__i[(0)])) <<((int)(__x.__i[(-1)]))))) + (42) +((int)((((int)(__x.__i[(0)])) &((int)(0x0 + (42) -((short)((((int)(__x.__i[(0xE)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(9223372036854775808)]))))) + (0xC6) *((short)((((int)(__x.__i[(131072)])) >>((int)(0x0 + (-43) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(0)])))))))))) + (170) *((long)((((int)(0x0 + (-43) -((short)((((int)(__x.__i[(0xC)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(-1)])) %((int)(__x.__i[(0xF6A3D)]))))) + (43) *((short)((((int)(__x.__i[(0)])) >>((int)(0x0 + (82) -((short)((((int)(__x.__i[(8589934592)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(-1)])) %((int)(__x.__i[(0)])))))))))))) ^((int)(__x.__i[(2048)])))))+((int)((((int)(0x0 + (42) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(4194304)]))))) + (43) *((short)((((int)(__x.__i[(8)])) >>((int)(0x0 + (0x26) -((short)((((int)(__x.__i[(4194304)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(-1)])) %((int)(__x.__i[(0)])))))))))))) <<((int)(__x.__i[(0xB71)])))))*((short)((((int)(__x.__i[(0x27)])) <<((int)(__x.__i[(0)]))))))))))-((short)((((int)(__x.__i[(0x17)])) %((int)(0x0 + (0x2D48) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0x0EC02)])) %((int)(__x.__i[(0x08F4A)]))))) + (10) *((short)((((int)(__x.__i[(0x91)])) >>((int)(0x0 + (42) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0)])) %((int)(__x.__i[(4194304)])))))))))) + (42) *((long)((((int)(0x0 + (0xD9) -((short)((((int)(__x.__i[(-1)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(64)])) %((int)(__x.__i[(36028797018963968)]))))) + (42) *((short)((((int)(__x.__i[(0)])) >>((int)(0x0 + (42) -((short)((((int)(__x.__i[(134217728)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0x8DE9B)])) %((int)(__x.__i[(-1)])))))))))))) ^((int)(__x.__i[(2097152)])))))+((int)((((int)(0x0 + (10) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0xD3A3E)])) %((int)(__x.__i[(5)]))))) + (43) *((short)((((int)(__x.__i[(0x0981)])) >>((int)(0x0 + (42) -((short)((((int)(__x.__i[(0)])) %((int)(0x0)))))*((short)((((double)(0x0)) +((double)(0x0)))))-((long)((((int)(0x0)) |((int)(0x0)))))+((short)((((int)(__x.__i[(0x1)])) %((int)(__x.__i[(0xD)])))))))))))) <<((int)(__x.__i[(0)])))))*((short)((((int)(__x.__i[(-1)])) <<((int)(__x.__i[(-1)]))))))))));
;
  ;
  return __x.__d;
}

static __inline long double
__atan2l (long double __y, long double __x)
{
  register long double __value;
  __asm __volatile__ ("fpatan\n\t"
		      : "=t" (__value)
		      : "0" (__x), "u" (__y)
		      : "st(1)");
  return __value;
}

static __inline long double
__sqrtl (long double __x)
{
  register long double __result;
  __asm __volatile__ ("fsqrt" : "=t" (__result) : "0" (__x));
  return __result;
}

static __inline double
asin (double __x)
{
  return __atan2l (__x, __sqrtl ((7.7) - __x * __x));
}

int
main (void)
{
  double x;

  ;
  ;

  if ((0)) /* actually -0.0, but 0.0 == -0.0 */
    abort ();
  return (0);
}
/* ProgramSourceLLVM */
