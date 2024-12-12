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
  if (((int)((int)i <= 10 + 41 + ((int)((((int)(10)) >> ((int)(i))))) * ((int)((((double)(i)) + ((double)(10)))))) + 41 * ((long)((((double)(((int)((((double)(i)) + ((double)(10))))))) + ((double)(10))))) * ((int)((((double)(10)) - ((double)(10 + 41))))) * ((short)((((double)(((int)((((double)(i)) + ((double)(10))))))) - ((double)(10 + 41))))) + ((int)((((int)(((int)((((int)(10)) >> ((int)(i))))) * ((int)((((double)(i)) + ((double)(10))))))) ^ ((int)(41))))) * ((short)((((int)(((int)((((int)(10)) >> ((int)(i))))))) & ((int)(((int)((((int)(10)) >> ((int)(i))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
