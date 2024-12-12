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
  if ((268435456))
    do
      {
	++i;
	asm ("");
      }
    while (i != (-(-13)));
  return ((9007199254740992));
}
/* ProgramSourceLLVM */
