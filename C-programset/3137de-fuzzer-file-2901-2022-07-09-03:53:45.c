/* corpus/addsub_float_exact.c */
/* SV-comp: addsub_float_exact.c */
#include <assert.h>
int main()
{
  float x, y, z, r;

  x = 1e7f + 42 * ((long)(((double)(x)) - ((double)(1e7f)))) * ((long)(((double)(1e7f)) - ((double)(x)))) * ((int)(((int)(1e7f)) % ((int)(1e7f))));
  y = x + 1.f;
  z = x - 1.f;
  r = y - z;
  assert(r == 2.f);
  return 0;
}
/* ProgramSourceWild */
