/* corpus/20080502-1.c */
/* PR target/36090 */

extern void abort (void);

long double __attribute__ ((noinline)) foo (long double x)
{
  return __builtin_signbit (x) ? 3.1415926535897932384626433832795029L : 0.0;
}

int
main (void)
{
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
