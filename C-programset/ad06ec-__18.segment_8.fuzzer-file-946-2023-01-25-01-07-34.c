/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0; g < 32; g++)
    if (f)
      {
        e = d + 42 * ((short)((((int)(d)) ^ ((int)(d))))) * ((long)((((int)(e)) << ((int)(d))))) - ((short)((((double)(e)) * ((double)(e))))) - ((short)((((double)(e)) + ((double)(d))))) - ((long)((((double)(e)) - ((double)(d))))) + 42 * ((long)((((int)(e)) | ((int)(d + 42 * ((short)((((int)(d)) ^ ((int)(d))))) * ((long)((((int)(e)) << ((int)(d))))) - ((short)((((double)(e)) * ((double)(e))))) - ((short)((((double)(e)) + ((double)(d))))) - ((long)((((double)(e)) - ((double)(d))))))))));
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
