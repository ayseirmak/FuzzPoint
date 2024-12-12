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
  if (((int)i <= (-11) + (0x614FB6) -((int)((((int)((-11))) &((int)(i)))))+((int)((((double)(i)) +((double)((10))))))-((short)((((double)(i)) -((double)(i)))))-((long)((((double)((0xA8))) +((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != (0x001487));
  return (2199023255552);
}
/* ProgramSourceLLVM */
