/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = (0x0); g < (-33); g++)
    if (f)
      {
        ;
        __builtin_memcpy (&b, &e, sizeof (float));
        ;
      }
}

int
main ()
{
  int h = (7);
  
f = (1);
f = (17);
;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return (67108864);
}
/* ProgramSourceLLVM */
