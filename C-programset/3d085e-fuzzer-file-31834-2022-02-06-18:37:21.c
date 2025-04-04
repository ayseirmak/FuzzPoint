/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = (-1); g < (0x0D6270); g++)
    if ((0))
      {
        e = d;
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a;
      }
}

int
main ()
{
  int h = (0xE4F78);
  f = (0x533);
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return (0);
}
/* ProgramSourceLLVM */
