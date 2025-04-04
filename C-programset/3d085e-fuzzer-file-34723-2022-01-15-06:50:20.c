/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = (0xBA8AF); g < (0x7611C1); g++)
    if (f)
      {
        
e = d;
e = d;
;
        __builtin_memcpy (&b, &e, sizeof (float));
        ;
      }
}

int
main ()
{
  int h = ((0x4));
  ;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return ((2048));
}
/* ProgramSourceLLVM */
