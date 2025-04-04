/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 +((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0)) ^((int)(g)))))*((short)((((double)(0)) -((double)(g))))) + 42 -((short)((((double)(g)) *((double)(g)))))*((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0 + 42 +((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0)) ^((int)(g)))))*((short)((((double)(0)) -((double)(g))))))) |((int)(0 + 42 +((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0)) ^((int)(g)))))*((short)((((double)(0)) -((double)(g))))))))))+((long)((((int)(0 + 42 +((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0)) ^((int)(g)))))*((short)((((double)(0)) -((double)(g))))))) %((int)(0 + 42 +((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0)) ^((int)(g)))))*((short)((((double)(0)) -((double)(g))))))))))-((short)((((int)(g)) ^((int)(0 + 42 +((long)((((double)(g)) *((double)(g)))))-((int)((((int)(0)) ^((int)(g)))))*((short)((((double)(0)) -((double)(g)))))))))); g < 32; g++)
    if (f)
      {
        
e = d + 42 -((int)((((int)(d)) |((int)(e)))))+((int)((((double)(e)) +((double)(d))))) + 42 *((short)((((double)(d + 42 -((int)((((int)(d)) |((int)(e)))))+((int)((((double)(e)) +((double)(d))))))) *((double)(e)))))+((long)((((double)(e)) +((double)(e)))))+((long)((((int)(e)) >>((int)(e)))));
e = d + 42 -((int)((((int)(d)) |((int)(e)))))+((int)((((double)(e)) +((double)(d))))) + 42 *((short)((((double)(d + 42 -((int)((((int)(d)) |((int)(e)))))+((int)((((double)(e)) +((double)(d))))))) *((double)(e)))))+((long)((((double)(e)) +((double)(e)))))+((long)((((int)(e)) >>((int)(e)))));
;
        __builtin_memcpy (&b, &e, sizeof (float));
        
b = *a + 42 *((int)((((int)(b)) <<((int)(*a)))))+((int)((((double)(b)) -((double)(b)))))*((int)((((double)(b)) -((double)(b))))) + 42 -((short)((((int)(b)) <<((int)(*a + 42 *((int)((((int)(b)) <<((int)(*a))))))))))+((int)((((int)(*a)) |((int)(((int)((((double)(b)) -((double)(b)))))*((int)((((double)(b)) -((double)(b))))))))));
b = *a + 42 *((int)((((int)(b)) <<((int)(*a)))))+((int)((((double)(b)) -((double)(b)))))*((int)((((double)(b)) -((double)(b))))) + 42 -((short)((((int)(b)) <<((int)(*a + 42 *((int)((((int)(b)) <<((int)(*a))))))))))+((int)((((int)(*a)) |((int)(((int)((((double)(b)) -((double)(b)))))*((int)((((double)(b)) -((double)(b))))))))));
;
      }
}

int
main ()
{
  int h = 5;
  ;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
