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
  if (((int)i <= (-11) + (58) +((int)((((double)(i)) *((double)(i)))))*((long)((((double)((-11))) +((double)((10))))))*((long)((((double)((0x14))) *((double)(i)))))+((short)((((double)(i)) -((double)(i)))))+((long)((((double)((0x1A3))) +((double)((74))))))-((short)((((double)((-11))) +((double)(i)))))+((int)((((int)(i)) ^((int)(i)))))+((long)((((double)(i)) +((double)((8))))))-((int)((((double)(i)) +((double)((10))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != (27));
  return (0);
}
/* ProgramSourceLLVM */
