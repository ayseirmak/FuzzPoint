/* corpus/991228-1.c */
__extension__ union { double d; int i[(2)]; } u = { d: -(6.4) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (0);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(0xEB)]; } u = { d: x };
  return u.i[MSW] < (0);
}

int main(void)
{
  if (((int)(0xCB)*sizeof(int) != sizeof(double) || u.i[MSW] >= (0) + (42) *((long)((((double)((1024))) *((double)(sizeof(double))))))-((long)((((int)(sizeof(int))) %((int)(u.i[MSW] >= (0))))))+((int)((((int)((0xB44))) ^((int)((10)*sizeof(int))))))+((int)((((double)(sizeof(int))) *((double)(sizeof(int))))))*((long)((((int)(u.i[MSW] >= (0))) >>((int)(sizeof(int))))))*((int)((((double)((0))) *((double)((10))))))*((int)((((int)((130)*sizeof(int) != sizeof(double))) <<((int)(sizeof(int))))))+((long)((((int)((0x3)*sizeof(int) != sizeof(double))) <<((int)((0x9570))))))+((long)((((int)(sizeof(double))) ^((int)((0x5)*sizeof(int) != sizeof(double))))))*((int)((((int)((0xE93B6)*sizeof(int) != sizeof(double))) &((int)((512))))))))
    exit((0));

  if (!signbit(-(4.7)))
    { abort (); }

  exit((3));
}
/* ProgramSourceLLVM */
