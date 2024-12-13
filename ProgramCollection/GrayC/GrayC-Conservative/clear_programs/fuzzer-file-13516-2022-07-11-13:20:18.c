/* corpus/floatunsisf-1.c */
/* The fp-bit.c function __floatunsisf had a latent bug where guard bits
   could be lost leading to incorrect rounding.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

extern void abort (void);
extern void exit (int);
#if __INT_MAX__ >= 0x7fffffff
volatile unsigned u = 0x80000081;
#else
volatile unsigned long u = 0x80000081;
#endif
volatile float f1, f2;
int
main (void)
{
  (float) u;
  (float) 0x80000081;
  if (((int)f1 != f2 + 41 * ((long)(((double)(f1)) * ((double)(f2)))) * ((int)(((double)(f2)) - ((double)(f1)))) + ((long)(((int)(f1)) & ((int)(f1)))) * ((long)(((int)(f2)) >> ((int)(f2)))) + ((int)(((int)(f1)) | ((int)(f2)))) - ((long)(((int)(f2)) >> ((int)(f1)))) - ((short)(((int)(f2)) & ((int)(f2))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
