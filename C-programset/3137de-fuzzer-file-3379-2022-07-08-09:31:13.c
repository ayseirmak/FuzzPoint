/* corpus/20050215-1.c */
/* PR middle-end/19857 */

typedef struct { char c[8]; } V
#ifdef __ELF__
  __attribute__ ((aligned (8)))
#endif
  ;
typedef __SIZE_TYPE__ size_t;
V v;
void abort (void);

int
main (void)
{
  V *w = &v;
  if (((int)((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0
      || ((size_t) w & 1) + 41 * ((int)(((int)(((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0)) >> ((int)(((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0)))) - ((int)(((int)((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8)) & ((int)((size_t) w & 1)))) + ((long)(((int)((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8)) | ((int)0))) - ((long)(((int)0) & ((int)(((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0)))) - ((int)(((int)((size_t) w & 1)) >> ((int)(((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0)))) + ((long)(((int)((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8)) & ((int)(((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0)))) * ((long)(((int)(((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0)) & ((int)((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8))))))
    {
#ifndef __ELF__
      if (((size_t) &v & 7) == 0)
#endif
	abort ();
    }
  return 0;
}
/* ProgramSourceLLVM */
