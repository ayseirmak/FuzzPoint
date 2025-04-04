/* corpus/991228-1.c */
__extension__ union { double d; int i[(0x24)]; } u = { d: -(7.2) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (3);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(130)]; } u = { d: x };
  return u.i[MSW] < (128);
}

int main(void)
{
  if (((int)(3)*sizeof(int) != sizeof(double) || u.i[MSW] >= (0) + 42 *((long)((((int)(u.i[MSW] >= (0))) |((int)((3)*sizeof(int) != sizeof(double))))))*((int)((((int)((3))) &((int)(u.i[MSW])))))*((short)((((int)((3))) <<((int)((3))))))+((long)((((int)(u.i[MSW])) ^((int)((3)*sizeof(int) != sizeof(double))))))-((int)((((int)((0))) ^((int)(sizeof(double))))))-((long)((((double)((0))) +((double)((3))))))*((int)((((int)(u.i[MSW] >= (0))) >>((int)((3)*sizeof(int) != sizeof(double))))))))
    exit((0));

  if (!signbit(-(8.1)))
    { abort (); }

  exit((0x3E7));
}
/* ProgramSourceLLVM */
