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
  if (((int)((int)i <= 10 + 42 +((int)((((double)(i)) *((double)(i)))))*((long)((((double)(10)) +((double)(10)))))*((long)((((double)(10)) *((double)(i)))))+((short)((((double)(i)) -((double)(i)))))+((long)((((double)(10)) +((double)(10)))))-((short)((((double)(10)) +((double)(i)))))+((int)((((int)(i)) ^((int)(i)))))+((long)((((double)(i)) +((double)(10)))))-((int)((((double)(i)) +((double)(10)))))) + 42 *((int)((((int)(10 + 42 +((int)((((double)(i)) *((double)(i)))))*((long)((((double)(10)) +((double)(10)))))*((long)((((double)(10)) *((double)(i)))))+((short)((((double)(i)) -((double)(i)))))+((long)((((double)(10)) +((double)(10)))))-((short)((((double)(10)) +((double)(i)))))+((int)((((int)(i)) ^((int)(i)))))+((long)((((double)(i)) +((double)(10)))))-((int)((((double)(i)) +((double)(10))))))) &((int)(10 + 42 +((int)((((double)(i)) *((double)(i)))))*((long)((((double)(10)) +((double)(10)))))*((long)((((double)(10)) *((double)(i)))))+((short)((((double)(i)) -((double)(i)))))+((long)((((double)(10)) +((double)(10)))))-((short)((((double)(10)) +((double)(i)))))+((int)((((int)(i)) ^((int)(i)))))+((long)((((double)(i)) +((double)(10))))))))))-((long)((((double)(((long)((((double)(i)) +((double)(10))))))) -((double)(10 + 42)))))-((long)((((int)(((int)((((double)(i)) *((double)(i)))))*((long)((((double)(10)) +((double)(10))))))) >>((int)((int)i)))))-((int)((((int)(10 + 42 +((int)((((double)(i)) *((double)(i)))))*((long)((((double)(10)) +((double)(10)))))*((long)((((double)(10)) *((double)(i)))))+((short)((((double)(i)) -((double)(i)))))+((long)((((double)(10)) +((double)(10)))))-((short)((((double)(10)) +((double)(i)))))+((int)((((int)(i)) ^((int)(i)))))+((long)((((double)(i)) +((double)(10))))))) &((int)(((int)((((double)(i)) +((double)(10))))))))))+((short)((((int)(10 + 42 +((int)((((double)(i)) *((double)(i)))))*((long)((((double)(10)) +((double)(10)))))*((long)((((double)(10)) *((double)(i)))))+((short)((((double)(i)) -((double)(i))))))) ^((int)(10 + 42 +((int)((((double)(i)) *((double)(i)))))*((long)((((double)(10)) +((double)(10)))))*((long)((((double)(10)) *((double)(i)))))+((short)((((double)(i)) -((double)(i)))))+((long)((((double)(10)) +((double)(10)))))-((short)((((double)(10)) +((double)(i)))))+((int)((((int)(i)) ^((int)(i))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
