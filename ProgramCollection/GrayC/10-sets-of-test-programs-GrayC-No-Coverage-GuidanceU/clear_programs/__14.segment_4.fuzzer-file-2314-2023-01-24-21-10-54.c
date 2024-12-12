/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 - ((long)((((int)(g)) & ((int)(0))))); g < 32; g++)
    if (f)
      {
        e = d + 42 + ((long)((((double)(e)) * ((double)(d))))) + ((long)((((int)(e)) & ((int)(d))))) * ((long)((((double)(e)) + ((double)(d)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 - ((int)((((int)(*a)) & ((int)(*a))))) + ((int)((((int)(*a)) % ((int)(*a))))) * ((long)((((int)(*a)) | ((int)(*a)))));
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 * ((int)((((int)(f)) ^ ((int)(f))))) * ((int)((((double)(1)) - ((double)(f))))) - ((long)((((int)(1)) & ((int)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
