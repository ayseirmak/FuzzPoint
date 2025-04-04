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
  if (((int)i <= 10 + 41 * ((long)((((double)(10)) - ((double)(10))))) + ((int)((((double)(i)) * ((double)(i))))) * ((int)((((int)(i)) ^ ((int)(10))))) + ((short)((((int)(i)) | ((int)(i))))) * ((int)((((double)(i)) - ((double)(10))))) - ((long)((((double)(i)) + ((double)(10))))) + ((long)((((double)(10)) * ((double)(10))))) * ((int)((((double)(10)) * ((double)(i))))) + ((long)((((double)(i)) * ((double)(10)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
