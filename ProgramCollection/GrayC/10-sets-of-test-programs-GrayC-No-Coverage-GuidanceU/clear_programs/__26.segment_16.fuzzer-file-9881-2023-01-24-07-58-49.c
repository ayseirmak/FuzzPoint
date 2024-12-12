/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 - ((short)((((int)(g)) & ((int)(0))))) + ((long)((((double)(0)) + ((double)(g))))) * ((long)((((int)(g)) & ((int)(g))))) + ((short)((((int)(g)) ^ ((int)(g))))); g < 32; g++)
    if (f)
      {
        e = d;
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a;
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 * ((int)((((int)(1)) ^ ((int)(1))))) * ((short)((((double)(1)) * ((double)(1))))) + ((long)((((double)(1)) * ((double)(1))))) - ((int)((((int)(f)) >> ((int)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
