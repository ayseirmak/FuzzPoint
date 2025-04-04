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
  if (((int)((int)i <= 10 + 41 + ((long)(((int)10) | ((int)(i)))) + ((short)(((double)10) + ((double)(i)))) * ((short)(((double)(i)) + ((double)10))) + ((short)(((double)(i)) + ((double)(i)))) * ((short)(((int)10) ^ ((int)10))) * ((short)(((int)(i)) ^ ((int)(i))))) + 41 + ((short)(((int)(10 + 41 + ((long)(((int)10) | ((int)(i)))) + ((short)(((double)10) + ((double)(i)))) * ((short)(((double)(i)) + ((double)10))) + ((short)(((double)(i)) + ((double)(i)))) * ((short)(((int)10) ^ ((int)10))) * ((short)(((int)(i)) ^ ((int)(i)))))) ^ ((int)((long)(((int)10) | ((int)(i))))))) + ((int)(((int)(((short)(((double)10) + ((double)(i)))) * ((short)(((double)(i)) + ((double)10))))) ^ ((int)(10 + 41 + ((long)(((int)10) | ((int)(i)))) + ((short)(((double)10) + ((double)(i)))) * ((short)(((double)(i)) + ((double)10))) + ((short)(((double)(i)) + ((double)(i)))) * ((short)(((int)10) ^ ((int)10))) * ((short)(((int)(i)) ^ ((int)(i)))))))) - ((long)(((int)(((short)(((double)10) + ((double)(i)))) * ((short)(((double)(i)) + ((double)10))))) | ((int)(((short)(((double)(i)) + ((double)(i)))) * ((short)(((int)10) ^ ((int)10))) * ((short)(((int)(i)) ^ ((int)(i)))))))) * ((int)(((int)((int)i)) ^ ((int)((int)i)))) - ((int)(((int)(((short)(((double)10) + ((double)(i)))) * ((short)(((double)(i)) + ((double)10))))) & ((int)(10 + 41)))) + ((int)(((int)(10 + 41 + ((long)(((int)10) | ((int)(i)))))) << ((int)(((short)(((double)(i)) + ((double)(i)))) * ((short)(((int)10) ^ ((int)10))) * ((short)(((int)(i)) ^ ((int)(i)))))))) * ((short)(((double)(10 + 41 + ((long)(((int)10) | ((int)(i)))))) * ((double)((int)i)))) * ((long)(((int)(((short)(((double)(i)) + ((double)(i)))) * ((short)(((int)10) ^ ((int)10))) * ((short)(((int)(i)) ^ ((int)(i)))))) | ((int)(((short)(((double)10) + ((double)(i)))) * ((short)(((double)(i)) + ((double)10))))))) + ((long)(((int)(((short)(((double)(i)) + ((double)(i)))) * ((short)(((int)10) ^ ((int)10))) * ((short)(((int)(i)) ^ ((int)(i)))))) | ((int)((int)i)))) - ((short)(((double)((long)(((int)10) | ((int)(i))))) * ((double)((long)(((int)10) | ((int)(i)))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
