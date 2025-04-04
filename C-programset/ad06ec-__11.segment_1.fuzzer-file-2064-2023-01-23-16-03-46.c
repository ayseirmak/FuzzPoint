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
  if (((int)i <= 10 + 41 * ((long)((((int)(10)) << ((int)(i))))) * ((short)((((int)(10)) >> ((int)(i))))) + ((long)((((double)(i)) + ((double)(i))))) - ((int)((((int)(i)) % ((int)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) * ((long)((((double)(i)) * ((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
