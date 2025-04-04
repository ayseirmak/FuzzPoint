/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 +((int)((((int)(0)) >>((int)(0))))); g < 32; g++)
    if (f)
      {
        
e = d + 42 +((int)((((int)(e)) <<((int)(e)))))-((short)((((int)(d)) &((int)(e)))))-((short)((((int)(d)) %((int)(e)))));
e = d + 42 +((int)((((int)(e)) <<((int)(e)))))-((short)((((int)(d)) &((int)(e)))))-((short)((((int)(d)) %((int)(e)))));
;
        __builtin_memcpy (&b, &e, sizeof (float));
        
b = *a + 42 +((long)((((int)(*a)) ^((int)(*a)))));
b = *a + 42 +((long)((((int)(*a)) ^((int)(*a)))));
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
