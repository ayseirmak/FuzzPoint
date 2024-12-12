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
  if (((int)((int)i <= 10 + 42 +((long)((((double)(i)) *((double)(i)))))+((long)((((int)(i)) <<((int)(i)))))*((short)((((double)(10)) +((double)(10)))))*((long)((((int)(10)) %((int)(10)))))-((short)((((int)(10)) <<((int)(i)))))*((int)((((double)(i)) *((double)(i)))))) + 42 *((int)((((int)(((long)((((int)(i)) <<((int)(i))))))) &((int)((int)i)))))-((int)((((int)(((short)((((int)(10)) <<((int)(i)))))*((int)((((double)(i)) *((double)(i))))))) |((int)(((long)((((int)(i)) <<((int)(i)))))*((short)((((double)(10)) +((double)(10)))))*((long)((((int)(10)) %((int)(10))))))))))+((long)((((int)(10 + 42 +((long)((((double)(i)) *((double)(i)))))+((long)((((int)(i)) <<((int)(i)))))*((short)((((double)(10)) +((double)(10)))))*((long)((((int)(10)) %((int)(10))))))) &((int)((int)i)))))-((short)((((int)(((long)((((int)(i)) <<((int)(i))))))) |((int)(10 + 42 +((long)((((double)(i)) *((double)(i)))))+((long)((((int)(i)) <<((int)(i)))))*((short)((((double)(10)) +((double)(10)))))*((long)((((int)(10)) %((int)(10)))))-((short)((((int)(10)) <<((int)(i)))))*((int)((((double)(i)) *((double)(i))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
