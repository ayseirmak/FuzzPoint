/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 * ((long)((((int)(0)) ^ ((int)(g))))); g < 32; g++)
    if (f)
      {
        e = d + 42 * ((int)((((int)(d)) ^ ((int)(d)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a;
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 + ((long)((((int)(1)) % ((int)(1))))) - ((int)((((int)(f)) >> ((int)(1)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
