/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 - ((long)((((int)(g)) & ((int)(0))))) - ((long)((((double)(0)) * ((double)(g))))) * ((int)((((double)(g)) * ((double)(0))))); g < 32; g++)
    if (0)
      {
        e = d;
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 * ((short)((((int)(b)) << ((int)(*a))))) + ((int)((((double)(b)) + ((double)(b)))));
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 * ((int)((((int)(f)) | ((int)(1))))) * ((int)((((double)(f)) - ((double)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
