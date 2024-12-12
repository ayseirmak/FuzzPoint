/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 + ((int)((((int)(g)) << ((int)(0))))) + ((int)((((int)(0)) ^ ((int)(g))))) - ((short)((((int)(0)) & ((int)(0))))) + ((short)((((double)(g)) + ((double)(0))))) - ((short)((((double)(g)) - ((double)(g))))); g < 32; g++)
    if (f)
      {
        e = d + 42 * ((short)((((int)(d)) ^ ((int)(d))))) + ((long)((((double)(d)) - ((double)(d))))) - ((short)((((double)(d)) + ((double)(e))))) * ((long)((((int)(e)) % ((int)(d))))) + ((long)((((double)(d)) + ((double)(e)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a;
      }
}

int
main ()
{
  int h = 5;
  f = 1;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
