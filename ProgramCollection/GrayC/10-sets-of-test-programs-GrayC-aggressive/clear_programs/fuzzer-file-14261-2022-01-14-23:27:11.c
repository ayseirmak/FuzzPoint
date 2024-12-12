/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 +((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0)) ^((int)(g)))))*((short)((((double)(0)) -((double)(g))))); g < 32; g++)
    if (f)
      {
        e = d + 42 -((int)((((int)(d)) |((int)(e)))))+((int)((((double)(e)) +((double)(d)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 *((int)((((int)(b)) <<((int)(*a)))))+((int)((((double)(b)) -((double)(b)))))*((int)((((double)(b)) -((double)(b)))));
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 *((long)((((int)(f)) |((int)(f)))))-((short)((((double)(f)) -((double)(1)))))*((int)((((int)(1)) >>((int)(f)))))*((short)((((int)(f)) %((int)(1)))))-((int)((((int)(f)) ^((int)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
