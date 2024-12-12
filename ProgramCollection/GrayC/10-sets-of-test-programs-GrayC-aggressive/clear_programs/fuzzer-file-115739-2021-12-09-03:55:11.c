/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 *((int)((((int)(g)) |((int)(g)))))+((short)((((double)(0)) *((double)(0))))); g < 32; g++)
    if (f)
      {
        e = d + 42 *((long)((((int)(d)) >>((int)(d)))))+((short)((((double)(d)) -((double)(e)))))-((long)((((double)(d)) +((double)(d)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 +((long)((((int)(*a)) <<((int)(b)))))*((long)((((int)(b)) <<((int)(*a)))))*((short)((((int)(b)) >>((int)(*a)))));
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 -((short)((((double)(f)) *((double)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
