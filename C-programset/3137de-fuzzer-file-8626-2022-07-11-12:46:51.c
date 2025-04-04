/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0; g < 32; g++)
    if (f)
      {
        
;b = *a;
d;
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 * ((long)(((int)(*a)) >> ((int)(*a)))) + ((short)(((int)(*a)) << ((int)(*a))));
      }
}

int
main ()
{
  int h = 5;
  f;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
