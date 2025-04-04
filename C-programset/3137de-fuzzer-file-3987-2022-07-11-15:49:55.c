/* corpus/20080529-1.c */
/* PR target/36362 */

extern void abort (void);

int
test (float c)
{
  return !!c * 7LL == 0;
}

int
main (void)
{
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
