/* corpus/pr79354.c */
/* PR target/79354 */

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void
foo (int *a)
{
  for (g = 0; g < 32; g++)
    if (0)
      {
        e = d + 42 * ((int)(((int)(d)) << ((int)(d)))) + ((int)(((double)(d)) - ((double)(d)))) * ((long)(((double)(d)) + ((double)(e)))) * ((short)(((double)(e)) + ((double)(e)))) * ((int)(((int)(e)) ^ ((int)(d)))) + 42 + ((short)(((int)(d + 42 * ((int)(((int)(d)) << ((int)(d)))) + ((int)(((double)(d)) - ((double)(d)))) * ((long)(((double)(d)) + ((double)(e)))) * ((short)(((double)(e)) + ((double)(e)))) * ((int)(((int)(e)) ^ ((int)(d)))))) % ((int)(e))));
        __builtin_memcpy (&b, &e, sizeof (float));
        
;f = 1;
*a + 42 * ((short)(((int)(*a)) % ((int)(b)))) - ((int)(((int)(b)) << ((int)(*a)))) * ((int)(((int)(*a)) & ((int)(b)))) * ((int)(((int)(*a)) | ((int)(*a)))) * ((long)(((double)(b)) - ((double)(b))));
      }
}

int
main ()
{
  int h = 5;
  f = 1;
  asm volatile ("" : : : "memory");
  foo (&h);
  asm volatile ("" : : : "memory");
  foo (&b);
  asm volatile ("" : : : "memory");
  return 0;
}
/* ProgramSourceLLVM */
