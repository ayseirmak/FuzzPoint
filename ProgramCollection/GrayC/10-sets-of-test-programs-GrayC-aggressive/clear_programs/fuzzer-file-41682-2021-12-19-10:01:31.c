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
  if (((int)((int)i <= 10 + 42 *((int)((((int)(i)) |((int)(10)))))*((int)((((int)(10)) ^((int)(i)))))*((long)((((int)(i)) <<((int)(10)))))*((int)((((double)(10)) -((double)(i)))))+((long)((((double)(i)) -((double)(i)))))*((short)((((int)(10)) &((int)(i)))))*((long)((((double)(i)) -((double)(10)))))) + 42 -((int)((((int)(((long)((((double)(i)) -((double)(i)))))*((short)((((int)(10)) &((int)(i)))))*((long)((((double)(i)) -((double)(10))))))) |((int)(10 + 42 *((int)((((int)(i)) |((int)(10)))))*((int)((((int)(10)) ^((int)(i)))))*((long)((((int)(i)) <<((int)(10)))))*((int)((((double)(10)) -((double)(i))))))))))-((short)((((int)(42 *((int)((((int)(i)) |((int)(10)))))*((int)((((int)(10)) ^((int)(i)))))*((long)((((int)(i)) <<((int)(10)))))*((int)((((double)(10)) -((double)(i))))))) &((int)(42 *((int)((((int)(i)) |((int)(10)))))*((int)((((int)(10)) ^((int)(i)))))*((long)((((int)(i)) <<((int)(10)))))*((int)((((double)(10)) -((double)(i))))))))))-((int)((((int)(((int)((((double)(10)) -((double)(i))))))) |((int)(((int)((((double)(10)) -((double)(i))))))))))-((short)((((int)((int)i)) |((int)(10 + 42 *((int)((((int)(i)) |((int)(10)))))*((int)((((int)(10)) ^((int)(i)))))*((long)((((int)(i)) <<((int)(10)))))*((int)((((double)(10)) -((double)(i)))))+((long)((((double)(i)) -((double)(i)))))*((short)((((int)(10)) &((int)(i)))))*((long)((((double)(i)) -((double)(10))))))))))+((int)((((int)(10 + 42 *((int)((((int)(i)) |((int)(10)))))*((int)((((int)(10)) ^((int)(i)))))*((long)((((int)(i)) <<((int)(10)))))*((int)((((double)(10)) -((double)(i))))))) ^((int)(((long)((((int)(i)) <<((int)(10))))))))))-((int)((((double)(((long)((((double)(i)) -((double)(i))))))) -((double)(((long)((((double)(i)) -((double)(i))))))))))))
    do
      {
	++i;
	asm ("");
      }
    while (i != 11);
  return 0;
}
/* ProgramSourceLLVM */
