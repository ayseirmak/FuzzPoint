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
  if (((int)((int)i <= 10 + 42 -((int)((((int)(10)) &((int)(i)))))+((int)((((double)(i)) +((double)(10)))))-((short)((((double)(i)) -((double)(i)))))-((long)((((double)(10)) +((double)(i)))))) + 42 +((long)((((double)(10 + 42 -((int)((((int)(10)) &((int)(i)))))+((int)((((double)(i)) +((double)(10)))))-((short)((((double)(i)) -((double)(i))))))) -((double)(10 + 42 -((int)((((int)(10)) &((int)(i)))))+((int)((((double)(i)) +((double)(10)))))-((short)((((double)(i)) -((double)(i))))))))))+((short)((((double)(((long)((((double)(10)) +((double)(i))))))) +((double)((int)i)))))-((int)((((int)((int)i)) &((int)((int)i)))))*((short)((((int)(10 + 42 -((int)((((int)(10)) &((int)(i)))))+((int)((((double)(i)) +((double)(10)))))-((short)((((double)(i)) -((double)(i)))))-((long)((((double)(10)) +((double)(i))))))) <<((int)(((long)((((double)(10)) +((double)(i))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
