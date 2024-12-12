/* corpus/991228-1.c */
__extension__ union { double d; int i[(2)]; } u = { d: -(1.1) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (0x18F3D);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(2)]; } u = { d: x };
  return u.i[MSW] < (-1);
}

int main(void)
{
  if (((int)(34)*sizeof(int) != sizeof(double) || u.i[MSW] >= (-1) + (0x03986) *((int)((((double)((66))) -((double)((0))))))+((int)((((int)((0x307))) %((int)(u.i[MSW])))))+((long)((((int)((0x7DB4))) %((int)(sizeof(double))))))))
    exit((16384));

  if (!signbit(-(4.6)))
    { abort (); }

  exit((0));
}
/* ProgramSourceLLVM */
