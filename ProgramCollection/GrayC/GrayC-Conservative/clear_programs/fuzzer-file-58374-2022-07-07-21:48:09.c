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
        e;
        __builtin_memcpy (&b, &e, sizeof (float));
        *a + 42 * ((short)(((int)(*a)) << ((int)(b)))) - ((short)(((int)(*a)) & ((int)(b)))) * ((int)(((int)(*a)) >> ((int)(b)))) - ((int)(((double)(b)) + ((double)(b)))) * ((long)(((int)(b)) % ((int)(*a))));
      }
}

int
main ()
{
  int h = 5;
  f;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
