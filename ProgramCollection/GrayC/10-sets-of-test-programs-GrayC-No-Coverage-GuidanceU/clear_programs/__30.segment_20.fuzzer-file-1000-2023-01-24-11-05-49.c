/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0 + 42 - ((int)((((double)(0)) + ((double)(g))))) * ((int)((((double)(g)) * ((double)(0))))) * ((short)((((int)(g)) << ((int)(0))))) + ((long)((((int)(0)) << ((int)(0))))); g < 32; g++)
    if (f)
      {
        e = d;
        __builtin_memcpy (&b, &e, sizeof (float));
        b = *a + 42 + ((short)((((int)(b)) % ((int)(b))))) * ((int)((((int)(b)) | ((int)(*a)))));
      }
}

int
main ()
{
  int h = 5;
  f = 1 + 42 - ((long)((((double)(f)) + ((double)(1))))) + 42 * ((short)((((double)(f)) - ((double)(1 + 42 - ((long)((((double)(f)) + ((double)(1)))))))))) + ((int)((((double)(1 + 42 - ((long)((((double)(f)) + ((double)(1))))))) - ((double)(1 + 42 - ((long)((((double)(f)) + ((double)(1)))))))))) * ((int)((((double)(1 + 42 - ((long)((((double)(f)) + ((double)(1))))))) - ((double)(f))))) - ((short)((((int)(1 + 42 - ((long)((((double)(f)) + ((double)(1))))))) ^ ((int)(1 + 42 - ((long)((((double)(f)) + ((double)(1)))))))))) * ((short)((((double)(1 + 42 - ((long)((((double)(f)) + ((double)(1))))))) + ((double)(1 + 42 - ((long)((((double)(f)) + ((double)(1))))))))));
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
