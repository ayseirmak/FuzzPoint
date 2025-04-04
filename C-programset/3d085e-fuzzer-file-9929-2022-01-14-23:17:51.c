/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 +((short)((((int)(g)) ^((int)(0)))))*((short)((((int)(g)) &((int)(g)))))*((long)((((int)(g)) <<((int)(0))))); g < 32; g++)
    if (0)
      {
        e = d + 42 +((short)((((double)(d)) *((double)(e)))))*((long)((((double)(e)) +((double)(e)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 *((int)((((int)(*a)) >>((int)(*a)))))*((short)((((double)(b)) -((double)(b)))))+((int)((((int)(*a)) |((int)(*a)))))*((int)((((int)(*a)) %((int)(*a)))));
      }
}

int
main ()
{
  int h = 8;
  f = 1 + 42 *((int)((((int)(1)) <<((int)(1)))))*((long)((((int)(f)) >>((int)(1)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
