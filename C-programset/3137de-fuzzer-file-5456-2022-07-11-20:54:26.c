/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 7062; g < 20786; g++)
    if (f)
      {
        
;b = *a;
e;
        __builtin_memcpy (&b, &e, sizeof (float));
        
;f = 18333;
b = *a;
      }
}

int
main ()
{
  int h = 22330;
  f = 18333;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
