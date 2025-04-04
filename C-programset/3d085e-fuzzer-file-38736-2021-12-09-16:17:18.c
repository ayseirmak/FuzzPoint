/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 -((short)((((double)(0)) -((double)(g)))))-((int)((((int)(0)) ^((int)(0)))))-((int)((((int)(g)) >>((int)(0))))); g < 32; g++)
    if (f)
      {
        e = d + 42 -((int)((((int)(d)) <<((int)(d)))))-((long)((((double)(d)) -((double)(e)))))-((short)((((int)(d)) &((int)(e)))))-((int)((((double)(e)) +((double)(e)))))*((short)((((int)(d)) >>((int)(d)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 *((int)((((int)(*a)) >>((int)(b)))));
      }
}

int
main ()
{
  int h = 8;
  f = 1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
