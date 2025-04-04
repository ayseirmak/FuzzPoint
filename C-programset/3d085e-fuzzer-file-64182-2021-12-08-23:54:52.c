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
  if (((int)i <= (-11) + (0x81) -((int)((((int)((14))) &((int)(i)))))+((int)((((double)(i)) +((double)((0x4059))))))-((short)((((double)(i)) -((double)(i)))))-((long)((((double)((26))) +((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != (11));
  return (0);
}
/* ProgramSourceLLVM */
