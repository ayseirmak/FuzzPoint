/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = (0); g < (40); g++)
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
  int h = 8;
  f = (-2);
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return (8192);
}
/* ProgramSourceLLVM */
