/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 -((long)((((double)(0)) +((double)(g)))))-((int)((((double)(0)) +((double)(0))))); g < 32; g++)
    if (f)
      {
        

e = d + 42 -((long)((((int)(d)) ^((int)(d)))))*((long)((((int)(e)) |((int)(e)))))*((long)((((double)(e)) -((double)(d)))));
e = d + 42 -((long)((((int)(d)) ^((int)(d)))))*((long)((((int)(e)) |((int)(e)))))*((long)((((double)(e)) -((double)(d)))));
;
;
;
        __builtin_memcpy (&b, &e, sizeof (float));
        
;
;
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
