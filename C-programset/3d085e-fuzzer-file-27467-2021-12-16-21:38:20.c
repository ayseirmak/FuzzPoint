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
  if ((0x1D64))
    do
      {
	++i;
	asm ("");
      }
    while (i != (0xDE91));
  return ((8796093022208));
}
/* ProgramSourceLLVM */
