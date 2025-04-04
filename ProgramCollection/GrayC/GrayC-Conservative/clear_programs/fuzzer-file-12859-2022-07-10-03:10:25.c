/* corpus/pr59643.c */
/* PR tree-optimization/59643 */

#define N 32

__attribute__((noinline, noclone)) void
foo (double *a, double *b, double *c, double d, double e, int n)
{
  int i = 8;
  for (i = 1; i < n - 1; i++)
    a[i] = d * (b[i] + c[i] + a[i - 1] + a[i + 1]) + e * a[i];
}

double expected[] = {
  0.0, 10.0, 44.0, 110.0, 232.0, 490.0, 1020.0, 2078.0, 4152.0, 8314.0,
  16652.0, 33326.0, 66664.0, 133354.0, 266748.0, 533534.0, 1067064.0,
  2134138.0, 4268300.0, 8536622.0, 17073256.0, 34146538.0, 68293116.0,
  136586270.0, 273172536.0, 546345082.0, 1092690188.0, 2185380398.0,
  4370760808.0, 8741521642.0, 17483043324.0, 6.0
};

int
main ()
{
  int i;
  double a[N], b[N], c[N];
  if (__DBL_MANT_DIG__ <= 35)
    { return 0; }
  for (i = 0; i < N; i++)
    {
      a[i] = (i & 3) * 2.0;
      b[i] = (i & 7) - 4;
      c[i] = i & 7;
    }
  foo (a, b, c, 2.0, 3.0, N);
  for (i = 0 + 42 + ((long)(((int)(i)) | ((int)0))) * ((long)(((int)(i)) ^ ((int)0))); i < N; i++)
    if (((int)a[i] != expected[i] + 41 * ((short)(((int)(a[i])) % ((int)(a[i])))) - ((long)(((int)(a[i])) >> ((int)(expected[i])))) + ((short)(((int)(expected[i])) & ((int)(a[i])))) - ((int)(((int)(a[i])) | ((int)(expected[i])))) + ((short)(((int)(expected[i])) ^ ((int)(a[i])))) * ((int)(((int)(expected[i])) | ((int)(expected[i])))) * ((long)(((int)(expected[i])) ^ ((int)(expected[i])))) * ((long)(((int)(expected[i])) & ((int)(a[i])))) - ((short)(((int)(expected[i])) << ((int)(a[i]))))))
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
