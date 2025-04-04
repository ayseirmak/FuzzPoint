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
  if (((int)i <= (0xB2A75) + (40) -((int)((((int)((0x5842))) &((int)(i)))))+((int)((((double)(i)) +((double)((80))))))-((short)((((double)(i)) -((double)(i)))))-((long)((((double)((0x5F770C))) +((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != (11));
  return (0);
}
/* ProgramSourceLLVM */
