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
  if (((int)i <= (26) + (0x89DB27) -((short)((((double)((11))) -((double)(i)))))+((int)((((double)((0xA00B6))) +((double)((10))))))-((short)((((double)(i)) -((double)(i)))))+((long)((((double)(i)) +((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != (11));
  return (0);
}
/* ProgramSourceLLVM */
