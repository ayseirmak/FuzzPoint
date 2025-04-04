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
  if (((int)test (1.0f) != 0 + 41 * ((int)(((int)test (1.0f)) & ((int)0))) + ((short)(((double)0) * ((double)test (1.0f)))) - ((long)(((int)0) | ((int)test (1.0f)))) + ((int)(((int)0) >> ((int)test (1.0f)))) + ((int)(((double)test (1.0f)) - ((double)0))) + ((short)(((double)0) + ((double)0))) + ((int)(((double)0) - ((double)test (1.0f)))) * ((long)(((double)test (1.0f)) + ((double)test (1.0f)))) - ((short)(((int)test (1.0f)) | ((int)0)))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
