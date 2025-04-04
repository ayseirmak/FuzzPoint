/* corpus/pr49218.c */
#ifdef __SIZEOF_INT128__
typedef __int128 L;
#else
typedef long long L;
#endif
float f;

int
main ()
{
  L i = f;
  if (((int)i <= 10 + 42 *((int)((((double)(i)) +((double)(i)))))+((int)((((int)(10)) ^((int)(i)))))-((int)((((double)(10)) +((double)(10)))))-((short)((((int)(10)) &((int)(i)))))-((long)((((int)(i)) <<((int)(10)))))-((long)((((double)(i)) -((double)(10)))))+((long)((((double)(10)) +((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
