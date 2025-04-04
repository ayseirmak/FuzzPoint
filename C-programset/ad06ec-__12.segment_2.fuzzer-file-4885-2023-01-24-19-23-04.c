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
  if (((int)((int)i <= 10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))) + ((short)((((double)(10)) - ((double)(i))))) + ((long)((((int)(10)) & ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((int)((((double)(i)) - ((double)(10))))) - ((long)((((int)(i)) & ((int)(i)))))) + 41 - ((long)((((int)(((short)((((double)(10)) - ((double)(i))))))) ^ ((int)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))) + ((short)((((double)(10)) - ((double)(i))))) + ((long)((((int)(10)) & ((int)(i)))))))))) + ((long)((((double)(((long)((((int)(10)) ^ ((int)(i))))))) - ((double)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))) + ((short)((((double)(10)) - ((double)(i))))) + ((long)((((int)(10)) & ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))) + ((int)((((double)(i)) - ((double)(10))))) - ((long)((((int)(i)) & ((int)(i)))))))))) - ((long)((((int)(((long)((((int)(10)) & ((int)(i))))))) ^ ((int)(10 + 41))))) + ((short)((((double)((int)i)) + ((double)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i)))))))))) + ((short)((((double)(((short)((((double)(10)) - ((double)(i))))))) - ((double)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))) + ((short)((((double)(10)) - ((double)(i)))))))))) + ((long)((((int)(((long)((((int)(i)) & ((int)(i))))))) & ((int)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i)))))))))) - ((long)((((double)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))) + ((short)((((double)(10)) - ((double)(i))))) + ((long)((((int)(10)) & ((int)(i))))) - ((long)((((double)(i)) - ((double)(i))))))) - ((double)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10)))))))))) + ((int)((((double)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))))) - ((double)(((short)((((double)(10)) - ((double)(i)))))))))) - ((long)((((int)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))) + ((short)((((double)(10)) - ((double)(i))))) + ((long)((((int)(10)) & ((int)(i))))))) & ((int)(10 + 41 - ((long)((((int)(10)) ^ ((int)(i))))) + ((long)((((double)(10)) - ((double)(10))))) - ((long)((((int)(10)) ^ ((int)(i))))) + ((short)((((double)(i)) + ((double)(i))))) + ((short)((((double)(10)) - ((double)(i))))) + ((long)((((int)(10)) & ((int)(i))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
