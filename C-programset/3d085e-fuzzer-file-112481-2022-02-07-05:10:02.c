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
  if (((int)i <= (-(0x7E94)) + (106) *((long)((((int)(i)) |((int)(i)))))-((int)((((double)((-(-12)))) -((double)(i)))))-((int)((((int)(i)) >>((int)(i)))))+((int)((((double)((-(-12)))) +((double)(i)))))-((short)((((int)((-(0x7927)))) |((int)((-(11)))))))+((short)((((double)(i)) *((double)((-(27)))))))+((short)((((int)(i)) ^((int)((-(-12)))))))-((long)((((double)(i)) -((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != (0xFF6));
  return ((0));
}
/* ProgramSourceLLVM */
