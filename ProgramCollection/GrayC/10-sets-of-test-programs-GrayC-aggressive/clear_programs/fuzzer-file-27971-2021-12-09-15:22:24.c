/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 -((short)((((double)(0)) -((double)(g)))))-((int)((((int)(0)) ^((int)(0)))))-((int)((((int)(g)) >>((int)(0))))) + 42 -((short)((((int)(((short)((((double)(0)) -((double)(g))))))) |((int)(g)))))-((int)((((int)(0)) ^((int)(((int)((((int)(0)) ^((int)(0))))))))))-((long)((((double)(0)) *((double)(0 + 42)))))*((int)((((double)(0 + 42 -((short)((((double)(0)) -((double)(g)))))-((int)((((int)(0)) ^((int)(0))))))) -((double)(0 + 42))))); g < 32; g++)
    if (0)
      {
        e = d + 42 -((int)((((int)(d)) <<((int)(d)))))-((long)((((double)(d)) -((double)(e)))))-((short)((((int)(d)) &((int)(e)))))-((int)((((double)(e)) +((double)(e)))))*((short)((((int)(d)) >>((int)(d))))) + 42 *((int)((((int)(d + 42 -((int)((((int)(d)) <<((int)(d)))))-((long)((((double)(d)) -((double)(e)))))-((short)((((int)(d)) &((int)(e)))))-((int)((((double)(e)) +((double)(e)))))*((short)((((int)(d)) >>((int)(d))))))) |((int)(e)))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 *((int)((((int)(*a)) >>((int)(b))))) + 42 -((short)((((int)(b)) &((int)(*a)))))*((int)((((int)(((int)((((int)(*a)) >>((int)(b))))))) ^((int)(42)))))-((long)((((int)(b)) <<((int)(b)))))-((short)((((int)(*a)) &((int)(*a + 42 *((int)((((int)(*a)) >>((int)(b))))))))))+((long)((((double)(42)) *((double)(b)))));
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))) + 42 -((short)((((double)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))) *((double)(f)))))+((int)((((double)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))) -((double)(f)))))-((int)((((double)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))) -((double)(f)))))-((short)((((double)(f)) *((double)(f)))))+((short)((((int)(f)) |((int)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
