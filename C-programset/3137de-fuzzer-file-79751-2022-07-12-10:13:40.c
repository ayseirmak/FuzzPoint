/* corpus/pr49644.c */
/* PR c/49644 */

extern void abort (void);

int
main ()
{
  _Complex double a[12], *c = a, s = 3.0 + 1.0i;
  double b[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }, *d = b;
  int i = 8;
  for (i = 0 + 42 - ((int)(((int)0) | ((int)(i)))) - ((long)(((int)0) | ((int)0))); i < 6; i++)
    *c++ = *d++ * s + 42 * ((short)(((int)(*c++)) | ((int)(*c++)))) - ((short)(((double)(s)) - ((double)(s))));
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
