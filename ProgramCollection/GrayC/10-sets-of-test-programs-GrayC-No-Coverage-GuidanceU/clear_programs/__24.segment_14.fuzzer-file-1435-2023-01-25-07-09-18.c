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
  if (((int)i <= 10 + 41 - ((short)((((double)(10)) - ((double)(i))))) - ((short)((((int)(10)) << ((int)(i))))) + ((short)((((int)(10)) & ((int)(10))))) + ((long)((((int)(i)) & ((int)(i))))) + ((short)((((double)(i)) + ((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
