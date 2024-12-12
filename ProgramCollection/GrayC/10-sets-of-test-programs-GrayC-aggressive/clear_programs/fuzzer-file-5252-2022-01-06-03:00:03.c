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
  if ((0xD6))
    do
      {
	++i;
	asm ("");
      }
    while (i != ((143)));
  return ((17592186044416));
}
/* ProgramSourceLLVM */
