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
  if (((int)((int)i <= 10 + 41 + ((short)((((double)(i)) - ((double)(i))))) - ((int)((((int)(10)) << ((int)(10))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) + ((double)(i))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) - ((double)(10))))) + ((int)((((double)(i)) + ((double)(10))))) - ((long)((((int)(i)) ^ ((int)(i)))))) + 41 - ((short)((((int)((int)i)) | ((int)(((int)((((double)(10)) + ((double)(i)))))))))) - ((short)((((int)(10 + 41 + ((short)((((double)(i)) - ((double)(i))))) - ((int)((((int)(10)) << ((int)(10))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) + ((double)(i))))))) % ((int)(10 + 41 + ((short)((((double)(i)) - ((double)(i))))) - ((int)((((int)(10)) << ((int)(10))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) + ((double)(i))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) - ((double)(10))))) + ((int)((((double)(i)) + ((double)(10))))) - ((long)((((int)(i)) ^ ((int)(i)))))))))) - ((int)((((double)(10 + 41 + ((short)((((double)(i)) - ((double)(i))))) - ((int)((((int)(10)) << ((int)(10))))))) + ((double)(((int)((((double)(i)) + ((double)(10)))))))))) * ((int)((((int)(((int)((((double)(i)) + ((double)(10))))))) ^ ((int)((int)i))))) * ((long)((((int)(10 + 41 + ((short)((((double)(i)) - ((double)(i))))) - ((int)((((int)(10)) << ((int)(10))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) + ((double)(i))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) - ((double)(10))))) + ((int)((((double)(i)) + ((double)(10))))) - ((long)((((int)(i)) ^ ((int)(i))))))) % ((int)(10 + 41 + ((short)((((double)(i)) - ((double)(i))))) - ((int)((((int)(10)) << ((int)(10))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) + ((double)(i))))) - ((int)((((double)(10)) + ((double)(i))))) * ((long)((((double)(10)) - ((double)(10))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
