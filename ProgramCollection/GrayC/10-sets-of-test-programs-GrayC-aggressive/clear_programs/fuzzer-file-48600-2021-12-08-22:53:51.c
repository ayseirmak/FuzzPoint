/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 -((short)((((double)(0)) -((double)(g)))))-((int)((((int)(0)) ^((int)(0)))))-((int)((((int)(g)) >>((int)(0))))) + 42 +((long)((((int)(0)) &((int)(((int)((((int)(0)) ^((int)(0))))))))))+((int)((((int)(0)) |((int)(0 + 42 -((short)((((double)(0)) -((double)(g))))))))))-((short)((((int)(0 + 42 -((short)((((double)(0)) -((double)(g)))))-((int)((((int)(0)) ^((int)(0))))))) |((int)(((int)((((int)(g)) >>((int)(0))))))))))+((short)((((double)(((int)((((int)(0)) ^((int)(0))))))) *((double)(0 + 42))))); g < 32; g++)
    if (f)
      {
        e = d + 42 -((int)((((int)(d)) <<((int)(d)))))-((long)((((double)(d)) -((double)(e)))))-((short)((((int)(d)) &((int)(e)))))-((int)((((double)(e)) +((double)(e)))))*((short)((((int)(d)) >>((int)(d))))) + 42 +((long)((((int)(e)) ^((int)(e)))))-((long)((((int)(e)) |((int)(e)))))-((short)((((double)(e)) *((double)(e)))))-((int)((((int)(e)) <<((int)(d + 42 -((int)((((int)(d)) <<((int)(d)))))-((long)((((double)(d)) -((double)(e)))))-((short)((((int)(d)) &((int)(e)))))-((int)((((double)(e)) +((double)(e)))))*((short)((((int)(d)) >>((int)(d))))))))))+((short)((((int)(d + 42 -((int)((((int)(d)) <<((int)(d)))))-((long)((((double)(d)) -((double)(e)))))-((short)((((int)(d)) &((int)(e)))))-((int)((((double)(e)) +((double)(e)))))*((short)((((int)(d)) >>((int)(d))))))) %((int)(d + 42 -((int)((((int)(d)) <<((int)(d)))))-((long)((((double)(d)) -((double)(e)))))-((short)((((int)(d)) &((int)(e)))))-((int)((((double)(e)) +((double)(e)))))*((short)((((int)(d)) >>((int)(d))))))))));
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 *((int)((((int)(*a)) >>((int)(b))))) + 42 +((short)((((int)(*a + 42 *((int)((((int)(*a)) >>((int)(b))))))) >>((int)(*a + 42 *((int)((((int)(*a)) >>((int)(b))))))))))-((short)((((int)(*a)) >>((int)(42 *((int)((((int)(*a)) >>((int)(b))))))))))+((short)((((int)(*a + 42 *((int)((((int)(*a)) >>((int)(b))))))) >>((int)(*a + 42 *((int)((((int)(*a)) >>((int)(b))))))))))*((short)((((int)(*a)) &((int)(*a + 42 *((int)((((int)(*a)) >>((int)(b))))))))));
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))) + 42 *((long)((((double)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))) *((double)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))))))-((long)((((int)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))) >>((int)(f)))))+((int)((((int)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))) |((int)(1 + 42 -((int)((((int)(1)) &((int)(1)))))+((int)((((double)(1)) +((double)(1)))))+((short)((((int)(1)) >>((int)(f)))))+((long)((((int)(f)) &((int)(f))))))))))-((long)((((int)(f)) &((int)(f)))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
