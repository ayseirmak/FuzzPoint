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
  if (((int)i <= 10 + 42 +((int)((((int)(10)) ^((int)(i)))))+((short)((((double)(10)) +((double)(10)))))-((long)((((int)(10)) <<((int)(10)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
