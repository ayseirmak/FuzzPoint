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
  if (((int)i <= ((0xAB43)) + (-(0x411C)) -((int)((((int)((0x4DA7))) &((int)(i)))))+((int)((((double)(i)) +((double)((0xB0AC35))))))-((short)((((double)(i)) -((double)(i)))))-((long)((((double)((0xB29))) +((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != ((0x861A)));
  return (0x0);
}
/* ProgramSourceLLVM */
