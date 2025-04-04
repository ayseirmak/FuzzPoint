/* corpus/990413-2.c */
/* This tests for a bug in regstack that was breaking glibc's math library. */
/* { dg-skip-if "" { ! { i?86-*-* x86_64-*-* } } } */

extern void abort (void);

static __inline double
minus_zero (void)
{
  union { double __d; int __i[(2)]; } __x;
  ;
  

;
;
;

;

__x.__i[(9)] = 0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))) + 42 -((short)((((int)(__x.__i[(9)])) |((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))))))-((long)((((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))) >>((int)(__x.__i[(9)])))))-((long)((((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))) <<((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))))));
__x.__i[(9)] = 0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))) + 42 -((short)((((int)(__x.__i[(9)])) |((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))))))-((long)((((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))) >>((int)(__x.__i[(9)])))))-((long)((((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))) <<((int)(0x80000000 + (42) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(0x379CA)]))))) + (-43) +((int)((((int)(__x.__i[(1)])) <<((int)(__x.__i[(3)])))))-((int)((((int)(0x80000000 + (-43) +((int)((((int)(0x80000000)) <<((int)(__x.__i[(-2)]))))))) |((int)(__x.__i[(1)]))))))))));
;
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
  return __atan2l (__x, __sqrtl ((10.4) - __x * __x));
}

int
main (void)
{
  double x;

  ;
  ;

  if (0) /* actually -0.0, but 0.0 == -0.0 */
    abort ();
  return (1073741824);
}
/* ProgramSourceLLVM */
