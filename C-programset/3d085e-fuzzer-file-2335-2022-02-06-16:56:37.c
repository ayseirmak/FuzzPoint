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
  if (((int)i <= (-11) + 42 *((long)((((int)(i)) |((int)(i)))))-((int)((((double)((-11))) -((double)(i)))))-((int)((((int)(i)) >>((int)(i)))))+((int)((((double)((-11))) +((double)(i)))))-((short)((((int)((-11))) |((int)((-11))))))+((short)((((double)(i)) *((double)((-11))))))+((short)((((int)(i)) ^((int)((-11))))))-((long)((((double)(i)) -((double)(i)))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != (0xFF6));
  return (0);
}
/* ProgramSourceLLVM */
