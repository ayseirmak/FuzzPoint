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
  if (i <= ((0xAD)))
    do
      {
	++i;
	asm ("");
      }
    while (i != ((139)));
  return ((0));
}
/* ProgramSourceLLVM */
