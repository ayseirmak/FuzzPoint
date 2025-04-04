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
  if (((int)((int)i <= 10 + 41 - ((long)((((double)(10)) * ((double)(i))))) - ((short)((((double)(10)) + ((double)(i))))) * ((long)((((int)(i)) | ((int)(i))))) + ((short)((((double)(10)) * ((double)(10)))))) + 41 - ((int)((((int)(((short)((((double)(10)) + ((double)(i))))) * ((long)((((int)(i)) | ((int)(i))))))) >> ((int)(((long)((((double)(10)) * ((double)(i)))))))))) - ((long)((((double)(10 + 41)) + ((double)(((short)((((double)(10)) + ((double)(i)))))))))) * ((int)((((int)((int)i)) << ((int)(((long)((((double)(10)) * ((double)(i))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
