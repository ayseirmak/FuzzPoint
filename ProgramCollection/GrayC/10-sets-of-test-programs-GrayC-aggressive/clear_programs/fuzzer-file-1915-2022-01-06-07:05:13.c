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
  if ((0x322D1))
    do
      {
	++i;
	asm ("");
      }
    while (i != ((143)));
  return ((1152921504606846976));
}
/* ProgramSourceLLVM */
