/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 *((int)((((int)(g)) ^((int)(0)))))*((short)((((double)(g)) -((double)(0)))))*((short)((((int)(g)) ^((int)(g))))); g < 32; g++)
    if (0)
      {
        
e = d + 42 -((long)((((double)(d)) *((double)(e)))))*((short)((((int)(d)) &((int)(d)))))-((short)((((double)(d)) +((double)(d)))))-((int)((((double)(e)) +((double)(e)))));
e = d + 42 -((long)((((double)(d)) *((double)(e)))))*((short)((((int)(d)) &((int)(d)))))-((short)((((double)(d)) +((double)(d)))))-((int)((((double)(e)) +((double)(e)))));
;
        __builtin_memcpy (&b, &e, sizeof (float));
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
