/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0; g < 32; g++)
    if (0)
      {
        e = d;
        __builtin_memcpy (&b, &e, sizeof (float));
        b;
      }
}

int
main ()
{
  int h = 5;
  1;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
