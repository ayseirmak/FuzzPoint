/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 *((int)((((double)(g)) +((double)(0))))); g < 32; g++)
    if (0)
      {
        e = d + 42 -((short)((((double)(d)) +((double)(d)))))*((int)((((double)(e)) *((double)(e)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 *((short)((((double)(b)) -((double)(b)))))-((long)((((int)(*a)) ^((int)(*a)))))+((int)((((int)(b)) <<((int)(*a)))))-((short)((((double)(b)) -((double)(b)))))*((long)((((double)(b)) +((double)(b)))));
      }
}

int
main ()
{
  int h = 8;
  f = 1 + 42 +((int)((((double)(1)) -((double)(1)))))+((int)((((double)(1)) *((double)(1)))))+((short)((((int)(1)) |((int)(f)))))+((short)((((double)(f)) +((double)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
